# Table of Contents #


Note: Space between content head and format start still needs to be described properly.


---

# Content Header #


## Header Format ##
Saved content header;
Header Size: 0x20 (32 bytes)
Header Extension Size: 0x34 (52 bytes)

Saved content must be decrypted using a special Brawl key for the first portion of the header, and the SD key for the remaining portion of the file.
```
0x00 (8)		//Wii ID - Same as "Wii Number" in Address Book (not necessary)
0x08 (8)		//Wii System Date/Time (not necessary)
0x10 (4)	!	//Checksum
0x14 (1)		//Region
	0x00 = "JAP";
	0x21 = "USA";
	0x44 = "EUR";
0x15 (1) 	!	//Content Type
	0x01 = "Snapshot";
	0x02 = "Replay";
	0x03 = "Stage";
0x16 (1)		//Save Type
	0x00 // Standard;
	0x01 // Unknown;
	0x02 // Official Download;
	0x03 // Savesample;
0x17 (1)	!	// Must be 0xDB (possibly to do with checksum; DB stand for DeadBeef)
0x18 (4)	!	//Uncompressed Size
0x1C (4)	!	//Current Size
```
! = Required Fields; Others can all be 0x00, other values untested.

The header extension is significant only in custom stages, as it contains the description.

```
0x00 (4)	// Unknown
0x04 (4)	// Unknown
0x0A ()		// Stage Description (Maximum of 20 characters. Unicode 16-bit formatting. Can be null terminated.)
0x32 (2)	// Padding
```

Data follows directly After


## File Names ##

  * Default file name for content is "xx\_yymmdd\_hhmm.bin".
  * Tests show that the file can be named anything, as long as it is named `xx_<name>.bin`
  * File name can be a maximum of 64 characters.
  * Characters must be valid, range is 0x20 to 0x7F. (32 to 127). Reason to believe that each character is read as a signed 8-bit integer. Characters less than 0x20 may be possible, but not using Windows Exploder.


## Compression ##

  * If uncompressed size is not equal to current size, the data is compressed, otherwise it is uncompressed.
  * If the data is compressed; It was have a common LZ format header. If it has been uncompressed, delete that header completely.

## Checksum Calculation ##

  1. Replace the checksum field with 0xDEADBEEF
  1. Calculate the file's checksum using crc32 from position 0x00 to (current size + 32)
  1. Replace the checksum field with the new checksum.


## Alignment ##

  * Before re-encrypting the file, append any bytes until the file is aligned to 0x10.

## Editing ##

  * Be sure to delete the LZ 4-byte header after decompression.


---

# Screenshot #

## Screenshot Format ##
```
0x00	u32	// Widescreen Flag (Set if screenshot was taken in widescreen mode)
0x04	u32	// Size of JPEG Data
0x08	*	// JPEG Data
```


---

# Replay #

