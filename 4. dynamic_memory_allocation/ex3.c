/*
 * 
 * 3. Implement a program that accepts user values and saves them in a vector,
 * dynamically allocated.
 * Reading ends when the user enters the value 0 (zero).
 * After reading, the program should present the sum of the vector values.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *numbers = NULL;
    int i = 0;
    int sum = 0;
    int value = 1;
    
    numbers = (int*)calloc(1, sizeof(int));
    
    if (numbers == NULL) {
        printf("Error to return memory\n");
        return -1;
    }
    
    while (value != 0) {
        printf("Insert a number: ");
        scanf("%d", &value);
        if (value != 0) {
            numbers[i] = value;
            i++;
            numbers = (int*)realloc(numbers, (i+1)*sizeof(int)); 
            if (numbers == NULL) {
                printf("Error to return memory\n");
                return -1;
            }
        }
    }
    for (int j = 0; j < i; j++) {
        sum += numbers[j];
    }
    printf("Sum of the numbers: %d\n", sum);
    free(numbers);
    return 0;
}