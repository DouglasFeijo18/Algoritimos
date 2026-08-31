#include <stdio.h>

#define MAX 100

// Struct que representa um imovel
typedef struct {
    int numeroCasa;
    float consumoKwh;
} Imovel;

int main() {
    Imovel imoveis[MAX];
    int total = 0;
    int opcao, i;

    do {
        printf("\n===== MENU - CONSUMO DE ENERGIA =====\n");
        printf("1 - Cadastrar imovel\n");
        printf("2 - Calcular media de consumo geral\n");
        printf("3 - Listar imoveis acima da media\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total < MAX) {
                    printf("\n--- Cadastro de Imovel ---\n");
                    printf("Numero da casa: ");
                    scanf("%d", &imoveis[total].numeroCasa);
                    printf("Consumo (kWh): ");
                    scanf("%f", &imoveis[total].consumoKwh);

                    total++;
                    printf("Imovel cadastrado com sucesso!\n");
                } else {
                    printf("Limite de imoveis atingido!\n");
                }
                break;

            case 2: {
                if (total == 0) {
                    printf("\nNenhum imovel cadastrado.\n");
                    break;
                }

                float soma = 0;
                for (i = 0; i < total; i++) {
                    soma += imoveis[i].consumoKwh;
                }

                float media = soma / total;
                printf("\nMedia de consumo da rua: %.2f kWh\n", media);
                break;
            }

            case 3: {
                if (total == 0) {
                    printf("\nNenhum imovel cadastrado.\n");
                    break;
                }

                float soma = 0;
                for (i = 0; i < total; i++) {
                    soma += imoveis[i].consumoKwh;
                }
                float media = soma / total;

                printf("\n--- Imoveis com consumo acima da media (%.2f kWh) ---\n", media);
                int encontrou = 0;

                for (i = 0; i < total; i++) {
                    if (imoveis[i].consumoKwh > media) {
                        printf("Casa: %d | Consumo: %.2f kWh\n",
                               imoveis[i].numeroCasa, imoveis[i].consumoKwh);
                        encontrou = 1;
                    }
                }

                if (!encontrou) {
                    printf("Nenhum imovel acima da media.\n");
                }
                break;
            }

            case 4:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
