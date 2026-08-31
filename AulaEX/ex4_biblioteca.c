#include <stdio.h>

#define MAX 100

// Struct que representa um livro
typedef struct {
    int codigo;
    int anoPublicacao;
    int qtdPaginas;
} Livro;

int main() {
    Livro livros[MAX];
    int total = 0;
    int opcao, i;

    do {
        printf("\n===== MENU - BIBLIOTECA =====\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros publicados apos 2020\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total < MAX) {
                    printf("\n--- Cadastro de Livro ---\n");
                    printf("Codigo: ");
                    scanf("%d", &livros[total].codigo);
                    printf("Ano de publicacao: ");
                    scanf("%d", &livros[total].anoPublicacao);
                    printf("Quantidade de paginas: ");
                    scanf("%d", &livros[total].qtdPaginas);

                    total++;
                    printf("Livro cadastrado com sucesso!\n");
                } else {
                    printf("Limite de livros atingido!\n");
                }
                break;

            case 2:
                printf("\n--- Livros publicados apos 2020 ---\n");
                int encontrou = 0;

                for (i = 0; i < total; i++) {
                    if (livros[i].anoPublicacao > 2020) {
                        printf("Codigo: %d | Ano: %d | Paginas: %d\n",
                               livros[i].codigo,
                               livros[i].anoPublicacao,
                               livros[i].qtdPaginas);
                        encontrou = 1;
                    }
                }

                if (!encontrou) {
                    printf("Nenhum livro publicado apos 2020.\n");
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
