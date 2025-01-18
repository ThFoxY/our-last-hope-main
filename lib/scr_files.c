// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description:
    /* Displays every save files: the player can create a new save or load one */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "functions.h"

// Constant(s):
#define PLAYER_NAME_MAX_LENGTH 12
#define FILE_NAME_MAX_LENGTH 24
#define PROGRESS 10

// Variable(s):
int saveFileChosen; // Holds the save file chosen by the player.
int item1, item2, item3, item4, item5, item6, item7; // Holds the items.

// Checks if a save file already exists:
bool checkSaveFileExists(int slot) {
    /* slot is an integer that specifies the save file chosen (1 to 3) */
    char filename[FILE_NAME_MAX_LENGTH];
    snprintf(filename, sizeof(filename), "saves/save_info%d", slot);
    FILE *file = fopen(filename, "r");

    if(file) { // If it does exist:
        fclose(file);
        return true;
    } // If it does not:
    return false;
}

// Displays a specific save file:
void showSaveFile(int slot){
    /* slot is an integer that specifies the save file chosen (1 to 3) */
    char filename[FILE_NAME_MAX_LENGTH];
    snprintf(filename, sizeof(filename), "saves/save_info%d", slot);
    FILE *file = fopen(filename, "r");

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 3 + slot);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 3 + slot);
    }

    if(checkSaveFileExists(slot)) { // If a save file does exist, search for the player's name.
        // Displays the player's name:
        fgets(playerName, PLAYER_NAME_MAX_LENGTH, file);
        playerName[strcspn(playerName, "\n")] = '\0';

        if(languageChosen == 0) {
            printf("Name: %s\n", playerName);
        }else{
            printf("Nom : %s\n", playerName);
        }

        // Displays the player's health:
        if(fscanf(file, "%d", &playerHealth) == 1) {
            healthBar(playerHealth, 0);
        }

    }else{ // If it does not, displays a empty save file.
        if(languageChosen == 0) {
            readUniqueLine("assets/lang_en/en_strings.txt", 7);
        }else{
            readUniqueLine("assets/lang_fr/fr_strings.txt", 7);
        }
    }
    newLine(2);
}

// Displays all save files:
void showAllSaveFiles() {
    for(int i = 1; i <= 3; i++) {
        showSaveFile(i);
    }
}

// Gets the save file chosen by the player:
int whichSaveFile() {
    int save;
    char input_length[10];

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 8);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 8);
    }

    if(fgets(input_length, sizeof(input_length), stdin)) {
        if(sscanf(input_length, "%d", &save) == 1 && (save == 1 || save == 2 || save == 3)) {
            return save;
        }else{
            initFilesScreen(); // Restarts the screen if an error occurs.
        }
    }
}

// Deletes a save file:
void deleteSaveFile(int slot) {
    /* slot is an integer that specifies the save file chosen (1 to 3) */
    char filename[FILE_NAME_MAX_LENGTH];
    snprintf(filename, sizeof(filename), "saves/save_info%d", slot);
    remove(filename);
}

// Handles save file interactions:
void handlingSaveFile() {
    int choice;
    char input_length[10];

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 9);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 9);
    }

    if(fgets(input_length, sizeof(input_length), stdin)) {
        if(sscanf(input_length, "%d", &choice) != 1 && (choice != 1 || choice != 2 || choice != 3)) {
            initFilesScreen(); // Restarts the screen if an error occurs.
        }
    }

    switch(choice) {
        case 1:
            // Initializes a new game:
            if(!checkSaveFileExists(saveFileChosen)) {
                gameLoop(3); // Goes to the naming screen.
            }else{
                // Loads the save file:
                char filename[FILE_NAME_MAX_LENGTH];
                snprintf(filename, sizeof(filename), "saves/save_info%d", saveFileChosen);
                loadGame(filename);

                char filename_map[FILE_NAME_MAX_LENGTH];
                snprintf(filename_map, sizeof(filename_map), "saves/map_info%d", saveFileChosen);

                loadMap(map, filename_map); // Loads the map.

                gameLoop(5); // Goes to the camp area.
            }
            break;
        case 2:
            // Deletes a save file:
            deleteSaveFile(saveFileChosen);
            initFilesScreen();
            break;
        case 3:
            // Back:
            initFilesScreen();
            break;
    }
}

// Initializes the files screen:
void initFilesScreen() {
    clearScreen();

    if(languageChosen == 0) {
        readLines("img/en_saves.txt");  
    }else{
        readLines("img/fr_saves.txt");
    }

    newLine(1);

    showAllSaveFiles();

    saveFileChosen = whichSaveFile();

    handlingSaveFile();
}