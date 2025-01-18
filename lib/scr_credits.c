// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 18/01/2025

// Description:
    /* Initializes the credits screen */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Initializes the credits screen:
void initCredits() {
    int end;
    char input_length[10];

    clearScreen();

    if(languageChosen == 0) {
        readLines("img/en_credits.txt");  
    }else{
        readLines("img/fr_credits.txt");
    }

    newLine(1);

    readLanguages("assets/lang_en/en_strings.txt", "assets/lang_fr/fr_strings.txt", 14, 16);

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 17);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 17);
    }

    if(fgets(input_length, sizeof(input_length), stdin)) {
        if(sscanf(input_length, "%d", &end) != 1 || (end != 1)) {
            initCredits(); // Restarts the screen if an error occurs.
        }
    }
    exit(0);
}