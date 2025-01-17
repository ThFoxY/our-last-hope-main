// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description :
    /* Initializes the forest area */

#include <stdio.h>
#include "functions.h"

// Creates the forest scene:
void initForestArea() {
    do{
        clearScreen();

        currentScreen = 6; // Screen number.
        lastScreen = 2;
        
        readLines("img/bg_forest.txt"); // Shows the backdrop image.

        hudHeader(1);
        hudElements(1);
        healthBar(playerHealth);

        playerInteractCHAR = interactPlayerCHAR();

        switch(playerInteractCHAR) {
            case 'm':
                gameLoop(11);
                break;
            case 'i':
                gameLoop(12);
                break;
            case 'e':
                // Do something.
                break;
            case 's':
                // Do something.
                break;
        }
    }while(playerInteractCHAR != 'm' && playerInteractCHAR != 'i' && playerInteractCHAR != 'e' && playerInteractCHAR != 's');
}