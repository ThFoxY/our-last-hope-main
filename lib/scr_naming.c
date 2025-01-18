// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description:
    /* Initializes the naming screen: saves the player's name and starts a new game */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

// Constant(s):
#define MAP_ROWS 2
#define MAP_COLS 3

// Variable(s):
char playerName[PLAYER_NAME_MAX_LENGTH]; // Holds the player's name.
int saveProgress; // Holds the save progress.
char** map[MAP_ROWS][MAP_COLS];

// Creates a new save file:
    /* filename takes the save file path 'save_info' */
void createNewFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    fclose(file);
}

// Saves the save file:
void saveGame(const char *filename) {
    FILE *file = fopen(filename, "w");

    // Saves the player's name:
    fprintf(file, "%s\n", playerName);

    // Saves the player's health:
    fprintf(file, "%d\n", playerHealth);

    // Saves all the items:
    fprintf(file, "%d %d %d %d %d %d %d\n", item1, item2, item3, item4, item5, item6, item7);

    // Saves the progress:
    fprintf(file, "%d\n", saveProgress);

    fclose(file);
}

// Loads the save file:
void loadGame(const char *filename) {
    FILE *file = fopen(filename, "r");

    // Reads the player's name:
    fgets(playerName, PLAYER_NAME_MAX_LENGTH, file);

    // Removes the newline character at the end of the name.
    size_t len = strlen(playerName);
    playerName[strcspn(playerName, "\n")] = '\0';

    // Reads the player's health:
    fscanf(file, "%d", &playerHealth);

    // Reads all items:
    fscanf(file, "%d %d %d %d %d %d %d\n", &item1, &item2, &item3, &item4, &item5, &item6, &item7);

    // Reads the save progress:
    fscanf(file, "%d", &saveProgress);

    fclose(file);
}

// Initializes the naming screen:
void initNamingScreen() {
    clearScreen();

    if(languageChosen == 0) {
        readLines("img/en_name.txt");  
    }else{
        readLines("img/fr_name.txt");
    }

    newLine(1);

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

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 11);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 11);
    }
    scanf("%s", &playerName);

    playerHealth = 3; // Initializes player's health.

    // Initializes items:
    item1 = 0;
    item2 = 0;
    item3 = 2; // The player starts with 2 cans of tomato soup.
    item4 = 0;
    item5 = 0;
    item6 = 0;
    item7 = 0;

    // Initializes the save progress:
    saveProgress = 0;

    // Uses 'save_info' to save the player's name, the player's health, all items and save progress:
    char filename[FILE_NAME_MAX_LENGTH];
    snprintf(filename, sizeof(filename), "saves/save_info%d", saveFileChosen);
    saveGame(filename);

    generateNewMap(map); // Generates a new map.

    // Uses 'map_info' to save the map:
    char filename_map[FILE_NAME_MAX_LENGTH];
    snprintf(filename_map, sizeof(filename_map), "saves/map_info%d", saveFileChosen);
    saveMap(map, filename_map); // Saves the randomly generated map.

    gameLoop(4); // Goes to the opening cutscene.
}