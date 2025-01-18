// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description:
    /* Initializes the town area */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Prints out elements relative to the town:
void displayTownScreen() {
    clearScreen();

    currentScreen = 7;
    lastScreen = 3;

    readLines("img/bg_town.txt");

    hudHeader(1);
    hudElements(1);
    healthBar(playerHealth, 1);

    playerInteract = interactPlayer();
}

// Check for materials:
void initTownMaterials() {
    saveProgress += PROGRESS; // Increases the save progress;
    do{
        clearScreen();

        // Items given:
        item2 += 1;
        item4 += 5;

        currentScreen = 13; // Screen number.
        lastScreen = 3;
        
        readLines("img/bg_town.txt"); // Shows the backdrop image.

        hudHeader(1);
        hudElements(1);
        healthBar(playerHealth, 1);

        playerInteract = interactPlayer();

        switch(playerInteract) {
            case 'm':
                initMap();
                break;
            case 'i':
                initInventory();
                break;
            case 's':
                char filename[FILE_NAME_MAX_LENGTH];
                snprintf(filename, sizeof(filename), "saves/save_info%d", saveFileChosen);
                saveGame(filename);
                break;
        }
    }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 's');
}

// Check for supplies:
void initTownSupplies() {
    saveProgress += PROGRESS; // Increases the save progress;
    do{
        clearScreen();

        // Items given:
        item3 += 1;
        item2 += 1;
        playerHealth -= 1;

        currentScreen = 14; // Screen number.
        lastScreen = 3;
        
        readLines("img/bg_town.txt"); // Shows the backdrop image.

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

// Initializes the town area:
void initTownArea() {
    // Has not checked the town:
    if(item2 == 0) { // The player does not have the axe.
        do{
            displayTownScreen();
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
                    initTownSupplies();
                    break;
                case '>':
                    initTownMaterials();
                    break;
            }
        }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 's' && playerInteract != '<' && playerInteract != '>');
    }

    // Has checked the town:
    if(item2 > 0) { // Has it.
        do{
            displayTownScreen();
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
}