// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description:
    /* Initializes the forest area */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Prints out elements relative to the forest:
void displayForestScreen() {
    clearScreen();

    currentScreen = 6;
    lastScreen = 2;

    readLines("img/bg_forest.txt");

    hudHeader(1);
    hudElements(1);
    healthBar(playerHealth, 1);

    playerInteract = interactPlayer();
}

// Helped the old man:
void initForestHelp() {
    saveProgress += PROGRESS; // Increases the save progress;
    do{
        clearScreen();

        // Items given:
        item7 += 2;
        item3 -= 1;

        currentScreen = 20; // Screen number.
        lastScreen = 2;
        
        readLines("img/bg_forest.txt"); // Shows the backdrop image.

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

// Ignored the old man:
void initForestIgnore() {
    saveProgress += PROGRESS; // Increases the save progress;
    do{
        clearScreen();

        // Items given:
        item7 += 2;
        item3 -= 2;
        playerHealth -= 2;

        currentScreen = 21; // Screen number.
        lastScreen = 2;
        
        readLines("img/bg_forest.txt"); // Shows the backdrop image.

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


// Went left path:
void initLeftPath() {
    do{
        clearScreen();

        currentScreen = 18; // Screen number.
        lastScreen = 7;
        
        readLines("img/bg_forest.txt"); // Shows the backdrop image.

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
            case '<':
                initForestHelp();
                break;
            case '>':
                initForestIgnore();
                break;
        }
    }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 's' && playerInteract != '<' && playerInteract != '>');
}

// Went right path:
void initRightPath() {
    saveProgress += PROGRESS; // Increases the save progress;
    do{
        clearScreen();

        // Items given:
        item7 += 2;
        playerHealth += 1;

        currentScreen = 19; // Screen number.
        lastScreen = 8;
        
        readLines("img/bg_forest.txt"); // Shows the backdrop image.

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

// Initializes the forest area:
void initForestArea() {
    // Has not found the flashlight:
    if(item1 == 0 || item7 > 0) {
        do{
            displayForestScreen();
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

    // Has found the flashlight:
    if(item1 > 0 && item7 == 0) {
        do{
            displayForestScreen();
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
                case '<':
                    initLeftPath();
                    break;
                case '>':
                    initRightPath();
                    break;
            }
        }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 's' && playerInteract != '<' && playerInteract != '>');
    }
}