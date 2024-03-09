/*
 * Fibonacci Function was written to calculate the nth number in the Fibonacci sequence.
 * 
 * The Fibonacci sequence is a series of numbers in which each number is the sum of the two preceding ones, 
 * usually starting with 0 and 1.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// function to calculate the nth number in the Fibonacci sequence
int fibonacci(int num){
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

// function to calculate the nth number in the Fibonacci sequence using iteration
int fibonacci_non_recursive(int num_){
    int a = 0, b = 1, c = 0;
    if (num_ == 0)
    {
        return 0;
    }
    else if (num_ == 1)
    {
        return 1;
    }
    else
    {
        for (int i = 2; i <= num_; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}

int main(){
    int num = 0;
    int res = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
//    res = fibonacci(num);
    res = fibonacci_non_recursive(num);
    printf("The %dth number in the Fibonacci sequence is %d\n", num, res);
    return 0;
}