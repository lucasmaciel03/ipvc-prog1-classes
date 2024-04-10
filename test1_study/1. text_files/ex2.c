/*
 * 
 * Suponha que se pretende fazer a gestão dos participantes num seminário sobre Qualidade de 
 * Software. Implemente um programa na linguagem C que recebe do utilizador 
 * o nome, o país e idade dos participantes no seminário e os armazene no ficheiro de texto
 * "QSoft2013.txt". 
 * Após a introdução dos dados de um participante o programa deverá perguntar ao utilizador 
 * se pretende sair ou não (S/N).
 * Se o utilizador introduzir um 'S' o programa termina, caso contrário, 
 * continua a sua execução. 
 * A informação que se encontra ar-mazenada no ficheiro não pode ser perdida 
 * sempre que o programa "corre" novamente.
 */

#include <stdio.h>
#include <string.h>

#define FILE_NAME "QSoft2013.txt"

typedef struct {
    char name[50];
    char country[50];
    int age;
} User;

int main(){
    FILE  *fp = NULL;
    
    char exit[2];
    User  user;
    
    fp = fopen(FILE_NAME, "a");
    if (fp == NULL)
    {
        printf("Error opening file");
        return -1;
    }
    
    while(1){
        printf("Name: ");
        scanf("%s", user.name);
        printf("Country: ");
        scanf("%s", user.country);
        printf("Age: ");
        scanf("%d", &user.age);
        fprintf(fp, "%s;%s;%d\n", user.name, user.country, user.age);
        printf("Presente sair ou não (S/N): ");
        scanf("%s", exit);
        if (strcmp(exit, "S") == 0) {
            break;
        }
    }
    fclose(fp);
    printf("Information about user was saved");
    
}