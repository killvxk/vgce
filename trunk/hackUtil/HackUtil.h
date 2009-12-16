/*
 Code written by Adam Heinermann
 Last Updated: October 31st, 2009
 Not for sale.
 Want to remove this? Go fuck yourself. Noob.
*/

#include <stdio.h>
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>

#ifndef ThisModuleName
#define ThisModuleName "Starcraft.exe"
#endif

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
IMAGE_THUNK_DATA32* GetImportsList(char* sourceModule, char* importModule);
IMAGE_THUNK_DATA32* GetImportsList(char* importModule);
DWORD* GetFunctionsList(char* sourceModule, char* importModule);
DWORD* GetFunctionsList(char* importModule);
bool PatchImport(char* sourceModule, char* importModule, LPCSTR function, void* patchFunction);
bool PatchImport(char* importModule, LPCSTR function, void* patchFunction);
FARPROC GetImport(char* importModule, LPCSTR function);

// Memory
void WriteNops(void* dest, u32 size);
void WriteNops(u32 dest, u32 size);
void WriteMem(void* dest, void* source, u32 size);
void WriteMem(u32 dest, void* source, u32 size);
void JmpPatch(void* dest, void* patch);
void JmpPatch(u32 dest, void* patch);
void CallPatch(void* dest, void* patch);
void CallPatch(u32 dest, void* patch);
void Revert();
void WriteMemRaw(void* dest, void* source, u32 size);
void WriteMemRaw(u32 dest, void* source, u32 size);
