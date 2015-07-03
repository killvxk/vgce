


---


# 0x00 - goto #
_Description:_
Jump to %1(block)



# 0x01 - notowns\_jump #
_Description:_
If computer doesn't have a %1(unit), jump to %2(block)



# 0x02 - wait #
_Description:_
Wait for %1(word) tenths of second in normal game speed



# 0x03 - start\_town #
_Description:_
Starts the AI Script for town management



# 0x04 - start\_areatown #
_Description:_
Starts the AI Script for area town management



# 0x05 - expand #
_Description:_
Run code at %2(block) for expansion number %1(byte)



# 0x06 - build #
_Description:_
Build %2(building) until it commands %1(byte) of them, at priority %3(byte)



# 0x07 - upgrade #
_Description:_
Research upgrade %2(upgrade) up to level %1(byte), at priority %3(byte)



# 0x08 - tech #
_Description:_
Research technology %1(technology), at priority %2(byte)



# 0x09 - wait\_build #
_Description:_
Wait until computer commands %1(byte) %2(building)



# 0x0A - wait\_buildstart #
_Description:_
Wait until construction of %1(byte) %2(unit) has started



# 0x0B - attack\_clear #
_Description:_
Clear the attack data



# 0x0C - attack\_add #
_Description:_
Add %1(byte) %2(military) to the current attacking party



# 0x0D - attack\_prepare #
_Description:_
Prepare the attack



# 0x0E - attack\_do #
_Description:_
Attack the enemy with the current attacking party



# 0x0F - wait\_secure #
_Description:_
The use of this command is unknown. Takes no parameters.



# 0x10 - capt\_expand #
_Description:_
Captures an expansion with a default build scheme.
> Takes no parameter



# 0x11 - build\_bunkers #
_Description:_
The use of this command is unknown. Takes no parameters.



# 0x12 - wait\_bunkers #
_Description:_
The use of this command is unknown. Takes no parameters.



# 0x13 - defensebuild\_gg #
_Description:_
Build %1(byte) %2(military) to defend against enemy attacking ground units, when ground units are attacked



# 0x14 - defensebuild\_ag #
_Description:_
Build %1(byte) %2(military) to defend against enemy attacking air units, when ground units are attacked



# 0x15 - defensebuild\_ga #
_Description:_
Build %1(byte) %2(military) to defend against enemy attacking ground units, when air units are attacked



# 0x16 - defensebuild\_aa #
_Description:_
Build %1(byte) %2(military) to defend against enemy attacking air units, when air units are attacked



# 0x17 - defenseuse\_gg #
_Description:_
Use %1(byte) %2(military) to defend against enemy attacking ground units, when ground units are attacked



# 0x18 - defenseuse\_ag #
_Description:_
Use %1(byte) %2(military) to defend against enemy attacking air units, when ground units are attacked



# 0x19 - defenseuse\_ga #
_Description:_
Use %1(byte) %2(military) to defend against enemy attacking ground units, when air units are attacked



# 0x1A - defenseuse\_aa #
_Description:_
Use %1(byte) %2(military) to defend against enemy attacking air units, when air units are attacked



# 0x1B - defenseclear\_gg #
_Description:_
Clear defense against enemy attacking ground units, when ground units are attacked



# 0x1C - defenseclear\_ag #
_Description:_
Clear defense against enemy attacking air units, when ground units are attacked



# 0x1D - defenseclear\_ga #
_Description:_
Clear defense against enemy attacking ground units, when air units are attacked



# 0x1E - defenseclear\_aa #
_Description:_
Clear defense against enemy attacking air units, when air units are attacked



# 0x1F - send\_suicide #
_Description:_
Send all units to suicide mission
> %1(byte) determines which type
```
0 = Strategic;
1 = Random;
```



# 0x20 - player\_enemy #
_Description:_
Make selected player enemy



# 0x21 - player\_ally #
_Description:_
Make selected player ally



# 0x22 - default\_min #
_Description:_
Defines the number of units that will be sent to expansions when the AI tries to expand.
> Takes %1(byte) as parameter


# 0x23 - defaultbuild\_off #
_Description:_
Does not automatically train units. Takes no parameters.


# 0x24 - stop #
_Description:_
Stop script code execution
> Often used to close script blocks called simultaneously



# 0x25 - switch\_rescue #
_Description:_
Switch computer to rescuable passive mode



# 0x26 - move\_dt #
_Description:_
Move Dark Templars to selected location



# 0x27 - debug #
_Description:_
Show debug string %2(string) and continue in %1(block)



# 0x28 - fatal\_error #
_Description:_
Causes a fatal AI script error "Illegal AI script executed."



# 0x29 - enter\_bunker #
_Description:_
Orders all valid units in a selected location to enter the closest bunker.



# 0x2A - value\_area #
_Description:_
Values the location's area higher than other regions. Units will rally or defend this position more frequently.



# 0x2B - transports\_off #
_Description:_
Computer will not manage/build transports on its own



# 0x2C - check\_transports #
_Description:_
Informs computer to use transports up to the defined Max#



