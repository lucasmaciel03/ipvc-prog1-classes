/*
 * The function
 *   long fread(void *ptr, long size, long n, FILE *fp)
 *   
 *   The fread function reads n elements of size bytes each from the file and stores them in the array pointed to by ptr.
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
    res = fread(&numbers[0], sizeof(int), 10, fp);
    printf("Total of records read: %ld\n", res);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", numbers[i]);
    }
    fclose(fp);
    return 0;
}