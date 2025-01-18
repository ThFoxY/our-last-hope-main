// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description:
    /* Functions use to read files */

// Librairie(s):
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Constant(s):
#define MAX_LINE_LENGTH 1024

// Variable(s):
char filename[FILE_NAME_MAX_LENGTH];
char max_char[MAX_LINE_LENGTH];

// Reads an unique line:
void readUniqueLine(const char *filename, int line_nbr) {
    /* filename takes the file path and line_nbr is returning the specified line */
    FILE *file = fopen(filename, "r");

    //! Error handling:
    if (file == NULL) {
        perror("Couldn't open file.");
        return;
    }

    char buffer[MAX_LINE_LENGTH];
    int count = 0;

    while(fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        count++;
        if (count == line_nbr) {
            printf("%s", buffer);
            fclose(file);
            return;
        }
    }

    //! Error handling:
    printf("Line %d does not exist.\n", line_nbr);

    fclose(file);
}

// Reads text between a specific start and end line:
    /* filename takes the file path */
void readBetween(const char *filename, int startLine, int endLine) {
    for(int i = startLine; i <= endLine; i++) {
        readUniqueLine(filename, i);
    }
}

// Reads a complete .txt file:
    /* filename takes the file path */
void readLines(const char *filename) {
    FILE *file = fopen(filename, "r");

    //! Error handling:
    if (file == NULL) {
        perror("Couldn't open the file.");
        return ;
    }

    while(fgets(max_char, sizeof(max_char), file)) {
        printf("%s", max_char);
    }
    fclose(file);
}

// Reads a line or a set of lines depending on the language chosen:
void readLanguages(const char *en_file, const char *fr_file, int startLine, int endLine) {
        if (languageChosen == 0) {
        if (startLine == endLine) {
            readUniqueLine(en_file, startLine);
        } else {
            readBetween(en_file, startLine, endLine);
        }
    } else {
        if (startLine == endLine) {
            readUniqueLine(fr_file, startLine);
        } else {
            readBetween(fr_file, startLine, endLine);
        }
    }
}