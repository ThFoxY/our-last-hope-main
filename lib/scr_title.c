// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description:
    /* Initializes the title screen: displays the title of the game and waits for player's input */

// Librairie(s):
#include <stdio.h>
#include "functions.h"

// Initializes the title screen:
void initTitleScreen() {
    int start;
    char input_length[10];

    clearScreen();

    readLines("img/title.txt"); // Displays the title.
    newLine(2);

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 3);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 3);
    }

    if(fgets(input_length, sizeof(input_length), stdin)) {
        if(sscanf(input_length, "%d", &start) != 1 || (start != 1)) {
            initTitleScreen(); // Restarts the screen if an error occurs.
        }
    }

    gameLoop(2); // Goes to the files screen.
}