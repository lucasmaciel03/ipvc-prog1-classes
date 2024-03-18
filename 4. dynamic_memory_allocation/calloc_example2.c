/*
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *city = NULL;
    
    city = (char*)calloc(10, sizeof(char));

    if (city == NULL) {
        printf("Error to return memory\n");
        return -1;
    }
    strcpy(city, "Viana");
    city = (char*)realloc(city, 50);
    if (city == NULL) {
        printf("Error to return memory\n");
        return -1;
    } else {
        strcat(city, " do Castelo, Av. do Atlântico");
        printf("City: %s\n", city);
        free(city);
        return 0;
    }
}

