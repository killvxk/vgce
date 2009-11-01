/*
 Code written by Adam Heinermann
 Last Updated: October 31st, 2009
 Not for sale.
 Want to remove this? Go fuck yourself. Noob.
*/
#include "Hack.h"

char hackbuffer[BUFFER_SIZE];

struct memPatch
{
  void* location;
  char  patch[128];
  u32   patchSize;
};

SYSTEMTIME time;
FILE* globalLog;
DWORD lastAccess;
HMODULE ThisModule;

std::vector<memPatch> changes;

///////////////////////////////   LOGGER    //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
void logfast(char* file, const char* format, ...)
{
  va_list ap;
  va_start(ap, format);
  vsnprintf_s(hackbuffer, BUFFER_SIZE, BUFFER_SIZE, format, ap);
  va_end(ap);

  GetLocalTime(&time);

  FILE* logFile;
  fopen_s(&logFile, file, "a+");
  fprintf_s(logFile, "[%02d:%02d:%02d:%03d] %s\n", time.wHour, time.wMinute, time.wSecond, time.wMilliseconds, hackbuffer);
  fclose(logFile);
  return;
}

void logError(const char* format, ...)
{
  va_list ap;
  va_start(ap, format);
  vsnprintf_s(hackbuffer, BUFFER_SIZE, BUFFER_SIZE, format, ap);
  va_end(ap);

  logfast("Errors.log", hackbuffer);
  return;
}

void logBegin(char* file)
{
  if (globalLog != NULL)
  {
    fprintf_s(globalLog, "\n");
    fclose(globalLog);
  }
  fopen_s(&globalLog, file, "a+");
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

void logBytes(u8 *data, unsigned int size)
{
  for (u32 i = 0; i < size; i++)
    logAdd(" %02X", data[i]);
  return;
}

void logAdd(const char *format, ...)
{
  if (globalLog == NULL)
    return;

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

  fprintf_s(globalLog, "\n");
  fclose(globalLog);
  return;
}
///////////////////////////////   IMPORTS   //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

IMAGE_THUNK_DATA32* GetImportsList(char* sourceModule, char* importModule)
{
  char *tempModuleName;
  if (sourceModule == NULL)
    tempModuleName = ThisModuleName;
  else
    tempModuleName = sourceModule;

  HMODULE tempModule;
  tempModule = GetModuleHandleA(tempModuleName);

  if (tempModule == NULL)
  {
    logError("Could not obtain module handle of \"%s\" in GetImportsList().", tempModuleName);
    return NULL;
  }

  IMAGE_DOS_HEADER *mzhead = (IMAGE_DOS_HEADER*)tempModule;
  if (mzhead->e_magic != IMAGE_DOS_SIGNATURE)
  {
    logError("Could not locate MZ header in GetImportsList().");
    return NULL;
  }
  IMAGE_NT_HEADERS32 *pehead = (IMAGE_NT_HEADERS32*)(mzhead->e_lfanew + (u32)tempModule);
  if (pehead->Signature != IMAGE_NT_SIGNATURE)
  {
    logError("Could not locate PE header in GetImportsList().");
    return NULL;
  }
  IMAGE_IMPORT_DESCRIPTOR *imports = (IMAGE_IMPORT_DESCRIPTOR*)(pehead->OptionalHeader.DataDirectory[1].VirtualAddress + (u32)tempModule);
  if (imports == NULL)
  {
    logError("Could not locate imports section in GetImportsList().");
    return NULL;
  }

  for (u32 i = 0; imports[i].Name != 0; i++)
  {
    if (lstrcmpiA((char*)(imports[i].Name + (u32)tempModule), importModule) == 0)
      return (IMAGE_THUNK_DATA32*)(imports[i].OriginalFirstThunk + (u32)tempModule);
  }
  return NULL;
}

IMAGE_THUNK_DATA32* GetImportsList(char* importModule)
{
  return GetImportsList(NULL, importModule);
}

DWORD* GetFunctionsList(char* sourceModule, char* importModule)
{
  char *tempModuleName;
  if (sourceModule == NULL)
    tempModuleName = ThisModuleName;
  else
    tempModuleName = sourceModule;

  HMODULE tempModule = GetModuleHandleA(tempModuleName);
  if (tempModule == NULL)
  {
    logError("Could not obtain module handle of \"%s\" in GetFunctionsList().", tempModuleName);
    return NULL;
  }

  IMAGE_DOS_HEADER *mzhead = (IMAGE_DOS_HEADER*)tempModule;
  if (mzhead->e_magic != IMAGE_DOS_SIGNATURE)
  {
    logError("Could not locate MZ header in GetFunctionsList().");
    return NULL;
  }
  IMAGE_NT_HEADERS32 *pehead = (IMAGE_NT_HEADERS32*)(mzhead->e_lfanew + (u32)tempModule);
  if (pehead->Signature != IMAGE_NT_SIGNATURE)
  {
    logError("Could not locate PE header in GetFunctionsList().");
    return NULL;
  }
  IMAGE_IMPORT_DESCRIPTOR *imports = (IMAGE_IMPORT_DESCRIPTOR*)(pehead->OptionalHeader.DataDirectory[1].VirtualAddress + (u32)tempModule);
  if (imports == NULL)
  {
    logError("Could not locate imports section in GetFunctionsList().");
    return NULL;
  }

  for (u32 i = 0; imports[i].Name != 0; i++)
  {
    if (lstrcmpiA((char*)(imports[i].Name + (u32)tempModule), importModule) == 0)
      return (DWORD*)(imports[i].FirstThunk + (u32)tempModule);
  }
  return NULL;
}

DWORD* GetFunctionsList(char* importModule)
{
  return GetFunctionsList(NULL, importModule);
}

bool PatchImport(char* sourceModule, char* importModule, LPCSTR function, void* patchFunction)
{
  if (function == NULL)
  {
    logError("Did not specify a function in PatchImport().");
    return false;
  }

  char *tempModuleName;
  if (sourceModule == NULL)
    tempModuleName = ThisModuleName;
  else
    tempModuleName = sourceModule;

  HMODULE tempModule = GetModuleHandleA(tempModuleName);
  if (tempModule == NULL)
  {
    logError("Could not obtain module handle of \"%s\" in PatchImport().", tempModuleName);
    return false;
  }

  IMAGE_THUNK_DATA32* importOrigin = GetImportsList(sourceModule, importModule);
  if (importOrigin == NULL)
  {
    logError("Could not locate Imports Section for \"%s\" in %s in PatchImport().", importModule, sourceModule);
    return false;
  }

  DWORD* importFunction = GetFunctionsList(sourceModule, importModule);
  if (importOrigin == NULL)
  {
    logError("Could not locate Functions list for \"%s\" in %s in PatchImport().", importModule, sourceModule);
    return false;
  }

  for (u32 i = 0; importOrigin[i].u1.Ordinal != 0; i++)
  {
    if (IMAGE_SNAP_BY_ORDINAL32(importOrigin[i].u1.Ordinal) && (DWORD)function < 0xFFFF)
    {
      if (IMAGE_ORDINAL32(importOrigin[i].u1.Ordinal) == IMAGE_ORDINAL32((DWORD)function))
      {
        WriteMem(&importFunction[i], &patchFunction, 4);
        return true;
      }
    }
    else
    {
      if (lstrcmpiA(function, (char*)&(((PIMAGE_IMPORT_BY_NAME)importOrigin[i].u1.AddressOfData)->Name)) == 0)
      {
        WriteMem(&importFunction[i], &patchFunction, 4);
        return true;
      }
    }
  }
  
  if ((DWORD)function < 0xFFFF)
    logError("Could not locate import of ordinal %d (0x%X) in %s in PatchImport().", (DWORD)function, (DWORD)function, tempModuleName);
  else
    logError("Could not locate import of function \"%s\" in %s in PatchImport().", function, tempModuleName);

  return false;
}

bool PatchImport(char* importModule, LPCSTR function, void* patchFunction)
{
  return PatchImport(NULL, importModule, function, patchFunction);
}


FARPROC GetImport(char* importModule, LPCSTR function)
{
  HMODULE module = GetModuleHandleA(importModule);
  if (module == NULL)
  {
    logError("Could not find module \"%s\" in GetImport().", importModule);
    return NULL;
  }

  FARPROC rval = GetProcAddress(module, function);
  if (rval == NULL)
  {
    if ((DWORD)function < 0xFFFF)
      logError("Could not find ordinal %d (0x%X) in module %s in GetImport().", (DWORD)function, (DWORD)function, importModule);
    else
      logError("Could not find function \"%s\" in module %s in GetImport().", function, importModule);
    return NULL;
  }

  return rval;
}

///////////////////////////////   MEMORY   //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

void WriteNops(void* dest, u32 size)
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
    logError("Wrote to invalid memory address 0x%08X[%d] in WriteNops().", (u32)dest, size);
  }
  VirtualProtect(dest, size, lastAccess, &lastAccess);
  return;
}

