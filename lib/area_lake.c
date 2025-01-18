// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description:
    /* Initializes the lake area */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int code;

// Prints out elements relative to the lake:
void displayLakeScreen() {
    clearScreen();

    currentScreen = 8;
    lastScreen = 4;

    readLines("img/bg_lake.txt");

    hudHeader(1);
    hudElements(1);
    healthBar(playerHealth, 1);
}

// Entered the wooden shed:
void initWoodenShed() {
    saveProgress += PROGRESS; // Increases the save progress;
    do{
        clearScreen();

        // Items given:
        item6 += 3;
        item1 += 1;

        currentScreen = 17; // Screen number.
        lastScreen = 4;
        
        readLines("img/bg_lake.txt"); // Shows the backdrop image.

        hudHeader(1);
        hudElements(1);
        healthBar(playerHealth, 1);

        playerInteract = interactPlayer();

        switch(playerInteract) {
            case 'm':
                gameLoop(11);
                break;
            case 'i':
                gameLoop(12);
                break;
            case 's':
                char filename[FILE_NAME_MAX_LENGTH];
                snprintf(filename, sizeof(filename), "saves/save_info%d", saveFileChosen);
                saveGame(filename);
                break;
        }
    }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 's');
}

// Initializes the lake area:
void initLakeArea() {
    // Has not found the piece of paper:
    if(item5 == 0 || item1 > 0) {
        do{
            displayLakeScreen();
            playerInteract = interactPlayer();

            switch(playerInteract) {
                case 'm':
                    gameLoop(11);
                    break;
                case 'i':
                    gameLoop(12);
                    break;
                case 's':
                    char filename[FILE_NAME_MAX_LENGTH];
                    snprintf(filename, sizeof(filename), "saves/save_info%d", saveFileChosen);
                    saveGame(filename);
                    break;
            }
        }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 's');
    }

    //
    if(item5 > 0 && item1 == 0) {
        // Has found the piece of paper:
        char input[10];
        int code;

        do{
            displayLakeScreen();

            if(languageChosen == 0) {
                readUniqueLine("assets/lang_en/en_strings.txt", 10);
            }else{
                readUniqueLine("assets/lang_fr/fr_strings.txt", 10);
            }

            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';

            if(strlen(input) == 4 && sscanf(input, "%d", &code) == 1) {
                if(code == 2731) {
                    initWoodenShed();
                }else{
                    initLakeArea();
                }
            }

            else if(strlen(input) == 1) {
                playerInteract = input[0];

                switch(playerInteract) {
                    case 'm':
                        gameLoop(11);
                        break;
                    case 'i':
                        gameLoop(12);
                        break;
                    case 's':
                        char filename[FILE_NAME_MAX_LENGTH];
                        snprintf(filename, sizeof(filename), "saves/save_info%d", saveFileChosen);
                        saveGame(filename);
                        break;
                }
            }
        }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 's');
    }
}