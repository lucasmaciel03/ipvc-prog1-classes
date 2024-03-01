/*
 *
 * 3. Implement a program that writes to the text file "numMul7.txt" the numbers that are multiples of 7 between 300 and 600. 
 * Write one number on each line.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    fptr = fopen("numMul7.txt", "w");
    if (fptr == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    for (int i = 300; i <= 600; i++)
    {
        if (i % 7 == 0) // 
        {
            fprintf(fptr, "%d\n", i);
        }
    }
    fclose(fptr);
    printf("----- File created and saved successfully...\n");
    return 0;
}