#include <stdio.h>     // Biblioteca padrão de entrada e saída
#include <stdlib.h>    // Biblioteca padrão para funções de alocação de memória, controle de processos e outras
#include <string.h>    // Biblioteca para manipulação de strings

#define MAX_TASK_LENGTH 100  // Define o tamanho máximo de uma tarefa
#define MAX_TASKS 100        // Define o número máximo de tarefas

// Função para adicionar uma tarefa à lista
void addTask(char tasks[][MAX_TASK_LENGTH], int *taskCount) {
    if (*taskCount < MAX_TASKS) {  // Verifica se ainda há espaço para mais tarefas
        printf("Digite a tarefa: ");  // Solicita ao usuário que digite a tarefa
        getchar();  // Limpa o buffer do teclado para evitar problemas com fgets
        fgets(tasks[*taskCount], MAX_TASK_LENGTH, stdin);  // Lê a tarefa digitada pelo usuário
        tasks[*taskCount][strcspn(tasks[*taskCount], "\n")] = '\0';  // Remove o caractere de nova linha '\n'
        (*taskCount)++;  // Incrementa o contador de tarefas
    } else {
        printf("Lista de tarefas cheia!\n");  // Informa ao usuário que a lista está cheia
    }
}

// Função para visualizar todas as tarefas na lista
void viewTasks(char tasks[][MAX_TASK_LENGTH], int taskCount) {
    if (taskCount == 0) {  // Verifica se não há tarefas na lista
        printf("Nenhuma tarefa adicionada!\n");  // Informa ao usuário que não há tarefas
    } else {
        for (int i = 0; i < taskCount; i++) {  // Percorre todas as tarefas na lista
            printf("%d. %s\n", i + 1, tasks[i]);  // Exibe cada tarefa numerada
        }
    }
}

// Função para remover uma tarefa da lista
void removeTask(char tasks[][MAX_TASK_LENGTH], int *taskCount) {
    if (*taskCount == 0) {  // Verifica se não há tarefas na lista
        printf("Nenhuma tarefa para remover!\n");  // Informa ao usuário que não há tarefas para remover
    } else {
        int taskNumber;
        printf("Digite o número da tarefa a remover: ");  // Solicita ao usuário o número da tarefa a ser removida
        scanf("%d", &taskNumber);  // Lê o número da tarefa a ser removida
        if (taskNumber < 1 || taskNumber > *taskCount) {  // Verifica se o número da tarefa é válido
            printf("Número da tarefa inválido!\n");  // Informa ao usuário que o número da tarefa é inválido
        } else {
            for (int i = taskNumber - 1; i < *taskCount - 1; i++) {  // Desloca todas as tarefas seguintes para cima
                strcpy(tasks[i], tasks[i + 1]);  // Copia a tarefa seguinte para a posição atual
            }
            (*taskCount)--;  // Decrementa o contador de tarefas
            printf("Tarefa removida com sucesso!\n");  // Informa ao usuário que a tarefa foi removida
        }
    }
}

// Função principal
int main() {
    char tasks[MAX_TASKS][MAX_TASK_LENGTH];  // Declara um array para armazenar as tarefas
    int taskCount = 0;  // Inicializa o contador de tarefas com zero

    while (1) {  // Loop infinito para o menu principal
        int choice;
        printf("1. Adicionar tarefa\n");  // Exibe a opção de adicionar tarefa
        printf("2. Visualizar tarefas\n");  // Exibe a opção de visualizar tarefas
        printf("3. Remover tarefa\n");  // Exibe a opção de remover tarefa
        printf("4. Sair\n");  // Exibe a opção de sair do programa
        printf("Escolha uma opcao: ");  // Solicita ao usuário que escolha uma opção
        scanf("%d", &choice);  // Lê a escolha do usuário

        switch (choice) {  // Verifica a escolha do usuário
            case 1:
                addTask(tasks, &taskCount);  // Chama a função para adicionar tarefa
                break;
            case 2:
                viewTasks(tasks, taskCount);  // Chama a função para visualizar tarefas
                break;
            case 3:
                removeTask(tasks, &taskCount);  // Chama a função para remover tarefa
                break;
            case 4:
                exit(0);  // Encerra o programa
            default:
                printf("Opção inválida!\n");  // Informa ao usuário que a opção é inválida
        }
    }

    return 0;  // Retorna 0 para indicar que o programa terminou corretamente
}
