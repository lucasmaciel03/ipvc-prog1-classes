/*
 * Insertion Sort
 */

#include <stdio.h>
#include <stdlib.h>

int insertionSort(int values[], int n) {
    int i, j=0, aux=0;
    
    for(i=0; i<n; i++){
        aux = values[i];
        while(j>=0 && values[j] > aux){
            values[j+1] = values[j];
            j--;
        }
        values[j+1] = aux;
    }
}

int main() {
    int values[20] = {70, 25, 34, 15, 5, 60, 3, 55};
    int i = 0;
    insertionSort(values, 20);
    
    for(i=0; i<20; i++){
         printf("%d ", values[i]);
    }
    
    return 0;
    
}