/*
 * Introduction to Sorting Algorithms
 *  Bubble Sort
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubbleSort(int values[], int n) {
    int x=0, i=0, aux=0;
    
    for(x=0; x<n; x++){
        for(i=0; i<n-1; i++){
            if(values[i] > values[i+1]){
                aux = values[i];
                values[i] = values[i+1];
                values[i+1] = aux;
            }
        }
    
    }
}

int main() {
    int values[20] = {70, 25, 34, 15, 5, 60, 3, 55};
    int i = 0;
    bubbleSort(values, 20);
    
    for(i=0; i<20; i++){
         printf("%d ", values[i]);
    }
    
    return 0;
    
}
