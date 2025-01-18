// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description:
    /* Initializes the mall area */

// Librairie(s):
#include <stdio.h>
#include "functions.h"

// Initializes the mall area:
void initMallArea() {
    // Has not found the batteries:
    if(item7 == 0){
        do{
            clearScreen();

            currentScreen = 10; // Screen number;
            lastScreen = 6;
            
            readLines("img/bg_mall.txt"); // Shows the backdrop image.

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

    // Has found the batteries:
    if(item7 > 0){
        do{
            clearScreen();

            currentScreen = 10; // Screen number;
            lastScreen = 6;
            
            readLines("img/bg_mall.txt"); // Shows the backdrop image.

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
                    gameLoop(22);
                    break;
                case '>':
                    //! Game over.
                    break;
            }
        }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 'e' && playerInteract != 's' && playerInteract != '<' && playerInteract != '>');
    }
}