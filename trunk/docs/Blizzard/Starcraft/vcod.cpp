DWORD CHK_PerformVCODcheck(void *hVCOD, int datasize, void *datalocation, int vcodSize);
BOOL CHK_VCOD(void *sectionData, int sectionSize, int unused);

#define BYTE1(x, n)   (*((_BYTE*)&(x)+1))
#define BYTE2(x, n)   (*((_BYTE*)&(x)+2))
#define BYTE3(x, n)   (*((_BYTE*)&(x)+3))


BOOL CHK_VCOD(void *sectionData, int sectionSize, int unused)
{
  HRSRC hVCOD = FindResourceA(0, (LPCSTR)202, "VCOD");
  if (!hVCOD)
    return 0;
    
  HGLOBAL VCOD_Loaded = LoadResource(0, hVCOD)
  if (!VCOD_Loaded)
    return 0;
    
  void *VCOD_Locked = LockResource(VCOD_Loaded)
  if (!VCOD_Locked)
    return 0;
  
  int VCOD_Size = SizeofResource(0, hVCOD)
  if (sectionSize != VCOD_Size)
    return 0;
    
  void *hCHKData = SMemAlloc(sectionSize, "Starcraft\\SWAR\\lang\\maphdr.cpp", 1171, 0)
  if (!hCHKData)
    return 0;
  
  if (!CopySectionData(sectionData, hCHKData))
  {
    SMemFree(hCHKData, "Starcraft\\SWAR\\lang\\maphdr.cpp", 1174, 0);
    return 0;
  }
  
  DWORD Hash_Chk  = CHK_PerformVCODcheck(sectionSize, hCHKData, 432, &playerStructs);
  DWORD Hash_VCOD = CHK_PerformVCODcheck(sectionSize, VCOD_Locked, 432, &playerStructs);
  
  SMemFree(hCHKData, "Starcraft\\SWAR\\lang\\maphdr.cpp", 1182, 0);
  return Hash_VCOD == Hash_Chk;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DWORD CHK_PerformVCODcheck(int vcodSize, DWORD *hVCOD, int datasize, DWORD *datalocation)
{
  DWORD result = 0;
  if ( (unsigned int)datasize >= 4 )
    for (int i = datasize / 4; i > 0; i--)
      if ( vcodSize > 1024 )
        for (char *vcod_opcode = (char*)hVCOD + 1024; vcod_opcode < (char*)hVCOD + vcodSize; ++vcod_opcode)
        {
          /* datalocation[i] is the current data in the loop.
             All playerstruct data except for owner, race, and force are 0.
          */
          char altData1 = datalocation[i] & 0x1F;           // owner
          char altData2 = BYTE1(datalocation[i]) & 0x1F;    // race
          char altData3 = BYTE2(datalocation[i]) & 0x1F;    // force
          char altData4 = BYTE3(datalocation[i]) & 0x1F;
          char N_altData1 = 32 - altData1;                  // owner
          char N_altData2 = 32 - altData2;                  // race
          char N_altData3 = 32 - altData3;                  // force
          char N_altData4 = 32 - altData4;
          switch (*vcod_opcode)
          {
            case 0:
              result ^= datalocation[i];
              break;
            case 1:
              result += datalocation[i];
              break;
            case 2:
              result -= datalocation[i];
              break;
            case 3:
            case 4:
            case 5:
              result ^= hVCOD[(char)datalocation[i]] ^ hVCOD[BYTE3(datalocation[i])] ^ hVCOD[BYTE1(datalocation[i])] ^ hVCOD[BYTE2(datalocation[i])];
              break;
            case 6:
              int v1 = result << altData1;
              int v2 = v1 | (result >> N_altData1);
              int v3 = (((v2 << altData2) | (v2 >> N_altData2)) << altData3)  |  (((v2 << altData2) | (v2 >> N_altData2)) >> N_altData3);
              result = (v3 << altData4) | (v3 >> N_altData4);
              break;
            case 7:
              int v1 = result >> altData1;
              int v2 = v1 | (result << N_altData1);
              int v3 = (((v2 >> altData2) | (v2 << N_altData2)) >> altData3)  |  (((v2 >> altData2) | (v2 << N_altData2)) << N_altData3);
              result = (v3 >> altData4) | (v3 << N_altData4);
              break;
            default:
              break;
          }
        }
  return result;
}