# Our Last Hope
>**(01/18/25) Warning:** this game is still under work.
Supports for Linux and MacOS is currently being tested.
Some issues are likely to be fixed.

**Our Last Hope** is a interactive text game made in **C** in a single week, based in a post-apocalyptic world.

## Authors

**Made by:**
- PACE--BOULNOIS Lysandre
- MELOCCO David

## Installation

Go to the main folder and click on ```game.exe``` to launch the game.

### Compiling

Open the .zip folder, extract it, and compile it with the following command line:

**On Windows:**
```gcc game.c lib/printing.c lib/scr_title.c lib/scr_naming.c lib/scr_languages.c lib/scr_files.c lib/area_camp.c lib/reading.c lib/player.c lib/cutsc_opening.c lib/area_town.c lib/area_park.c lib/area_mall.c lib/area_lake.c lib/area_forest.c lib/scr_map.c lib/scr_inventory.c lib/cutsc_areas.c lib/cutsc_ending.c lib/scr_credits.c lib/scr_gameover.c -o game.exe```

**On Linux (Debian 12):**
```gcc game.c lib/printing.c lib/scr_title.c lib/scr_naming.c lib/scr_languages.c lib/scr_files.c lib/area_camp.c lib/reading.c lib/player.c lib/cutsc_opening.c lib/area_town.c lib/area_park.c lib/area_mall.c lib/area_lake.c lib/area_forest.c lib/scr_map.c lib/scr_inventory.c lib/cutsc_areas.c lib/cutsc_ending.c lib/scr_credits.c lib/scr_gameover.c -o game.ext```

>It will compile all the necessary libraries to launch it properly.

Then, use the following command line : ```./game.exe``` or ```./game.ext``` to launch the game.

### Prerequisites

To play the game correctly on Windows (*Linux and MacOS have it enabled by default*), please configure your command prompt to read UTF-8 characters (including emoticons) by following these steps:

1. Go to settings (```Win + U```) 
2. Time and language -> Language and region
3. Administration of language settings
4. Change regional settings
5. Enable **Beta** to use **UTF-8** encoding.
6. Restart your computer

## Controls
- m : Map 🗺️
- i : Inventory 🎒
- s : Save 💾

## Challenges

This is the list of the challenges that are

***Currently featured:***
- Add a possibility to save the progress in a file
  
**How we did it:** three save files are available. When the player starts a new game, it creates a 'save_info' file with the number of the save file chosen (between 1 and 3) and saves its data (name, map, items, health). It also creates a separate file 'map_info' which saves the randomly generated map.

- Add a method of automatic generation of the map in a random way:
  
**How we did it:** each time a new game is started, the map is randomly generated apart from the camp (always in the top-left corner of the map) and the mall (always in the bottom-right corner of the map) to emphasize that the player can't access the final area directly at the start of the game because it's too far away. However, other areas are ramdomly generated to fill the gap between the camp and the mall.

- Add an inventory management system in which you can retrieve items and use them:
  
**How we did it:** to gain time on development, the inventory only displays the items you have (when the item variable is greater than 0, it means you have this item at least once in your backpack). If you have enough cans of tomato soup, you can heal yourself!

- Manage simple typing errors:
  
**How we dit it:** if the input doesn't match the correct data type (*integer or unique character*) or value, the current scene/screen/cutscene/area will be reloaded. The player's name can be any type of characters, such as letters, numbers or special characters.

- Add a percentage of progression:
  
**How we dit it:** the progress is saved in the 'save_info' of a save file. Depending on the choices you make, the progress of your save file increases.
> (01/18/25: not included due to bugs).

- Add images throughout the game:
  
**How we did it:** every 'images' are actually .txt files. Using the ***Code Page 437 encoding***, these images blend perfectly within the apocalyptic mood.

- Use of UTF-8 encoding:
  
**How we did it:** to exploit the full power of a text-based command line interface, we've managed to include UTF-8 characters and emoticons. It helps the player navigate through its choices and constrasts with the monochrome look of a console.
