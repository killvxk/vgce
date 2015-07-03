
```
0x00		Region (0x14 = USA; 0x15 = PAL) (4)
0x04		Size? (4)
0x08		character unlock flags (8) [3 bits per character]
0x10		Unknown (16)
0x20		Stage Unlock Flags (4)
0x24		Unknown unlockable flagsets (32)
0x44		Notice (Special Message) Data; 4 bytes per entry; 128 entries; date/time stamp
0x244		Unknown Flagset 1 (12)
0x250		Unknown Flagset 2 (28)
0x26C		Unknown Flagset 3 (4)
0x270		Game Mode Availability Flags (Allstar, Boss Battles, additional rules, random stage) (?)
0x274		Assist Trophy Unlockables (?)
0x278		Unknown Flagset 5 (16)
0x288		Unknown Flagset 6 (4)
0x28C		
0x290		Time Match Total
0x294		Stock Match Total
0x298		Coin Match Total
0x29C		
0x2A0		
0x2A4		
0x2A8		
0x2AC		Match Reset Counter
0x2B0		VS Play Contenstants
0x2B4		VS Play Time
0x2B8		Combined VS Play Time
0x2BC		Solo Play Time
0x2C0		Combined Solo Play Time
0x2C4		Wifi Play Time with Friends
0x2C8		Wifi Play Time with Anyone
0x2CC		Total Matches Spectated
0x2D0		Number of Coins * 10
0x2D4		Max Number of Coins * 10
0x2D8		Power Count
0x2DC		Power Time
0x2E0		Total Damage
0x2E4		KO Total
0x2E8		Self-Destruct Total
0x2EC		Unknown (Flags??)
917B640
0x2F0		Array of unknown data; 1 byte each; 0x34 entries?

0x310		Unknown (2)
0x31C		Unknown (1)

0x334		Event Clear Data (Easy) start; 4 bytes per entry; 51 entries (Byte 1 = Flags; 0x40 = Easy; 0x80 = Medium; 0xC0 = Hard)
0x400		Event Clear Data (Medium) start
0x4CC		Event Clear Data (Hard) start
0x598		Co-op Event Clear Data (Easy) start; 4 bytes per entry; 51 entries (Byte 1 = Flags; 0x40 = Easy; 0x80 = Medium; 0xC0 = Hard)
0x664		Co-op Event Clear Data (Medium) start
0x730		Co-op Event Clear Data (Hard) start

0x7FC		Unknown

0x818		Item Switch (00=None; 01=Low; 02=Medium; 03=High) [1]
0x820		Item Switches (8 bytes)
			Byte 1:
				Unused
			Byte 2:
				0x01 - Screw Attack
				0x02 - Cds, Trophies, Stickers
				0x04 - Cds, Trophies, Stickers
				0x08 - Cds, Trophies, Stickers
				0x10 - Unused
				0x20 - Unused
				0x40 - Unused
				0x80 - Unused
			Byte 3:
				0x01 - Green Shell
				0x02 - Banana Peel
				0x04 - Bumper
				0x08 - Spring
				0x10 - Unira
				0x20 - Soccer Ball
				0x40 - Team Healer (Only in team games)
				0x80 - Franklin Badge
			Byte 4:
				0x01 - Gooey Bomb
				0x02 - Smart Bomb
				0x04 - Deku Nut
				0x08 - Freezie
				0x10 - Smoke Ball
				0x20 - Pitfall
				0x40 - Hothead
				0x80 - Mr. Saturn
			Byte 5:
				0x01 - Hammer
				0x02 - Golden Hammer
				0x04 - Super Scope
				0x08 - Ray Gun
				0x10 - Fire Flower
				0x20 - Cracker Launcher
				0x40 - Bob-Omb
				0x80 - Motion Sensor Bomb
			Byte 6:
				0x01 - Superspice Curry
				0x02 - Timer
				0x04 - Lightning
				0x08 - Beam Sword
				0x10 - Home-Run Bat
				0x20 - Fan
				0x40 - Lip's Stick
				0x80 - Star Rod
			Byte 7:
				0x01 - Heart Container
				0x02 - Dragoon Parts
				0x04 - Super Mushroom
				0x08 - Poison Mushroom
				0x10 - Warp Star
				0x20 - Starman
				0x40 - Metal Box
				0x80 - Bunny Hood
			Byte 8:
				0x01 - Smash Ball
				0x02 - Assist Trophy
				0x04 - Pokeball
				0x08 - Containers
				0x10 - Blast Box
				0x20 - Sandbag
				0x40 - Food
				0x80 - Maximum Tomato

0x828		Global Rumble Option (GCN)
0x82C		Global Rumble Option (Wii)
0x830		Music/SFX Balance (0x64[100] = neutral)

0x840		Global Game Options (0x80 = Widescreen[on]; 0x40 = Deflicker[on])

0x84A		Trophy Data (2 bytes each) (544 entries; space for 651 entries)
			+0x00	Flags
				0x40 = Seen
				0x80 = Obtained
			+0x01	Amount

0xD60		Sticker Data (2 bytes each) (700 entries; space for 1000 entries)
			+0x00	Flags
				0x40 = Seen
				0x80 = Obtained
			+0x01	Amount

0x1530		Challenge Data Flags (128 challenges) [0x00 = hidden; 0x01 = preview; 0x02 = broken]
0x15B0		Remaining Golden Hammers
0x15B4		Unknown (132 bytes)
0x1638		Unknown (4)
0x163C		Mario Group Records (224 bytes) [0xE0 bytes]
0x171C		DK Group Records
0x17FC		Link Group Records
0x18DC		Samus Group Records
0x19BC		Yoshi Group Records
0x1A9C		Kirby Group Records
0x1B7C		Fox Group Records
0x1C5C		Pikachu Group Records
0x1D3C		Luigi Group Records
0x1E1C		Captain Falcon Group Records
0x1EFC		Ness Group Records
0x1FDC		Bowser Group Records
0x20BC		Peach Group Records
0x219C		Zelda Group Records
0x227C		Ice Climbers Group Records
0x235C		Falco Group Records
0x243C		Ganon Group Records
0x251C		Wario Group Records
0x25FC		Metaknight Group Records
0x26DC		Pit Group Records
0x27BC		Olimar Group Records
0x289C		Lucas Group Records
0x297C		Diddy Group Records
0x2A5C		DeDeDe Group Records
0x2B3C		Ike Group Records
0x2C1C		ROB Group Records
0x2CFC		Snake Group Records
0x2DDC		Pokemon Trainer Group Records
0x2EBC		Lucario Group Records
0x2F9C		Marth Group Records
0x307C		Game & Watch Group Records
0x315C		Jigglypuff Group Records
0x323C		Toon Link Group Records
0x331C		Wolf Group Records
0x33FC		Sonic Group Records
----------------------------------------------------
			+0x00	KOs Against [Mario]
			+0x02	KOs Against [DK]
			+0x04	KOs Against [Link]
			+0x06	KOs Against [Samus]
			+0x08	KOs Against [Yoshi]
			+0x0A	KOs Against [Kirby]
			+0x0C	KOs Against [Fox]
			+0x0E	KOs Against [Pikachu]
			+0x10	KOs Against [Luigi]
			+0x12	KOs Against [Capt. Falcon]
			+0x14	KOs Against [Ness]
			+0x16	KOs Against [Bowser]
			+0x18	KOs Against [Peach]
			+0x1A	KOs Against [Zelda]
			+0x1C	KOs Against [Ice Climbers]
			+0x1E	KOs Against [Falco]
			+0x20	KOs Against [Ganon]
			+0x22	KOs Against [Wario]
			+0x24	KOs Against [Metaknight]
			+0x26	KOs Against [Pit]
			+0x28	KOs Against [Olimar]
			+0x2A	KOs Against [Lucas]
			+0x2C	KOs Against [Diddy]
			+0x2E	KOs Against [Dedede]
			+0x30	KOs Against [Ike]
			+0x32	KOs Against [ROB]
			+0x34	KOs Against [Snake]
			+0x36	KOs Against [Pokemon Trainer]
			+0x38	KOs Against [Lucario]
			+0x3A	KOs Against [Marth]
			+0x3C	KOs Against [Game&Watch]
			+0x3E	KOs Against [Jigglypuff]
			+0x40	KOs Against [Toon Link]
			+0x42	KOs Against [Wolf]
			+0x44	KOs Against [Sonic]
			+0x46	Falls
			+0x48	Self Destructs
			+0x4A	Unknown (2)
			+0x4C	Unknown (4) (Attacks attempted?)
			+0x50	Unknown (4) (Hits landed?)
			+0x54	Damage Given (4)
			+0x58	Damage Taken (4)
			+0x5C	Damage Recovered (4)
			+0x60	Peak Damage (2)
			+0x62	Matches (2)
			+0x64	Victories
			+0x66	Losses
			+0x68	Play Time [in s] (4)
			+0x6C	Play % (4)
			+0x70	Ground Distance (in metres; divide by 3.048 to get feet)
			+0x74	Jump Distance (in metres)
			+0x78	Drop Distance (in metres)
			+0x7C	Launch Distance (in metres)
			+0x80	Coins Collected
			+0x84	Coins Dropped
			+0x88	Coins Lost
			+0x8C	Prat Falls
			+0x90	Swim Distance
			+0x94	Drownings
			+0x98	Games Played by Human Player (2)
			+0x9A	unknown (2)
			+0x9C	Unknown (4) [function call???wtf]
			+0xA0	Classic Mode Score
			+0xA4	All-Star Mode Score
			+0xA8	Boss Battles Time
			+0xAC	HRC Distance (in metres; divide by 3.048 to get feet)
			+0xB0	Score in 10-man Brawl
			+0xB4	Score in 100-man Brawl
			+0xB8	Score in 3-minute Brawl
			+0xBC	Score in 15-minute Brawl
			+0xC0	Score in Endless Brawl
			+0xC4	Score in Cruel Brawl
			+0xC8	Max Combos (Training) (2)
			+0xCA	Unknown (2)
			+0xCC	Target Test 1 Score (First byte = best difficulty)
			+0xD0	Target Test 2 Score
			+0xD4	Target Test 3 Score
			+0xD8	Target Test 4 Score
			+0xDC	Target Test 5 Score
----------------------------------------------------
0x34DC		Flags??

0x34E8		Co-Op HRC Record (ft)
0x34EC		Co-Op 10-Man Brawl High Score
0x34F0		Co-Op 100-Man Brawl High Score
0x34F4		Co-Op 3-minute Brawl High Score
0x34F8		Co-Op 15-minute Brawl High Score
0x34FC		Co-Op Endless Brawl High Score
0x3500		Co-Op Cruel Brawl High Score
0x3504		Co-Op BTT Level 1 High Score
0x3508		Co-Op BTT Level 1 Character 1
0x350A		Co-Op BTT Level 1 Character 2
0x350C		Co-Op BTT Level 2 High Score
0x3510		Co-Op BTT Level 2 Character 1
0x3512		Co-Op BTT Level 2 Character 2
0x3514		Co-Op BTT Level 3 High Score
0x3518		Co-Op BTT Level 3 Character 1
0x351A		Co-Op BTT Level 3 Character 2
0x351C		Co-Op BTT Level 4 High Score
0x3520		Co-Op BTT Level 4 Character 1
0x3522		Co-Op BTT Level 4 Character 2
0x3524		Co-Op BTT Level 5 High Score
0x3528		Co-Op BTT Level 5 Character 1
0x352A		Co-Op BTT Level 5 Character 2

0x3534		Co-Op HRC Character 1
0x3536		Co-Op HRC Character 2
0x3538		Co-Op 10-Man Brawl Character 1
0x353A		Co-Op 10-Man Brawl Character 2
0x353C		Co-Op 100-Man Brawl Character 1
0x353E		Co-Op 100-Man Brawl Character 2
0x3540		Co-Op 3-minute Brawl Character 1
0x3542		Co-Op 3-minute Brawl Character 2
0x3544		Co-Op 15-minute Brawl Character 1
0x3546		Co-Op 15-minute Brawl Character 2
0x3548		Co-Op Endless Brawl Character 1
0x354A		Co-Op Endless Brawl Character 2
0x354C		Co-Op Cruel Brawl Character 1
0x354E		Co-Op Cruel Brawl Character 2


0x3594		My Music Data
----------------------------------------------------
			+0x00 - Music Flags/Parameters
			+0x02 - Music ID (0x00 00 = none)
			+0x04 - Flags? (2) (0xFFFF = locked)
			+0x06 - Area ID (1)
				0x00	Battlefield
				0x01	Final Destination
				0x02	Delfino Plaza
				0x03	Luigi's Mansion
				0x04	Mushroomy Kingdom 1
				0x05	Mushroomy Kingdom 2
				0x06	Mario Circuit
				0x07	75m
				0x08	Jungle Falls
				0x09	Pirate Ship
				0x0A	Eldin Bridge
				0x0B	Norfair
				0x0C	Frigate Orpheon
				0x0D	Yoshi's Island
				0x0E	Halberd
				0x0F	Space Armada
				0x10	Pokemon Stadium 2
				0x11	Spear Pillar
				0x12	Port Town Aero Dive
				0x13	Summit
				0x14	Flat Zone 2
				0x15	Castle Siege
				0x16	Wario Ware, Inc.
				0x17	Distant Planet
				0x18	Skyworld
				0x19	Mario Bros.
				0x1A	New Pork City
				0x1B	Smashville
				0x1C	Shadow Moses Island
				0x1D	Green Hill Zone
				0x1E	Picto Chat
				0x1F	Hanenbow
				0x20	Temple (Melee)
				0x21	Yoshi's Island (Melee)
				0x22	Jungle Japes (Melee)
				0x23	Onett (Melee)
				0x24	Green Greens (Melee)
				0x25	Pokemon Stadium (Melee)
				0x26	Rainbow Cruise (Melee)
				0x27	Corneria (Melee)
				0x28	Big Blue (Melee)
				0x29	Brinstar (Melee)
				0x2A	Menu
				0xFF	End Section
			+0x07 - Percentage (1)
----------------------------------------------------
0x3CF4	Unknown (0x00000000)
0x3CF8		Personal Data Slot 1 (292 bytes) [0x124 bytes]
0x3E1C		Personal Data Slot 2
0x3F40		Personal Data Slot 3
0x4064		Personal Data Slot 4
0x4188		Personal Data Slot 5
0x42AC		Personal Data Slot 6
0x43D0		Personal Data Slot 7
0x44F4		Personal Data Slot 8
0x4618		Personal Data Slot 9
0x473C		Personal Data Slot 10
0x4860		Personal Data Slot 11
0x4984		Personal Data Slot 12
0x4AA8		Personal Data Slot 13
0x4BCC		Personal Data Slot 14
0x4CF0		Personal Data Slot 15
0x4E14		Personal Data Slot 16
0x4F38		Personal Data Slot 17
0x505C		Personal Data Slot 18
0x5180		Personal Data Slot 19
0x52A4		Personal Data Slot 20
0x53C8		Personal Data Slot 21
0x54EC		Personal Data Slot 22
0x5610		Personal Data Slot 23
0x5734		Personal Data Slot 24
0x5858		Personal Data Slot 25
0x597C		Personal Data Slot 26
0x5AA0		Personal Data Slot 27
0x5BC4		Personal Data Slot 28
0x5CE8		Personal Data Slot 29
0x5E0C		Personal Data Slot 30
0x5F30		Personal Data Slot 31
0x6054		Personal Data Slot 32
0x6178		Personal Data Slot 33
0x629C		Personal Data Slot 34
0x63C0		Personal Data Slot 35
0x64E4		Personal Data Slot 36
0x6608		Personal Data Slot 37
0x672C		Personal Data Slot 38
0x6850		Personal Data Slot 39
0x6974		Personal Data Slot 40
0x6A98		Personal Data Slot 41
0x6BBC		Personal Data Slot 42
0x6CE0		Personal Data Slot 43
0x6E04		Personal Data Slot 44
0x6F28		Personal Data Slot 45
0x704C		Personal Data Slot 46
0x7170		Personal Data Slot 47
0x7294		Personal Data Slot 48
0x73B8		Personal Data Slot 49
0x74DC		Personal Data Slot 50
0x7600		Personal Data Slot 51
0x7724		Personal Data Slot 52
0x7848		Personal Data Slot 53
0x796C		Personal Data Slot 54
0x7A90		Personal Data Slot 55
0x7BB4		Personal Data Slot 56
0x7CD8		Personal Data Slot 57
0x7DFC		Personal Data Slot 58
0x7F20		Personal Data Slot 59
0x8044		Personal Data Slot 60
0x8168		Personal Data Slot 61
0x828C		Personal Data Slot 62
0x83B0		Personal Data Slot 63
0x84D4		Personal Data Slot 64
0x85F8		Personal Data Slot 65
0x871C		Personal Data Slot 66
0x8840		Personal Data Slot 67
0x8964		Personal Data Slot 68
0x8A88		Personal Data Slot 69
0x8BAC		Personal Data Slot 70
0x8CD0		Personal Data Slot 71
0x8DF4		Personal Data Slot 72
0x8F18		Personal Data Slot 73
0x903C		Personal Data Slot 74
0x9160		Personal Data Slot 75
0x9284		Personal Data Slot 76
0x93A8		Personal Data Slot 77
0x94CC		Personal Data Slot 78
0x95F0		Personal Data Slot 79
0x9714		Personal Data Slot 80
0x9838		Personal Data Slot 81
0x995C		Personal Data Slot 82
0x9A80		Personal Data Slot 83
0x9BA4		Personal Data Slot 84
0x9CC8		Personal Data Slot 85
0x9DEC		Personal Data Slot 86
0x9F10		Personal Data Slot 87
0xA034		Personal Data Slot 88
0xA158		Personal Data Slot 89
0xA27C		Personal Data Slot 90
0xA3A0		Personal Data Slot 91
0xA4C4		Personal Data Slot 92
0xA5E8		Personal Data Slot 93
0xA70C		Personal Data Slot 94
0xA830		Personal Data Slot 95
0xA954		Personal Data Slot 96
0xAA78		Personal Data Slot 97
0xAB9C		Personal Data Slot 98
0xACC0		Personal Data Slot 99
0xADE4		Personal Data Slot 100
0xAF08		Personal Data Slot 101
0xB02C		Personal Data Slot 102
0xB150		Personal Data Slot 103
0xB274		Personal Data Slot 104
0xB398		Personal Data Slot 105
0xB4BC		Personal Data Slot 106
0xB5E0		Personal Data Slot 107
0xB704		Personal Data Slot 108
0xB828		Personal Data Slot 109
0xB94C		Personal Data Slot 110
0xBA70		Personal Data Slot 111
0xBB94		Personal Data Slot 112
0xBCB8		Personal Data Slot 113
0xBDDC		Personal Data Slot 114
0xBF00		Personal Data Slot 115
0xC024		Personal Data Slot 116
0xC148		Personal Data Slot 117
0xC26C		Personal Data Slot 118
0xC390		Personal Data Slot 119
0xC4B4		Personal Data Slot 120
----------------------------------------------------
			+0x00	KOs
			+0x02	Falls
			+0x04	Self-Destructs
			+0x06	Unknown (2)
			+0x08	Unknown (4) (Hits landed?)
			+0x0C	Unknown (4) (Attacks Attempted?)
			+0x10	Damage Given
			+0x14	Damage Taken
			+0x18	Damage Recovered (4)
			+0x1C	Peak Damage (2)
			+0x1E	Matches (2)
			+0x20	Victories
			+0x22	Losses
			+0x24	Play Time [in s] (4)
			+0x28	Play % (?) (4)
			+0x2C	Ground Distance (in metres; divide by 3.048 to get feet)
			+0x30	Jump Distance (in metres)
			+0x34	Drop Distance (in metres)
			+0x38	Launch Distance (in metres)
			+0x3C	Coins Collected
			+0x40	Coins Dropped
			+0x44	Coins Lost
			+0x48	Prat Falls
			+0x4C	Swim Distance
			+0x50	Drownings
			+0x54	Unknown (2) (Most used Character?)
			+0x56	Unknown (2) (Second most used Character?)
			+0x58	Unknown (4)
			+0x5C	Classic Mode Score
			+0x60	All-Star Mode Score
			+0x64	Boss Battles Time
			+0x68	HRC Distance (in metres; divide by 3.048 to get feet)
			+0x6C	Score in 10-man Brawl
			+0x70	Score in 100-man Brawl
			+0x74	Score in 3-minute Brawl
			+0x78	Score in 15-minute Brawl
			+0x7C	Score in Endless Brawl
			+0x80	Score in Cruel Brawl
			+0x84	Max Combos (Training) (2)
			+0x86	Unknown (2)
			+0x88	Target Test 1 Score (First byte = best difficulty)
			+0x8C	Target Test 2 Score
			+0x90	Target Test 3 Score
			+0x94	Target Test 4 Score
			+0x98	Target Test 5 Score

			+0xE0	Player Name (16bit Unicode Formatting; 6 Characters)
			+0xEC	Assuming this and beyond is button configuration and other settings
			
			+0x120	Final Field (4)
----------------------------------------------------
0xC5D8		Unknown

0xC664		Total File Size

0xC67C		Checksum & Default EOF
```