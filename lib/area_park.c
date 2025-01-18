// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description:
    /* Initializes the park area */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Prints out elements relative to the park:
void displayParkScreen() {
    clearScreen();

    currentScreen = 9;
    lastScreen = 5;

    readLines("img/bg_park.txt");

    hudHeader(1);
    hudElements(1);
    healthBar(playerHealth, 1);

    playerInteract = interactPlayer();
}

// Check for materials:
void initParkMaterials() {
    saveProgress += PROGRESS; // Increases the save progress;
    do{
        clearScreen();

        // Items given:
        item5 += 1;

        currentScreen = 15; // Screen number.
        lastScreen = 5;
        
        readLines("img/bg_park.txt"); // Shows the backdrop image.

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
void initParkSupplies() {
    saveProgress += PROGRESS; // Increases the save progress;
    do{
        clearScreen();

        // Items given:
        item3 += 1;
        item5 += 1;

        currentScreen = 16; // Screen number.
        lastScreen = 5;
        
        readLines("img/bg_park.txt"); // Shows the backdrop image.

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

// Initializes the park area:
void initParkArea() {
    // Has not checked the park:
    if(item5 == 0 && item2 > 0) { // The player does not have the code, but has the axe.
        do{
            displayParkScreen();
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
                    initParkSupplies();
                    break;
                case '>':
                    initParkMaterials();
                    break;   
            }
        }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 's' && playerInteract != '<' && playerInteract != '>');
    }

    // Has checked the park:
    if(item5 > 0 || item2 == 0) { // Has it.
        do{
            displayParkScreen();
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
