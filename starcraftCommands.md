# Table of Contents #



# Notes #
This list has been merged due to the similarity between Replay data and Packet data.

The command opcode is not stored in the Command ID of the packet, but rather in the data, where many commands may stack.
Command class 1 opcodes are typically those from ~0x37 to ~0x50.


# Command Opcodes #

---

## 0x5C - New Game Chat ##
```
   u8          playerID
   char[80]    message
```

---

## 0x5B -  Make Game Public ##
```
   No parameters.
```
CLASS 1 ONLY


---

## 0x5A - Merge Dark Archon ##
```
   No parameters.
```
CLASS 2 ONLY


---

0x59 - INVALID

---

## 0x58 - Minimap Ping ##
```
       s16  x
       s16  y
```
CLASS 2 ONLY


---

## 0x57 - Leave Game ##
```
	u8  type
        {
            0x01    = "Quit",
            0x02    = "Defeat",
            0x03    = "Victory",
            0x04    = "unk",        // game ended?
            0x05    = "Draw",
            0x06    = "Drop"
        }
```
CLASS 2 ONLY


---

## 0x56 - Change Replay Speed ##
```
    u8   type
        {
            0x00    = "Play",
            0x01    = "Pause"
        }
    u32  speed
        {
            0x00 = "Slowest",
            0x01 = "Slower",
            0x02 = "Slow",
            0x03 = "Normal",
            0x04 = "Fast",
            0x05 = "Faster",
            0x06 = "Fastest"
        }
    u32  multiplier
```
CLASS 2 ONLY


---

## 0x55 - Set Latency ##
```
    u8  latency
```
CLASS 2 ONLY


---

## 0x54 -  Mission Briefing Start ##
```
    // No Parameters
```
CLASS 1


---

0x53 -  DEFAULT CASE 2 (unknown command) INVALID
CLASS 1


---

0x52 -  DEFAULT CASE (unknown command) INVALID
CLASS 1


---

0x51 - INVALID



---

0x50 - Unknown
```
      // No Parameters.
```
CLASS 1


---

## 0x4F - Map data transfer ##
```
      u16  (packet size [after value])
      u16  (transfer ID)
	
	*ID 0 - Unknown*
		6 bytes
	*ID 1 - File Name*
		unsigned long (file size?)
		unsigned long (file hash?)
		string (file name)
	*ID 2 - Unknown*
	*ID 3 - Unknown*
	*ID 4 - Transfer data*
	      u8   (unknown)
	      unsigned long (file offset ?)
		unsigned short (block size [after value])
		void (..data..)
	*ID 5 - Request data*
	      u8   (unknown)
	      unsigned long (file offset ?)
	*ID 6 - Unknown*
```
INVALID


---

## 0x4E - Boot Player ##
```
      u8	Type
		{
			0x00 = "You have been banned."
			0x01 = "The game creator closed all available slots."
			0x02 = "The game host has left."
			0x03 = "Unable to join game."
			0x04 = "Save game file not found."
			0x05 = "Unable to write scenario file."
			0x06 = "You cannot join this game because it is a different version of Starcraft."
			0x07 = "You are not able to join this game. It was not created with the same CD that spawned your copy of StarCraft."
			0x08 = "Unable to authenticate map."
			0x09 = "You have been booted."			// Default case
		}
```
INVALID
CLASS 1


---

0x4D -  		(unban player?)
```

```
INVALID
CLASS 1


---

## 0x4C - Lobby Chat ##
```
      cstring   message
```
INVALID
CLASS 1


---

## 0x4B - Force Name Transfer ##
```
      // 120 bytes - undefined
```
CLASS 1


---

