// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 18/01/2025

// Description:
    /* Initializes the ending cutscene: wraps up the main story */

// Librairie(s):
#include <stdio.h>
#include "functions.h"

// Variable(s):
int currentFrameEnding; // Holds the current displayed frame.

// Plays a specific frame:
    /* filename takes the file path to retrieves the opening text between a start and end line, takes the next frame to display and the image shown */
void playFrameEnding(const char *filename, int startLine, int endLine, void (*nextFrame)(), const char *image) {
    int skip;
    char input_length[10];

    clearScreen();

    // Displays the image along with the text:
    readLines(image);
    readBetween(filename, startLine, endLine);

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 12);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 12);
    }

    // Waits for player's input to skip to the next frame:
    if(fgets(input_length, sizeof(input_length), stdin)) {
        if(sscanf(input_length, "%d", &skip) != 1 || (skip != 1)) {
            initEndingCutscene(); // Restarts the screen if an error occurs.
        }
    }
    nextFrame();
}

// Frame 5:
void frame5Ending() {
    currentFrameEnding = 5;

    if(languageChosen == 0) {
        playFrameEnding("assets/lang_en/en_ending.txt", 13, 24, initCredits, "img/bag.txt");
    }else{
        playFrameEnding("assets/lang_fr/fr_ending.txt", 13, 24, initCredits, "img/bag.txt");
    }
}

// Frame 4:
void frame4Ending() {
    currentFrameEnding = 4;

    if(languageChosen == 0) {
        playFrameEnding("assets/lang_en/en_ending.txt", 10, 12, frame5Ending, "img/bag.txt");
    }else{
        playFrameEnding("assets/lang_fr/fr_ending.txt", 10, 12, frame5Ending, "img/bag.txt");
    }
}

// Frame 3:
void frame3Ending() {
    currentFrameEnding = 3;

    if(languageChosen == 0) {
        playFrameEnding("assets/lang_en/en_ending.txt", 7, 9, frame4Ending, "img/bag.txt");
    }else{
        playFrameEnding("assets/lang_fr/fr_ending.txt", 7, 9, frame4Ending, "img/bag.txt");
    }
}

// Frame 2:
void frame2Ending() {
    currentFrameEnding = 2;

    if(languageChosen == 0) {
        playFrameEnding("assets/lang_en/en_ending.txt", 4, 6, frame3Ending, "img/radio_emitter.txt");
    }else{
        playFrameEnding("assets/lang_fr/fr_ending.txt", 4, 6, frame3Ending, "img/radio_emitter.txt");
    }
}

// Frame 1:
void frame1Ending() {
    currentFrameEnding = 1;

    if(languageChosen == 0) {
        playFrameEnding("assets/lang_en/en_ending.txt", 1, 3, frame2Ending, "img/bunker.txt");
    }else{
        playFrameEnding("assets/lang_fr/fr_ending.txt", 1, 3, frame2Ending, "img/bunker.txt");
    }
}

// Initializes the opening cutscene:
void initEndingCutscene() {
    clearScreen();

    frame1Ending(); // Starts with the first frame.

    gameLoop(23); // Goes to the credits.
}