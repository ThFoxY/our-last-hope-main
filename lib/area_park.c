// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description :
    /* Initializes the park area */

#include <stdio.h>
#include "functions.h"

// Creates the park scene:
void initParkArea() {
    do{
        clearScreen();

        currentScreen = 9; // Screen number.
        lastScreen = 5;
        
        readLines("img/bg_park.txt"); // Shows the backdrop image.

        hudHeader(1);
        hudElements(1);
        healthBar(playerHealth);

        playerInteractCHAR = interactPlayerCHAR();

        switch(playerInteractCHAR) {
            case 'm':
                initMap();
                break;
            case 'i':
                initInventory();
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