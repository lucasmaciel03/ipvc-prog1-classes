/*
 * 
 * 1. Implement a program that writes to the text file "Curriculum.txt" the name, number, course name and lists of subjects 
 * that have already finished in the course and their respective grade. The program should write one subject on each line
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM_SUBJECTS 5 // Number of subjects
#define MAX_SUBJECT_NAME_LENGTH 50 // Maximum length of subject names
#define FILE_NAME "Curriculum.txt" // File name
// The file should be created in the same directory as the source code


int main() {
    FILE *fptr;

    // Attempt to open the file for writing
    fptr = fopen(FILE_NAME, "w");
    if (fptr == NULL) {
        perror("Failed to open file for writing"); // More descriptive error message
        return EXIT_FAILURE;
    }

    // Writing header information to the file with improved formatting
    fprintf(fptr, "Software Engineering - IPVC\n");
    fprintf(fptr, "Lucas Maciel Andrade - 27712\n\n");

    // Initializing arrays for subjects and grades
    char subjects[NUM_SUBJECTS][MAX_SUBJECT_NAME_LENGTH] = {
            "Arquitetura e Sistema de Computadores",
            "Algoritmos e Estruturas de Dados",
            "Programação II",
            "Base de Dados",
            "Redes de Computadores"
    };

    int grades[NUM_SUBJECTS] = {
            12, 15, 10, 16, 16
    };

    // Writing subjects and grades to the file with improved formatting
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        fprintf(fptr, "Disciplina: %-45s Avaliação: %2d\n", subjects[i], grades[i]); // Improved formatting
    }

    // Close the file
    fclose(fptr);

    printf("----- File created and saved successfully...\n");
    return EXIT_SUCCESS; // Use EXIT_SUCCESS for successful termination
}
