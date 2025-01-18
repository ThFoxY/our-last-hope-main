// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description:
    /* Initializes the opening cutscene: introduces the game to the player by giving context */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Variable(s):
int currentFrameOpening; // Holds the current displayed frame.

// Plays a specific frame:
    /* filename takes the file path to retrieves the opening text between a start and end line, takes the next frame to display and the image shown */
void playFrameOpening(const char *filename, int startLine, int endLine, void (*nextFrame)(), const char *image) {
    int skip;
    char input_length[10];

    clearScreen();

    // Displays the image along with the text:
    readLines(image);
    readBetween(filename, startLine, endLine);

    // Displays player's name on final frame:
    if(currentFrameOpening == 3){
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
    if(fgets(input_length, sizeof(input_length), stdin)) {
        if(sscanf(input_length, "%d", &skip) != 1 || (skip != 1)) {
            initOpeningCutscene(); // Restarts the screen if an error occurs.
        }
    }
    nextFrame();
}

// Frame 3:
void frame3Opening() {
    currentFrameOpening = 3;

    if(languageChosen == 0) {
        playFrameOpening("assets/lang_en/en_opening.txt", 7, 10, initCampArea, "img/player.txt");
    }else{
        playFrameOpening("assets/lang_fr/fr_opening.txt", 7, 10, initCampArea, "img/player.txt");
    }
}

// Frame 2:
void frame2Opening() {
    currentFrameOpening = 2;

    if(languageChosen == 0) {
        playFrameOpening("assets/lang_en/en_opening.txt", 4, 6, frame3Opening, "img/radio_emitter.txt");
    }else{
        playFrameOpening("assets/lang_fr/fr_opening.txt", 4, 6, frame3Opening, "img/radio_emitter.txt");
    }
}

// Frame 1:
void frame1Opening() {
    currentFrameOpening = 1;

    if(languageChosen == 0) {
        playFrameOpening("assets/lang_en/en_opening.txt", 1, 3, frame2Opening, "img/bomb.txt");
    }else{
        playFrameOpening("assets/lang_fr/fr_opening.txt", 1, 3, frame2Opening, "img/bomb.txt");
    }
}

// Initializes the opening cutscene:
void initOpeningCutscene() {
    saveProgress += PROGRESS; // Increases the save progress;

    clearScreen();

    frame1Opening(); // Starts with the first frame.

    gameLoop(5); // Goes to the camp area.
}