# Our Last Hope (WIP)
>**Warning:** this game is still under work.
Supports for Linux and MacOS will be included afterwards.

**Our Last Hope** is a interactive text game made in **C** based in a post-apocalyptic world.

## To do:

- Window resizing.
- Ensure player's input can not break the game.
- Use items in inventory.
- Add comments, make sure everything is correctly labelled.

## Authors

**Made by:**
- PACE--BOULNOIS Lysandre
- MELOCCO David

## Installation

Go to the main folder and click on ```game.exe``` to launch the game (Windows only for now).

### Compiling

Open the .zip folder, extract it, and compile it with the following command line:

```gcc game.c lib/screen.c lib/scr_title.c lib/scr_naming.c lib/scr_languages.c lib/scr_files.c lib/area_camp.c lib/reading.c lib/player.c lib/cutsc_opening.c lib/area_town.c lib/area_park.c lib/area_mall.c lib/area_lake.c lib/area_forest.c lib/scr_map.c lib/scr_inventory.c -o game.exe```

>It will compile all the necessary libraries (for now) to launch it properly.

Then, use the following command line : ```./game.exe``` to launch the game.


### Prerequisites

To play the game correctly, please configure your command prompt to read UTF-8 characters by following these steps:

1. Go to settings (```Win + U```) 
2. Time and language -> Language and region
3. Administration of language settings
4. Change regional settings
5. Enable **Beta** to use **UTF-8** encoding.
6. Restart your computer

## Controls
- e : Interact 👉
- m : Map 🗺️
- i : Inventory 🎒
- s : Save 💾

>Theses settings are likely to be changed in further versions.

## Challenges

This is the list of the challenges that are

***currently featured:***
- Add a possibility to save the progress in a file.
**How we did it:** three save files are available. When the player starts a new game, it creates a 'save_info' file with the number of the save file chosen (between 1 and 3) and saves its data (name, map, items, health). It also creates a separate file 'map_info' which saves the randomly generated map.

- Add a method of automatic generation of the map in a random way.
**How we did it:** each time a new game is started, the map is randomly generated apart from the camp (always in the top-left corner of the map) and the mall (always in the bottom-right corner of the map) to emphasize that the player can't access the final area directly at the start of the game because it's too far away. However, other areas are ramdomly generated to fill the gap between the camp and the mall.

- Add an inventory management system in which you can retrieve items and use them.
**How we did it:** to gain time on development, the inventory only displays the items you have (when the item variable is greater than 0, it means you have this item at least once in your backpack).

***partially featured:***
- Manage simple typing errors (uppercase instead of lowercase).

***likely to be featured:***
- Add a percentage of progression.
- Random in-game events (traps, attacks, sicknesses, weather conditions...)
- Add in-game events based on the player current game time.
- Add a virtual economy that allows you to buy or sell items based on their rarity.
- Add non-player characters with more advanced behaviors, able to react to the player’s actions.
