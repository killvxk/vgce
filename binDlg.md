# Table of Contents #



# Dialog Structure #
```
0x00 	u32	Next Entry Offset
0x04 	u16	Left Position
0x06 	u16	Top Position
0x08 	u16	Right Position
0x0A 	u16	Bottom Position
0x0C 	u16	Width
0x0E 	u16	Height
0x10 	u32	Running-Flags (Internal Use)
0x14 	u32	String Offset
0x18 	u32	Flags (See Dialog Flags)
0x1C 	u32	Unknown Internal use
0x20 	u16	Control ID
0x22 	u32	Control Type (See Control Types)
0x26 	u32	Unknown Internal use
0x2A 	u32	Update function 1  (Internal Use)
0x2E 	u32	Update function 2  (Internal Use)
0x32 	u32	Parent Dialog
0x36 	u16	Response Area Left
0x38 	u16	Response Area Top
0x3A 	u16	Response Area Right
0x3C 	u16	Response Area Bottom
0x3E	u32	Unknown Internal use
0x42	u32	Child Offset(SMK for children of main window)
0x46 	u16	Text Offset X
0x48 	u16	Text Offset Y
0x4A 	u16	Response Area Width
0x4C 	u16	Response Area Height
0x4E 	u32	Unknown Internal use
0x52 	u32	Unknown Internal use
```

# SMK Structure #
```
0x00	u32	SMK Overlay Offset
0x04	u16	Flags (See SMK Flags)
0x06	u32	Internal use
0x0A	u32	SMK Filename (String Offset)
0x0E	u32	Internal use
0x12	u16	SMK Overlay X Position
0x14	u16	SMK Overlay Y Position
0x16	u32	Internal use
0x1A	u32	Internal use
```

# Flags #
```
0x00000001 = "Unknown 0"
0x00000002 = "Disabled"
0x00000004 = "Unknown 2"
0x00000008 = "Visible"
0x00000010 = "Responds to Events"
0x00000020 = "Unknown 5"
0x00000040 = "Cancel Button"
0x00000080 = "No Hover Sound"
0x00000100 = "Special Hotkey (Virtual Key)"
0x00000200 = "Has Hotkey"
0x00000400 = "Smallest Font (Size 10)"
0x00000800 = "Larger Font (Size 16)"
0x00001000 = "Unknown 12"
0x00002000 = "Transparent (Hide Color 0)"
0x00004000 = "Largest Font (Size 16x)"
0x00008000 = "Alternate Style (WC2)"
0x00010000 = "Smaller Font (Size 14)"
0x00020000 = "Remove Styles"
0x00040000 = "Apply Translucency"
0x00080000 = "Default Button"
0x00100000 = "Bring to Front"
0x00200000 = "Horizontal Alignment: Left"
0x00400000 = "Horizontal Alignment: Right"
0x00800000 = "Horizontal Alignment: Center"
0x01000000 = "Vertical Alignment: Top"
0x02000000 = "Vertical Alignment: Middle"
0x04000000 = "Vertical Alignment: Bottom"
0x08000000 = "Unknown 27"
0x10000000 = "Reverse Dialog Direction"
0x20000000 = "Use Alternate Style"
0x40000000 = "No Click Sound"
0x80000000 = "Highlight Text"
```

# SMK Flags #
```
0x0001 - Fade In
0x0002 - Dark
0x0004 - Repeat Forever
0x0008 - Show If Over
0x0010 - Unknown 4
(rest unknown/unused)
```

# Control Types #
```
0x00000000 = "Dialog Box"
0x00000001 = "Default Button"
0x00000002 = "Button"
0x00000003 = "Option Button"
0x00000004 = "Check box"
0x00000005 = "Image"
0x00000006 = "Horizontal Scroll Bar"
0x00000007 = "Vertical Scroll Bar"
0x00000008 = "Text box"
0x00000009 = "Label (Left align)"
0x0000000A = "Label (Right align)"
0x0000000B = "Label (Center align)"
0x0000000C = "List box"
0x0000000D = "Combo box"
0x0000000E = "Light-up Button"
```