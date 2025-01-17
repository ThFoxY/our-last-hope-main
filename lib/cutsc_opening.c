// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description:
    /* Initializes the opening cutscene: introduces the game to the player by giving context */

// Librairie(s):
#include <stdio.h>
#include "functions.h"

// Variable(s):
int currentFrame; // Holds the current displayed frame.

// Plays a specific frame:
    /* filename takes the file path to retrieves the opening text between a start and end line, takes the next frame to display and the image shown */
void playFrame(const char *filename, int startLine, int endLine, void (*nextFrame)(), const char *image) {
    int skip;

    do{
        clearScreen();

        // Displays the image along with the text:
        readLines(image);
        readBetween(filename, startLine, endLine);

        //
        if(currentFrame == 3){
            getPlayerName();
            printf(".");
        }

        newLine(2);

        if(languageChosen == 0) {
            readUniqueLine("assets/lang_en/en_strings.txt", 12);
        }else{
            readUniqueLine("assets/lang_fr/fr_strings.txt", 12);
        }

        // Waits for player's input to skip to the next frame:
        scanf("%d", &skip);
        if(skip == 1 && nextFrame != NULL) {
            nextFrame();
        }
    }while(skip != 1);
}

// Frame 3:
void frame3() {
    currentFrame = 3;

    if(languageChosen == 0) {
        playFrame("assets/lang_en/en_opening.txt", 7, 10, initCampArea, "img/bag.txt");
    }else{
        playFrame("assets/lang_fr/fr_opening.txt", 7, 10, initCampArea, "img/bag.txt");
    }
}

// Frame 2:
void frame2() {
    currentFrame = 2;

    if(languageChosen == 0) {
        playFrame("assets/lang_en/en_opening.txt", 4, 6, frame3, "img/radio_emitter.txt");
    }else{
        playFrame("assets/lang_fr/fr_opening.txt", 4, 6, frame3, "img/radio_emitter.txt");
    }
}

// Frame 1:
void frame1() {
    currentFrame = 1;

    if(languageChosen == 0) {
        playFrame("assets/lang_en/en_opening.txt", 1, 3, frame2, "img/bunker.txt");
    }else{
        playFrame("assets/lang_fr/fr_opening.txt", 1, 3, frame2, "img/bunker.txt");
    }
}

// Initializes the opening cutscene:
void initOpeningCutscene() {
    clearScreen();

    frame1(); // Starts with the first frame.

    gameLoop(5); // Goes to the camp area.
}