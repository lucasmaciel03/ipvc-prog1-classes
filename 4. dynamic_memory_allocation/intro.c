/*
 * Introduction to Dynamic Memory Allocation 
 *  - Dynamic memory allocation is a process of allocating memory at run time.
 *  
 * void *malloc(int qtd_bytes);
 *  - Malloc - Memory Allocation
 *  - qtd_bytes - Quantity of bytes
 *  
 * void *calloc(int qtd, int size);
 * - Calloc - Contiguous Allocation
 * - qtd - Quantity of elements
 * - size - Size of each element
 *  
 *  Example below
 *  
 *  
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *apt = NULL;
    
    apt = (char*)malloc(500);
    // When malloc is used, to release the memory allocated by malloc, free is used
    
    if (apt == NULL) {
        printf("Error to return memory\n");
        return -1;
    }
    strcpy(apt, "Viana do Castelo - Praia Norte");
    strcat(apt, "IPVC");
    printf("Apt: %s\n", apt);
    free(apt);
    // Free was used to release the memory allocated by malloc
    return 0;
    
}

