#include <stdio.h>

#define MAX 100

// Struct que representa um carro
typedef struct {
    int codigo;
    int ano;
    float preco;
} Carro;

int main() {
    Carro carros[MAX];
    int total = 0;
    int opcao, i;

    do {
        printf("\n===== MENU - CATALOGO DE CARROS =====\n");
        printf("1 - Cadastrar carro\n");
        printf("2 - Buscar carros por preco maximo\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total < MAX) {
                    printf("\n--- Cadastro de Carro ---\n");
                    printf("Codigo: ");
                    scanf("%d", &carros[total].codigo);
                    printf("Ano: ");
                    scanf("%d", &carros[total].ano);
                    printf("Preco: ");
                    scanf("%f", &carros[total].preco);

                    total++;
                    printf("Carro cadastrado com sucesso!\n");
                } else {
                    printf("Limite de carros atingido!\n");
                }
                break;

            case 2: {
                float precoMax;
                printf("\nDigite o valor maximo desejado: ");
                scanf("%f", &precoMax);

                printf("\n--- Carros ate R$ %.2f ---\n", precoMax);
                int encontrou = 0;

                for (i = 0; i < total; i++) {
                    if (carros[i].preco <= precoMax) {
                        printf("Codigo: %d | Ano: %d | Preco: R$ %.2f\n",
                               carros[i].codigo,
                               carros[i].ano,
                               carros[i].preco);
                        encontrou = 1;
                    }
                }

                if (!encontrou) {
                    printf("Nenhum carro encontrado nessa faixa de preco.\n");
                }
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