# 0x2D - nuke\_rate #
_Description:_
Builds nukes every %1(byte) minutes



# 0x2E - max\_force #
_Description:_
The use of this command is unknown
> Takes %1(word) as parameter



# 0x2F - clear\_combatdata #
_Description:_
Clear previous combat data



# 0x30 - random\_jump #
_Description:_
There is %1(byte) chances out of 256 to jump to %2(block)



# 0x31 - time\_jump #
_Description:_
Jumps to %2(block) if %1(byte) normal game minutes have passed in the game



# 0x32 - farms\_notiming #
_Description:_
Build necessary farms only when it hits the maximum supply available



# 0x33 - farms\_timing #
_Description:_
Build necessary farms with a correct timing, so nothing is paused by a maximum supply limit hit



# 0x34 - build\_turrets #
_Description:_
The use of this command is unknown. Takes no parameters.



# 0x35 - wait\_turrets #
_Description:_
The use of this command is unknown. Takes no parameters.



# 0x36 - default\_build #
_Description:_
Notifies the AI that it should automatically start training race-specific units if it has at least 600 minerals and 300 gas. It will train these units until the define\_max value is reached.

Takes no parameters.

## Units Trained ##
  * Zerg
    * Hydralisk
    * Mutalisk
  * Terran
    * Marine
    * Ghost
    * Siege Tank
    * Goliath
    * Wraith
    * Battlecruiser
  * Protoss
    * Zealot
    * Dragoon
    * Reaver
    * Scout
    * Carrier


# 0x37 - harass\_factor #
_Description:_
The use of this command is unknown. Takes %1(short).



# 0x38 - start\_campaign #
_Description:_
Starts the AI Script for Campaign.



# 0x39 - race\_jump #
_Description:_
According to the nearest enemy race, jump in %1(block) if it is Terran, %2(block) if Zerg or %3(block) if Protoss.



# 0x3A - region\_size #
_Description:_
If enemy unit is within %1 (byte) (unknown measure), jump to %2 (block).



# 0x3B - get\_oldpeons #
_Description:_
This command takes %1(byte) number of workers from the main to move to the expansion. Should be used only after the expansion is completed.



# 0x3C - groundmap\_jump #
_Description:_
If it is a ground map(in other words, if the enemy is reachable), jump to %1(block)



# 0x3D - place\_guard #
_Description:_
Assign one %1(unit) to guard town at position %2(byte).

## Position ##
  * 0 = Town Location Center
  * 1 = Mineral Line
  * 2 = Gas Refinery


# 0x3E - wait\_force #
_Description:_
Wait until computer commands %1(byte) %2(military)



# 0x3F - guard\_resources #
_Description:_
Send units of type %1(military) to guard as many resources spots as possible(1 per spot)



# 0x40 - call #
_Description:_
Call %1(block) as a sub-routine



# 0x41 - return #
_Description:_
Return to the flow point of the call command



# 0x42 - eval\_harass #
_Description:_
The use of this command is unknown. Takes %1(military).

**_Eval probably stands for evaluate._**


# 0x43 - creep #
_Description:_
Place towers using %1(byte) placement scheme (undefined).



# 0x44 - panic #
_Description:_
Expand in %1(block) when unmined resources reach below 7500 (not completely known). Repeats.



# 0x45 - player\_need #
_Description:_
If player does not have %1(byte) %2(buildings), build it, otherwise ignore this op.



# 0x46 - do\_morph #
_Description:_
Morph %2(military) until it commands %1(byte) of them.



# 0x47 - wait\_upgrades #
_Description:_
The use of this command is unknown. Takes no parameters.



# 0x48 - multirun #
_Description:_
Run simultaneously code at %1(block)



# 0x49 - rush #
_Description:_
Jump to %2(block) if predifined condition scheme %1(byte) is met
```
0  = // Barracks OR Spawning Pool OR Gateway (includes incomplete)
1  = // At Least 17 Marines + Bunkers, OR at least 16 Sunken Colonies + Hydralisks, OR at least 7 Zealots
2  = // At least 25 Marines + Bunkers, OR At least 11 Mutalisks + Spore Colonies + Hydralisks
3  = // At least 6 Marines + Bunkers, OR At least 3 Sunken Colonies + Hydralisks, OR Hydralisk Den?, OR at least 2 Zealots
4  = // At least 17 Marines + Bunkers, OR At least 16 Sunken Colonies + Hydralisks, OR at least 9 Zealots
5  = // At least 7 Marines + Bunkers, OR at least 7 Sunken Colonies + Hydralisks, OR at least 4 Zealots
6  = // At least 13 Marines + Bunkers, OR at least 2 Sunken Colonies, OR at least 2 Dragoons
7  = // ?? Siege Tank, OR ?? Queen, OR at most 5 Zealots.
8  = // At least 6 Marines + Bunkers, OR at least 3 Sunken Colonies + Hydralisks, OR at least 2 Zealots
9  = // At least 10 Marines + Bunkers, OR at least 5 sunken colonies + Hydralisks, OR at least 6 Zealots
10 = // At least 5 Marines + Bunkers, OR at least 5 Sunken Colonies + Hydralisks, OR at least 3 Zealots
11 = // At least 10 Marines + Bunkers, OR at least 10 Sunken Colonies + Hydralisks, OR at least 6 Zealots
12 = // At Least 17 Marines + Bunkers, OR at least 6 Mutalisks + Spore Colonies + Hydralisks, OR at least 3 Dragoons + Scouts
13 = // At least 25 Marines + Bunkers, OR at least 11 Mutalisks + Spore Colonies + Hydralisks, OR at least 8 Dragoons + Scouts
```


