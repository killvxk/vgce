# Format #
```
u8          isBroodwar;
u32         frameCount;
u8          unk1;
u8          unk2;
u8          unk3;
u32         dateCreated;
u8[12]      slotsAvailable;
char[28]    gameName;
u16         mapWidth;
u16         mapHeight;
u8          isBroodwar2;
u8          availableSlots;
u16         gameSpeed;
u16         gameType;
u16         gameSubtype;
u32         randSeed;
u16         tileset;
u16         unk4;
char[25]    creatorName;
char[32]    mapName;
u16         GameTemplate_gameType;
u16         GameTemplate_subType;
u16         GameTemplate_subTypeDisplay;
u16         GameTemplate_subTypeLabel;
u8          GameTemplate_victoryConditions
                {
                    0x00 = "Map Default",
                    0x01 = "Melee",
                    0x02 = "Highest Score",
                    0x03 = "Resources",
                    0x04 = "CTF",
                    0x05 = "Sudden Death",
                    0x06 = "Slaughter",
                    0x07 = "One on One"
                };
u8          GameTemplate_resourceType
                {
                    0x00 = "Map Default",
                    0x01 = "Fixed Value",
                    0x02 = "Low",
                    0x03 = "Medium",
                    0x04 = "High",
                    0x05 = "Income"
                };
u8          GameTemplate_useStandardUnitStats;
u8          GameTemplate_fogOfWarUnused;
u8          GameTemplate_startingUnits
                {
                    0x00 = "Map Default",
                    0x01 = "Workers Only",
                    0x02 = "Workers and Center"
                };
u8          GameTemplate_useFixedPositions;
u8          GameTemplate_restrictionFlags
                {
                    0x01 = "Allow Computer Players",
                    0x02 = "Allow Single Player"
                };
u8          GameTemplate_alliesAllowed;
u8          GameTemplate_teams;
u8          GameTemplate_cheats;
u8          GameTemplate_tournamentMode;
u32         GameTemplate_victoryConditionValue;
u32         GameTemplate_resourcesValue;
u32         GameTemplate_unused;
u8          extraUnused;

pStruct
{
    u32         playerID;
    u32         playerFlags;
    u8          playerOwner;
    u8          playerRace;
    u8          playerForce;
    char[25]    playerName;
}[12];

u32[8]  playerColour;
u8[8]   useCustomColour;
```