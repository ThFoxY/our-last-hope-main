// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Initializes the campfire area */

#include <stdio.h>
#include "functions.h"

// Creates the camp scene:
void initCampFireArea() {
    do{
        clearScreen();

        currentScreen = 5; // Screen number.
        lastScreen = 1;
        
        readLines("img/bg_campfire.txt"); // Shows the backdrop image.

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