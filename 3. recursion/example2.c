/*
 * Example of Summation from 1 to n using recursion
 *  
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// function to calculate summation using recursion
int summation(int num){
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return num + summation(num - 1);
    }
}


int main(){
    int num = 0;
    int res = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    res = summation(num);
    printf("Summation of 1 to %d is %d\n", num, res);
    return 0;
}