/*
 * 7. O máximo divisor comum de dois números inteiros positivos pode ser calculado, 
 * utilizando o método de Euclides, cujo algoritmo é dado pela seguinte relação de 
 * recorrência:
 * 
 * mdc(m, n) = m, se n=0
 * 
 * mdc(m, n) = mdc(n, m%n), se n != 0
 * 
 * Escrever um programa que leia do teclado dois números inteiros positivos, calcule e 
 * escreva para o ecrã o seu máximo divisor comum. Implemente uma versão do programa 
 * usando um algoritmo iterativo e outra versão usando um algoritmo recursivo.
 */

#include <stdio.h>
#include <stdlib.h>

// function to calculate the greatest common divisor using recursion
int gcd(int m, int n){
    if (n == 0)
    {
        return m;
    }
    else
    {
        return gcd(n, m % n); // m % n is the remainder of the division of m by n
        
    }
}

// function to calculate the greatest common divisor using iteration
int gcd_non_recursive(int m_, int n_){
    int temp = 0;
    while(n_ != 0){
        temp = m_;
        m_ = n_;
        n_ = temp % n_;
    }
    return m_;
}

int main(){
    int m = 0;
    int n = 0;
    int res = 0;
    printf("Enter the first number: ");
    scanf("%d", &m);
    printf("Enter the second number: ");
    scanf("%d", &n);
    res = gcd(m, n);
    printf("Recursion: The greatest common divisor of %d and %d is %d\n", m, n, res);
    res = gcd_non_recursive(m, n);
    printf("Iteration: The greatest common divisor of %d and %d is %d\n", m, n, res);
}
