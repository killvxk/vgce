
```
Theory: Should compress better if things are nulled out, or values are lower(more common) or removed completely.
Melee maps should use the 1.00 format because they will not require the TYPE section.

A melee map will compress a LOT better because it does not require the sections that UMS maps do.
A 1.00 melee map only requires 12 sections; "VER ", "VCOD", "OWNR", "ERA ", "DIM ", "SIDE", "MTXM", "UNIT", "THG2", "STR ", "SPRP", and "FORC" 
Where FORC is a size of 0, MTXM, UNIT, and THG2 are the only real variable sections that will be most of your map size(THG2 not so much).

Heinermann's experimental compression:
====>MPQ
Recreate the MPQ archive with a maximum size of what is required of your map.
Re-Import any files that have a negative compression ratio with no compression.
Import WAV files at Maximum audio compression.


====>WAV FILES
Delete optional fact section from WAV files.
Modify the "fmt " header to be 0x10.
Delete any unnecessary data in WAV files appended by some programs.
Make sure your WAV files are 16-bit for better MPQ compression.
Be sure your WAV files are at most 22 050 kHz.
A more quality-saving compression would be to manually change the frequency, and "speed up" the result.
Make sure your WAV files are mono, not stereo. (halves file)
Import at maximum WAV compression.
Reference all WAV files from current strings rather than their own individual file names. For example; Play WAV "Force 1", would play the wav file called "Force 1".


====>CHK FILE
Make sure there are no split sections.
Make sure there are no unused spaces between sections.
Remove all duplicate sections.
Remove all invalid sections.


==>"VER "
If Broodwar unit settings and extra locations are not required, immediately make your map forced compatibility with Starcraft 1.00. Expansion tilesets, units, and triggers should load correctly.


==>"TYPE"
Delete this section if your map is only 1.00 compatible.


==>"IVER", "IVE2", "IOWN", "ISOM", "TILE", "DD2 ", "WAV ", "SWNM"
Delete all of these sections.


==>"VCOD"
Change all 0x05 opcodes to 0x04. Null out bytes while making sure your map is still compatible.


==>"OWNR"
Set unused players to 0x00. Set players 9-12 to 0x00.
Used players in a melee map can all be set to 0x03(rescue passive, replaced with open slot for melee map). This will prevent the map from being playable in the UMS game type.


==>"ERA "
If this value is 8 or greator, AND it by 7. (A protection method is to let Starcraft do the ANDing process, while most editors do not)


==>"DIM "
Be sure the size of the map is standard. There are bugs with non-standard map sizes in Starcraft.


==>"SIDE"
Set unused players to 0x00.
Set players 9-12 to 0x00.


==>"MTXM"
Make sure this section is not larger than mapWidth*mapHeight*2.
You have the option of removing mapWidth*2+6 bytes from the end of this section without affecting gameplay(black bar at bottom of map).
If the last tile in this section is a Null tile, remove those 2 bytes. Continue until a non-null tile is found. If your map consists of only Null tiles, you may make this entire section a size of 0.


==>"PUNI"
Remove this section if your map is melee only.

 =>Player availability
 Null out each entry with override defaults off.
 Null out any unused entry.
 Null out entries for players 9-12.

 =>Global availability
 Null out any unused entry.

 =>Override defaults
 Null out any unused entry.
 Find out if player can use the global availability without affecting gameplay.
 Null out entries for players 9-12.
 Make sure entries are either 0 or 1.

Unused units for availability include:
	Spider Mine
	Zerg Larva
	Zerg Egg
	Zerg Broodling
	Mutalisk Cocoon
	Protoss Dark Archon
	Protoss Archon
	Critters
	Lurker Egg
	Map Revealer
	Zerg Lurker
	Infested Command Center
	All Hero units.
	All subUnits(for tanks/goliath).
	All spells(dweb, swarm, scan)
	All "Unused" or "Crashing" units.
	All special buildings.
	All powerups.
	Everything AFTER the Protoss Shield Battery entry.


==>"UPGR", "PUPx"
Remove UPGR if your map is hybrid or Broodwar. Remove PUPx if your map is 1.00.
Remove both if your map is melee only.

 =>MaxLevel
 Null out any entry with useGlobal on.
 Null MaxLevel entry if StartLevel is equal to or greater than the max level.
 Null global60's maxlevel. It cannot be upgraded.
 Null out unused entries.

 =>startLevel
 Null out any entry with useGlobal on.
 Null out unused entries.

 =>globalMaxLevel
 Null out any unused entries.
 Null MaxLevel entry if StartLevel is equal to or greater than the max Level.
 Null global60's maxlevel.

 =>globalStartLevel
 Null out any unused entries.

 =>useGlobal
 Null out any unused entries. Attempt to use global settings rather than individual settings.
 Make sure entries are only 1 or 0.

Unused upgrades include:
	Burst Lasers (Unused)
	Unknown Upgrade45
	Unknown Upgrade46
	Unknown Upgrade48
	Unknown Upgrade50
	Unused Upgrade 55
	Unused Upgrade 56
	Unused Upgrade 57
	Unused Upgrade 58
	Unused Upgrade 59


==>"PTEC", "PTEx"
Remove PTEC if your map is hybrid or Broodwar. Remove PTEx if your map is 1.00.
Remove both if your map is melee only.

 =>Availability
 Null out any entry with global setting on.
 Null out any entry if researched entry is checked.
 Make sure entries are only 1 or 0.
 Null unused entries.

 =>researched
 Null out any entry with global setting on.
 Make sure entries are only 1 or 0.
 Null unused entries.

 =>global availability
 Null out unused entries.
 Make sure entries are only 1 or 0.

 =>global researched
 Null out unused entries.
 Make sure entries are only 1 or 0.

 =>use global setting
 Null out any unused entry. Attempt to use global settings rather than individual settings.
 Make sure entries are only 1 or 0.

Unused technologies include:
	Unused Tech 26
	Unused Tech 33
	Unused Tech 35
	Unused Tech 36
	Unused Tech 37
	Unused Tech 38
	Unused Tech 39
	Unused Tech 40
	Unused Tech 41
	Unused Tech 42
	Unused Tech 43


==>"UNIT"
Null unit class if unused.
Null special property flags if their corresponding property is not used or not valid.

 =>Null the following property flags:
   Owner.
   HP if HP is 100%.
   SP if Shields are 100%, or unit has no shields.
   Energy if Energy is 100%, or unit has no energy.
   Resource amount if unit is not a resource, or resources are 0.
   Hangar amount if unit is not a Carrier/Reaver, or doesn't start with any interceptors/scarabs.
   All unused flags.

Null HP%, SP%, EP%, Resources, and hangar units if their corresponding property flags are unchecked, or they are unused by the unit.
Null unnecessary unit state flags.
Null unused field.

Remove all duplicate Start Locations.
If the map is melee, remove all units except for Start Locations, Critters(Player 12 only), Resources(Player 12 only).
Null unit "serial" and other misc information if it is not connected with anything(addon, nydus).


==>"THG2"
Null the player number on pure sprites if there is no colour associated with the graphic.
Null the unused byte.
Null all flags except for the "Draw as Sprite" and "Disabled" flags.
Null the "Disabled" flag if "Draw as Sprite" is checked.
If the map is melee, remove all non-player12 sprites with "Draw as Sprite" unchecked.


==>"MASK"
Turn on all flags for unused players.
For every 0xFF at the end of the section, you can delete it. Repeat until a non-0xFF is found.
If your map does not modify the fog of war, then you can set this section's size to 0.
Remove this section if your map is melee only.


==>"STR "
Set the number of strings to only the amount of strings used in the map. Resize the section and delete unused data. You may remove the first and last 0x00 bytes from where the strings are stored(be sure there is a 0x00 between each string).
Merge some string entries. For example: "Preparing Level 1" and "Level 1". "<grey>Holy Shit Defence" and "<green>Holy Shit Defence" can be merged as "<grey><green>Holy Shit Defence" because of the colour tags' special properties.
A melee map should have a MAXIMUM of two strings.
If the map contains no strings, set the section size to 0x01.


==>"UPRP"
Merge similar entries. For example. If you are spawning an Infested Terran with 50% HP, and at another time you are spawning a Carrier with 50% HP AND 8 interceptors, you can merge the two entries since the Infested Terran will ignore the interceptors entry. A similar case could be creating a lifted building and creating a broodling that will run out of energy. The broodling ignores the lifted flag.
Remove this section if your map is melee only.


==>"UPUS"
Remove this section if your map is melee only.


==>"MRGN"
Null the string index pointer for every location.
Null out unused locations(including anywhere).
Remove this section if your map is melee only.


==>"TRIG", "MBRF"
Remove all triggers that will never execute. Including triggers with an AtLeast value greater than an AtMost value.
Remove all "unchecked" conditions and actions.
Remove all always conditions("No Condition" is the same as Always).
Remove similar conditions, like AtLeast 0.
Change AtLeast/AtMost conditions of the same value to Exactly.
Remove duplicate Preserve Actions.
Remove comments.
Remove all Briefing conditions.
Remove the time(unused) for the Play WAV action.
Check LeaderBoard text strings. If the string is the same as the default string, make it 0x00.
Remove all single-player actions if the map is intended for multi-player.
Change "Current Player" to "Player 1" for all of Player 1(ONLY player 1)'s triggers.
Null out trigger execution for unused and invalid players and groups.
Remove these sections if your map is melee only.
Reference all WAV files from current strings rather than their own individual file names. For example; Play WAV "Force 1", would play the wav file called "Force 1".

Single-player only actions include:
	Pause Game
	Unpause Game
	Set Next Scenario
	Disable Debug
	Enable Debug
	Enable Skip Tutorial

==>"SPRP"
Null map description if there is none.
Null map name if it is the same as the file name.


==>"FORC"
Null force for unused players.
Null strings for unused forces.
Null properties for unused forces.
Null unused force properties.
If random start location is not used and the force only contains computer players, you can null out the properties.
If your map is melee only, you can set the size of this section to 0.


==>"UNIS", "UNIx"
Remove this section if your map is melee only.
Null all properties for units that use default settings.
Null all settings for unused or crash units.
Null all shield point settings for units that have no shields.
Null all build times for units that cannot be built, trained, morphed, merged, or repaired.
Null all Mineral/gas costs for units that cannot be built, trained, morphed, or repaired.
Null all unused weapons.
Null all bonuses if their respective upgrade will always be 0.


==>"UPGS", "UPGx"
Remove this section if your map is melee only.
Null all properties for upgrades that use default settings.
Null all settings for unused upgrades.
Null all upgrade factors if the upgrade can only be achieved a single time.
Null all settings for upgrades that start at their max.


==>"TECS", "TECx"
Remove this section if your map is melee only.
Null all properties for technologies that use default settings.
Null all unused properties for specific technologies.
Null all unused technologies.
Null all mineral/gas/time costs for technologies if they are defaultly researched.


==>"COLR"
Delete this section if your scenario is not Broodwar.
Null unused colours if start locations are not random.
```