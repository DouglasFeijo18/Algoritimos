#include <stdio.h>

#define MAX 100

// Struct que representa um cliente
typedef struct {
    int codigo;
    int idade;
    char telefone[15];
} Cliente;

int main() {
    Cliente clientes[MAX];
    int total = 0;
    int opcao, i;

    do {
        printf("\n===== MENU - CADASTRO DE CLIENTES =====\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar todos os clientes\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total < MAX) {
                    printf("\n--- Cadastro de Cliente ---\n");
                    printf("Codigo: ");
                    scanf("%d", &clientes[total].codigo);
                    printf("Idade: ");
                    scanf("%d", &clientes[total].idade);
                    printf("Telefone: ");
                    scanf("%s", clientes[total].telefone);

                    total++;
                    printf("Cliente cadastrado com sucesso!\n");
                } else {
                    printf("Limite de clientes atingido!\n");
                }
                break;

            case 2:
                printf("\n--- Lista de Clientes ---\n");
                if (total == 0) {
                    printf("Nenhum cliente cadastrado.\n");
                } else {
                    for (i = 0; i < total; i++) {
                        printf("Codigo: %d | Idade: %d | Telefone: %s\n",
                               clientes[i].codigo,
                               clientes[i].idade,
                               clientes[i].telefone);
                    }
                }
                break;

            case 3:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}
