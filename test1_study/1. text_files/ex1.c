/*
 * 
 * Escreva um programa na linguagem C que LEIA do ficheiro de texto "Valores.txt" um conjunto
 * de número inteiros, sabendo que cada linha contém apenas um número. 
 * O programa deverá imprimir para o ecrã o somatório dos números
 */

#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "Valores.txt"

int main(){
    FILE  *fp = NULL;
    int sum=0, number;
    
    fp = fopen(FILE_NAME, "r");
    if (fp == NULL){
        printf("Error opening file");
        return -1;
    }
    
    while (fscanf(fp, "%d\n", &number) != EOF){
        sum += number;
    }

    fclose(fp);
    printf("Sum: %d\n", sum);
    
}