/*
 * 
 * 2. Implement a program to read and store in memory the contents of the file "NotasEI_2024.dat" (created in the previous question).
 * Then it should print the contents of the file to the screen, calculate and print to the screen the average of the students' grades.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
    int num;
    char name[10];
    float grade;
} STUDENT;

int read_data(STUDENT grades[]) {
    long res = 0;
    FILE *file;
    file = fopen("NotasEI_2024.dat", "rb");

    if(file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    
    res = fread(grades, sizeof(STUDENT), MAX, file);
    fclose(file);
    printf("Total of records read: %ld\n", res);
    return res;
}

int print_data(STUDENT students[]) {
    int i=0;
    float sum=0;

    for(i=0; i<MAX; i++) {
        printf("Student number: %d\n", students[i].num);
        printf("Student name: %s\n", students[i].name);
        printf("Student grade: %.2f\n", students[i].grade);
        sum += students[i].grade;
    }

    printf("--------------------\n");
    printf("Average grade: %.2f\n", sum/MAX);
}

int main() {
    STUDENT grades[MAX];
    long qtd_reg = 0; // Quantity of records

    read_data(grades);

    print_data(grades);

    return 0;

}
