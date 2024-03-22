/*
 * 
 * 2. Write a program to calculate the average of n numbers and print to
 * the screen the numbers below half of its average.
 * The number n is an integer entered by the user, as well as the
 * n numbers. The program should not impose limitations on the value of n and
 * should reserve memory strictly necessary.
 * 
 * Execution example:
 * Enter the number of numbers you want to enter:
 *  5
 * Enter the 5 numbers:
 *  10 4 5 25 20
 * Numbers below (12.8): 10,4,5
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0;
    int *numbers= NULL;
    float average = 0;
    int i=0;
    int j=0;
    
    printf("Insert the number of numbers you want to insert: ");
    scanf("%d", &n);
    
    numbers = (int*)calloc(n, sizeof(int));
    
    if (numbers == NULL) {
        printf("Error to return memory\n");
        return -1;
    }

    while (i < n) {
        printf("Insert the number %d: ", i+1);
        scanf("%d", &numbers[i]);
        average += numbers[i];
        i++;
    }
    average = average / n;
    printf("Numbers below (%.1f): ", average);
    for (j = 0; j < n; j++) {
        if (numbers[j] < average) {
            printf("%d ", numbers[j]); 
        }
    }
    printf("\n");
    free(numbers);
    return 0;
}