// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description:
    /* Initializes the park area */

// Librairie(s):
#include <stdio.h>
#include "functions.h"

// Check for materials:
void initParkMaterials() {
    do{
        clearScreen();

        // Items given:
        item5 += 1;

        currentScreen = 15; // Screen number.
        lastScreen = 5;
        
        readLines("img/bg_park.txt"); // Shows the backdrop image.

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
void initParkSupplies() {
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

// Initializes the park area:
void initParkArea() {
    // Has not checked the park:
    if(item5 == 0 && item2 > 0) { // The player does not have the code, but has the axe.
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
                case '<':
                    initParkSupplies();
                    break;
                case '>':
                    initParkMaterials();
                    break;   
            }
        }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 'e' && playerInteract != 's' && playerInteract != '<' && playerInteract != '>');
    }

    // Has checked the park:
    if(item5 > 0 || item2 == 0) { // Has it.
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
}
