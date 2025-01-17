// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description:
    /* Initializes the park area */

// Librairie(s):
#include <stdio.h>
#include "functions.h"

// Initializes the park area:
void initParkArea() {
    do{
        clearScreen();

        currentScreen = 9; // Screen number.
        lastScreen = 5;
        
        readLines("img/bg_park.txt"); // Shows the backdrop image.

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