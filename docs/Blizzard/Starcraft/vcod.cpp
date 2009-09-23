DWORD CHK_PerformVCODcheck(void *hVCOD, int datasize, void *datalocation, int vcodSize);
BOOL CHK_VCOD(void *sectionData, int sectionSize, int unused);

#define BYTE1(x, n)   (*((char*)&(x)+1))
#define BYTE2(x, n)   (*((char*)&(x)+2))
#define BYTE3(x, n)   (*((char*)&(x)+3))

struct vcodMain
{
    DWORD data[256] = {0x3419CA77, 0x99DC6871, 0x0A60BFC3, 0xA7E775A7,
                        0x1F297DA6, 0xD7B03ABB, 0xCC3124ED, 0x174C130B,
                        0x6520A2B7, 0x91BD186B, 0x8DC35DDD, 0xE27AD537,
                        0xF65964D4, 0x639A120F, 0x435C2E46, 0xE374F82A,
                        0x086A3706, 0x37F6D63B, 0x0E946316, 0x45675CEC,
                        0xD77BF7B7, 0x1AFCD49E, 0x73FA3F8C, 0x2EC0E10F,
                        0xD1740907, 0x95E364D7, 0x75166874, 0x99A74FDA,
                        0xD520181F, 0xE7E6A0BE, 0xA6B6E31F, 0xCA0CEF70,
                        0x31D51A31, 0x4DB82435, 0xE3F8C77D, 0xE11A58DE,
                        0xF4052743, 0xBAACDB07, 0xDC69BE0A, 0xA88FEC49,
                        0xD758163F, 0xE5DBC18A, 0x41CFC005, 0x9DCA1C72,
                        0xA2B15FA5, 0xC423709B, 0x8404E114, 0x807B90DA,
                        0xFADB6906, 0xA3F30F40, 0xBEF3CED4, 0xE3C9CBD7,
                        0x5A400134, 0xF26814F8, 0x388EC51A, 0xFED63D4B,
                        0x530505FA, 0x3410458E, 0xDD9169FE, 0xAFE0EEF0,
                        0xF3487EDD, 0x9FADDC75, 0x627AACE5, 0x311B6267,
                        0x20CD364D, 0xE0982174, 0xFB097971, 0x3667CD7F,
                        0x775FD63C, 0xA2A2A6C6, 0x1AE3CE6A, 0x4ECDA96C,
                        0x86BA9D3B, 0xB5F476FD, 0xF844F0BC, 0x2EE96E29,
                        0x23252F6B, 0x08AB2744, 0x7A12CC99, 0xEDDCF275,
                        0xC53C387E, 0xF71C1BC5, 0xD12D9465, 0x06C948DD,
                        0xBE322DAC, 0xB5C93281, 0x664AD834, 0x353F15DF,
                        0xB2EEEBB6, 0x04F64D96, 0x3542949C, 0x628AD361,
                        0x52A87B6F, 0xDC61FCF4, 0x6C142DFE, 0x99EAA40A,
                        0xE8D9FE13, 0xD0484459, 0x8066F3E3, 0x34D98D19,
                        0x16D763FE, 0x30187E3A, 0x9B8D0FB1, 0x12F0F58C,
                        0x0A7858DB, 0x3E63B88C, 0x3AAAF38E, 0x378A1A2E,
                        0x5C31F9EF, 0xE36DE37E, 0x9BBD3E13, 0xC644C0B9,
                        0xBC3ADA90, 0xA4ADB074, 0xF8572789, 0x47E63F37,
                        0xE442795A, 0xDF438DEE, 0xB40A49E8, 0x3CC3881A,
                        0x88016B76, 0x8AC3FDA3, 0x167A4E56, 0xA77FCBBA,
                        0x025E1CEC, 0xB0B9C976, 0x1E82B139, 0x3EC957C5,
                        0x1924384C, 0x5D2F54B8, 0x6F5D578E, 0x30A10A52,
                        0x6D18715E, 0x1306C359, 0x1FDC3E62, 0xDCDAB5EB,
                        0x1B9195F9, 0xA791D5DA, 0x3353CE6B, 0xF5007001,
                        0x7FD8EEE8, 0xC00AF1CE, 0x63EBB6D3, 0x78EFCCA5,
                        0xAA5DBCA4, 0x96ABF2D2, 0x61FFEA9A, 0xA86AEDA2,
                        0xBD3EED61, 0x39C18292, 0x163623B1, 0xB0A024E5,
                        0x059BA7AA, 0x0D129B33, 0x839220DA, 0x25B0ECFC,
                        0x24D03823, 0xFC95F274, 0x8073E519, 0x97507D44,
                        0x459344DB, 0xA2AD1D69, 0x4414EEE7, 0x2C7F87FF,
                        0x389E32F1, 0x4DBC29DA, 0x422726FE, 0xC1D22BA9,
                        0xF6427A0E, 0xCBE87CD1, 0x0F5BEC56, 0x69B76131,
                        0xB46DF925, 0x4034796D, 0xFA53A70B, 0xFAA482CE,
                        0xC3454961, 0x0D452C8F, 0x284960F7, 0xF37DC91E,
                        0x0FD089C1, 0x2652F8D3, 0x4D8F3514, 0xBA9D5F0B,
                        0x07A94A00, 0xF722262F, 0x3E67FB1F, 0xA19C11C6,
                        0x694F5D66, 0x58341590, 0x6CE55446, 0xAF5F63D6,
                        0x8A0C95DF, 0xBD0DE4AF, 0xBF40404C, 0xA3F65171,
                        0x29ED26F8, 0x852822D5, 0xBFBECFFA, 0x28C57F51,
                        0xB8066307, 0xECBD8F29, 0xFA557E71, 0x1A403266,
                        0xE8D4DE9D, 0xD45EFC93, 0x7A3DD53B, 0xCD752E80,
                        0x0A4F7487, 0x1BCC8FEA, 0x9AA9DB7C, 0x1653E5EF,
                        0xAB78C16E, 0xA472895A, 0x982C7050, 0xFBA1DF1F,
                        0x6BB7D944, 0x07808256, 0xFDBFC083, 0x0E49D05B,
                        0x1E686A0E, 0x9AC20B2F, 0x8E43A0E1, 0x990CF6B2,
                        0xE07A1C5E, 0x2CC8A045, 0x3C0BE988, 0xACB996C6,
                        0x74AE832A, 0xBB13FA65, 0xEB4F1FA6, 0xB08A8AE1,
                        0x81E9B8B9, 0xD555154E, 0x45F2AD9B, 0x3EC2357E,
                        0x5F922E72, 0xB65B6823, 0x6EC6450E, 0xE93B87D4,
                        0xF441C0E3, 0xA80544BE, 0xE40F8A13, 0x1AC437F4,
                        0x5A4055EF, 0x9D791D4B, 0x4A793A9C, 0x768537CC,
                        0x823D0FB6, 0x60A6937E, 0xBD5CC2C4, 0x72C77F90,
                        0x4D1B9610, 0x13056868, 0x35C07BFF, 0x4685432A };
    char opcode[16] = {01, 04, 05, 06, 02, 01, 05, 02, 00, 03, 07, 07, 05, 04, 06, 03 };
} rscVCOD;

struct playerStruct
{
    unsigned int id = 0;
    unsigned int actions = 0;
    unsigned __int8 owner;
    unsigned __int8 race;
    unsigned __int8 force;
    char name[25];
} pStructs[12];

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