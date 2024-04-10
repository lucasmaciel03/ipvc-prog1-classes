/*
Suponha que o excerto de código em baixo faz parte de um programa implementado na linguagem C, para fazer a gestão dos livros comprados para uma biblioteca.

a. Implemente a função storeAllData(...) que escreve para o ficheiro binário "Ii-vros-dat" toda a informação armazenada no array livros.

b. Implemente a função sortBylsbn(....) que ordena a informação do array livros por ordem alfabética do ISBN.

c. Implemente a função existelSBN(...) que verifica se o ISBN recebido como parâmetro na função já existe no array livros. A função deverá retornar 1 caso já exista, caso contrário, deverá retornar 0.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "Iivros.dat"

#define MAX 300

typedef struct livro
{
    int cod_livro, num_exemplares, ano;
    char ISBN[20], titulo[100], AUTOR[6][100];
} LIVRO;

void storeAllData(LIVRO livros[], int tamanho)
{
    FILE *fp = fopen("livros.dat", "wb");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fwrite(livros, sizeof(LIVRO), tamanho, fp);
    fclose(fp);
}

void sortByIsbn(LIVRO livros[], int tamanho)
{
    int i, j;
    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = 0; j < tamanho - i - 1; j++)
        {
            if (strcmp(livros[j].ISBN, livros[j + 1].ISBN) > 0)
            {
                LIVRO temp = livros[j];
                livros[j] = livros[j + 1];
                livros[j + 1] = temp;
            }
        }
    }
}

int existeISBN(LIVRO livros[], int tamanho, char isbn[])
{
    for (int i = 0; i < tamanho; i++)
    {
        if (strcmp(livros[i].ISBN, isbn) == 0)
        {
            return 1; // Encontrou
        }
    }
    return 0; // Não encontrou
}

int main()
{
    LIVRO livros[MAX] = {
        {1, 10, 2021, "123456", "Livro 1", {"Autor 1", "Autor 2", "Autor 3", "Autor 4", "Autor 5", "Autor 6"}},
        {2, 20, 2020, "654321", "Livro 2", {"Autor 1", "Autor 2", "Autor 3", "Autor 4", "Autor 5", "Autor 6"}},
        {3, 30, 2019, "987654", "Livro 3", {"Autor 1", "Autor 2", "Autor 3", "Autor 4", "Autor 5", "Autor 6"}},
        {4, 40, 2018, "456789", "Livro 4", {"Autor 1", "Autor 2", "Autor 3", "Autor 4", "Autor 5", "Autor 6"}}};

    storeAllData(livros, 4);

    sortByIsbn(livros, 4);

    printf("Existe ISBN: %d\n", existeISBN(livros, 4, "123456"));
    printf("Existe ISBN: %d\n", existeISBN(livros, 4, "123457"));

    return 0;
}
