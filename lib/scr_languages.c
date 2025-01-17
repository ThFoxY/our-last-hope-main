// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Initializes the language selection screen */

#include <stdio.h>
#include "functions.h"

int languageChosen;

// Retrieves chosen language (0 being English (default), 1 being French):
int chosenLanguage() {
    int lang;

    newLine(4);
    readUniqueLine("assets/lang_en/en_strings.txt", 13);
    scanf("%d", &lang);

    return lang;
}

// Creates language selection screen:
void initLanguagesScreen() {
    do{
        clearScreen();
        readUniqueLine("assets/lang_en/en_strings.txt", 1);
        readUniqueLine("assets/lang_en/en_strings.txt", 2);

        languageChosen = chosenLanguage();
    }while(languageChosen != 0 && languageChosen != 1);

    gameLoop(1);
}