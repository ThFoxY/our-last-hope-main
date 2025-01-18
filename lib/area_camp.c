// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description:
    /* Initializes the campfire area */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Initializes the camp area:
void initCampArea() {
    do{
        clearScreen();

        currentScreen = 5; // Screen number.
        lastScreen = 1;
        
        readLines("img/bg_camp.txt"); // Shows the backdrop image.

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