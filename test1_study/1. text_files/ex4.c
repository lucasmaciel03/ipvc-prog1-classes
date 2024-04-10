#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "licenciatura.txt"
#define MAX_LICENCIATURAS 100

void escreveLicenciaturas(char licenciaturas[MAX_LICENCIATURAS][100])
{
    FILE *fp = NULL;

    fp = fopen(FILE_NAME, "w");

    if (fp == NULL)
    {
        printf("Error opening file");
        return;
    }

    for (int i = 0; i < MAX_LICENCIATURAS; i++)
    {
        if (licenciaturas[i][0] != '\0')
        { // Check if string is not empty
            fprintf(fp, "%s\n", licenciaturas[i]);
        }
    }

    printf("Information was saved");

    fclose(fp); // Don't forget to close the file
}

int main()
{
    char licenciaturas[MAX_LICENCIATURAS][100] = {
        "Engenharia Informática",
        "Engenharia Mecânica",
        "Economia",
        "Direito"};

    escreveLicenciaturas(licenciaturas);

    return 0;
}