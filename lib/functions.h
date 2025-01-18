// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description:
    /* Imports all the functions needed: contains common components for every files to use */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Constant(s):
#define MAP_ROWS 2
#define MAP_COLS 3

// External variable(s):
    // --- General ---

        extern int languageChosen; // Chosen language.
        extern int saveFileChosen; // Chosen save file.
        extern int currentScreen; // Current screen.
        extern int lastScreen; // Last screen played.

    // --- Player ---
        extern int playerHealth;
        extern char playerInteract;

    // --- Map ---
    extern char** map[MAP_ROWS][MAP_COLS];

    // --- Items ---
    extern int item1; // Flashlight.
    extern int item2; // Axe.
    extern int item3; // Can.
    extern int item4; // Radio antenna.
    extern int item5; // Piece of paper.
    extern int item6; // Electric wires.
    extern int item7; // Batteries;

// Mains functions:
    // --- Game loop ---
        void gameLoop();

    // --- Screens ---
        void initLanguageScreen();
        void initTitleScreen();
        void initFilesScreen();
        void initNamingScreen();
        void initInventory();
        void initCredits();

    // -- Cutscenes ---
        void initOpeningCutscene();
        void initAreaCutscene();
        void initEndingCutscene();

    // --- Map ---
        void initMap();
        void generateNewMap();
        void saveMap();
        void loadMap();

    // --- Areas ---
        //! area_camp.c
        void initCampArea();

        //! area_forest.c
        void initForestArea();
        void initLeftPath();
        void initRightPath();
        void initForestHelp();
        void initForestIgnore();

        //! area_town.c
        void initTownArea();
        void initTownSupplies();
        void initTownMaterials();

        //! area_lake.c
        void initLakeArea();
        void initWoodenShed();

        //! area_park.c
        void initParkArea();
        void initParkSupplies();
        void initParkMaterials();

        //! area_mall.c
        void initMallArea();

// Specific functions:
    // --- Reading ---
    void readUniqueLine();
    void readBetween();
    void readLines();

    // --- Printing ---
    void clearScreen();
    void newLine();
    void tab();
    void hudHeader();
    void hudElements();
    void lastPlayedScreen();

    // --- Player ---
    void healthBar();
    void getPlayerName();
    char interactPlayer();

#endif // FUNCTIONS_H