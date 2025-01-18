// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 18/01/2025

// Description:
    /* Initializes the gameover screen */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Initializes the gameover screen:
void initGameOver() {
    int end;
    char input_length[10];

    clearScreen();

    if(languageChosen == 0) {
        readLines("img/en_gameover.txt");  
    }else{
        readLines("img/fr_gamevoer.txt");
    }

    newLine(4);

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 18);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 18);
    }

    if(fgets(input_length, sizeof(input_length), stdin)) {
        if(sscanf(input_length, "%d", &end) != 1 || (end != 1)) {
            initGameOver(); // Restarts the screen if an error occurs.
        }
    }
    gameLoop(1); // Goes to the title screen.
}