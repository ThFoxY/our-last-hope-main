// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Initializes the title screen */
    
#include <stdio.h>
#include "functions.h"

// Creates title screen:
void initTitleScreen() {
    int option = 0;

    do{
        clearScreen();

        readLines("img/title.txt");
        newLine(2);

        if(languageChosen == 0) {
            readUniqueLine("assets/lang_en/en_strings.txt", 3);
        }else{
            readUniqueLine("assets/lang_fr/fr_strings.txt", 3);
        }

        scanf("%d", &option);
    }while(option != 1);

    gameLoop(2);
}