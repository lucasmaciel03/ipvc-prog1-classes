/*
 * 1. Implemente uma função que recebe como parâmetro um array
 * de nomes (com 100 carateres cada string) e a quantidade de 
 * nomes e coloca os nomes por ordem alfabética.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bubbleSort(char names[][100], int n) {
    int x=0, i=0;
    char aux[100];
    
    for(x=0; x<n; x++){
        for(i=0; i<n-1; i++){
            if(strcmp(names[i], names[i+1]) > 0){
                strcpy(aux, names[i]);
                strcpy(names[i], names[i+1]);
                strcpy(names[i+1], aux);
            }
        }
    
    }
}

int main() {
    char names[5][100] = {"Joao", "Maria", "Ana", "Pedro", "Ricardo"};
    int i = 0;
    bubbleSort(names, 5);
    
    for(i=0; i<5; i++){
         printf("%s\n", names[i]);
    }
    
    return 0;
    
}