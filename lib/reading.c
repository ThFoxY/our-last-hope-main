// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Reads a text file */

#include <stdio.h>
#include "functions.h"

#define FILE_NAME_MAX_LENGTH 20
#define MAX_LINE_LENGTH 1024

char filename[FILE_NAME_MAX_LENGTH];
char max_char[MAX_LINE_LENGTH];

// Reads an unique line.
void readUniqueLine(const char *filename, int line_nbr) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Couldn't open file.");
        return;
    }

    char buffer[MAX_LINE_LENGTH];
    int count = 0;

    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        count++;
        if (count == line_nbr) {
            printf("%s", buffer);
            fclose(file);
            return;
        }
    }

    printf("Line %d does not exist.\n", line_nbr);
    fclose(file);
}

// Reads text between a specific start and end line.
void readBetween(const char *filename, int startLine, int endLine) {
    for(int i = startLine; i <= endLine; i++) {
        readUniqueLine(filename, i);
    }
}

// Reads a full text.
void readLines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Couldn't open the file.");
        return ;
    }

    while (fgets(max_char, sizeof(max_char), file)) {

        printf("%s", max_char);
    }

    fclose(file);
}