void WriteNops(u32 dest, u32 size)
{
  WriteNops((void*)dest, size);
  return;
}

void WriteMem(void* dest, void* source, u32 size)
{
  memPatch tempPatch;
  tempPatch.location = dest;
  tempPatch.patchSize = size;
  memcpy_s(tempPatch.patch, 128, dest, size);
  changes.push_back(tempPatch);

  WriteMemRaw(dest, source, size);
  return;
}

void WriteMemRaw(void* dest, void* source, u32 size)
{
  VirtualProtect(dest, size, PAGE_EXECUTE_READWRITE, &lastAccess);
  __try
  {
    memcpy_s(dest, size, source, size);
  } 
  __except(1)
  {
    logError("Wrote to invalid memory address 0x%08X[%d] in WriteMemRaw().", (u32)dest, size);
  }
  VirtualProtect(dest, size, lastAccess, &lastAccess);
  return;
}

void WriteMem(u32 dest, void* source, u32 size)
{
  WriteMem((void*)dest, source, size);
  return;
}

void WriteMemRaw(u32 dest, void* source, u32 size)
{
  WriteMemRaw((void*)dest, source, size);
  return;
}

void JmpPatch(void* dest, void* patch)
{
  u8 temp[5];
  temp[0] = 0xE9;
  *(int*)&temp[1] = (int)dest - (int)patch - 5;
  WriteMem(dest, temp, 5);
  return;
}

void JmpPatch(u32 dest, void* patch)
{
  JmpPatch((void*)dest, patch);
  return;
}

void CallPatch(void* dest, void* patch)
{
  u8 temp[5];
  temp[0] = 0xE8;
  *(int*)&temp[1] = (int)dest - (int)patch - 5;
  WriteMem(dest, temp, 5);
  return;
}

void CallPatch(u32 dest, void* patch)
{
  CallPatch((void*)dest, patch);
  return;
}

void Revert()
{
  for each (memPatch i in changes)
    WriteMemRaw(i.location, i.patch, i.patchSize);
  changes.clear();
  return;
}
