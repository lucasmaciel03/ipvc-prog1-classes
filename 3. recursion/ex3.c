/*
 *
 * 3. Implement a recursive function that calculates the summation of an array of
 * integers. The numbers of the array should be introduced by the user.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// function to calculate summation using recursion
int summation(int *arr, int size){
    if (size == 0)
    {
        return 0;
    }
    else
    {
        return arr[size - 1] + summation(arr, size - 1);
    }
}

// function to calculate summation using iteration
int summation_non_recursive(int *arr_, int size_){
    int sum = 0;
    for (int i = 0; i < size_; i++)
    {
        sum += arr_[i];
    }
    return sum;
}

int main(){
    int size = 0;
    int res = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %dth number: ", i + 1);
        scanf("%d", &arr[i]);
    }
    res = summation(arr, size);
    printf("Recursion: Summation of the array is %d\n", res);
    res = summation_non_recursive(arr, size);
    printf("Iteration: Summation of the array is %d\n", res);
    return 0;
}