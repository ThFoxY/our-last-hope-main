// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 15/01/2025

// Description:
    /* Initializes the map screen */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

// Constant(s):
#define TILE_WIDTH 40
#define TILE_HEIGHT 8
#define TILE_TYPES_COUNT 6

// Tiles:
char* TILE_TOWN[TILE_HEIGHT] = {
    "........................................",
    ".       ^                              .",
    ".  ^    |    #####     ^               .",
    ".  |         #0#0#     |     #####   ^ .",
    ".    #####   ##/##  ^        #0#0#   | .",
    ". ^  #0#0#          |    ^   ##/##     .",
    ". |  ##/##               |             .",
    "........................................"
};

char* TILE_MALL[TILE_HEIGHT] = {
    "........................................",
    ".          ^                           .",
    ".       ^  |       ############        .",
    ".   ^   |    ########################  .",
    ". ^ |     ^  ##0000###000000###0000##  .",
    ". |    ^  |  ##0000###00//00###0000##  .",
    ".      |                               .",
    "........................................"
};

char* TILE_PARK[TILE_HEIGHT] = {
    "........................................",
    ".         ^          ^                 .",
    ".   ^     |    o     |     ^  ^  o     .",
    ".   |   ___     _---__     |  |        .",
    ". ___---   --___      -___        ___- .",
    ".       o     ^    ^      --___---     .",
    ".             |    |               o   .",
    "........................................"
};

char* TILE_LAKE[TILE_HEIGHT] = {
    "........................................",
    ".                                      .",
    ".            ~^~^     ~^~^       ~^~^  .",
    ".  ~^~^    ~^~^          ~^~^          .",
    ".                    ~^~^         ~^~^ .",
    ".       ~^~^     ~^~^       ~^~^       .",
    ".                                      .",
    "........................................"
};

char* TILE_FOREST[TILE_HEIGHT] = {
    "........................................",
    ".                                      .",
    ".        ^    ^     ^     ^        ^   .",
    ".   ^    |    |  ^  |     |   ^    |   .",
    ".   |     ^      |     ^      |        .",
    ".     ^   |   ^    ^   |   ^     ^     .",
    ".     |       |    |       |     |     .",
    "........................................"
};

char* TILE_CAMP[TILE_HEIGHT] = {
    "........................................",
    ". CAMP                                 .",
    ".       ^   ^   #     ^        ^    ^  .",
    ".    ^  | ^ |  #*# o  |     ^  |    |  .",
    ".  ^ |    | ^   #         ^ | ^   ^    .",
    ".  |   ^    | ^     o  ^  |   |   |^   .",
    ".      |      |  o     |           |   .",
    "........................................"
};

// Tile types array:
char** TILE_TYPES[TILE_TYPES_COUNT] = {TILE_TOWN, TILE_LAKE, TILE_FOREST, TILE_MALL, TILE_PARK, TILE_CAMP};

// Generates a new random map:
void generateNewMap(char** map[MAP_ROWS][MAP_COLS]) {
    srand((unsigned int)(time(NULL)));

    for(int i = 0; i < MAP_ROWS; i++) {
        for(int j = 0; j < MAP_COLS; j++) {
            map[i][j] = NULL;
        }
    }

    map[0][0] = TILE_CAMP;
    map[MAP_ROWS - 1][MAP_COLS - 1] = TILE_MALL;

    char** mandatoryTiles[] = {TILE_FOREST, TILE_LAKE, TILE_PARK, TILE_TOWN};
    int mandatoryCount = sizeof(mandatoryTiles) / sizeof(mandatoryTiles[0]);

    for(int i = 0; i < mandatoryCount; i++) {
        int row, col;
        do{
            row = rand() % MAP_ROWS;
            col = rand() % MAP_COLS;
        }while((row == 0 && col == 0) || (row == MAP_ROWS -1 && col == MAP_COLS - 1) || map[row][col] != NULL);

        map[row][col] = mandatoryTiles[i];
    }

    for(int i = 0; i < MAP_ROWS; i++) {
        for(int j = 0; j < MAP_COLS; j++) {
            if(map[i][j] == NULL) {
                int random = rand() % TILE_TYPES_COUNT;
                map[i][j] = TILE_TYPES[random];
            }
        }
    }
}

