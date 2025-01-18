// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description:
    /* Initializes the town area */

// Librairie(s):
#include <stdio.h>
#include "functions.h"

// Check for materials:
void initTownMaterials() {
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
        healthBar(playerHealth);

        playerInteract = interactPlayer();

        switch(playerInteract) {
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
    }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 'e' && playerInteract != 's');
}

// Check for supplies:
void initTownSupplies() {
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

// Initializes the town area:
void initTownArea() {
    // Has not checked the town:
    if(item2 == 0) { // The player does not have the axe.
        do{
            clearScreen();

            currentScreen = 7; // Screen number.
            lastScreen = 3;
            
            readLines("img/bg_town.txt"); // Shows the backdrop image.

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
                case '<':
                    initTownSupplies();
                    break;
                case '>':
                    initTownMaterials();
                    break;
            }
        }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 'e' && playerInteract != 's' && playerInteract != '<' && playerInteract != '>');
    }

    // Has checked the town:
    if(item2 > 0) { // Has it.
        do{
            clearScreen();

            currentScreen = 7; // Screen number.
            lastScreen = 3;
            
            readLines("img/bg_town.txt"); // Shows the backdrop image.

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
}