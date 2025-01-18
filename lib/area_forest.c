// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description:
    /* Initializes the forest area */

// Librairie(s):
#include <stdio.h>
#include "functions.h"

// Helped the old man:
void initForestHelp() {
    do{
        clearScreen();

        // Items given:
        item7 += 2;
        item3 -= 1;

        currentScreen = 20; // Screen number.
        lastScreen = 2;
        
        readLines("img/bg_forest.txt"); // Shows the backdrop image.

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

// Ignored the old man:
void initForestIgnore() {
    do{
        clearScreen();

        // Items given:
        item7 += 2;
        item3 -= 2;
        playerHealth -= 2;

        currentScreen = 21; // Screen number.
        lastScreen = 2;
        
        readLines("img/bg_forest.txt"); // Shows the backdrop image.

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


// Went left path:
void initLeftPath() {
    do{
        clearScreen();

        currentScreen = 18; // Screen number.
        lastScreen = 7;
        
        readLines("img/bg_forest.txt"); // Shows the backdrop image.

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
                initForestHelp();
                break;
            case '>':
                initForestIgnore();
                break;
        }
    }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 'e' && playerInteract != 's' && playerInteract != '<' && playerInteract != '>');
}

// Went right path:
void initRightPath() {
    do{
        clearScreen();

        currentScreen = 19; // Screen number.
        lastScreen = 8;
        
        readLines("img/bg_forest.txt"); // Shows the backdrop image.

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

// Initializes the forest area:
void initForestArea() {
    // Has not found the flashlight:
    if(item1 == 0 || item7 > 0) {
        do{
            clearScreen();

            currentScreen = 6; // Screen number.
            lastScreen = 2;
            
            readLines("img/bg_forest.txt"); // Shows the backdrop image.

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

    // Has found the flashlight:
    if(item1 > 0 && item7 == 0) {
        do{
            clearScreen();

            currentScreen = 6; // Screen number.
            lastScreen = 2;
            
            readLines("img/bg_forest.txt"); // Shows the backdrop image.

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
                    initLeftPath();
                    break;
                case '>':
                    initRightPath();
                    break;
            }
        }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 'e' && playerInteract != 's' && playerInteract != '<' && playerInteract != '>');
    }
}