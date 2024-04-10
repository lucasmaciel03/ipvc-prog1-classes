/*
 * 
 * Suponha que no array de caracteres canoistas|250/[100), declarado local à 
 * função main, estão armazenados os nomes dos canoístas inscritos na FPC 
 * (Federação Portuguesa de Canoagem) no ano 2018.
 * 
 *  Implemente a função write Canoistas(...) que escreve para o ficheiro de 
 *  texto canoistas2018.txt os nomes dos canoistas (um em cada linha) armazenados 
 *  no array canoistas.
 *  
 *  Implemente a função ordenaCanoistas (...) que, coloca os nomes dos 
 *  canoístas ordenados por ordem alfabética.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANOISTAS 100

#define FILE_NAME "canoistas2018.txt"

typedef struct{
    char name[50]
} Canoista;

void writeCanoistas(Canoista *canoistas){ // * is used to pass the struct by reference
    FILE  *fp = NULL;
    
    fp = fopen(FILE_NAME, "a");
    
    char exit[2];
    
    if (fp == NULL){
        printf("Error opening file");
        return;
    }
    
    while(1){
        printf("Nome do Canoista: ");
        scanf("%s", canoistas->name);
        fprintf(fp, "%s\n", canoistas->name); // O -> é usado para aceder a um membro de uma struct apontada por um ponteiro
        printf("Presente sair ou não (S/N): ");
        scanf("%s", exit);
        if (strcmp(exit, "S") == 0) {
            printf("Information was saved");
            fclose(fp);
            return;
        }
    }

}

void ordenaCanoistas() {
    Canoista canoistas[MAX_CANOISTAS];
    int n = 0; // Contador para o número de canoístas lidos

    // Abrir arquivo para leitura
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    // Ler os nomes dos canoístas do arquivo
    while(fscanf(fp, "%49[^\n]\n", canoistas[n].name) != EOF && n < MAX_CANOISTAS - 1) {
        n++;
    }
    fclose(fp);

    // Ordenar os canoístas por nome usando o algoritmo de Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(canoistas[j].name, canoistas[j + 1].name) > 0) {
                Canoista temp = canoistas[j];
                canoistas[j] = canoistas[j + 1];
                canoistas[j + 1] = temp;
            }
        }
    }

    // Imprimir os nomes ordenados no ecrã
    printf("Canoistas por ordem alfabética:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", canoistas[i].name);
    }
    
    return;
}
int main(){
    char option;
    Canoista canoistas;
    
    while(1){
        printf("Escolha uma opção: \n");
        printf("1. Adicionar Canoista \n");
        printf("2. Ordenar Canoistas \n");
        printf("3. Sair \n");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                writeCanoistas(&canoistas);
                break;
            case '2':
                ordenaCanoistas();
                break;
            case '3':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option...\n");
                break;
        }
        
    }
    
}