/*
 * 
 * Write a program to receive the number, name and grade(decimal) of n students,
 * calculate the average of the grades and print to the screen the information of the students with
 * grade above the average.
 * The number of students (n) is entered by the user.
 * The program should not impose limitations on the number of students and should
 * reserve memory strictly necessary.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct students{
    int number;
    char name[100];
    float grade;
} Student;

int main(){
    int qtd = 0, i = 0, sum = 0, count = 0;
    float avg=0;
    Student *students = NULL;
    printf("Enter the quantity of students: \n");
    scanf("%i", &qtd); // %i is used to read an integer
    students = (Student*)calloc(qtd, sizeof(Student));
    if (students == NULL) {
        printf("Error reserve memory\n");
        return -1;
    }
    for (i=0; i < qtd; i++){
        printf("Enter the number of the student %i: ", i+1);
        scanf("%i", &students[i].number);
        printf("Enter the name of the student %i: ", i+1);
        scanf("%s", students[i].name);
        printf("Enter the grade of the student %i: ", i+1);
        scanf("%f", &students[i].grade);
        sum += students[i].grade;
    }
    avg = (float)sum/qtd;
    printf("The average is %.2f\n", avg);
    printf("The students with grade above the average are:\n");
    for (i=0; i < qtd; i++){
        if (students[i].grade > avg) {
            printf("Number: %i\n", students[i].number);
            printf("Name: %s\n", students[i].name);
            printf("Grade: %.2f\n", students[i].grade);
            count++;
        }
    }
    if (count == 0) {
        printf("No students with grade above the average\n");
    } else {
        printf("The quantity of students above the average is %i\n", count);
    }
    free(students);
    return 0;
}