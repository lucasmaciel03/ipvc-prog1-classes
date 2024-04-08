/*
 *
 * 1. Escreva um programa na linguagem C que recebe, e escreve para o ficheiro “caninos.txt”,
 * o nome, a raça e a idade dos cães que participam num concurso canino.
 * O programa termina quando o utilizador introduzir a palavra “END”.
 * 
 * Σ
 */

#include <stdio.h>
#include <string.h>

#define FILE_NAME "caninos.txt" // File Name

int main() {
    FILE  *fptr;

    fptr = fopen(FILE_NAME, "w");
    char name[50], breed[50];
    int age;

    if (fptr == NULL){
        printf("Error opening file");
        return -1;
    }
    while (1){
        printf("Enter the dog name: ");
        scanf("%s", name);
        if (strcmp(name, "END") == 0){
            break;
        }
        printf("Enter the name of dog breed: ");
        scanf("%s", breed);
        printf("Enter the age of dog: ");
        scanf("%d", &age);
        fprintf(fptr, "%s;%s;%d\n", name, breed, age);
    }
    fclose(fptr);
    printf("---- File Created successfully ----\n");
    return 0;
}