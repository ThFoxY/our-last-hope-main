// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description:
    /* Initializes the mall area */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Prints out elements relative to the mall:
void displayMallScreen() {
    clearScreen();

    currentScreen = 10;
    lastScreen = 6;

    readLines("img/bg_mall.txt");

    hudHeader(1);
    hudElements(1);
    healthBar(playerHealth, 1);

    playerInteract = interactPlayer();
}

// Initializes the mall area:
void initMallArea() {
    // Has not found the batteries:
    if(item7 == 0){
        do{
            displayMallScreen();
            switch(playerInteract) {
                case 'm':
                    gameLoop(11);
                    break;
                case 'i':
                    gameLoop(12);
                    break;
                case 's':
                    char filename[FILE_NAME_MAX_LENGTH];
                    snprintf(filename, sizeof(filename), "saves/save_info%d", saveFileChosen);
                    saveGame(filename);
                    break;
            }
        }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 's');
    }

    // Has found the batteries:
    if(item7 > 0){
        do{
            displayMallScreen();
            switch(playerInteract) {
                case 'm':
                    gameLoop(11);
                    break;
                case 'i':
                    gameLoop(12);
                    break;
                case 's':
                    char filename[FILE_NAME_MAX_LENGTH];
                    snprintf(filename, sizeof(filename), "saves/save_info%d", saveFileChosen);
                    saveGame(filename);
                    break;
                case '<':
                    gameLoop(22);
                    break;
                case '>':
                    gameLoop(24);
                    break;
            }
        }while(playerInteract != 'm' && playerInteract != 'i' && playerInteract != 's' && playerInteract != '<' && playerInteract != '>');
    }
}