// Displays the map:
void viewMap(char** map[MAP_ROWS][MAP_COLS]) {
    for(int row = 0; row < MAP_ROWS; row++) {
        for(int line = 0; line < TILE_HEIGHT; line++) {
            for(int col = 0; col < MAP_COLS; col++) {
                printf("%s", map[row][col][line]);
            }
        }
        printf("\n");
    }
}

// Saves map into save file:
void saveMap(char** map[MAP_ROWS][MAP_COLS], const char* filename) {
    FILE *file = fopen(filename, "w");
    if(!file) {
        perror("Error opening file for saving.");
        return;
    }

    for(int i = 0; i < MAP_ROWS; i++) {
        for(int j = 0; j < MAP_COLS; j++) {
            for(int t = 0; t < TILE_TYPES_COUNT; t++) {
                if(map[i][j] == TILE_TYPES[t]) {
                    fprintf(file, "%d ", t);
                    break;
                }
            }
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Loads map from save file:
void loadMap(char** map[MAP_ROWS][MAP_COLS], const char* filename) {
    FILE *file = fopen(filename, "r");
    if(!file) {
        perror("Error opening file for loading.");
        return;
    }

    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            int savedTile;
            if(fscanf(file, "%d", &savedTile) != 1 || savedTile < 0 || savedTile >= TILE_TYPES_COUNT) {
                map[i][j] = TILE_FOREST; // Default title if error.
            }else{
                map[i][j] = TILE_TYPES[savedTile];
            }
        }
    }
    fclose(file);
}

// Initializes the map screen:
void initMap() {
    do{
        clearScreen();

        currentScreen = 11; // Screen number.

        viewMap(map);

        hudHeader(2);
        hudElements(2);
        healthBar(playerHealth);

        playerInteract = interactPlayer();

        switch(playerInteract) {
            case 'b': // Go back to last screen.
                lastPlayedScreen(lastScreen);
                break;
            // Camp:
            case 'c':
                gameLoop(5);
                break;
            // Forest:
            case 'f':
                if(item1 > 0){
                    if(languageChosen == 0) {
                        initAreaCutscene("assets/lang_en/en_cutscenes.txt", 10, 12, 2);
                    }else{
                        initAreaCutscene("assets/lang_fr/fr_cutscenes.txt", 10, 12, 2);
                    }      
                }else{
                    gameLoop(6);
                }
                break;
            // Town:
            case 't':
                if(item2 == 0) { // The player does not have the axe.
                    if(languageChosen == 0) {
                        initAreaCutscene("assets/lang_en/en_cutscenes.txt", 1, 3, 3);
                    }else{
                        initAreaCutscene("assets/lang_fr/fr_cutscenes.txt", 1, 3, 3);
                    }
                }else{
                    gameLoop(7);
                }
                break;
            case 'l':
            // Lake:
                if(item5 == 1 && item1 == 0) {
                    if(languageChosen == 0) {
                        initAreaCutscene("assets/lang_en/en_cutscenes.txt", 7, 9, 4);
                    }else{
                        initAreaCutscene("assets/lang_fr/fr_cutscenes.txt", 7, 9, 4);
                    }
                }else{
                    gameLoop(8);
                }
                break;
            case 'p':
            // Park:
                if(item2 > 0 && item5 == 0) { // The player has the axe.
                    if(languageChosen == 0) {
                        initAreaCutscene("assets/lang_en/en_cutscenes.txt", 4, 6, 5);
                    }else{
                        initAreaCutscene("assets/lang_fr/fr_cutscenes.txt", 4, 6, 5);
                    }
                }else{
                    gameLoop(9);
                }
                break;
            case 'm':
            // Mall:
                if(item7 > 0) {
                    if(languageChosen == 0) {
                        initAreaCutscene("assets/lang_en/en_cutscenes.txt", 13, 15, 6);
                    }else{
                        initAreaCutscene("assets/lang_fr/fr_cutscenes.txt", 13, 15, 6);
                    }  
                }else{
                    gameLoop(10);
                }
                break;
        }
    }while(playerInteract != 'b' && playerInteract != 'f' && playerInteract != 't' && playerInteract != 'p' && playerInteract != 'l' && playerInteract != 'm' && playerInteract != 'c' );
}