/*
 * Introduction to Sorting Algorithms
 * Selection Sort
 */

#include <stdio.h>
#include <stdlib.h>

int selectionSort(int values[], int n) {
    int i=0, j=0, aux=0, min=0;
    
    for(i=0; i<n; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(values[j] < values[min]){
                min = j;
            }
        }
        aux = values[i];
        values[i] = values[min];
        values[min] = aux;
    }
}

int main() {
    int values[20] = {70, 25, 34, 15, 5, 60, 3, 55};
    int i = 0;
    selectionSort(values, 20);
    
    for(i=0; i<20; i++){
         printf("%d ", values[i]);
    }
    
    return 0;
    
}