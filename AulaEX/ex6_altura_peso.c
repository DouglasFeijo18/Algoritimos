#include <stdio.h>

#define MAX 100

// Struct que representa o perfil de um aluno da academia
typedef struct {
    int codigo;
    float peso;
    float altura;
} Perfil;

int main() {
    Perfil alunos[MAX];
    int total = 0;
    int opcao, i;

    do {
        printf("\n===== MENU - PERFIL FISICO =====\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Exibir aluno mais alto cadastrado\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total < MAX) {
                    printf("\n--- Cadastro de Aluno ---\n");
                    printf("Codigo: ");
                    scanf("%d", &alunos[total].codigo);
                    printf("Peso (kg): ");
                    scanf("%f", &alunos[total].peso);
                    printf("Altura (m): ");
                    scanf("%f", &alunos[total].altura);

                    total++;
                    printf("Aluno cadastrado com sucesso!\n");
                } else {
                    printf("Limite de alunos atingido!\n");
                }
                break;

            case 2:
                if (total == 0) {
                    printf("\nNenhum aluno cadastrado.\n");
                } else {
                    int indiceMaisAlto = 0;

                    for (i = 1; i < total; i++) {
                        if (alunos[i].altura > alunos[indiceMaisAlto].altura) {
                            indiceMaisAlto = i;
                        }
                    }

                    printf("\n--- Aluno mais alto ---\n");
                    printf("Codigo: %d | Peso: %.2f kg | Altura: %.2f m\n",
                           alunos[indiceMaisAlto].codigo,
                           alunos[indiceMaisAlto].peso,
                           alunos[indiceMaisAlto].altura);
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
