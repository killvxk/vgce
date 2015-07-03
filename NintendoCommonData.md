# Games Seen #

  * Super Smash Bros. Melee
  * Super Smash Bros. Brawl
  * Paper Mario 2: The Thousand-Year Door

# Format #

```
0x00	EOF (File Size)
0x04	Data Table Pointer
0x08	Number of Pointers
0x0C	Number of Files
0x10	Unknown
0x14	Unknown (is ASCII "001B" for some files)
0x18	Unknown
0x1C	Unknown

DATA TABLE ENTRIES [Starts at "Data Table Pointer"(excludes header)]
	+0x00	Additional File pointer	[4]
		* Number of Pointers

NAME TABLE ENTRIES [starts immediately after DATA TABLE ends]
	+0x00	File offset pointer
	+0x04	Pointer to null terminated string (from beginning of name entries)
		* Number of Files

NAME ENTRIES [starts immediately after NAME TABLE ends]
	Strings, each end in 00 
```