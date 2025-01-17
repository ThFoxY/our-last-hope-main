// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description:
    /* Initializes the naming screen: saves the player's name and starts a new game */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// Constant(s):
#define PLAYER_NAME_MAX_LENGTH 10
#define FILE_NAME_MAX_LENGTH 20
#define MAP_ROWS 2
#define MAP_COLS 3

// Variable(s):
char** map[MAP_ROWS][MAP_COLS];

// Creates a game file structure to hold save file informations:
struct game_file {
    char player_name[PLAYER_NAME_MAX_LENGTH];
    int progress, item1, item2, item3, item4;
};

// Creates a new game file:
    /* filename takes the save file path 'save_info' */
void createNewFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    struct game_file info;

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 11);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 11);
    }
    scanf("%s", &info.player_name);

    fwrite(&info, sizeof(struct game_file), 1, file); // Writes the player's name in the right save file.
    fclose(file);
}

// Initializes the naming screen:
void initNamingScreen() {
    clearScreen();

    // Creates a new file depending on the save file chosen by the player:
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

    generateNewMap(map); // Generates a new map.

    playerHealth = 3; // Initializes player's health.

    // Initializes items:
    item1 = 0;
    item2 = 0;
    item3 = 2;
    item4 = 0;
    item5 = 0;

    // Uses 'map_info' to save the map:
    char filename[FILE_NAME_MAX_LENGTH];
    snprintf(filename, sizeof(filename), "saves/map_info%d", saveFileChosen);

    saveMap(map, filename); // Saves the randomly generated map.

    gameLoop(4); // Goes to the opening cutscene.
}