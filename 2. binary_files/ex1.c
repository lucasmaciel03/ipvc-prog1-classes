/*
 *
 * 
 * 1. Pretende-se implementar um programa para gerir a informação sobre os participantes no 
 * workshop sobre Transformação Digital. Sobre cada participante deve-se armazenar o 
 * nome, valor pago na inscrição e Tipo de participante (E-Empresa, A-Aluno, C-Convidado, O-Outro). 
 * As inscrições estão abertas durante 15 dias. O máximo número de participantes é de 150. 
 * A informação deve ser armazenada no ficheiro binário “TranfDigital2024.dat”
 * 
 * O programa deverá permitir:
 *  1. Receber informação sobre um participante: O programa deverá pedir ao utilizador os dados do 
 *  participante e acrescentá-los aos dados já armazenados. 
 *  Os participantes são numerados sequencialmente à medida que são introduzidos no sistema.
 *  
 *  2. Listar informação: O programa deverá permitir listar informação sobre 
 *  todos os participantes inscritos.
 *  
 *  3. Listar um participante: O programa deverá permitir listar a informação sobre um 
 *  participante (dado o número de inscrição).
 *  
 *  4. Soma pagamentos: O programa deverá permitir calcular o somatório dos valores
 *  pagos por todos os participantes.
 *  
 *  5. Listar por tipo de participante: O programa deverá permitir saber quantos dos 
 *  participantes são de um determinado tipo de participante (por ex. aluno).
 *  
 *  6. Escrever informação para ficheiro texto: O programa deverá permitir escrever
 *  para o ficheiro de texto “TD2024_Inscritos.txt” o número e nome de todos os 
 *  participantes (um participante em cada linha).
 *  
 *  7. Alterar informação: O programa deverá permitir alterar o valor pago por um 
 *  determinado participante (dado o número de inscrição).
 *  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "TranfDigital2024.dat"
#define FILENAME_TXT "TD2024_Inscritos.txt"
#define MAX 150 // Maximum number of participants

typedef struct {
    char name[64];
    float valuePaid;
    char type;
} PARTICIPANT;

void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
} // This was addes to switch the fflush(stdin) to clearBuffer(), is not a good practice use fflush(stdin)

void checkAndCreateFile() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        // O arquivo não existe, vamos criá-lo
        file = fopen(FILENAME, "wb");
        if (!file) {
            perror("Failed to create file");
            exit(EXIT_FAILURE);
        }
    }
    fclose(file);
}

void loadParticipants(PARTICIPANT *info, int *total) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("File is empty, initializing...\n");
        return; // If file does not exist, return
    }

    while(fread(&info[*total], sizeof(PARTICIPANT), 1, file)) {
        (*total)++;
    }

    fclose(file);
}

void insertParticipant(PARTICIPANT *info, int *total) { // 1. Receives information about a participant
    if (*total >= MAX) {
        printf("Maximum number of participants reached...\n");
        return;
    }
    
    // Return the number of participants already registered
    printf("Total of participants: %d\n", *total);

    printf("Enter participant name (or type 'exit' to return): ");
    scanf(" %63[^\n]", info[*total].name); // Limit the input to 63 characters
    
    // If the user types 'exit', return to the main menu
    if (strcmp(info[*total].name, "exit") == 0) {
        printf("Returning to main menu...\n");
        return; 
    }
    
    printf("Enter value paid: ");
    scanf("%f", &info[*total].valuePaid);
    clearBuffer();

    printf("Enter participant type (E-Empresa, A-Aluno, C-Convidado, O-Outro): ");
    while(scanf(" %c", &info[*total].type) != 1 || (info[*total].type != 'E' && info[*total].type != 'A' && info[*total].type != 'C' && info[*total].type != 'O')) {
        clearBuffer();
        printf("Invalid type. Please enter E, A, C, or O: ");
    }    
    
    (*total)++;
    
    // Save the new participant to the file
    FILE *file = fopen(FILENAME, "ab");
    if (file != NULL) {
        fwrite(&info[*total-1], sizeof(PARTICIPANT), 1, file);
        fclose(file);
    } else {
        printf("Error opening file...\n");
    }
}

void listInformation(PARTICIPANT *info, int total) { // 2. List information
    if (total == 0) {
        printf("No participants registered...\n");
        return;
    }

    printf("List of all participants:\n");
    for (int i = 0; i < total; i++) {
        printf("--------------------\n");
        printf("Participant number: %d, Name: %s, Value Paid: %.2f, Type: %c\n", i+1, info[i].name, info[i].valuePaid, info[i].type);
        printf("--------------------\n");
    }
}

void listParticipant(PARTICIPANT *info, int total) { // 3. List a participant
    int num;
    printf("Enter the registration number of the participant: ");
    scanf("%d", &num);
  
    
    if (num < 1 || num > total) {
        printf("Invalid participant number...\n");
        return;
    }
    printf("--------------------\n");
    printf("Participant number: %d, Name: %s, Value Paid: %.2f, Type: %c\n", num, info[num-1].name, info[num-1].valuePaid, info[num-1].type);
    printf("--------------------\n");
}

void calculatePayments(PARTICIPANT *info, int total) { // 4. Sum of payments
    float sum = 0;
    for (int i = 0; i < total; i++) {
        sum += info[i].valuePaid;
    }
    printf("--------------------\n");
    printf("Total sum of payments: %.2f\n", sum);
    printf("--------------------\n");
}

void listParticipantByType(PARTICIPANT *info, int total) { // 5. List by participant type
    char type;
    int count = 0;
    
    printf("Enter the participant type (E-Empresa, A-Aluno, C-Convidado, O-Outro): ");
    while(scanf(" %c", &type) != 1 || (type != 'E' && type != 'A' && type != 'C' && type != 'O')) {
        clearBuffer();
        printf("Invalid type. Please enter E, A, C, or O: ");
    }
    
    for (int i = 0; i < total; i++) {
        if (info[i].type == type) {
            count++;
        }
    }
    printf("--------------------\n");
    printf("Total of participants of type %c: %d\n", type, count);
    printf("--------------------\n");
}

void writeInformationToFile(PARTICIPANT *info, int total) { // 6. Write information to text file
    FILE *file = fopen(FILENAME_TXT, "w");
    if (file != NULL) {
        for (int i = 0; i < total; i++) {
            fprintf(file, "Participant number: %d, Name: %s\n", i+1, info[i].name);
        }
        printf("--------------------\n");
        printf("Information written to file...\n");
        printf("--------------------\n");
        fclose(file);
    } else {
        printf("Error opening file...\n");
    }
}

void changeInformation(PARTICIPANT *info, int total) { // 7. Change information
    int num;
    printf("Enter the registration number of the participant: ");
    scanf("%d", &num);
    
    if (num < 1 || num > total) {
        printf("Invalid participant number...\n");
        return;
    }

    // print f the current value paid of the participant
    
    printf("Enter new value paid: ");
    scanf("%f", &info[num-1].valuePaid);
    printf("--------------------\n");
    printf("Information changed...\n");
    printf("--------------------\n");
    
}

int main() {
    PARTICIPANT info[MAX];
    int total = 0;
    char option;
    
    checkAndCreateFile(); // Check if the file exists, if not, create it
    loadParticipants(info, &total); // Load the participants from the file
    
    while(1) {
        printf("Choose an option:\n");
        printf("1. Insert new participant\n");
        printf("2. List all participants\n");
        printf("3. List a participant\n");
        printf("4. Sum of payments\n");
        printf("5. List by participant type\n");
        printf("6. Write information to text file\n");
        printf("7. Change information\n");
        printf("8. Exit\n");
        scanf(" %c", &option);
        clearBuffer();

        switch (option) {
            case '1':
                insertParticipant(info, &total);
                break;
                
            case '2':
                listInformation(info, total);
                break;
                
            case '3':
                listParticipant(info, total);
                break;
                
            case '4':
                calculatePayments(info, total);
                break;
                
            case '5':
                listParticipantByType(info, total);
                break;
                
            case '6':
                writeInformationToFile(info, total);
                break;
                
            case '7':
                changeInformation(info, total);
                break;
            
            case '8':
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid option...\n");
                break;
        }
    } 
    
    return 0;
}


