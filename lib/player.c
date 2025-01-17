// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description:
    /* Initializes the player: holds every informations about the player */

// Librairie(s):
#include <stdio.h>
#include "functions.h"

// Constant(s):
#define FILE_NAME_MAX_LENGTH 20

// Variable(s):
int playerHealth; // Holds player's current number of hearts.
char playerInteract; // Holds player's current interaction.

// Retrieves player's health:
    /* currentHearts is an integer which represents the current number of hearts the player has */
void healthBar(int currentHearts) {
    if(languageChosen == 0) { // Displays HUD header.
        readUniqueLine("assets/lang_en/en_hud.txt", 4);
    }else{
        readUniqueLine("assets/lang_fr/fr_hud.txt", 4);
    }
    
    if(currentHearts == 3) { // If player's number of hearts is equal to 3 (max).
        readUniqueLine("assets/lang_en/en_hud.txt", 5);
    }else if(currentHearts == 2) { // If player's number of hearts is equal to 2.
        readUniqueLine("assets/lang_en/en_hud.txt", 6);
    }else if(currentHearts == 1) { // If player's number of hearts is equal to 1.
        readUniqueLine("assets/lang_en/en_hud.txt", 7);
    }
}

// Retrieves player's name:
void getPlayerName() {
    char filename[FILE_NAME_MAX_LENGTH];
    snprintf(filename, sizeof(filename), "saves/save_info%d", saveFileChosen); // Opens the right save file.

    readUniqueLine(filename, 1); // Reads the first line (which contains the player's name).
}

// Gets player's interaction:
char interactPlayer() {
    char interact;

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 10);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 10);
    }
    scanf(" %c", (char*)&interact);

    return interact;
}