## 0x4A - Player/Force Data Transfer ##
```
      u16  (Game Speed ?)
      u16  (unknown)
      u16  (unknown)

      u8   (Player 1 Controller) // not accurate?
      u8   (Player 2 Controller)
      u8   (Player 3 Controller)
      u8   (Player 4 Controller)
      u8   (Player 5 Controller)
      u8   (Player 6 Controller)
      u8   (Player 7 Controller)
      u8   (Player 8 Controller)
      u8   (Player 9 Controller)
      u8   (Player 10 Controller)
      u8   (Player 11 Controller)
      u8   (Player 12 Controller)

      u8   (Player 1 Race)
      u8   (Player 2 Race)
      u8   (Player 3 Race)
      u8   (Player 4 Race)
      u8   (Player 5 Race)
      u8   (Player 6 Race)
      u8   (Player 7 Race)
      u8   (Player 8 Race)
      u8   (Player 9 Race)
      u8   (Player 10 Race)
      u8   (Player 11 Race)
      u8   (Player 12 Race)

      u8   (Player 1 Race) // not accurate?
      u8   (Player 2 Race)
      u8   (Player 3 Race)
      u8   (Player 4 Race)
      u8   (Player 5 Race)
      u8   (Player 6 Race)
      u8   (Player 7 Race)
      u8   (Player 8 Race)

      u8   (Player 1 Controller)
      u8   (Player 2 Controller)
      u8   (Player 3 Controller)
      u8   (Player 4 Controller)
      u8   (Player 5 Controller)
      u8   (Player 6 Controller)
      u8   (Player 7 Controller)
      u8   (Player 8 Controller)
      u8   (Player 9 Controller)
      u8   (Player 10 Controller)
      u8   (Player 11 Controller)
      u8   (Player 12 Controller)

      u8   (Player 1 owning Force)
      u8   (Player 2 owning Force)
      u8   (Player 3 owning Force)
      u8   (Player 4 owning Force)
      u8   (Player 5 owning Force)
      u8   (Player 6 owning Force)
      u8   (Player 7 owning Force)
      u8   (Player 8 owning Force)
      u8   (Player 9 owning Force)
      u8   (Player 10 owning Force)
      u8   (Player 11 owning Force)
      u8   (Player 12 owning Force)

```
CLASS 1

---

## 0x49 - Information Request ##
```
      u32   (Information Byte; 6 = File Name, 7 = File Data ??)
```
CLASS 5
CLASS 1


---

0x48 -  Unknown
```
     u32  (Unknown)
     u8   (Unknown [player related])
     u8   (Unknown [player related])
     u8   (Unknown [player related])
     u8   (Unknown [player related])
     u8   (Unknown [player related])
     u8   (Unknown [player related])
     u8   (Unknown [player related])
     u8   (Unknown [player related])
```
INVALID CLASS 2


---

0x47 - INVALID
0x46 - INVALID

---

## 0x45 - Swap Players ##
```
	u8  sourceSlot
	u8  destinationSlot
```
CLASS 1 ONLY


---

## 0x44 -  Slot Change ##
```
        u8  slot
        u8  owner
```
CLASS 1 ONLY


---

0x43 - UNKNOWN
```
	u8  Unknown
```
CLASS 1 ONLY


---

0x42 - UNKNOWN
```
	u8  Unknown
```
CLASS 1 ONLY


---

## 0x41 - Race Change ##
```
	u8  slot
	u8  race
```
CLASS 1 ONLY


---

0x40 - Unknown    // Version
```
     17 bytes (unknown)
```
CLASS 1 ONLY


---

0x3F - Unknown (Confirmation?)
```
	u8   (player ID?)
	u16  (Null)
	u16  (01 00)
	u16  (05 00)
```
CLASS 1 ONLY


---

## 0x3E - Game Slot Modification ##
```
	u8  slot
	u8  playerID
	u8  owner
	u8  race
	u8  force
```
CLASS 1 ONLY


---

## 0x3D - Map Download % ##
```
	s8  percentage
```
CLASS 1 ONLY


---

## 0x3C - Start Game ##
```
     // No parameters.
```
CLASS 1 ONLY


---

0x3B - Unknown (Same as 0x3A)
```
	u8  Unknown
```
CLASS 1 & 2


---

0x3A - Unknown
```
	u8  Unknown
```
CLASS 1 & 2


---

0x39 - Unknown (same as 0x38)
```
   // No parameters.
```
CLASS 2 ONLY


---

0x38 - Unknown
```
   // No parameters.
```
CLASS 2 ONLY


---

== 0x37 - Game Hash == (determines syncronized gameplay, sent every ~0.2 seconds or before any order)
```
   6 bytes - Unknown
```
CLASS 2 ONLY


---

## 0x36 - Stim ##
```
   // No parameters.
```
CLASS 2 ONLY AND REPLAY


---

## 0x35 - Building Morph ##
```
	u16  unitID
```
CLASS 2 ONLY AND REPLAY


---

## 0x34 - Cancel Addon ##
```
   // No parameters.
```
CLASS 2 ONLY AND REPLAY


---

## 0x33 - Cancel Upgrade ##
```
   // No parameters.
```
CLASS 2 ONLY AND REPLAY


---

## 0x32 - Upgrade ##
```
	u8   upgradeID
```
CLASS 2 ONLY AND REPLAY


