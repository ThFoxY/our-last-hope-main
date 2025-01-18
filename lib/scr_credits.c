// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 18/01/2025

// Description:
    /* Initializes the credits screen:  */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// Initializes the credits screen:
void initCredits() {
    int end;
    char input_length[10];

    clearScreen();

    readLines("img/bag.txt");

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 14);
        readUniqueLine("assets/lang_en/en_strings.txt", 15);
        readUniqueLine("assets/lang_en/en_strings.txt", 16);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 14);
        readUniqueLine("assets/lang_fr/fr_strings.txt", 15);
        readUniqueLine("assets/lang_fr/fr_strings.txt", 16);
    }

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 14);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 14);
    }

    if(fgets(input_length, sizeof(input_length), stdin)) {
        if(sscanf(input_length, "%d", &end) != 1 || (end != 1)) {
            initCredits(); // Restarts the screen if an error occurs.
        }
    }
    exit(0);
}