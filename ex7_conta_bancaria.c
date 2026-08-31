#include <stdio.h>

#define MAX 100

// Struct que representa uma conta bancaria
typedef struct {
    int numeroConta;
    float saldo;
} Conta;

int main() {
    Conta contas[MAX];
    int total = 0;
    int opcao, i;

    do {
        printf("\n===== MENU - CONTA BANCARIA =====\n");
        printf("1 - Cadastrar conta\n");
        printf("2 - Depositar\n");
        printf("3 - Mostrar todas as contas\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total < MAX) {
                    printf("\n--- Cadastro de Conta ---\n");
                    printf("Numero da conta: ");
                    scanf("%d", &contas[total].numeroConta);
                    printf("Saldo inicial: ");
                    scanf("%f", &contas[total].saldo);

                    total++;
                    printf("Conta cadastrada com sucesso!\n");
                } else {
                    printf("Limite de contas atingido!\n");
                }
                break;

            case 2: {
                if (total == 0) {
                    printf("\nNenhuma conta cadastrada.\n");
                    break;
                }

                int indice;
                float valor;

                printf("\nDigite a posicao (indice) da conta (0 a %d): ", total - 1);
                scanf("%d", &indice);

                if (indice >= 0 && indice < total) {
                    printf("Valor do deposito: ");
                    scanf("%f", &valor);

                    contas[indice].saldo += valor;
                    printf("Deposito realizado! Novo saldo: R$ %.2f\n", contas[indice].saldo);
                } else {
                    printf("Indice invalido!\n");
                }
                break;
            }

            case 3:
                printf("\n--- Todas as Contas ---\n");
                if (total == 0) {
                    printf("Nenhuma conta cadastrada.\n");
                } else {
                    for (i = 0; i < total; i++) {
                        printf("Indice: %d | Numero: %d | Saldo: R$ %.2f\n",
                               i, contas[i].numeroConta, contas[i].saldo);
                    }
                }
                break;

            case 4:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
