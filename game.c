// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description:
    /* Initializes game events: starts the game loop */

// Librairie(s):
#include <stdio.h>
#include <locale.h>
#include "lib/functions.h"

//! Windows only:
#ifdef _WIN32
#include <windows.h>
#endif

// Variable(s):
int currentScreen; // Holds the current screen being played (screens, scenes, cutscenes or areas).

// Starts the game loop:
    /* currentScreen is a integer that takes the player to a chosen screen, scene, cutscene or area */
void gameLoop(int currentScreen) {
    int running = 1;

    while(running) {

        switch(currentScreen) {
            case 0:
                initLanguageScreen();
                break;
            case 1:
                initTitleScreen();
                break;
            case 2:
                initFilesScreen();
                break;
            case 3:
                initNamingScreen();
                break;
            case 4:
                initOpeningCutscene();
                break;
            case 5:
                initCampArea();
                break;
            case 6:
                initForestArea();
                break;
            case 7:
                initTownArea();
                break;
            case 8:
                initLakeArea();
                break;
            case 9:
                initParkArea();
                break;
            case 10:
                initMallArea();
                break;
            case 11:
                initMap();
                break;
            case 12:
                initInventory();
                break;
            case 13:
                initTownSupplies();
                break;
            case 14:
                initTownMaterials();
                break;
            default: // If an error occurs.
                running = 0;
                break;
        }
    }
}

// Starts the game:
int main(int argc, char *argv[]) {

    setlocale(LC_ALL, "");
    
    // Changes the game's window name:
    #ifdef _WIN32
        //! Windows only.
        SetConsoleTitle("Our Last Hope");
    #else
        printf("\033]0;Our Last Hope\007");
    #endif

    gameLoop(0); // Goes to the langauge screen.

    return 0;
}