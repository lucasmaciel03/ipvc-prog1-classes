/*
 *
 * 4. Implement a program that allows the user to request and save in a text file the number, grade of the 1st test, grade of the 2nd test and practical work grade of a list of students. The name of the file should be entered by the user. The values for a student should be written on a line and should be separated by ';'. The program ends when the student number 0 is entered.
 * Example of file:
 * 2345;12;10;14
 * 1234;11;13;18
 * 2340;10;15;17
 * 4567;16;17;16
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    char filename[50];
    int number, test1, test2, practicalWork;
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    fptr = fopen(filename, "w");
    if (fptr == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    while (1)
    {
        printf("Enter the student number: ");
        scanf("%d", &number);
        if (number == 0)
        {
            break;
        }
        printf("Enter the grade of the 1st test: ");
        scanf("%d", &test1);
        printf("Enter the grade of the 2nd test: ");
        scanf("%d", &test2);
        printf("Enter the grade of the practical work: ");
        scanf("%d", &practicalWork);
        fprintf(fptr, "%d;%d;%d;%d\n", number, test1, test2, practicalWork);
    }
    fclose(fptr);
    printf("----- File created and saved successfully...\n");
    return 0;
}