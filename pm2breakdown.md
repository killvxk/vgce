# Root #

## battle ##

Contains tpl containers of common sprites seen in battles.

## e ##

Stands for Effect. Contains tpl containers.

## msg ##

Message data for events and NPCs. In each file, every string is separated by a 0x00 byte. Every two strings contains a message pair, including the reference name and the message text, in that order.

## rel ##

Don't worry too much about this. .rel files are external modules that the game reads(like DLLs) for each area of the game.

## sound ##

Obviously contains sounds. SFX and BGM data are all stored here.

## w ##

Stands for Window. Mostly contains tpl containers of images appearing in a window and not in the actual game.

## a ##

Not sure what this could possibly stand for; but contains all models and textures for the game. Files that end in a hyphen("-") are TPL containers with textures.

## b ##

Backgrounds. TPL containers with backgrounds.

## f ##
Font. Contains font data. TPL containers with common images associated with fonts and bfn font files.

## m ##

Maps. All map data is stored here.

### c ###

Camera data; format unknown.

### d ###

DAT file.

### s ###

STR file. Contains all NPC and enemy placement on the map, as well as where the battle scene will take place and what battle preset will be used.

### t ###

TPL container for the textures in the map.