## Replay Format ##
```
0x00    char("PR05")
0x04    u32      // Unknown
0x08    u16      // Unknown (2)
0x0A    u16      // Unknown (2)
0x0C    u32      // Unused (RAM Pointer)
0x10    u32      // Size of Action Data
0x14    u32      // Unknown(additional size?)
0x18             // Unknown (0xFF 01 00 00; 00 00 00 00)
0x1C             // Unknown
0x20    flags[4] // Match Rules (4)
	0x04000000 // Match is a Tournament/Single Event/Practice
	0x08000000 // Match is a Single Event/Multi-Man
	0x10000000 // Single Player Match (Classic/Event/Practice)
	0x20000000 // Stadium/Practice Game

	0x00010000 // Timer counts up
	0x00020000 // Score Match?
	0x00040000 // BTT/Adventure
	0x00080000 // Single Player
	0x00100000 // Unknown(Always checked?)
	0x00200000 // Stock Match?
	0x00400000 // Coin Match

	0x00000100 // Team Attack
	0x00000200 // Timer counts up
	0x00001000 // HRC
	0x00008000 // Match is Timed

	0x00000002 // Hide the damage gauge
	0x00000004 // Adventure
	0x00000008 // Allow pausing
	0x00000020 // HP-based Match

0x24    flags[4] //More Match Rules (4)
	0x01000000 // Match is BTT
	0x08000000 // Fixed Camera
	0x10000000 // Angled Camera
	0x80000000 // Dont use score

	0x00200000 // Players???

	0x00002000 // Difficulty (3 bits)
	0x00001000 // Difficulty (3 bits)
	0x00000800 // Difficulty (3 bits)

0x28    u32      // Unknown (Event match use) (00000001 = practice)
0x2C    u8       // Stadium Type (1)
	00 // HRC;
	03 // BTT;
	05 // 10-Man;
	06 // 100-man;
	07 // 3-Minute;
	08 // 15-Minute;
	09 // Endless;
	0A // Cruel;
0x2D    u8       // Unknown 
0x2E    u8       // Item Rate
	0 = "None";
	1 = "Low";
	2 = "Med";
	3 = "High";
0x2F    u8       // Unknown (Always 0xFF??)
0x30    u24      // Unknown (??)
0x33    u8       // Stage ID (1)
0x34    u8       // Stage Sub-ID [Difficulty] (1)
0x35    u24      // Unknown
0x38    u32      // Match Time (4) [0 for infinite]
0x3C    u32      // Unknown
0x40    u32      // Unknown
0x44    u32      // Unknown
0x48    flags[8] // Item Switches (8)
	0x00080000 00000000 // Cds, Trophies, Stickers
	0x00040000 00000000 // Cds, Trophies, Stickers
	0x00020000 00000000 // Cds, Trophies, Stickers
	0x00010000 00000000 // Screw Attack
	0x00008000 00000000 // Franklin Badge
	0x00004000 00000000 // Team Healer (Only in team games)
	0x00002000 00000000 // Soccer Ball
	0x00001000 00000000 // Unira
	0x00000800 00000000 // Spring
	0x00000400 00000000 // Bumper
	0x00000200 00000000 // Banana Peel
	0x00000100 00000000 // Green Shell
	0x00000080 00000000 // Mr. Saturn
	0x00000040 00000000 // Hothead
	0x00000020 00000000 // Pitfall
	0x00000010 00000000 // Smoke Ball
	0x00000008 00000000 // Freezie
	0x00000004 00000000 // Deku Nut
	0x00000002 00000000 // Smart Bomb
	0x00000001 00000000 // Gooey Bomb
	0x00000000 80000000 // Motion Sensor Bomb
	0x00000000 40000000 // Bob-Omb
	0x00000000 20000000 // Cracker Launcher
	0x00000000 10000000 // Fire Flower
	0x00000000 08000000 // Ray Gun
	0x00000000 04000000 // Super Scope
	0x00000000 02000000 // Golden Hammer
	0x00000000 01000000 // Hammer
	0x00000000 00800000 // Star Rod
	0x00000000 00400000 // Lips Stick
	0x00000000 00200000 // Fan
	0x00000000 00100000 // Home-Run Bat
	0x00000000 00080000 // Beam Sword
	0x00000000 00040000 // Lightning
	0x00000000 00020000 // Timer
	0x00000000 00010000 // Superspice Curry
	0x00000000 00008000 // Bunny Hood
	0x00000000 00004000 // Metal Box
	0x00000000 00002000 // Starman
	0x00000000 00001000 // Warp Star
	0x00000000 00000800 // Poison Mushroom
	0x00000000 00000400 // Super Mushroom
	0x00000000 00000200 // Dragoon Parts
	0x00000000 00000100 // Heart Container
	0x00000000 00000080 // Maximum Tomato
	0x00000000 00000040 // Food
	0x00000000 00000020 // Sandbag
	0x00000000 00000010 // Blast Box
	0x00000000 00000008 // Containers
	0x00000000 00000004 // Pokeball
	0x00000000 00000002 // Assist Trophy
	0x00000000 00000001 // Smash Ball

0x50    flags[4] // Pokemon Switches (4)
	0x20000000 // Bonsly
	0x10000000 // Suicune
	0x08000000 // Wobuffet
	0x04000000 // Gardevoir
	0x02000000 // Goldeen
	0x01000000 // Togepi
	0x00800000 // Piplup
	0x00400000 // Meowth
	0x00200000 // Mew
	0x00100000 // Metagross
	0x00080000 // Electrode
	0x00040000 // Weavile
	0x00020000 // Manaphy
	0x00010000 // Lugia
	0x00008000 // Latias/Latios
	0x00004000 // Kyogre
	0x00002000 // Bellossom
	0x00001000 // Snorlax
	0x00000800 // Jirachi
	0x00000400 // Ho-Oh
	0x00000200 // Staryu
	0x00000100 // Gulpin
	0x00000080 // Groudon
	0x00000040 // Deoxys
	0x00000020 // Munchlax
	0x00000010 // Moltres
	0x00000008 // Entei
	0x00000004 // Chickorita
	0x00000002 // Cerebi
	0x00000001 // Torchic

0x54    flags[4] // Assist Trophy Switches (4)
	0x04000000 // Dr. Wright
	0x02000000 // Waluigi
	0x01000000 // Tingle
	0x00800000 // Infantry+Tanks
	0x00400000 // Stafy
	0x00200000 // Shadow the Hedgehog
	0x00100000 // Saki Amamiya
	0x00080000 // Isaac
	0x00040000 // Mr. Resetti
	0x00020000 // Nintendog
	0x00010000 // Metroid
	0x00008000 // Little Mac
	0x00004000 // Lyn
	0x00002000 // Jill & Drill Dozer
	0x00001000 // Kat & Ana
	0x00000800 // Helirin
	0x00000400 // Hammer Bro.
	0x00000200 // Knuckle Joe
	0x00000100 // Lakitu
	0x00000080 // Jeff
	0x00000040 // Excitebike
	0x00000020 // Devil
	0x00000010 // Samurai Goroh
	0x00000008 // Ray MKII (Custom Robo)
	0x00000004 // Gray Fox
	0x00000002 // Barbara
	0x00000001 // Andross

0x58    flags[4] // Random Stage Switches (Brawl) [Section is completely Unused] (4)
0x5C    flags[4] // Random Stage Switches (Melee) [Section is completely Unused] (4)
0x60    float    // Unknown (Float)
0x64    float    // Global Damage Ratio
0x68    float    // Global Speed Ratio
0x6C    float    // Random Seed ?
0x70    u32      // Unknown (01 00 00 00)
0x74    u16      // Music Type/Category?
0x76    u16      // Music ID (2)
0x78    u32      // Unknown (Float?Flags?)
	// Unknown

0xB0    // Character 1 (92) >----+
0x10C   // Character 2 (92) >---|
0x168   // Character 3 (92) >---|
0x1C4   // Character 4 (92) >---|
0x220   // Character 5 (92) >---|
0x27C   // Character 6 (92) >---|
0x2D8   // Character 7 (92) >---+-------------------+
0x334   u32      // Unknown			    |
0x338   u32      // Unknown			    |
0x33C   u16      // Pointer to Stage Data (2)	    |
0x33E   u16      // Size of Stage Data (2)	    |
0x340   u32      // Pointer to Action data (4)	    |
0x344   u32      // Size of Action data (4)	    |
0x348   u16      // # of actions (2)		    |
	// Unknown				    |
0x37F  // Last byte for this section		    |
//						    |
//						    |
//  +-----------------------------------------------+
//  |
//  +--> Character Structure (92 bytes[0x5C]):
		+0x00    u8         // Character ID
		+0x01    u8         // Character Controller
				0x00 = "Human";
				0x01 = "CPU";
				0x03 = "Unused";
		+0x02    u8         // Character spawn point ? player #
		+0x03    u8         // Character spawn point ? player #
		+0x04    u8         // Stock (FF = infinite)
		+0x05    u8         // Colour (0x0C for special)
		+0x06    u8         // Portrait
		+0x07    u8         // Unknown (01)
		+0x08    u8         // Character spawn point ? player #
		+0x09    u8         // Unknown
		+0x0A    u8         // Overlay (04=dark)
		+0x0B    u8         // Team
		+0x0C    char[2][6] // Character Name (16-bit unicode; null terminated; 6 characters max)
		+0x18    flags[2]   // Some Flags (2)
			0x4000 // Always checked
			0x2000 // Always checked
			0x1000 // Always checked
			0x0800 // Always checked

			0x0040 // Always checked (multi)
			0x0020 // Always checked (multi)
			0x0010 // Always checked (multi)
			0x0008 // Always checked (multi)

		+0x1A   u8          // Unknown
		+0x1B	flags[2]
			0x8000 // Fighting Alloy
			0x4000 // Rumble on
			0x2000 // Unknown
			0x1000 // Is Metal
			0x0800 // Unknown
			0x0400 // Is Clear
			0x0200 // Unknown
			0x0100 // Unknown
			0x0080 // HP enabled
			0x0040 // Unknown
			0x0020 // Character is named
			0x0010 // Unknown (Always checked)
			0x0008 // Has Bunny Hood
			0x0004 // Has Flower (Lips Stick)
			0x0002 // Has Superspice Curry
			0x0001 // Has Franklin Badge

		+0x1D    u8         // Unknown
		+0x1E    u8         // CPU AI
			00 = "None";
			01 = "Stand";
			02 = "Walk";
			03 = "Jump";
			04 = "Run";
			05 = "Event" // (inf final smash run);
			07 = "Event" // (visitor to Flatzone);
			0E = "Attack";
			19 = "Control";
		+0x1F    u8         // CPU Level (%)
		+0x20    u32        // Damage (%) (4)
		+0x24    u16        // HP (2)
		+0x26    u16        //  (Adventure)
		+0x28    u16        //  (Adventure)
		+0x2A    u16        //  (Adventure)
		+0x2C    u16        //  (Adventure)
		+0x2E    u16        //  (Adventure)
		+0x30    float      // Damage Receive/Stun Ratio (float)
		+0x34    float      // Attack Ratio (4)
		+0x38    float      // Defence Ratio (4)
		+0x3C    u8         // Unknown Character Flags???
		+0x3D    u8         // Unknown Character Flags???
		+0x3E    u8         // Unknown Character Flags???
		+0x3F    u8         // Character spawn point ? player #
		+0x40    float      // Size Ratio (4)
		+0x44    float      // Unknown (float)
		+0x48    float      // Weight Ratio (4)
		+0x4C    float      // Unknown
		+0x50    float      // Unknown
		+0x54    float      // Unknown (float)
		+0x58    float      // Unknown
```

