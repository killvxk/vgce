/*
 Code written by Adam Heinermann
 Last Updated: October 31st, 2009
*/
#include "HackUtil.h"

static char hackbuffer[BUFFER_SIZE];

struct memPatch
{
  void* location;
  char  patch[128];
  u32   patchSize;
};

static SYSTEMTIME time;
static FILE* globalLog;
static DWORD lastAccess;

static std::vector<memPatch> changes;

///////////////////////////////   LOGGER    //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
void logfast(char* file, const char* format, ...)
{
  if (file == NULL)
  {
    logError("No file name specified for logfast()");
    return;
  }

  if (format == NULL)
  {
    logError("No formatting specified for logfast()");
    return;
  }

  va_list ap;
  va_start(ap, format);
  vsnprintf_s(hackbuffer, BUFFER_SIZE, BUFFER_SIZE, format, ap);
  va_end(ap);

  GetLocalTime(&time);

  FILE* logFile = _fsopen(file, "a+", _SH_DENYNO);
  fprintf_s(logFile, "[%02d:%02d:%02d:%03d] %s\n", time.wHour, time.wMinute, time.wSecond, time.wMilliseconds, hackbuffer);
  fclose(logFile);
  return;
}

void logError(const char* format, ...)
{
  if (format == NULL)
  {
    logError("No formatting specified for logError()");
    return;
  }

  va_list ap;
  va_start(ap, format);
  vsnprintf_s(hackbuffer, BUFFER_SIZE, BUFFER_SIZE, format, ap);
  va_end(ap);
  logfast("Errors.log", "%s", hackbuffer);
  return;
}

void logBegin(char* file)
{
  if (file == NULL)
  {
    logError("No file name specified for logBegin().");
    return;
  }

  if (globalLog != NULL)
  {
    fprintf_s(globalLog, "\n");
    fclose(globalLog);
  }
  globalLog = _fsopen(file, "a+", _SH_DENYNO);
  return;
}

void logBegin()
{
  if (globalLog == NULL)
    return;

  fprintf_s(globalLog, "\n");
  return;
}

