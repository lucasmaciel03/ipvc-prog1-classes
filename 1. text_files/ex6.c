/*
 *
 * 6. Implement a program that allows you to read the file created in exercise 4 and
 * write to the screen:
 * a. the average of the grades per evaluation (test 1, test 2 and TP).
 * b. Number of students with the highest TP grade.
 * c. Number of students with the lowest grade on test1.
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = NULL;
    int res = 0;
    int number_of_students = 0;
    int grades[5];
    int i = 0;
    int sum = 0;
    int highest_tp = 0;
    int lowest_test1 = 20;
    int *highest_tp_indices = NULL;
    int highest_tp_count = 0;
    int *lowest_test1_indices = NULL;
    int lowest_test1_count = 0;

    fp = fopen("Avaliações", "r");
    if (fp == NULL)
    {
        printf("Error opening file");
        return -1;
    }
    while(!feof(fp))
    {
        res = fscanf(fp, "%d;%d;%d;%d", &grades[0], &grades[1], &grades[2], &grades[3]);
        if (res > 0) {
            sum += grades[1] * 0.25 + grades[2] * 0.25 + grades[3] * 0.5;
            number_of_students++;
            if (grades[3] > highest_tp)
            {
                highest_tp = grades[3];
                free(highest_tp_indices);
                highest_tp_indices = (int*)malloc(sizeof(int)); // Allocate memory for the first index
                highest_tp_indices[0] = grades[0];
                highest_tp_count = 1;
            }
            else if (grades[3] == highest_tp)
            {
                highest_tp_indices = (int*)realloc(highest_tp_indices, (highest_tp_count + 1) * sizeof(int));
                highest_tp_indices[highest_tp_count] = grades[0];
                highest_tp_count++;
            }
            if (grades[1] < lowest_test1)
            {
                lowest_test1 = grades[1];
                free(lowest_test1_indices);
                lowest_test1_indices = (int*)malloc(sizeof(int));
                lowest_test1_indices[0] = grades[0];
                lowest_test1_count = 1;
            }
            else if (grades[1] == lowest_test1)
            {
                lowest_test1_indices = (int*)realloc(lowest_test1_indices, (lowest_test1_count + 1) * sizeof(int));
                lowest_test1_indices[lowest_test1_count] = grades[0];
                lowest_test1_count++;
            }
        }
    }

    printf("Average of the grades per evaluation: %.2f\n", (float)sum / number_of_students);
    printf("Number of student(s) with the highest TP grade: ");
    for (i = 0; i < highest_tp_count; i++)
    {
        printf("%d ", highest_tp_indices[i]);
    }
    printf("\n");
    printf("Number of student(s) with the lowest grade in test1: ");
    for (i = 0; i < lowest_test1_count; i++)
    {
        printf("%d ", lowest_test1_indices[i]);
    }
    printf("\n");
    fclose(fp);
    free(highest_tp_indices);
    free(lowest_test1_indices);
    return 0;
}