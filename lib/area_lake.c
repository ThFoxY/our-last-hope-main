// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description:
    /* Initializes the lake area */

// Librairie(s):
#include <stdio.h>
#include <string.h>
#include "functions.h"

// Entered the wooden shed:
void initWoodenShed() {
    do{
        clearScreen();

        // Items given:
        item6 += 3;
        item1 += 1;

        currentScreen = 17; // Screen number.
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

// Initializes the lake area:
void initLakeArea() {
    // Has not found the piece of paper:
    if(item5 == 0 || item1 > 0) {
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

    //
    if(item5 > 0 && item1 == 0) {
        // Has found the piece of paper:
        char input[10];
        int code;

        do{
            clearScreen();

            currentScreen = 8; // Screen number.
            lastScreen = 4;
            
            readLines("img/bg_lake.txt"); // Shows the backdrop image.

            hudHeader(1);
            hudElements(1);
            healthBar(playerHealth);

            if(languageChosen == 0) {
                readUniqueLine("assets/lang_en/en_strings.txt", 10);
            }else{
                readUniqueLine("assets/lang_fr/fr_strings.txt", 10);
            }

            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';

            if(strlen(input) == 4 && sscanf(input, "%d", &code) == 1) {
                if(code == 2731) {
                    initWoodenShed();
                }else{
                    initLakeArea();
                }
            }

            else if(strlen(input) == 1) {
                playerInteract = input[0];

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
            }
        }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 'e' && playerInteract != 's');
    }
}