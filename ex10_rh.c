#include <stdio.h>

#define MAX 100

// Struct que representa um funcionario
typedef struct {
    int codigo;
    int idade;
    float salario;
} Funcionario;

int main() {
    Funcionario funcionarios[MAX];
    int total = 0;
    int opcao, i;

    do {
        printf("\n===== MENU - SISTEMA DE RH =====\n");
        printf("1 - Cadastrar funcionario\n");
        printf("2 - Contar funcionarios com mais de 40 anos e salario acima de R$ 5000,00\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total < MAX) {
                    printf("\n--- Cadastro de Funcionario ---\n");
                    printf("Codigo: ");
                    scanf("%d", &funcionarios[total].codigo);
                    printf("Idade: ");
                    scanf("%d", &funcionarios[total].idade);
                    printf("Salario: ");
                    scanf("%f", &funcionarios[total].salario);

                    total++;
                    printf("Funcionario cadastrado com sucesso!\n");
                } else {
                    printf("Limite de funcionarios atingido!\n");
                }
                break;

            case 2: {
                int contador = 0;

                for (i = 0; i < total; i++) {
                    if (funcionarios[i].idade > 40 && funcionarios[i].salario > 5000.0) {
                        contador++;
                    }
                }

                printf("\nFuncionarios com mais de 40 anos e salario acima de R$ 5000,00: %d\n", contador);
                break;
            }

            case 3:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}
