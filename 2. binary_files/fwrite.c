/*
 * Different modes in binary files
 *  - "rb" - Read mode
 *  - "wb" - Write mode
 *  - "ab" - Append mode
 *  - "r+b" - Read/Write mode
 *  - "w+b" - Write/Read mode
 *  - "a+b" - Append/Read mode
 *  
 *  The function
 *      long fwrite(void *ptr, long size, long n, FILE *fp)´
 *      
 *      The fwrite function writes n elements of size bytes each from the array pointed to by ptr to the file.
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    long res = 0;
    FILE *fp = NULL;
    int values[10] = {10, 20, 0, 5, 7, 15, 7, 8, 9, 10};
    fp = fopen("example.dat", "wb"); // Open a binary file in write mode
    if (fp == NULL)
    {
        printf("Error creating file");
        return -1;
    }
    res = fwrite(&values[0], sizeof(int), 10, fp); // Write the entire array to the file
    printf("Total of records saved: %ld\n", res);
    fclose(fp);
    return 0;
}