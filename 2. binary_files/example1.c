/*
 * 
 * 1. Implement a program that asks the user for the number, name and grade of MAX students.
 * Then the program should write all the information to the binary file "NotasEI_2024.dat".
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

int receive_data(STUDENT students[]) {
    int i=0;

    for(i=0; i<MAX; i++) {
        printf("Student number: ");
        scanf("%d", &students[i].num);
        printf("Student name: ");
        scanf("%s", students[i].name);
        printf("Student grade: ");
        scanf("%f", &students[i].grade);
    }
}

int generate_data(STUDENT students[]) {
    FILE *file;
    file = fopen("NotasEI_2024.dat", "wb");

    if(file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fwrite(students, sizeof(STUDENT), MAX, file);

    fclose(file);
}

int main() {
    STUDENT students[MAX];

    int i=0;

    receive_data(students);

    generate_data(students);

    return 0;

}

