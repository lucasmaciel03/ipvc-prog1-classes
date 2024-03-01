/*
 *
 * 
 * 7. Implement a program that allows to save in a text file the list of people registered in the cimeiraIPVC2024.
 * The program should allow adding new registrations and listing registrations made so far.
 * The name of the file should be "CimeiraIPVC2024.txt"
 * 
 *  a. Insert new registration - The program should ask the user for the name, phone number,
 * name of the participant's home institution. The information of a participant will be written on a line.
 * The insertion will end when the user types the word 'FIM'. It should be possible to add new registrations to the file whenever necessary.
 * Whenever a new element registers, a registration number is provided to him.
 * 
 *  b. List registrations made so far - The program should read the file created in the previous exercise and print to the screen the contents of the text file.
 * 
 *  c. Change the registration data of a participant, given the registration number.
 *  
 *  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "CimeiraIPVC2024.txt"

typedef struct {
    int id;
    char name[100];
    char phone[10];
    char institution[100];
} Participant;

int main() {
    FILE *fp = NULL;
    char option;
    int res = 0;
    int num_participants = 0;
    Participant p;
    Participant *participants = NULL;
    int i = 0;
    int id = 0;
    int found = 0;
    char line[100];

    while (1) {
        printf("Choose an option:\n");
        printf("a. Insert new registration\n");
        printf("b. List registrations made so far\n");
        printf("c. Change registration data of a participant, given the registration number\n");
        printf("d. Exit\n");
        scanf(" %c", &option);

        if (option == 'a') {
            fp = fopen(FILENAME, "a");
            if (fp == NULL) {
                printf("Error opening file");
                return -1;
            }
            while (1) {
                printf("Name: ");
                scanf(" %99[^\n]", p.name);
                if (strcmp(p.name, "FIM") == 0) {
                    break;
                }
                printf("Phone: ");
                scanf(" %9[^\n]", p.phone);
                printf("Institution: ");
                scanf(" %99[^\n]", p.institution);
                fprintf(fp, "%d;%s;%s;%s\n", num_participants, p.name, p.phone, p.institution);
                num_participants++;
            }
            fclose(fp);
        } else if (option == 'b') {
            fp = fopen(FILENAME, "r");
            if (fp == NULL) {
                printf("Error opening file");
                return -1;
            }
            while (!feof(fp)) {
                res = fscanf(fp, "%d;%99[^;];%9[^;];%99[^\n]", &id, p.name, p.phone, p.institution);
                if (res > 0) {
                    printf("%d;%s;%s;%s\n", id, p.name, p.phone, p.institution);
                }
            }
            fclose(fp);
        } else if (option == 'c') {
            printf("Enter the registration number: ");
            scanf("%d", &id);
            fp = fopen(FILENAME, "r");
            if (fp == NULL) {
                printf("Error opening file");
                return -1;
            }
            while (!feof(fp)) {
                res = fscanf(fp, "%d;%99[^;];%9[^;];%99[^\n]", &id, p.name, p.phone, p.institution);
                if (res > 0) {
                    participants = (Participant *) realloc(participants, (i + 1) * sizeof(Participant));
                    participants[i] = p;
                    i++;
                }
            }
            fclose(fp);
            for (i = 0; i < num_participants; i++) {
                if (participants[i].id == id) {
                    printf("Name: ");
                    scanf(" %99[^\n]", participants[i].name);
                    printf("Phone: ");
                    scanf(" %9[^\n]", participants[i].phone);
                    printf("Institution: ");
                    scanf(" %99[^\n]", participants[i].institution);
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                printf("Participant not found\n");
            }
            fp = fopen(FILENAME, "w");
            if (fp == NULL) {
                printf("Error opening file");
                return -1;
            }
            for (i = 0; i < num_participants; i++) {
                fprintf(fp, "%d;%s;%s;%s\n", participants[i].id, participants[i].name, participants[i].phone, participants[i].institution);
            }
            fclose(fp);
        } else if (option == 'd') {
            
            break;
        }
    }
    return 0;
}