---

## 0x31 - Cancel Research ##
```
   // No parameters.
```
CLASS 2 ONLY AND REPLAY


---

## 0x30 - Research ##
```
	u8   techID
```
CLASS 2 ONLY AND REPLAY


---

## 0x2F - Lift ##
```
	s16  x      // unused?
	s16  y      // unused?
```
CLASS 2 ONLY AND REPLAY


---

## 0x2E - Cancel Nuke ##
```
   // No parameters.
```
CLASS 2 ONLY AND REPLAY


---

## 0x2D - Unburrow ##
```
	u8   type   // Unknown
```
CLASS 2 ONLY AND REPLAY


---

## 0x2C - Burrow ##
```
	u8   type   // Unknown
```
CLASS 2 ONLY AND REPLAY


---

## 0x2B - Hold Position ##
```
	u8   type
        {
            0x00    = "Instant Order",
            0x01    = "Queued Order"
        }
```
CLASS 2 ONLY AND REPLAY


---

## 0x2A - Merge Archon ##
```
   // No parameters.
```
CLASS 2 ONLY AND REPLAY


---

## 0x29 - Unload ##
```
	u16  unitMemory
```
CLASS 2 ONLY AND REPLAY


---

## 0x28 - Unload All ##
```
	u8  type
        {
            0x00    = "Instant Order",
            0x01    = "Queued Order"
        }
```
CLASS 2 ONLY AND REPLAY


---

## 0x27 - Train Fighter ##
```
   // No parameters.
```
CLASS 2 ONLY AND REPLAY


---

## 0x26 - Siege ##
```
	u8   type   // unknown
```
CLASS 2 ONLY AND REPLAY


---

## 0x25 - Unsiege ##
```
	u8   type   // unknown
```
CLASS 2 ONLY AND REPLAY


---

0x24 -  INVALID

---

## 0x23 - Unit Morph ##
```
	u16  unitID
```
CLASS 2 ONLY AND REPLAY


---

## 0x22 - Decloak ##
```
	u8   type   // unknown
```
CLASS 2 ONLY AND REPLAY


---

## 0x21 - Cloak ##
```
	u8   type   // unknown
```
CLASS 2 ONLY AND REPLAY


---

## 0x20 - Cancel Train ##
```
	u16  unitID
```
CLASS 2 ONLY AND REPLAY


---

## 0x1F - Train ##
```
	u16  unitID
```
CLASS 2 ONLY AND REPLAY


---

## 0x1E - Return Cargo ##
```
	u8   type
        {
            0x00    = "Instant Order",
            0x01    = "Queued Order"
        }
```
CLASS 2 ONLY AND REPLAY


---

## 0x1D - Nothing ##
```
    // No parameters.
```
CLASS 2 ONLY AND REPLAY


---

## 0x1C - Reaver Stop ##
```
     // No parameters
```
CLASS 2 ONLY AND REPLAY


---

## 0x1B - Carrier Stop ##
```
     // No parameters
```
CLASS 2 ONLY AND REPLAY


---

## 0x1A - Stop ##
```
	u8   type
        {
            0x00    = "Instant Order",
            0x01    = "Queued Order"
        }
```
CLASS 2 ONLY AND REPLAY


---

## 0x19 - Cancel Unit Morph ##
```
   // No parameters.
```
CLASS 2 ONLY AND REPLAY


---

## 0x18 - Cancel Construction ##
```
   // No parameters.
```
CLASS 2 ONLY AND REPLAY


---

0x17 - INVALID
0x16 - INVALID

---

## 0x15 - Target Command ##
```
	s16  x
	s16  y
	u16  unitMem
	u16  unitID
	u8   orderID
	u8   type
        {
            0x00    = "Instant Order",
            0x01    = "Queued Order"
        }
```
CLASS 2 ONLY AND REPLAY


---

## 0x14 - Right Click ##
```
	s16  x
	s16  y
	u16  unitMem
	u16  unitID
	u8   type
        {
            0x00    = "Instant Order",
            0x01    = "Queued Order"
        }
```
CLASS 2 ONLY AND REPLAY


---

## 0x13 - Hotkey ##
```
	u8  type
        {
            0x00    = "save",
            0x01    = "recall"
        }
	u8  slot
```
CLASS 2 ONLY AND REPLAY


---

## 0x12 - Use Cheat ##
```
    u32  flags
```
CLASS 2 ONLY AND REPLAY


---