# 0x4A - scout\_with #
_Description:_
Takes %1(military) as parameter, but is unused(no code executed).



# 0x4B - define\_max #
_Description:_
Define maximum number of %2(unit) to %1(byte)



# 0x4C - train #
_Description:_
Train %2(military) until it commands %1(byte) of them



# 0x4D - target\_expansion #
_Description:_
Attack an enemy expansion.



# 0x4E - wait\_train #
_Description:_
Wait until computer commands %1(byte) %2(military)



# 0x4F - set\_attacks #
_Description:_
The use of this command is unknown
> Takes %1(byte) as parameter



# 0x50 - set\_gencmd #
_Description:_
Set generic command target



# 0x51 - make\_patrol #
_Description:_
Make these units patrol in selected location



# 0x52 - give\_money #
_Description:_
Give 2000 ore and gas if owned resources are low
> Should only be used in campaign scripts



# 0x53 - prep\_down #
_Description:_
The use of this command is unknown. Takes %1(byte), %2(byte), and %3(military).



# 0x54 - resources\_jump #
_Description:_
If computer has at least %1(word) minerals and %2(word) gas then jump in %3(block)



# 0x55 - enter\_transport #
_Description:_
Enter in nearest Transport in selected location



# 0x56 - exit\_transport #
_Description:_
Exit Transport in selected location



# 0x57 - sharedvision\_on #
_Description:_
Enable Shared vision for selected player



# 0x58 - sharedvision\_off #
_Description:_
Disable Shared Vision for selected player



# 0x59 - nuke\_location #
_Description:_
Nuke at selected location



# 0x5A - harass\_location #
_Description:_
AI Harass at selected location



# 0x5B - implode #
_Description:_
The use of this command is unknown. Takes no parameters.



# 0x5C - guard\_all #
_Description:_
Sends all units to guard the town.
> Takes no parameters



# 0x5D - enemyowns\_jump #
_Description:_
If enemy has a %1(unit), jump to %2(block)



# 0x5E - enemyresources\_jump #
_Description:_
If enemy has at least %1(word) minerals and %2(word) gas then jump in %3(block)



# 0x5F - if\_dif #
_Description:_
The use of this command is unknown. Takes %1(byte), %2(byte), and %3(short).

_**Probably stands for "If Different", where %3 is a block to jump to.**_


# 0x60 - easy\_attack #
_Description:_
The use of this command is unknown. Takes %1(byte) and %2(military).



# 0x61 - kill\_thread #
_Description:_
Kill the current thread



# 0x62 - killable #
_Description:_
Allows the current thread to be killed by another one



# 0x63 - wait\_finishattack #
_Description:_
Wait until attacking party has finished to attack
> (? definition ?)


# 0x64 - quick\_attack #
_Description:_
Perform a quick attack (attack\_prepare and attack\_do).



# 0x65 - junkyard\_dog #
_Description:_
Junkyard Dog at selected location



# 0x66 - fake\_nuke #
_Description:_
The use of this command is unknown
> Takes no parameters



# 0x67 - disruption\_web #
_Description:_
Disruption Web at selected location



# 0x68 - recall\_location #
_Description:_
Recall at selected location



# 0x69 - set\_randomseed #
_Description:_
Set random seed to %1(word) %2(word) (The two words are transformed in a 32-bit integer)



# 0x6A - if\_owned #
_Description:_
The use of this command is unknown
> Takes %1(unit) and %2(block) as parameters

_**This is probably known, and looks pretty obvious.**_


# 0x6B - create\_nuke #
_Description:_
Create a nuke
> Should only be used in campaign scripts



# 0x6C - create\_unit #
_Description:_
Create %1(unit) at map position (x,y) where x = %2(word) and y = %3(word)
> Should only be used in campaign scripts



# 0x6D - nuke\_pos #
_Description:_
Launch a nuke at map position (x,y) where x = %1(word) and y = %2(word)
> Should only be used in campaign scripts



# 0x6E - help\_iftrouble #
_Description:_
Ask allies help if computer is ever in trouble



# 0x6F - allies\_watch #
_Description:_
The use of this command is unknown
> Takes %1(byte) and %2(block) as parameters

_**Probably response to help\_iftrouble**_

# 0x70 - try\_townpoint #
_Description:_
The use of this command is unknown. Takes %1(byte) and %2(block) as parameters
