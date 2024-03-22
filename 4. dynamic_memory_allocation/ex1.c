/*
 *
 * 1. Implement a program that concatenates 2 strings. The program should ask the
 * user for the 1st and 2nd string and should display the two concatenated
 * strings. The input strings have no more than 99 characters. The final string
 * should occupy only the strictly necessary memory.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    char *str1 = NULL; 
    char *str2 = NULL;
    char *strFinal = NULL;
    int i = 0;
    int j = 0;
    
    str1 = (char*)calloc(100, sizeof(char));
    str2 = (char*)calloc(100, sizeof(char));
    strFinal = (char*)calloc(200, sizeof(char));
    
    if (str1 == NULL || str2 == NULL || strFinal == NULL) {
        printf("Error to return memory\n");
        return -1;
    }
    
    printf("Insert the 1st string: ");
    fgets(str1, 100, stdin);
    printf("Insert the 2nd string: ");
    fgets(str2, 100, stdin);
    
    while (str1[i] != '\0') {
        strFinal[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') {
        strFinal[i] = str2[j];
        i++;
        j++;
    }
    
    printf("Concatenated string: %s\n", strFinal);
    
    free(str1);
    free(str2);
    free(strFinal);
    
    return 0;
}