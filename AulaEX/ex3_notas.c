#include <stdio.h>

#define MAX 100

// Struct que representa um aluno
typedef struct {
    int matricula;
    float nota1;
    float nota2;
} Aluno;

int main() {
    Aluno alunos[MAX];
    int total = 0;
    int opcao, i;

    do {
        printf("\n===== MENU - DIARIO DE NOTAS =====\n");
        printf("1 - Cadastrar aluno e suas notas\n");
        printf("2 - Listar alunos com matricula e media\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total < MAX) {
                    printf("\n--- Cadastro de Aluno ---\n");
                    printf("Matricula: ");
                    scanf("%d", &alunos[total].matricula);
                    printf("Nota 1: ");
                    scanf("%f", &alunos[total].nota1);
                    printf("Nota 2: ");
                    scanf("%f", &alunos[total].nota2);

                    total++;
                    printf("Aluno cadastrado com sucesso!\n");
                } else {
                    printf("Limite de alunos atingido!\n");
                }
                break;

            case 2:
                printf("\n--- Lista de Alunos ---\n");
                if (total == 0) {
                    printf("Nenhum aluno cadastrado.\n");
                } else {
                    for (i = 0; i < total; i++) {
                        float media = (alunos[i].nota1 + alunos[i].nota2) / 2;
                        printf("Matricula: %d | Media: %.2f\n",
                               alunos[i].matricula, media);
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
