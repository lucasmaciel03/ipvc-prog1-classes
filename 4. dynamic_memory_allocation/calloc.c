/*
 * Average of n numbers using calloc
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtd = 0, *numbers = NULL, sum = 0, i = 0, count = 0;
    float avg=0;
    printf("Enter the quantity of numbers: ");
    scanf("%i", &qtd);
    numbers = (int*)calloc(qtd, sizeof(int));
    if (numbers == NULL) {
        printf("Error reserve memory\n");
        return -1;
    }
    for (i=0; i < qtd; i++){
        printf("Enter the number %i: ", i+1);
        scanf("%i", &numbers[i]);
        sum += numbers[i];
    }
    avg = (float)sum/qtd;
    for (i=0; i < qtd; i++){
        if (numbers[i] > avg) {
            count++;
        }
    }
    printf("The quantity of numbers above the average is %i\n", count);
    free(numbers);
    return 0;

}