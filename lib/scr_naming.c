// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Initializes the naming screen */

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// Constants
#define PLAYER_NAME_MAX_LENGTH 10
#define FILE_NAME_MAX_LENGTH 20
#define MAP_ROWS 2
#define MAP_COLS 3

char** map[MAP_ROWS][MAP_COLS];

// Creates a game file structure to hold save file informations:
struct game_file {
    char player_name[PLAYER_NAME_MAX_LENGTH];
};

// Creates a new game file:
void createNewFile(const char *filename) {
    FILE *file;
    struct game_file info;

    file = fopen(filename, "w");

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 11);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 11);
    }
    scanf("%s", &info.player_name);

    fwrite(&info, sizeof(struct game_file), 1, file);
    fclose(file);
}

// Asks player's name:
void initNamingScreen() {
    clearScreen();

    switch(saveFileChosen) {
        case 1:
            createNewFile("saves/save_info1");
            break;
        case 2:
            createNewFile("saves/save_info2");
            break;
        case 3:
            createNewFile("saves/save_info3");
            break;
    }

    generateNewMap(map);

    playerHealth = 3; // Initializes player health.

    // Initializes items:
    item1 = 0;
    item2 = 0;
    item3 = 2;
    item4 = 0;
    item5 = 0;

    char filename[FILE_NAME_MAX_LENGTH];
    snprintf(filename, sizeof(filename), "saves/map_info%d", saveFileChosen);

    saveMap(map, filename);

    gameLoop(4);
}