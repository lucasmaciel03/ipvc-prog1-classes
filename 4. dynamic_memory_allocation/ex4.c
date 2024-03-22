/*
 * 4. Escreva um programa que leia um número inteiro positivo n e 
 * n números inteiros e imprima esses n números por ordem inversa à ordem lida do teclado. 
 * O programa não deve impor limitações sobre o valor de n e deve reservar
 * o espaço de memória estritamente necessário.
 * Exemplo de execução:
 * Introduza o número de números: 3 Introduza os números
 * 2 989 454
 * O programa deve imprimir: 454 989 2.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0;
    int *numbers = NULL;
    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    numbers = (int*)calloc(n, sizeof(int));
    if (numbers == NULL) {
        printf("Error to return memory\n");
        return -1;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter the number %d: ", i+1);
        scanf("%d", &numbers[i]);
    }
    printf("The numbers in reverse order: ");
    for (int i = n-1; i >= 0; i--) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    free(numbers);
    return 0;
}