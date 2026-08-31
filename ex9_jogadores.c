#include <stdio.h>

#define MAX 100

// Struct que representa um jogador
typedef struct {
    int id;
    int pontos;
} Jogador;

int main() {
    Jogador jogadores[MAX];
    int total = 0;
    int opcao, i;

    do {
        printf("\n===== MENU - PONTUACAO DE JOGADORES =====\n");
        printf("1 - Cadastrar jogador\n");
        printf("2 - Buscar jogador por ID\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total < MAX) {
                    printf("\n--- Cadastro de Jogador ---\n");
                    printf("ID do jogador: ");
                    scanf("%d", &jogadores[total].id);
                    printf("Pontos: ");
                    scanf("%d", &jogadores[total].pontos);

                    total++;
                    printf("Jogador cadastrado com sucesso!\n");
                } else {
                    printf("Limite de jogadores atingido!\n");
                }
                break;

            case 2: {
                int idBusca;
                int encontrado = 0;

                printf("\nDigite o ID do jogador que deseja buscar: ");
                scanf("%d", &idBusca);

                for (i = 0; i < total; i++) {
                    if (jogadores[i].id == idBusca) {
                        printf("Jogador encontrado! ID: %d | Pontos: %d\n",
                               jogadores[i].id, jogadores[i].pontos);
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Jogador nao encontrado.\n");
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
