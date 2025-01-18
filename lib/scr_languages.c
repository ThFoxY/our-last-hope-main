// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description:
    /* Initializes the language screen: the player can use between English or French */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Variable(s):
int languageChosen; // Holds the language chosen by the player (0: English, 1: French).

// Gets the language chosen by the player:
int setLanguage() {
    int lang;
    char input_length[10];

    readUniqueLine("assets/lang_en/en_strings.txt", 13);
    if(fgets(input_length, sizeof(input_length), stdin)) {
        if(sscanf(input_length, "%d", &lang) == 1 && (lang == 0 || lang == 1)) {
            return lang;
        }else{
            initLanguageScreen(); // Restarts the screen if an error occurs.
        }
    }
}

// Initializes the language screen:
void initLanguageScreen() {
    clearScreen();

    readLines("img/en_language.txt");

    newLine(1);

    readUniqueLine("assets/lang_en/en_strings.txt", 1);
    readUniqueLine("assets/lang_en/en_strings.txt", 2);

    newLine(4);
        
    languageChosen = setLanguage(); // Retrieves the language chosen by the player and saves it.

    gameLoop(1); // Goes to the title screen.
}