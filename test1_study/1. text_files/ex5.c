/*
Escreva um programa na linguagem C que recebe, e escreve para o ficheiro "caninos.txt", o nome, a raça e a idade dos cães que participam num concurso canino. O programa termina quando o utilizador introduzir a palavra "END".
*/

#include <stdio.h>
#include <string.h>

#define FILE_NAME "caninos.txt"

typedef struct{
    char name[50];
    char breed[50];
    int age;
} Dog;

int main(){
    FILE *fp = NULL;

    Dog dog;

    fp = fopen(FILE_NAME, "a");

    if (fp == NULL){
        printf("Error opening file");
        return -1;
    }

    while(1){
        printf("Dog Name: ");
        scanf("%s", dog.name);
        if (strcmp(dog.name, "END") == 0){
            break;
        }
        printf("Dog Breed: ");
        scanf("%s", dog.breed);

        printf("Dog Age: ");
        scanf("%d", &dog.age);

        fprintf(fp, "%s; %s; %d\n", dog.name, dog.breed, dog.age);
    }
    fclose(fp);
    printf("Information was saved!");
    return 0;
}