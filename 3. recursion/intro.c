/*
 * Introduction to recursion and its implementation
 * 
 *  Normally recursive functions are small and easy to understand
 *  
 *  What is recursion?
 *      Recursion is a process in which a function calls itself as a subroutine. 
 *      This allows the function to be repeated several times, since it calls itself during its execution.
 *  
 *  What is the difference between recursion and iteration?
 *      Recursion is a process, while iteration is a loop.
 *      
 *  When we should to use recursion?
 *    When the problem can be divided into smaller sub-problems of the same type.
 *    So we can solve the problem by solving the smaller sub-problems and then combining the solutions.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// function to calculate factorial using recursion
int factorial(int num){
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}

// function to calculate factorial using non-recursive method
int factorial_non_recursive(int num_){
    int result = 1;
    for (int i = 1; i <= num_; i++)
    {
        result *= i;
    }
    return result;
}

int main(){
   int num = 0;
   int res = 0;
   printf("Enter a number: ");
   scanf("%d", &num);
   res = factorial(num);
   printf("Factorial of %d is %d\n", num, res);
   return 0;
}

