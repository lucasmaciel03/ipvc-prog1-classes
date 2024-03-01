/*
 * The function
 *   long ftell(FILE *fich)
 *   
 *   The ftell function returns the current position of the file pointer in the file.
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    long res = 0;
    FILE  *fp = NULL;
    int numbers[20];
    fp = fopen("example.dat", "rb");
    if (fp == NULL)
    {
        printf("Error opening file");
        return -1;
    }
    fseek(fp, sizeof (int) * 5, 0);
    res = ftell(fp);
    printf("Current position: %ld\n", res);
    fclose(fp);
    return 0;
}
