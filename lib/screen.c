// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description:
    /* Functions use to print graphic elements */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// Variable(s):
int lastScreen;

// Clears the current screen:
void clearScreen() {
    #ifdef _WIN32
        // ! Windows only.
        system("cls");
    #else
        system("clear");
    #endif
}

// Creates a new line:
    /* number is an integer that specifies the number of new lines to print */
void newLine(int number) {
    for(int i = 0; i < number; i++) {
        printf("\n");
    }
}

// Creates a tabulation:
    /* number is an integer that specifies the number of tabulation to print */
void tab(int number) {
    for (int i = 0; i < number; i++) {
        printf("\t");
    }
}

// Saves the last played screen:
    /* screen is an integer that specifies the last screen played */
    //! This function is use to get back on the right screen, scene or area when looking at the map or in the inventory.
void lastPlayedScreen(int screen) {
    switch(screen) {
        // Area:
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

// Displays the HUD (Head up display):
    /* screen is an integer that specifies the current screen the player is on */
void hudHeader(int screen) {
    switch(screen) {
        case 1:
        // Area:
            if(languageChosen == 0) {
                readUniqueLine("assets/lang_en/en_hud.txt", 1);
            }else{
                readUniqueLine("assets/lang_fr/fr_hud.txt", 1);
            }
            break;
        
        case 2:
        // Map:
            if(languageChosen == 0) {
                readUniqueLine("assets/lang_en/en_hud.txt", 8);
            }else{
                readUniqueLine("assets/lang_fr/fr_hud.txt", 8);
            }
            break;
        
        case 3:
        // Inventory:
            if(languageChosen == 0) {
                readUniqueLine("assets/lang_en/en_hud.txt", 10);
            }else{
                readUniqueLine("assets/lang_fr/fr_hud.txt", 10);
            }
            break;
    }
}

// Displays specific elements for the HUD (Head up display):
void hudElements(int screen) {
    /* screen is an integer that specifies the current screen the player is on */
    switch(screen) {
        case 1:
        // Area:

            // Camp:
            if(currentScreen == 5) {
                if(item2 == 0) { // The player does not have the axe.
                    if(languageChosen == 0) {
                        readBetween("assets/lang_en/en_hud.txt", 16, 17);
                    }else{
                        readBetween("assets/lang_fr/fr_hud.txt", 16, 17);
                    }
                }else{ //! To do.
                    if(languageChosen == 0) {
                        readBetween("assets/lang_en/en_hud.txt", 16, 17);
                    }else{
                        readBetween("assets/lang_fr/fr_hud.txt", 16, 17);
                    }
                }
            }

            // Forest:
            if(currentScreen == 6) {
                if(item1 == 0) { // The player does not have the flashlight.
                    if(languageChosen == 0) {
                        readBetween("assets/lang_en/en_hud.txt", 12, 13);
                    }else{
                        readBetween("assets/lang_fr/fr_hud.txt", 12, 13);
                    }
                }else{ // The player has it.
                    if(languageChosen == 0) {
                        readBetween("assets/lang_en/en_hud.txt", 14, 15);
                    }else{
                        readBetween("assets/lang_fr/fr_hud.txt", 14, 15);
                    }
                }
            }

            // Town:
            if(currentScreen == 7) {
                if(item2 == 0) { // The player does not have the axe.
                    if(languageChosen == 0) {
                        readBetween("assets/lang_en/en_hud.txt", 24, 25);
                    }else{
                        readBetween("assets/lang_fr/fr_hud.txt", 24, 25);
                    }
                }else{ // The player has it.
                    if(languageChosen == 0) {
                        readBetween("assets/lang_en/en_hud.txt", 30, 31);
                    }else{
                        readBetween("assets/lang_fr/fr_hud.txt", 30, 31);
                    }
                }
            }

            // Town materials:
            if(currentScreen == 13) {
                if(languageChosen == 0) { // The player chooses to search for materials.
                    readBetween("assets/lang_en/en_hud.txt", 26, 27);
                }else{
                    readBetween("assets/lang_fr/fr_hud.txt", 26, 27);
                }
            }

            // Town supplies:
            if(currentScreen == 14) {
                if(languageChosen == 0) { // The player chooses to search for supplies.
                    readBetween("assets/lang_en/en_hud.txt", 32, 33);
                }else{
                    readBetween("assets/lang_fr/fr_hud.txt", 32, 33);
                }
            }

            // Park:
            if(currentScreen == 9) {
                if(item2 == 0) { // The player does not have the axe.
                    if(languageChosen == 0) {
                        readBetween("assets/lang_en/en_hud.txt", 18, 19);
                    }else{
                        readBetween("assets/lang_fr/fr_hud.txt", 18, 19);
                    }
                }else{ // The player has it.
                    if(languageChosen == 0) {
                        readBetween("assets/lang_en/en_hud.txt", 20, 21);
                    }else{
                        readBetween("assets/lang_fr/fr_hud.txt", 20, 21);
                    }
                }
            }

            // Lake:
            if(currentScreen == 8) {
                //! To do.
                    if(languageChosen == 0) {
                        readBetween("assets/lang_en/en_hud.txt", 22, 23);
                    }else{
                        readBetween("assets/lang_fr/fr_hud.txt", 22, 23);
                    }
            }

            // Mall:
            if(currentScreen == 10) {
                //! To do.
                    if(languageChosen == 0) {
                        readBetween("assets/lang_en/en_hud.txt", 28, 29);
                    }else{
                        readBetween("assets/lang_fr/fr_hud.txt", 28, 29);
                    }
            }
            break;

        case 2:
        // Map:
            if(languageChosen == 0) {
                readUniqueLine("assets/lang_en/en_hud.txt", 9);
            }else{
                readUniqueLine("assets/lang_fr/fr_hud.txt", 9);
            }
            break;

        case 3:
        // Inventory:
            if(languageChosen == 0) {
                readUniqueLine("assets/lang_en/en_hud.txt", 11);
            }else{
                readUniqueLine("assets/lang_fr/fr_hud.txt", 11);
            }
            break;
    }
}