// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description:
    /* Initializes the lake area */

// Librairie(s):
#include <stdio.h>
#include "functions.h"

// Creates the lake area:
void initLakeArea() {
    do{
        clearScreen();

        currentScreen = 8; // Screen number.
        lastScreen = 4;
        
        readLines("img/bg_lake.txt"); // Shows the backdrop image.

        hudHeader(1);
        hudElements(1);
        healthBar(playerHealth);

        playerInteract = interactPlayer();

        switch(playerInteract) {
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
    }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 'e' && playerInteract != 's');
}