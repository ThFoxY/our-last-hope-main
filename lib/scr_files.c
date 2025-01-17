// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Retrieves every save files */

#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

#define PLAYER_NAME_MAX_LENGTH 10
#define FILE_NAME_MAX_LENGTH 20

// Holds the save file chosen by the player:
int saveFileChosen;

// Holds items:
int item1, item2, item3, item4, item5;

// Creates a game file structure to hold save file informations:
struct game_file {
    char player_name[PLAYER_NAME_MAX_LENGTH];
};

// Checks if a save file already exist:
bool checkSaveFileExists(int slot) {
    char filename[FILE_NAME_MAX_LENGTH];
    snprintf(filename, sizeof(filename), "saves/save_info%d", slot);
    FILE *file = fopen(filename, "r");

    if(file) {
        fclose(file);
        return true;
    }
    return false;
}

// Shows a specific save file:
void showSaveFile(int slot){
    char filename[FILE_NAME_MAX_LENGTH];
    char line[PLAYER_NAME_MAX_LENGTH];
    struct game_file info;

    snprintf(filename, sizeof(filename), "saves/save_info%d", slot);
    FILE *file = fopen(filename, "r");

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 3 + slot);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 3 + slot);
    }

    if(checkSaveFileExists(slot)) {
        if(file && fgets(line, sizeof(line), file) != NULL) {
            sscanf(line, "%s", info.player_name);
            if(languageChosen == 0) {
                printf("Name: %s\n", info.player_name);
            }else{
                printf("Nom : %s\n", info.player_name);
            }
        }
    }else{
        if(languageChosen == 0) {
            printf("New game\n");
        }else{
            printf("Nouvelle partie\n");
        }
    }
    newLine(2);
}

// Shows all save files:
void showAllSaveFiles() {
    for(int i = 1; i <= 3; i++) {
        showSaveFile(i);
    }
}

int whichSaveFile() {
    int save;

    do{
        if(languageChosen == 0) {
            readUniqueLine("assets/lang_en/en_strings.txt", 8);
        }else{
            readUniqueLine("assets/lang_fr/fr_strings.txt", 8);
        }
        scanf("%d", &save);
    }while(save < 1 || save > 3);

    return save;
}

// Deletes a save file:
void deleteSaveFile(int slot) {
    char filename[FILE_NAME_MAX_LENGTH];
    snprintf(filename, sizeof(filename), "saves/save_info%d", slot);
    remove(filename);
}

// Handles save file interactions:
void choiceSaveFile() {
    int choice;

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 9);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 9);
    }
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if(!checkSaveFileExists(saveFileChosen)) {
                // Initializes a new game:
                
                gameLoop(3);
            }else{
                // Loads the save file:

                char filename[FILE_NAME_MAX_LENGTH];
                snprintf(filename, sizeof(filename), "saves/map_info%d", saveFileChosen);

                loadMap(map, filename); // Loads the map.

                gameLoop(5);
            }
            break;
        case 2:
            deleteSaveFile(saveFileChosen);
            initFilesScreen();
            break;
        case 3:
            initFilesScreen();
            break;
    }
}

// Creates a files screen:
void initFilesScreen() {
    clearScreen();

    showAllSaveFiles();

    saveFileChosen = whichSaveFile();

    choiceSaveFile();
}