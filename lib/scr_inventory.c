// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 15/01/2025

// Description:
    /* Displays the inventory of the player: only displays the items the player owns */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Constant(s):
#define MAX_ITEMS 7

// Displays an item:
void viewItem(int item) {
    /* item is an integer which represents an item */
    switch(item) {
        // Flashlight:
        case 1:
            if(item1 > 0) { // Only displays the item if the player has it at least once.
                readLanguages("assets/lang_en/en_inventory.txt", "assets/lang_fr/fr_inventory.txt", 1, 2);

                if(languageChosen == 0) { // Displays the quantity of the item:
                    printf("Quantity: %d\n", item1);
                }else{
                    printf("Quantité : %d\n", item1);
                }
                newLine(1);
            }
            break;

        // Axe:
        case 2:
            if(item2 > 0) { // Only displays the item if the player has it at least once.
                readLanguages("assets/lang_en/en_inventory.txt", "assets/lang_fr/fr_inventory.txt", 3, 4);

                if(languageChosen == 0) { // Displays the quantity of the item:
                    printf("Quantity: %d\n", item2);
                }else{
                    printf("Quantité : %d\n", item2);
                }
                newLine(1);
            }
            break;

        // Can:
        case 3:
            if(item3 > 0) { // Only displays the item if the player has it at least once.
                readLanguages("assets/lang_en/en_inventory.txt", "assets/lang_fr/fr_inventory.txt", 5, 6);

                if(languageChosen == 0) { // Displays the quantity of the item:
                    printf("Quantity: %d\n", item3);
                }else{
                    printf("Quantité : %d\n", item3);
                }
                newLine(1);
            }
            break;
        
        // Radio antenna:
        case 4:
            if(item4 > 0) { // Only displays the item if the player has it at least once.
                readLanguages("assets/lang_en/en_inventory.txt", "assets/lang_fr/fr_inventory.txt", 7, 8);

                if(languageChosen == 0) { // Displays the quantity of the item:
                    printf("Quantity: %d\n", item4);
                }else{
                    printf("Quantité : %d\n", item4);
                }
                newLine(1);
            }
            break;
        
        // Piece of paper:
        case 5:
            if(item5 > 0) { // Only displays the item if the player has it at least once.
                readLanguages("assets/lang_en/en_inventory.txt", "assets/lang_fr/fr_inventory.txt", 9, 10);

                if(languageChosen == 0) { // Displays the quantity of the item:
                    printf("Quantity: %d\n", item5);
                }else{
                    printf("Quantité : %d\n", item5);
                }
                newLine(1);
            }
            break;

        // Electric wire:
        case 6:
            if(item6 > 0) { // Only displays the item if the player has it at least once.
                readLanguages("assets/lang_en/en_inventory.txt", "assets/lang_fr/fr_inventory.txt", 11, 12);

                if(languageChosen == 0) { // Displays the quantity of the item:
                    printf("Quantity: %d\n", item6);
                }else{
                    printf("Quantité : %d\n", item6);
                }
                newLine(1);
            }
            break;
        
        // Batteries:
        case 7:
            if(item7 > 0) { // Only displays the item if the player has it at least once.
                readLanguages("assets/lang_en/en_inventory.txt", "assets/lang_fr/fr_inventory.txt", 13, 14);

                if(languageChosen == 0) { // Displays the quantity of the item:
                    printf("Quantity: %d\n", item7);
                }else{
                    printf("Quantité : %d\n", item7);
                }
                newLine(1);
            }
            break;
    }
}

// Displays all the items:
void viewAllItems() {
    for(int i = 1; i <= MAX_ITEMS; i++) {
        viewItem(i);
    }
}

// Initializes the inventory screen:
void initInventory() {
    do{
        clearScreen();

        currentScreen = 12; // Screen number.

        viewAllItems(); // Displays all the items in the inventory.

        hudHeader(3);
        hudElements(3);
        healthBar(playerHealth, 1);

        playerInteract = interactPlayer(); // Waits for player's input.

        switch(playerInteract) {
            case 'b': // Goes back to the last played screen.
                lastPlayedScreen(lastScreen);
                break;
            case 'h': // Uses heal if the player has supplies.
                useHeal();
                initInventory();
                break;
        }
    }while(playerInteract != 'b' && playerInteract != 'u');
}