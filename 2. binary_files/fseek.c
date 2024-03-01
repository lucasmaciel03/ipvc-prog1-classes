/*
 * The function
 *   int fseek(FILE *fp, long offset, int origin)
 *   
 *   The fseek function moves the file pointer to a new location in the file.
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
    res = fread(&numbers[0], sizeof(int), 10, fp);
    printf("Total of records read: %ld\n", res);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", numbers[i]);
    }
    fclose(fp);
    return 0;
}

