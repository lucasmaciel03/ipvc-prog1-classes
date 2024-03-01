/*
 *
 * 5. Implement a program that allows you to read the file created in the previous exercise (ex4.c) 
 * and send to the screen the number of students with a positive Final Grade (NF), knowing that NF = 25% test1 + 25% test2 + 50% TP. In the end, 
 * it should present the number of approved students.
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fptr;
    char filename[50];
    int number, test1, test2, practicalWork;
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    int approved = 0;
    while (fscanf(fptr, "%d;%d;%d;%d\n", &number, &test1, &test2, &practicalWork) != EOF)
    {
        int finalGrade = test1 * 0.25 + test2 * 0.25 + practicalWork * 0.5;
        if (finalGrade >= 9.5)
        {
            printf("Student number: %d, Final Grade: %d\n", number, finalGrade);
            approved++;
        }
    }
    printf("Approved students: %d\n", approved);
    fclose(fptr);
    return 0;
}