## Action Data ##

### Action Header ###
1-byte Header (flags)
  * 0x01 = Player 1
  * 0x02 = Player 2
  * 0x04 = Player 3
  * 0x08 = Player 4
  * 0x10 = Unknown (+4)
  * 0x20 = Unknown (+8)
  * 0x40 = Unknown/Unused
  * 0x80 = Unknown

Then there are 4 bytes allocated for each player specified in the header.

### Byte 1 ###
```
	0x01 // ATTACK
	0x02 // Unknown
	0x04 // D-Pad UP
	0x08 // D-Pad Right/Left
	0x10 // D-Pad Down
	0x20 // D-Pad Left
	0x40 // D-Pad Right
	0x80 // Unknown 
```

### Byte 2 ###
```
	0x01 = "ATTACK";
	0x02 = "SPECIAL";
	0x04 = "JUMP";
	0x08 = "SHIELD";
	0x10 // Unknown
	0x20 = "SMASH"; // (C-Stick used)
	0x40 // Alternate 1
	0x80 // Alternate 2
```

### Byte 3 ###
> X-Movement (signed %)


### Byte 4 ###
> Y-Movement (signed %)




---

# Custom Stage #

## Custom Stage Format ##

Format excludes saved content header.

```
0x00    char("ED01")
0x04    u32         // Section Size
0x08    u32         // Pointer to JPEG data (relative to section start)
0x0C    u32         // Size of JPEG data
0x10    u32         // Unknown/Unused
0x14    u8          // Stage Style
			00 = "Nature";
			01 = "Factory";
			02 = "Remains";
0x15    u8          // Stage Size
			00 = "Small";  // (10 block width)
			01 = "Medium"; // (14 block width)
			02 = "Large"   // (18 block width)
0x16    u8          // Number of Blocks contained (1)
0x17    u8          // Preview aspect Ratio
			00 = "4:3";
			01 = "16:9";
0x18    u16         // Music ID (2)
0x1A    u16         // Unknown (2)
0x1C    char[2][16] // Stage name (Maximum of 16 characters. Unicode 16-bit formatting. Can be null terminated.)
0x3C    u32         // Unknown (4)
0x40    float       // Start p1 X (float)
0x44    float       // Start p1 Y (float)
0x48    float       // Start p2 X (float)
0x4C    float       // Start p2 Y (float)
0x50    float       // Start p3 X (float)
0x54    float       // Start p3 Y (float)
0x58    float       // Start p4 X (float)
0x5C    float       // Start p4 Y (float)
0x60    float       // Start p5 X (float)
0x64    float       // Start p5 Y (float)
0x68    float       // Start p6 X (float)
0x6C    float       // Start p6 Y (float)
0x70    float       // Start p7 X (float)
0x74    float       // Start p7 Y (float)
0x78    float       // Unknown
0x7C    float       // Unknown
0x80    *           // Blocks
```

