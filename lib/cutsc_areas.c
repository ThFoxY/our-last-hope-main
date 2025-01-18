// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 17/01/2025

// Description:
    /* Initializes the area cutscenes */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Skip the cutscene to the next screen:
void skipCutscene(int screen) {
    switch(screen) {
        // Camp:
        case 1:
            initCampArea();
            break;
        // Forest:
        case 2:
            initForestArea();
            break;
        // Town:
        case 3:
            initTownArea();
            break;
        // Lake:
        case 4:
            initLakeArea();
            break;
        // Park:
        case 5:
            initParkArea();
            break;
        // Mall:
        case 6:
            initMallArea();
            break;
    }
}

// Plays a cutscene between areas:
void initAreaCutscene(const char *filename, int startLine, int endLine, int nextScreen) {
    int skip;
    char input_length[10];

    clearScreen();

    readBetween(filename, startLine, endLine);

    newLine(2);

    if(languageChosen == 0) {
         readUniqueLine("assets/lang_en/en_strings.txt", 12);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 12);
    }

    // Waits for player's input to skip to the next screen:
    if(fgets(input_length, sizeof(input_length), stdin)) {
        if(sscanf(input_length, "%d", &skip) != 1 || (skip != 1)) {
            initAreaCutscene(filename, startLine, endLine, nextScreen); // Restarts the screen if an error occurs.
        }
    }
    skipCutscene(nextScreen);
}