void logTime()
{
  if (globalLog == NULL)
    return;

  GetLocalTime(&time);
  fprintf_s(globalLog, "[%02d:%02d:%02d:%03d] ", time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
  return;
}

void logBytes(u8 *data, u32 size)
{
  logBytes(globalLog, data, size);
  return;
}

void logBytes(FILE* file, u8* data, u32 size)
{
  if (file == NULL)
  {
    logError("Bad file handle for logBytes().");
    return;
  }

  if (data == NULL)
  {
    logError("No data specified for logBytes().");
    return;
  }

  memset(hackbuffer, 0, BUFFER_SIZE);
  for (u32 i = 0; i < size; i++)
  {
    u8 wbyte;
    __try
    {
      wbyte = data[i];
    }
    __except(1)
    {
      wbyte = 0xFF;
      logError("Read from invalid memory address 0x%08X[%d] in logBytes().", data, size);
    }
    char temp[5];
    sprintf_s(temp, 4, " %02X", wbyte);
    strcat_s(hackbuffer, BUFFER_SIZE, temp);
  }
  fprintf_s(globalLog, "%s", &hackbuffer[1]);
  return;
}

void logBytes(char* file, u8* data, u32 size)
{
  if (file == NULL)
  {
    logError("No file name specified for logBytes().");
    return;
  }

  FILE* logFile = _fsopen(file, "a+", _SH_DENYNO);
  logBytes(logFile, data, size);
  fclose(logFile);
  return;
}

void logAdd(const char *format, ...)
{
  if (globalLog == NULL)
    return;

  if (format == NULL)
  {
    logError("No format specified for logAdd()");
    return;
  }

  va_list ap;
  va_start(ap, format);
  vsnprintf_s(hackbuffer, BUFFER_SIZE, BUFFER_SIZE, format, ap);
  va_end(ap);

  fprintf_s(globalLog, "%s", hackbuffer);
  return;
}

void logEnd()
{
  if (globalLog == NULL)
    return;

  fseek(globalLog, 0, SEEK_END);
  fprintf_s(globalLog, "\n");
  fclose(globalLog);
  return;
}
///////////////////////////////   IMPORTS   //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

IMAGE_IMPORT_DESCRIPTOR* _GetImportDescriptor(const char *logline, HMODULE module)
{
  IMAGE_DOS_HEADER *mzhead = (IMAGE_DOS_HEADER*)module;
  if (mzhead->e_magic != IMAGE_DOS_SIGNATURE)
  {
    logError("Could not locate MZ header (%s).", logline);
    return NULL;
  }
  IMAGE_NT_HEADERS32 *pehead = (IMAGE_NT_HEADERS32*)(mzhead->e_lfanew + (u32)module);
  if (pehead->Signature != IMAGE_NT_SIGNATURE)
  {
    logError("Could not locate PE header (%s).", logline);
    return NULL;
  }
  IMAGE_IMPORT_DESCRIPTOR *imports = (IMAGE_IMPORT_DESCRIPTOR*)(pehead->OptionalHeader.DataDirectory[1].VirtualAddress + (u32)module);
  if (imports == NULL)
  {
    logError("Could not locate imports section (%s).", logline);
    return NULL;
  }
  return imports;
}

IMAGE_THUNK_DATA32* _GetImportsList(const char *logline, char* sourceModule, char* importModule)
{
  char *tempModuleName = NULL;
  if (sourceModule != NULL)
    tempModuleName = sourceModule;

  HMODULE tempModule;
  tempModule = GetModuleHandleA(tempModuleName);

  if (tempModule == NULL)
  {
    logError("Could not obtain module handle of \"%s\" (%s).", tempModuleName, logline);
    return NULL;
  }

  IMAGE_IMPORT_DESCRIPTOR *imports = _GetImportDescriptor(logline, tempModule);
  if (imports == NULL)
    return NULL;
  
  for (u32 i = 0; imports[i].Name != 0; i++)
  {
    if (lstrcmpiA((char*)(imports[i].Name + (u32)tempModule), importModule) == 0)
      return (IMAGE_THUNK_DATA32*)(imports[i].OriginalFirstThunk + (u32)tempModule);
  }
  return NULL;
}

IMAGE_THUNK_DATA32* _GetImportsList(const char *logline, char* importModule)
{
  return _GetImportsList(logline, NULL, importModule);
}

DWORD* _GetFunctionsList(const char *logline, char* sourceModule, char* importModule)
{
  char *tempModuleName = NULL;
  if (sourceModule != NULL)
    tempModuleName = sourceModule;

  HMODULE tempModule = GetModuleHandleA(tempModuleName);
  if (tempModule == NULL)
  {
    logError("Could not obtain module handle of \"%s\" (%s).", tempModuleName, logline);
    return NULL;
  }

  IMAGE_IMPORT_DESCRIPTOR *imports = _GetImportDescriptor(logline, tempModule);
  if (imports == NULL)
    return NULL;

  for (u32 i = 0; imports[i].Name != 0; i++)
  {
    if (lstrcmpiA((char*)(imports[i].Name + (u32)tempModule), importModule) == 0)
      return (DWORD*)(imports[i].FirstThunk + (u32)tempModule);
  }
  return NULL;
}

DWORD* _GetFunctionsList(const char *logline, char* importModule)
{
  return _GetFunctionsList(logline, NULL, importModule);
}

bool PatchImport(char* sourceModule, char* importModule, LPCSTR function, void* patchFunction)
{
  if (function == NULL)
  {
    logError("Did not specify a function for PatchImport().");
    return false;
  }

  char *tempModuleName = NULL;
  if (sourceModule != NULL)
    tempModuleName = sourceModule;

  HMODULE tempModule = GetModuleHandleA(tempModuleName);
  if (tempModule == NULL)
  {
    logError("Could not obtain module handle of \"%s\" for PatchImport().", tempModuleName);
    return false;
  }

  IMAGE_THUNK_DATA32* importOrigin = _GetImportsList(FILELINE, sourceModule, importModule);
  if (importOrigin == NULL)
  {
    logError("Could not locate Imports Section for \"%s\" in %s for PatchImport().", importModule, sourceModule);
    return false;
  }

  DWORD* importFunction = _GetFunctionsList(FILELINE, sourceModule, importModule);
  if (importOrigin == NULL)
  {
    logError("Could not locate Functions list for \"%s\" in %s for PatchImport().", importModule, sourceModule);
    return false;
  }

  for (u32 i = 0; importOrigin[i].u1.Ordinal != 0; i++)
  {
    if (IMAGE_SNAP_BY_ORDINAL32(importOrigin[i].u1.Ordinal) && (DWORD)function < 0xFFFF)
    {
      if (IMAGE_ORDINAL32(importOrigin[i].u1.Ordinal) == IMAGE_ORDINAL32((DWORD)function))
      {
        _WriteMem(FILELINE, &importFunction[i], &patchFunction, 4);
        return true;
      }
    }
    else
    {
      if (lstrcmpiA(function, (char*)&(((PIMAGE_IMPORT_BY_NAME)importOrigin[i].u1.AddressOfData)->Name)) == 0)
      {
        _WriteMem(FILELINE, &importFunction[i], &patchFunction, 4);
        return true;
      }
    }
  }
  
  if ((DWORD)function < 0xFFFF)
    logError("Could not locate import of ordinal %d (0x%X) in %s for PatchImport().", (DWORD)function, (DWORD)function, tempModuleName);
  else
    logError("Could not locate import of function \"%s\" in %s for PatchImport().", function, tempModuleName);

  return false;
}

bool PatchImport(char* importModule, LPCSTR function, void* patchFunction)
{
  return PatchImport(NULL, importModule, function, patchFunction);
}

FARPROC _GetImport(const char *logline, char* importModule, LPCSTR function)
{
  HMODULE module = GetModuleHandleA(importModule);
  if (module == NULL)
  {
    logError("Could not find module \"%s\"", importModule, logline);
    return NULL;
  }

  FARPROC rval = GetProcAddress(module, function);
  if (rval == NULL)
  {
    if ((DWORD)function < 0xFFFF)
      logError("Could not find ordinal %d (0x%X) in module %s (%s).", (DWORD)function, (DWORD)function, importModule, logline);
    else
      logError("Could not find function \"%s\" in module %s (%s).", function, importModule, logline);
    return NULL;
  }

  return rval;
}

///////////////////////////////   MEMORY   //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

void _WriteNops(const char *logline, void* dest, u32 size)
{
  memPatch tempPatch;
  tempPatch.location = dest;
  tempPatch.patchSize = size;
  memcpy_s(tempPatch.patch, 128, dest, size);
  changes.push_back(tempPatch);

  VirtualProtect(dest, size, PAGE_EXECUTE_READWRITE, &lastAccess);
  __try
  {
    memset(dest, 0x90, size);
  } 
  __except(1)
  {
    logError("Wrote to invalid memory address 0x%08X[%d] (%s).", (u32)dest, size, logline);
  }
  VirtualProtect(dest, size, lastAccess, &lastAccess);
  return;
}

void _WriteNops(const char *logline, u32 dest, u32 size)
{
  _WriteNops(logline, (void*)dest, size);
  return;
}

void _WriteMem(const char *logline, void* dest, void* source, u32 size)
{
  memPatch tempPatch;
  tempPatch.location = dest;
  tempPatch.patchSize = size;
  memcpy_s(tempPatch.patch, 128, dest, size);
  changes.push_back(tempPatch);

  _WriteMemRaw(logline, dest, source, size);
  return;
}

void _WriteMemRaw(const char *logline, void* dest, void* source, u32 size)
{
  VirtualProtect(dest, size, PAGE_EXECUTE_READWRITE, &lastAccess);
  __try
  {
    memcpy_s(dest, size, source, size);
  } 
  __except(1)
  {
    logError("Wrote to invalid memory address 0x%08X[%d] (%s).", (u32)dest, size, logline);
  }
  VirtualProtect(dest, size, lastAccess, &lastAccess);
  return;
}

void _WriteMem(const char *logline, u32 dest, void* source, u32 size)
{
  _WriteMem(logline, (void*)dest, source, size);
  return;
}

void _WriteMemRaw(const char *logline, u32 dest, void* source, u32 size)
{
  _WriteMemRaw(logline, (void*)dest, source, size);
  return;
}

void _JmpPatch(const char *logline, void* dest, void* patch)
{
  u8 temp[5];
  temp[0] = 0xE9;
  *(int*)&temp[1] = (int)dest - (int)patch - 5;
  _WriteMem(logline, dest, temp, 5);
  return;
}

void _JmpPatch(const char *logline, u32 dest, void* patch)
{
  _JmpPatch(logline, (void*)dest, patch);
  return;
}

void _CallPatch(const char *logline, void* dest, void* patch)
{
  u8 temp[5];
  temp[0] = 0xE8;
  *(int*)&temp[1] = (int)dest - (int)patch - 5;
  _WriteMem(logline, dest, temp, 5);
  return;
}

void _CallPatch(const char *logline, u32 dest, void* patch)
{
  _CallPatch(logline, (void*)dest, patch);
  return;
}

void _Revert(const char *logline)
{
  for each (memPatch i in changes)
    _WriteMemRaw(logline, i.location, i.patch, i.patchSize);
  changes.clear();
  return;
}
