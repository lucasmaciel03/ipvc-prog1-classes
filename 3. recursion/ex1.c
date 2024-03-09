/*
 *  
 * 1. Develop a program that, giving the value of x and y, calculates xy using
 * recursion. Unrecursive the function implemented previously.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// function to calculate x^y using recursion
int power(int x, int y){
    if (y == 0)
    {
        return 1;
    }
    else
    {
        return x * power(x, y - 1);
    }
}

int main(){
    int x = 0, y = 0;
    int res = 0;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);
    res = power(x, y);
    printf("%d^%d is %d\n", x, y, res);
    return 0;
}