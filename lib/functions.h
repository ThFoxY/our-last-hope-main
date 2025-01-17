// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Imports all of the functions needed to launch the game.
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Constants
#define MAP_ROWS 2
#define MAP_COLS 3

// External values:

    // Retrieves chosen language (0 being English (default), 1 being French):
    extern int languageChosen;

    // Retrieves chosen save file (between 1 and 3):
    extern int saveFileChosen;

    // Retrieves player's current health:
    extern int playerHealth;

    // Retrieves player's interaction (only int):
    extern int playerInteractINT;

    // Retrieves player's interaction (only character):
    extern char playerInteractCHAR;

    // Retrieves current screen:
    extern int currentScreen;

    // Retrieves player's last screen played:
    extern int lastScreen;

    // Retrieves map:
    extern char** map[MAP_ROWS][MAP_COLS];

    // Retrieves item 1:
    extern int item1; // Flashlight.
    extern int item2; // Axe.
    extern int item3; // Can.
    extern int item4; // Radio antenna.
    extern int item5; // Monitor.

// game.c
void gameLoop();

// Mains functions:
    // scr_languages.c
void initLanguagesScreen();

    // scr_title.c
void initTitleScreen();

    // scr_files.c
void initFilesScreen();

    // scr_naming.c
void initNamingScreen();

    // cutsc_opening.c
void initOpeningCutscene();

    // area_campfire.c
void initCampFireArea();

    // area_forest.c
void initForestArea();

    // area_town.c
void initTownArea();
void initTownSupplies();
void initTownMaterials();

    // area_lake.c
void initLakeArea();

    // area_park.c
void initParkArea();

    // area_mall.c
void initMallArea();

    // scr_map.c
void initMap();
void generateNewMap();
void viewMap();
void saveMap();
void loadMap();

    // scr_inventory.c
void initInventory();

// Specific functions:
    // reading.c
void readUniqueLine();
void readBetween();
void readLines();

    // screen.c
void clearScreen();
void newLine();
void tab();
void hudHeader();
void hudElements();
void lastPlayedScreen();

    // player.c
void healthBar();
void getPlayerName();
int interactPlayerINT();
char interactPlayerCHAR();

#endif // FUNCTIONS_H