## Block Format ##
### Block Byte 1 ###
**Tile position** (no X/Y, just position as if a single dimension ex: if the width is 12 and you want to place it in the second row, then this byte is 0x12(18 dec), since it is read always as an internal width of 18)
```
	X = byte % 18, Y = byte / 18  //(Always 18 on all stage sizes)
```

### Bytes 2, 3, 4 ###
```
	11100000 00000000 00000000	// Size X (u3)
	00011100 00000000 00000000	// Size Y (u3)
	00000011 10000000 00000000	// Smallest X (u3)
	00000000 01110000 00000000	// Smallest Y (u3)
	00000000 00001100 00000000	// Tile group (u2)
		0x00 = "Basic";
		0x01 = "Deco"; // Unused
		0x02 = "Fixed";
		0x03 = "Gimmick";
	00000000 00000011 11000000	// Tile ID (u4)
	00000000 00000000 00100000 	// Flipped Flag (u1)
		0 = "Normal";
		1 = "Flipped";
	00000000 00000000 00011000	// Sub-Value (Spring jump height) (u2)
	00000000 00000000 00000111	// Extension (big red field of shit surrounding block) (u3)
		0x00 // None;
		0x02 // +1 to sides+top;
		0x03 // +1 to top+bottom;
		0x05 // +1 to top;
```

