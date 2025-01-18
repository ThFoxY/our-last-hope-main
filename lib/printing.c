// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description:
    /* Functions use to print */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        // Camp:
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
        // Forest (left path):
        case 7:
            initLeftPath();
            break;
        // Forest (right path):
        case 8:
            initRightPath();
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
        // Areas:

            // Camp:
            if(currentScreen == 5) {
                if(item2 == 0) { // The player does not have the axe.
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 16, 17);
                }else if(item2 > 0 && item7 == 0){
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 38, 39);
                }else{
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 58, 59);
                }
            }

            // Forest:
            if(currentScreen == 6) {
                if(item1 == 0) { // The player does not have the flashlight.
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 12, 13);
                }else if(item1 > 0 && item7 == 0){ // The player has it.
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 14, 15);
                }else{ // The player has the flashlight and the batteries:
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 56, 57);
                }
            }

            // Left path:
            if(currentScreen == 18) {
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 48, 49);
            }

            // Helped the old man:
            if(currentScreen == 20) {
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 50, 51);
            }

            // Ignored the old man:
            if(currentScreen == 21) {
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 52, 53);
            }

            // Right path:
            if(currentScreen == 19) {
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 54, 55);
            }

            // Town:
            if(currentScreen == 7) {
                if(item2 == 0) { // The player does not have the axe.
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 24, 25);
                }else{ // The player has it.
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 30, 31);
                }
            }

            // Town materials:
            if(currentScreen == 13) { // The player chooses to search for materials.
                readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 26, 27);
            }

            // Town supplies:
            if(currentScreen == 14) { // The player chooses to search for supplies.
                readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 32, 33);
            }

            // Park:
            if(currentScreen == 9) {
                if(item2 == 0) { // The player does not have the axe.
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 18, 19);
                }else if(item2 > 0 && item5 == 0){ // The player has it.
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 20, 21);
                }else{ // The player has the code and the axe.
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 42, 43);
                }
            }

            // Park materials:
            if(currentScreen == 15) { // The player chooses to search for materials.
                readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 36, 37);
            }

            // Park supplies:
            if(currentScreen == 16) { // The player chooses to search 
                readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 34, 35);
            }

            // Lake:
            if(currentScreen == 8) {
                if(item5 == 0) { // The player does not have the code.
                readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 22, 23);
                }else if(item5 > 0 && item1 == 0){ // The player has it.
                readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 40, 41);
                }else{ // The player has the code and the flashlight.
                readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 46, 47);
                }
            }

            // Wooden shed:
            if(currentScreen == 17) {
                readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 44, 45);          
            }

            // Mall:
            if(currentScreen == 10) {
                if(item7 == 0) {
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 28, 29);
                }else{
                    readLanguages("assets/lang_en/en_hud.txt", "assets/lang_fr/fr_hud.txt", 60, 61);
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