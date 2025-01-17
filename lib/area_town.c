// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description :
    /* Initializes the town area */

#include <stdio.h>
#include "functions.h"

// Check for supplies
void initTownMaterials() {
    do{
        clearScreen();

        item2 += 1;
        item4 += 6;

        currentScreen = 13; // Screen number.
        lastScreen = 3;
        
        readLines("img/bg_town.txt"); // Shows the backdrop image.

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

// Check for supplies
void initTownSupplies() {
    do{
        clearScreen();

        item3 += 1;
        playerHealth -= 1;

        currentScreen = 14; // Screen number.
        lastScreen = 3;
        
        readLines("img/bg_town.txt"); // Shows the backdrop image.

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

// Creates the town scene:
void initTownArea() {
    // Has not checked the town:
    if(item2 == 0) {
        do{
            clearScreen();

            currentScreen = 7; // Screen number.
            lastScreen = 3;
            
            readLines("img/bg_town.txt"); // Shows the backdrop image.

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
                case '<':
                    initTownSupplies();
                    break;
                case '>':
                    initTownMaterials();
                    break;
            }
        }while(playerInteractCHAR != 'm' && playerInteractCHAR != 'i' && playerInteractCHAR != 'e' && playerInteractCHAR != 's' && playerInteractCHAR != '<' && playerInteractCHAR != '>');
    }

    // Has checked the town:
    if(item2 > 0) {
        do{
            clearScreen();

            currentScreen = 7; // Screen number.
            lastScreen = 3;
            
            readLines("img/bg_town.txt"); // Shows the backdrop image.

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
}