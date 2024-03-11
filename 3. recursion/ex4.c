/*
 *
 *  4. Implement a program that reads from the keyboard a positive integer and
 *  writes to the screen the respective triangular number. Triangular numbers are
 *  defined by the following recurrence relationship:
 *  
 *  If n=1, T(n)=1
 *  If n>1, T(n)=T(n-1)+n
 *  
 */ 

#include <stdio.h>
#include <stdlib.h>

// function to calculate the triangular number using recursion
int triangular(int n){
    if (n == 1) // T(1)=1
    {
        return 1;
    }
    else
    {
        return n + triangular(n - 1); // T(n)=T(n-1)+n
        // 3 + T(2) = 3 + 3 = 6
    }
}

// function to calculate the triangular number using iteration
int triangular_non_recursive(int n_){
    int res = 1;
    while(n_ != 1){
        res += n_;
        n_--;
    }
    return res;
}

int main(){
    int n = 0;
    int res = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    res = triangular(n);
    printf("Recursion: The triangular number of %d is %d\n", n, res);
    res = triangular_non_recursive(n);
    printf("Iteration: The triangular number of %d is %d\n", n, res);
    return 0;
}