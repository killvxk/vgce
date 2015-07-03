Incomplete. Work in progress.

```
Compressed block format:
{
    u32     modified crc32 checksum of the uncompressed data
    u32     #Segments
    {
        u32                    compressedSize
        u8 * CompressedSize    data
    }
}

String data until 0x1A

block_isCompressed       { 0,   1,   1,     1, 0, 0, 1, 0, 1,    0,    0, 0, 1, 0, 1, 0, 1,    1, 0, 1, 0,  0, 0, 1,     1, 0, 0, 0, 1, 0, 1,     1,    1,  1,  1,      1,      1,      1, 0, 1,    1, 0, 1,   1, 0, 1, 1,     1, 1,     1,  1,     1,     1,     1,  1,     1,    1, 1,     1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1, 0, 0 }
block_uncompressedSize   { 4, 181, 432, 96000, 4, 2, v, 2, v, 1024, 1024, 2, v, 2, v, 2, v, 1700, 4, v, 4, 48, 2, v, 40000, 4, 4, 4, v, 4, v, 20480, 4096, 40, 20, 131072, 131072, 262144, 2, v, 1280, 4, v, 384, 4, v, 4, 20004, v, 32004, 64, 24004, 44004, 46004, 64, 10048, 5204, 8, 12008, 912, 456, 228, 456, 456, 456, 456, 260, 260, 122, 122, 122, 122, 122, 122, 88, 88, 88, 88, 4, 4 }

u32         unk1
cmp         unk2
cmp         pStructs
cmp         oreGasSelections
u32         unk3
u16         cImageCount
cmp         cImages
u16         cSpriteCount
cmp         cSprites
u8[1024]    cSpriteUnk1
u8[1024]    cSpriteUnk2
u16         cThingy1Count
cmp         cThingy1s
u16         cThingy2Count
cmp         cThingy2s
u16         cFlingyCount
cmp         cFlingys
cmp         cUnitUnk1
u32         cUnitCount
cmp         cUnits
u32         cUnitUnk2
u32[12]     cUnitStart
u16         cBulletCount
cmp         cBullets
cmp         unk4
u32         unk4_Val1
u32         unk4_Val2
u32         Unk5
cmp         Unk6
u32         Unk7
cmp         Unk8
cmp         Unk9
cmp         Unk10
cmp         Unk11
cmp         Unk12
cmp         Unk13
cmp         Unk14
cmp         Unk15
u16         victoryCount
cmp         victorys
cmp         victoryUnk
u32         unk16
cmp         unk17
cmp         unk18
u32         unk19
cmp         unk20
cmp         unk21
cmp         unk22
cmp         unk23
cmp         unk24
cmp         unk25
cmp         unk26
cmp         unk27
cmp         unk28
cmp         unk29
cmp         unk30
cmp         unk31
cmp         unk32
cmp         unk33
cmp         unk34
cmp         unk35
cmp         unk36
cmp         unk37
cmp         unk38
cmp         unk39
cmp         unk40
cmp         unk41
cmp         unk42
cmp         unk43
cmp         unk44
cmp         unk45
cmp         unk46
cmp         unk47
cmp         unk48
cmp         unk49
cmp         unk50
cmp         unk51
cmp         unk52
u32         screenX
u32         screenY
```