## 0x11 - Resume Game ##
```
    // No parameters.
```
CLASS 2 ONLY AND REPLAY


---

## 0x10 - Pause Game ##
```
    // No parameters.
```
CLASS 2 ONLY AND REPLAY


---

## 0x0F - Change Game Speed ##
```
    u8   speed
    {
        0x00 = "Slowest",
        0x01 = "Slower",
        0x02 = "Slow",
        0x03 = "Normal",
        0x04 = "Fast",
        0x05 = "Faster",
        0x06 = "Fastest"
    }
```
CLASS 2 ONLY AND REPLAY


---

## 0x0E - Ally ##
```
	u2 	(Alliance p1) [0 = enemy, 1= allied, 2 = allied vic]
	u2 	(Alliance p2) [0 = enemy, 1= allied, 2 = allied vic]
	u2 	(Alliance p3) [0 = enemy, 1= allied, 2 = allied vic]
	u2 	(Alliance p4) [0 = enemy, 1= allied, 2 = allied vic]

	u2 	(Alliance p5) [0 = enemy, 1= allied, 2 = allied vic]
	u2 	(Alliance p6) [0 = enemy, 1= allied, 2 = allied vic]
	u2 	(Alliance p7) [0 = enemy, 1= allied, 2 = allied vic]
	u2 	(Alliance p8) [0 = enemy, 1= allied, 2 = allied vic]

	u2 	(Alliance p9) [0 = enemy, 1= allied, 2 = allied vic]
	u2 	(Alliance p10) [0 = enemy, 1= allied, 2 = allied vic]
	u2 	(Alliance p11) [0 = enemy, 1= allied, 2 = allied vic]
	u2 	(Alliance p12) [0 = enemy, 1= allied, 2 = allied vic]

	u8	Unknown/unused
```
CLASS 2 ONLY AND REPLAY


---

## 0x0D - Vision ##
```
	u1	Vision for p1
	u1	Vision for p2
	u1	Vision for p3
	u1	Vision for p4
	u1	Vision for p5
	u1	Vision for p6
	u1	Vision for p7
	u1	Vision for p8

	u1	Vision for p9
	u1	Vision for p10
	u1	Vision for p11
	u1	Vision for p12
	u4	unused
```
CLASS 2 ONLY AND REPLAY


---

## 0x0C - Build ##
```
	u8   orderID
	s16  xTile
	s16  yTile
	u16  unitID
```
CLASS 2 ONLY AND REPLAY


---

## 0x0B - Shift Deselect ##
```
	u8          count
	u16*count  unitMem
```
CLASS 2 ONLY AND REPLAY


---

## 0x0A - Shift Select ##
```
	u8          count
	u16*count  unitMem
```
CLASS 2 ONLY AND REPLAY


---

## 0x09 - Select ##
```
	u8          count
	u16*count  unitMem
```
CLASS 2 ONLY AND REPLAY


---

## 0x08 - Restart Game ##
```
      No parameters.
```
CLASS 2 ONLY


---

## 0x07 -  Load Game ##
```
      u32       time
      cstring   name
```
CLASS 2 ONLY


---

## 0x06 - Save Game ##
```
      u32       time
      cstring   name
```
CLASS 2 ONLY


---

## 0x05 -  Keep Alive ##
```
      // No parameters.
```
CLASS 1 & 2


---

0x04 - UNDEFINED

---

0x03 -  Unknown
```
      // No parameters.
```
UNDEFINED

---

0x02 - UNDEFINED (game chat?)

---

0x01 -  Claim Host ? (game chat?)
```
      // No parameters.
```
UNDEFINED

---

## 0x00 - Game Chat ##
```
      u8        type
      cstring   message
```


---



# Packet Header #
```
	u32  udptype (0x00)
	u16  checksum
	u16  packet length
	u16  Sent packets to player (seq1)
	u16  Recieved packets from player (seq2)
	u8   Command Class
	u8   Command ID (0x00)
	u8   Player ID
	u8   Resend
	...Packet Data...
```
The command opcode is not stored in the Command ID of the packet, but rather in the data, where many commands may stack.
Command class 2 opcodes are those you'd find in a replay; unit actions.
Command class 1 opcodes are others used by Starcraft for communication; send text; lobby data; join game.

# Replay Header #
```
   u32  time (Game Ticks * 255??)
   u8   frameSize (Amount of bytes before the start of the next game frame)

        u8   Player ID
        u8   Command ID
        ...Command Variables...
```