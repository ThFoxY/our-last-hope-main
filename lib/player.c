// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Initializes the player */

#include <stdio.h>
#include "functions.h"

#define FILE_NAME_MAX_LENGTH 20

int playerHealth;
int playerInteractINT;
char playerInteractCHAR;

// Retrieves player's health:
void healthBar(int current_hearts) {
    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_hud.txt", 4);
    }else{
        readUniqueLine("assets/lang_fr/fr_hud.txt", 4);
    }
    
    if(current_hearts == 3) {
        readUniqueLine("assets/lang_en/en_hud.txt", 5);
    }else if(current_hearts == 2) {
        readUniqueLine("assets/lang_en/en_hud.txt", 6);
    }else if(current_hearts == 1) {
        readUniqueLine("assets/lang_en/en_hud.txt", 7);
    }
}

// Gets player's name:
void getPlayerName() {
    char filename[FILE_NAME_MAX_LENGTH];
    
    snprintf(filename, sizeof(filename), "saves/save_info%d", saveFileChosen);
    readUniqueLine(filename, 1);
}

// Waits for player's input:
int interactPlayerINT() {
    int interact;

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 10);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 10);
    }
    scanf(" %d", (int*)&interact);

    return interact;
}

char interactPlayerCHAR() {
    char interact;

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 10);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 10);
    }
    scanf(" %c", (char*)&interact);

    return interact;
}