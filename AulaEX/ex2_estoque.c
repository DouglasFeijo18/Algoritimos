#include <stdio.h>

#define MAX 100

// Struct que representa um produto
typedef struct {
    int codigo;
    int quantidade;
    float preco;
} Produto;

int main() {
    Produto produtos[MAX];
    int total = 0;
    int opcao, i;

    do {
        printf("\n===== MENU - ESTOQUE DE MERCADO =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Exibir valor total investido no estoque\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total < MAX) {
                    printf("\n--- Cadastro de Produto ---\n");
                    printf("Codigo: ");
                    scanf("%d", &produtos[total].codigo);
                    printf("Quantidade: ");
                    scanf("%d", &produtos[total].quantidade);
                    printf("Preco: ");
                    scanf("%f", &produtos[total].preco);

                    total++;
                    printf("Produto cadastrado com sucesso!\n");
                } else {
                    printf("Limite de produtos atingido!\n");
                }
                break;

            case 2:
                if (total == 0) {
                    printf("\nNenhum produto cadastrado.\n");
                } else {
                    float valorTotal = 0;

                    for (i = 0; i < total; i++) {
                        valorTotal += produtos[i].quantidade * produtos[i].preco;
                    }

                    printf("\nValor total investido no estoque: R$ %.2f\n", valorTotal);
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