## Tile ID ##
### BASIC TILES ###
```
	0x00 // Debug Block ( *_BASIC_00) [unused, invalid piece]
	0x01 // Normal Platform ( *_BASIC_01)
	0x02 // Sloping Platform ( *_BASIC_02)
	0x03 // Tiny Platform ( *_BASIC_03)
	0x04 // Staircase top ( *_BASIC_04) [unused, valid piece]
	0x05 // Square Block ( *_BASIC_05)
	0x06 // Sloping Staircase ( *_BASIC_06)
	0x07 // 45 Degree Slope  ( *_BASIC_07)
	0x08 // *_BASIC_08 [unused]
	0x09 // Horizontally dominent slope ( *_BASIC_09)
	0x0A // *_BASIC_10 [unused]
	0x0B // *_BASIC_11 [unused]
	0x0C // *_BASIC_12 [unused]
	0x0D // *_BASIC_13 [unused]
	0x0E // *_BASIC_14 [unused]
	0x0F // *_BASIC_15 [unused]
```
### FIXED TILES ###
```
	0x00 // *_FIX_00 [unused]
	0x01 // *_FIX_01 [unused]
	0x02 // *_FIX_02 (Factory, Nature, Remains)
	0x03 // *_FIX_03 (Factory, Nature)
	0x04 // *_FIX_04 (Factory, Nature, Remains)
	0x05 // *_FIX_05 (Remains)
	0x06 // *_FIX_06 (Factory, Remains)
	0x07 // *_FIX_07 [unused]
	0x08 // *_FIX_08 (Factory, Nature, Remains)
	0x09 // *_FIX_09 (Factory, Remains)
	0x0A // *_FIX_10 (Nature)
	0x0B // *_FIX_11 (Nature, Remains)
	0x0C // *_FIX_12 (Factory, Nature, Remains)
	0x0D // *_FIX_13 (Factory, Nature)
	0x0E // *_FIX_14 [unused]
	0x0F // *_FIX_15 [unused]
```
### GIMMICK TILES ###
```
	0x00 // GIMMICK_00 [unused]
	0x01 // Vertical Moving Platform (GIMMICK_01)
	0x02 // Horizontal Moving Platform (GIMMICK_02)
	0x03 // Platform Wheel (GIMMICK_03)
	0x04 // Spring (GIMMICK_04)
	0x05 // Ice Block (GIMMICK_05)
	0x06 // Falling Block (GIMMICK_06)
	0x07 // Conveyor Belt (GIMMICK_07)
	0x08 // Spikes (GIMMICK_08)
	0x09 // Ladder (GIMMICK_09)
	0x0A // GIMMICK_10 [unused]
	0x0B // GIMMICK_11 [unused]
	0x0C // GIMMICK_12 [unused]
	0x0D // GIMMICK_13 [unused]
	0x0E // GIMMICK_14 [unused]
	0x0F // GIMMICK_15 [unused]
```

