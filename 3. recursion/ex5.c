/*
 * 
 * 5. Implementar um programa que leia do teclado um número inteiro positivo e 
 * escreva para o ecrã o respectivo número quadrático. Os números quadráticos são 
 * definidos pela seguinte relação de recorrência:
 * 
 * Se n=1, Q(n) = 1
 * Se  n>1, Q(n) = Q(n-1) + 2n - 1
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// function to calculate the square of a number using recursion
int square(int n){
    if (n == 1) // Q(1)=1
    {
        return 1;
    }
    else
    {
        return square(n - 1) + 2 * n - 1; // Q(n)=Q(n-1)+2n-1
        
    }
}

// function to calculate the square of a number using iteration
int square_non_recursive(int n_){
    int res = 1;
    while(n_ != 1){
        res += 2 * n_ - 1;
        n_--;
    }
    return res;
}

int main(){
    int n = 0;
    int res = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    res = square(n);
    printf("Recursion: The square of %d is %d\n", n, res);
    res = square_non_recursive(n);
    printf("Iteration: The square of %d is %d\n", n, res);
    return 0;
}

