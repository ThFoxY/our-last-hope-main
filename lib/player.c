// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description:
    /* Initializes the player: holds every informations about the player */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Variable(s):
int playerHealth; // Holds player's current number of hearts.
char playerInteract; // Holds player's current interaction.

// Retrieves player's health:
    /* currentHearts is an integer which represents the current number of hearts the player has */
void healthBar(int currentHearts, int displayerHeader) {
    if(displayerHeader == 1) {
        if(languageChosen == 0) { // Displays HUD header.
            readUniqueLine("assets/lang_en/en_hud.txt", 4);
        }else{
            readUniqueLine("assets/lang_fr/fr_hud.txt", 4);
        }
    }

    // If player's number of hearts is equal to 0 (min).
    if(playerHealth <= 0) {
        playerHealth = 0;
        initGameOver(); // Goes to the game over screen.
    }

    switch(playerHealth) {
        case 3: // If player's number of hearts is equal to 3 (max).
            readUniqueLine("assets/lang_en/en_hud.txt", 5);
            break;
        case 2: // If player's number of hearts is equal to 2.
            readUniqueLine("assets/lang_en/en_hud.txt", 6);
            break;
        case 1: // If player's number of hearts is equal to 1.
            readUniqueLine("assets/lang_en/en_hud.txt", 7);
            break;
    }
}

// Heals the player:
void useHeal(int currentHearts) {
    if(item3 > 0) {
        if(playerHealth < 3) {
            item3 -= 1;
            playerHealth += 1;
        }
    } 
}

// Retrieves player's name:
void getPlayerName() {
    char filename[FILE_NAME_MAX_LENGTH];
    snprintf(filename, sizeof(filename), "saves/save_info%d", saveFileChosen); // Opens the right save file.
    FILE *file = fopen(filename, "r");

    fgets(playerName, PLAYER_NAME_MAX_LENGTH, file);
    playerName[strcspn(playerName, "\n")] = '\0'; // Supprime le retour à la ligne.

    printf(playerName);
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