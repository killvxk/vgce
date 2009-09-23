BOOL __stdcall CHK_VCOD(void *sectionData, int size, int unused)
{
  HRSRC hVCOD; // eax@1
  HRSRC hVCOD_0; // esi@1
  HGLOBAL VCOD_Loaded; // eax@2
  int VCOD_Size; // ebx@2
  int sizeof_VCOD; // edi@5
  void *hCHKData; // eax@6
  void *hCHKData_0; // esi@6
  signed int hChkData; // eax@7
  void *VCOD_Locked; // eax@3
  int Hash; // edi@10
  LPVOID VCOD_Locked_0; // [sp+8h] [bp-4h]@3

  hVCOD = FindResourceA(0, (LPCSTR)202, "VCOD");
  hVCOD_0 = hVCOD;
  if ( !hVCOD
    || (VCOD_Size = SizeofResource(0, hVCOD), VCOD_Loaded = LoadResource(0, hVCOD_0), !VCOD_Loaded)
    || (VCOD_Locked = LockResource(VCOD_Loaded), VCOD_Locked_0 = VCOD_Locked, !VCOD_Locked) )
    return 0;
  sizeof_VCOD = size;
  if ( size != VCOD_Size
    || (hCHKData = SMemAlloc(size, "Starcraft\\SWAR\\lang\\maphdr.cpp", 1171, 0), hCHKData_0 = hCHKData, !hCHKData) )
    return 0;
  hChkData = CopySectionData(sectionData, hCHKData);
  if ( !hChkData )
  {
    SMemFree(hCHKData_0, "Starcraft\\SWAR\\lang\\maphdr.cpp", 1174, hChkData);
    return 0;
  }
  size = CHK_PerformVCODcheck(sizeof_VCOD, hCHKData_0, 432, &playerStructs_0);// Size is now the hash here
  Hash = CHK_PerformVCODcheck(sizeof_VCOD, VCOD_Locked_0, 432, &playerStructs_0);
  SMemFree(hCHKData_0, "Starcraft\\SWAR\\lang\\maphdr.cpp", 1182, 0);
  return Hash == size;
}

DWORD __userpurge CHK_PerformVCODcheck<eax>(void *hVCOD<ebx>, int datasize<ecx>, void *datalocation<edx>, int vcodSize)
{
  DWORD result; // eax@1
  unsigned int currentData; // edx@3
  int vcod_opcode; // esi@3
  int v7; // ecx@9
  unsigned __int32 v8; // edi@12
  unsigned __int32 v9; // esi@12
  unsigned __int32 v10; // esi@12
  int v11; // eax@12
  unsigned __int32 v12; // esi@13
  int v13; // eax@13
  unsigned __int8 v14; // of@15
  char v15; // sf@15
  char v16; // zf@16
  void *datalocation_0; // [sp+Ch] [bp-8h]@1
  unsigned int v18; // [sp+0h] [bp-14h]@2
  unsigned int currentData_0; // [sp+10h] [bp-4h]@3
  char *v20; // [sp+8h] [bp-Ch]@3
  signed int v21; // [sp+4h] [bp-10h]@4

  result = 0;
  datalocation_0 = datalocation;
  if ( (unsigned int)datasize >= 4 )
  {
    v18 = (unsigned int)datasize >> 2;
    do
    {
      currentData = *(_DWORD *)datalocation_0;
      vcod_opcode = (int)((char *)hVCOD + 1024);
      currentData_0 = *(_DWORD *)datalocation_0;
      v20 = (char *)hVCOD + 1024;
      if ( vcodSize > 1024 )
      {
        v21 = 1024;
        do
        {
          switch ( *(_BYTE *)vcod_opcode )
          {
            case 0:
              result ^= currentData;
              break;
            case 1:
              result += currentData;
              break;
            case 2:
              result -= currentData;
              break;
            case 3:
              v7 = (unsigned __int8)(currentData_0 >> 16);
              goto LABEL_11;
            case 4:
            case 5:
              v7 = BYTE2(currentData_0);
LABEL_11:
              result ^= *((_DWORD *)hVCOD + (_BYTE)currentData) ^ *((_DWORD *)hVCOD + (currentData >> 24)) ^ *((_DWORD *)hVCOD + BYTE1(currentData)) ^ *((_DWORD *)hVCOD + v7);
              break;
            case 6:
              v10 = (((((result << (currentData & 0x1F)) | (result >> (char)(32 - (currentData & 0x1F)))) << (BYTE1(currentData) & 0x1F)) | (((result << (currentData & 0x1F)) | (result >> (char)(32 - (currentData & 0x1F)))) >> (char)(32 - ((currentData >> 8) & 0x1F)))) << ((currentData >> 16) & 0x1F)) | (((((result << (currentData & 0x1F)) | (result >> (char)(32 - (currentData & 0x1F)))) << (BYTE1(currentData) & 0x1F)) | (((result << (currentData & 0x1F)) | (result >> (char)(32 - (currentData & 0x1F)))) >> (char)(32 - ((currentData >> 8) & 0x1F)))) >> (char)(32 - ((currentData >> 16) & 0x1F)));
              v11 = (currentData >> 24) & 0x1F;
              v8 = v10 >> (32 - v11);
              v9 = v10 << v11;
              goto LABEL_14;
            case 7:
              v12 = (((((result >> (char)(currentData & 0x1F)) | (result << (char)(32 - (currentData & 0x1F)))) >> (BYTE1(currentData) & 0x1F)) | (((result >> (char)(currentData & 0x1F)) | (result << (char)(32 - (currentData & 0x1F)))) << (char)(32 - ((currentData >> 8) & 0x1F)))) >> (char)((currentData >> 16) & 0x1F)) | (((((result >> (char)(currentData & 0x1F)) | (result << (char)(32 - (currentData & 0x1F)))) >> (BYTE1(currentData) & 0x1F)) | (((result >> (char)(currentData & 0x1F)) | (result << (char)(32 - (currentData & 0x1F)))) << (char)(32 - ((currentData >> 8) & 0x1F)))) << (char)(32 - ((currentData >> 16) & 0x1F)));
              v13 = (currentData >> 24) & 0x1F;
              v8 = v12 << (32 - v13);
              v9 = v12 >> v13;
LABEL_14:
              result = v9 | v8;
              break;
            default:
              break;
          }
          vcod_opcode = (int)(v20 + 1);
          v14 = __SETO__(v21 + 1, vcodSize);
          v15 = v21 + 1 < vcodSize;
          ++v20;
          ++v21;
        }
        while ( v15 ^ v14 );
      }
      v16 = v18 == 1;
      datalocation_0 = (char *)datalocation_0 + 4;
      --v18;
    }
    while ( !v16 );
  }
  return result;
}
