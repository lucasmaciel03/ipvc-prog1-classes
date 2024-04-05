/*
 * 2. Implemente um programa que receba do utilizador o nome 
 * de 10 capitais europeias, invoque a função criada anteriormente 
 * e apresenta o resultado para o ecrã.

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
    char names[10][100];
    int i = 0;

    for(i=0; i<10; i++){
        printf("Introduza o nome da capital %d: ", i+1);
        fgets(names[i], sizeof(names[i]), stdin);
    }

    bubbleSort(names, 10);

    for(i=0; i<10; i++){
         printf("%s\n", names[i]);
    }

    return 0;

}