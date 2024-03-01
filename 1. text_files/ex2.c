/*
 * 
 * 2. Implement a program that writes to the text file "Curriculum.txt" the name, number, course name and lists of subjects 
 * that have already finished in the course and their respective grade. The program should write one subject on each line
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = NULL;
    char lines[100];
    int res = 0;
    
    fp = fopen("Curriculum.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file");
        return -1;
    }
    while(!feof(fp))
    {
        res = fgets(lines, 100, fp);
        if (res > 0) {
            printf("%s", lines);
        }
    }
    fclose(fp);
    return 0;
}