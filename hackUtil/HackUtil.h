/*
 Code written by Adam Heinermann
 Last Updated: October 31st, 2009
*/

#include <stdio.h>
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>

// Typedefs
typedef unsigned __int8  u8 ;
typedef unsigned __int16 u16;
typedef unsigned __int32 u32;
typedef unsigned __int64 u64;

typedef signed   __int8  s8 ;
typedef signed   __int16 s16;
typedef signed   __int32 s32;
typedef signed   __int64 s64;

// Variables
#define BUFFER_SIZE 1024

#define __TOSTRING(l) #l
#define _TOSTRING(l) __TOSTRING(l)
#define FILELINE __FILE__ ":" _TOSTRING(__LINE__)

// Logger
void logfast(char* file, const char* format, ...);
void logError(const char* format, ...);
void logBegin(char* file);
void logBegin();
void logTime();
void logBytes(u8* data, u32 size);
void logBytes(char* file, u8* data, u32 size);
void logBytes(FILE* file, u8* data, u32 size);
void logAdd(const char* format, ...);
void logEnd();

// Imports
#define GetImportDescriptor(m) _GetImportDescriptor(FILELINE, m)
IMAGE_IMPORT_DESCRIPTOR* _GetImportDescriptor(const char *logline, HMODULE module);
IMAGE_THUNK_DATA32*      _GetImportsList(const char *logline, char* sourceModule, char* importModule);
IMAGE_THUNK_DATA32*      _GetImportsList(const char *logline, char* importModule);
DWORD*                   _GetFunctionsList(const char *logline, char* sourceModule, char* importModule);
DWORD*                   _GetFunctionsList(const char *logline, char* importModule);
/* These functions are not specifically made for public use */

bool PatchImport(char* sourceModule, char* importModule, LPCSTR function, void* patchFunction);
bool PatchImport(char* importModule, LPCSTR function, void* patchFunction);
/* Creates a detour for the specified import function in any loaded module */

#define GetImport(i,f) _GetImport(FILELINE, i, f)
FARPROC                _GetImport(const char *logline, char* importModule, LPCSTR function);
/* Retrieves the address of the imported function from the specified module */

// Memory
#define WriteNops(d,s) _WriteNops(FILELINE, d, s)
void _WriteNops(const char *logline, void* dest, u32 size);
void _WriteNops(const char *logline, u32 dest, u32 size);
/* Writes NOPs to the specified destination */

#define WriteMem(d,s,l) _WriteMem(FILELINE, d, s, l)
void _WriteMem(const char *logline, void* dest, void* source, u32 size);
void _WriteMem(const char *logline, u32 dest, void* source, u32 size);
/* Writes data to the specified destination from the source */

#define JmpPatch(d,p) _JmpPatch(FILELINE, d, p)
void _JmpPatch(const char *logline, void* dest, void* patch);
void _JmpPatch(const char *logline, u32 dest, void* patch);
/* Writes a jump to the specified patch at the destination */

#define CallPatch(d,p) _CallPatch(FILELINE, d, p)
void _CallPatch(const char *logline, void* dest, void* patch);
void _CallPatch(const char *logline, u32 dest, void* patch);
/* Writes a call to the specified patch at the destination */

#define Revert() _Revert(FILELINE)
void _Revert(const char *logline);
/* Reverts all changes made with any function except for WriteMemRaw */

#define WriteMemRaw(d,s,l) _WriteMemRaw(FILELINE, d, s, l)
void _WriteMemRaw(const char *logline, void* dest, void* source, u32 size);
void _WriteMemRaw(const char *logline, u32 dest, void* source, u32 size);
/* Writes to memory and does not include the change in the changes list */
