// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 15/01/2025

// Description :
    /* Shows the inventory of the player */

#include <stdio.h>
#include "functions.h"

// Shows an item:
void viewItem(int item) {
    switch(item) {
        // Flashlight:
        case 1:
            if(item1 > 0) {
                if(languageChosen == 0) {
                    readBetween("assets/lang_en/en_inventory.txt", 1, 2);
                }else{
                    readBetween("assets/lang_fr/fr_inventory.txt", 1, 2);
                }

                if(languageChosen == 0) {
                    printf("Quantity: %d", item1);
                }else{
                    printf("Quantité : %d", item1);
                }
                newLine(1);
            }
            break;

        // Axe:
        case 2:
            if(item2 > 0) {
                if(languageChosen == 0) {
                    readBetween("assets/lang_en/en_inventory.txt", 3, 4);
                }else{
                    readBetween("assets/lang_fr/fr_inventory.txt", 3, 4);
                }

                if(languageChosen == 0) {
                    printf("Quantity: %d", item2);
                }else{
                    printf("Quantité : %d", item2);
                }
                newLine(1);
            }
            break;

        // Can:
        case 3:
            if(item3 > 0) {
                if(languageChosen == 0) {
                    readBetween("assets/lang_en/en_inventory.txt", 5, 6);
                }else{
                    readBetween("assets/lang_fr/fr_inventory.txt", 5, 6);
                }

                if(languageChosen == 0) {
                    printf("Quantity: %d", item3);
                }else{
                    printf("Quantité : %d", item3);
                }
                newLine(1);
            }
            break;
        
        // Radio antenna:
        case 4:
            if(item4 > 0) {
                if(languageChosen == 0) {
                    readBetween("assets/lang_en/en_inventory.txt", 7, 8);
                }else{
                    readBetween("assets/lang_fr/fr_inventory.txt", 7, 8);
                }

                if(languageChosen == 0) {
                    printf("Quantity: %d", item4);
                }else{
                    printf("Quantité : %d", item4);
                }
                newLine(1);
            }
            break;
        
        // Monitor:
        case 5:
            if(item5 > 0) {
                if(languageChosen == 0) {
                    readBetween("assets/lang_en/en_inventory.txt", 9, 10);
                }else{
                    readBetween("assets/lang_fr/fr_inventory.txt", 9, 10);
                }

                if(languageChosen == 0) {
                    printf("Quantity: %d", item5);
                }else{
                    printf("Quantité : %d", item5);
                }
                newLine(1);
            }
            break;
    }
}

// Shows all the items in the inventory:
void viewAllItems() {
    for(int i = 1; i <= 5; i++) {
        viewItem(i);
    }
}

// Shows the inventory:
void initInventory() {
    clearScreen();

    currentScreen = 12; // Screen number.

    viewAllItems();

    hudHeader(3);
    hudElements(3);
    healthBar(playerHealth);

    playerInteractCHAR = interactPlayerCHAR();

    switch(playerInteractCHAR) {
        case 'b': // Go back to last screen.
            lastPlayedScreen(lastScreen);
            break;
        case '1': // First object
            break;
        case '2': // Second object
            break;
        case '3': // Third object 
            break;
        case 'e': // Use the object
            break;
        case 'f': // Leave the object's choice
            break;
    }
}