## Moving Platform Analysis ##
> A moving platform's location at the start of the game is related to the position it is placed in the stage builder.

> A vertical moving platform of any size, starting at coordinate 0x00 [(0,0) see block position rules] will start at the center moving downwards(default, not flipped). The next one placed at 0x01 will start in the next "frame" of the animation. It takes 10 blocks to complete one animation cycle. The 10th block, 0x0A, will start over again, in the center moving downwards.

> A horizontal moving platform of any size, starting at coordinate 0x00 will start at the center and move left(not flipped). The next one placed at 0x01 will start in the next "frame" of the animation. It takes 6 blocks to complete one animation cycle. The 6th block, 0x06, will start over again, in the center moving left.

> One animation cycle will take place in the same set time, regardless of size. So larger moving platforms move faster than smaller ones.


## The Stage Builder limit bar ##
> stageConstants provides a limit value for each block and its size. When the limit is reached, the Stage Builder doesn't allow placement of any more blocks. The limit is 8000.


## Actual Part Sizes ##
> The actual sizes of the parts can be determined by the following formulae:
```
	defaultSmallestSize / smallestSize * currentSize = finalSize

	// rsx/rsy = real Smallest Size x/y
	// sx/sy = smallest Size x/y

	rsx/sx*x
	rsy/sy*y
```
> These rules only apply if x OR y is greater than or equal to the respective x/y values for the large size object, otherwise the object will be centered in its x/y, instead of stretching.


## Starting Positions ##
> The starting position X and Y are float values, with 2.0 = 1 block. The value is signed and starts with the exact center of the stage.

> So 0.0 would be the direct center of your stage, and -8.0 would be 4 blocks to the left of the center.


## Preview ##
> The stage preview image is not required. If it is omitted, the stage will appear to have a garbage preview. Any valid JPG can be used as a preview image.