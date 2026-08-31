#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	int main(){
		
	float nota[8];
	int opcao;
	int i=0, j=0, qnt=0;
	
	
	do {
		
		system ("cls");
		printf ("------MENU PRINCIPAL------\n");
		printf ("1 - Cadastrar as notas dos alunos\n");
		printf ("2 - Listar notas\n");
		printf ("3 - Buscar a maior e menor nota da turma\n");
		printf ("4 - Alunos aprovados\n");
		printf ("5 - Sair do Programa\n");
		
		printf ("opcao: ");
		scanf ("%i", &opcao);
		
		switch (opcao){
			
			case 1:
				qnt=0;
				for (i=0; i < 8; i++){
					do {
						printf ("Digite a nota do seu aluno: \n");
						scanf ("%f", &nota[i]);
					} while (nota[i] < 0 || nota[i] > 10);
					qnt++;	
				}
				break;	
			
			case 2:
				printf ("Lista dos alunos e suas respectivas notas: \n");
				if (qnt > 0){
					for (i=0; i<8; i++){
						printf("Aluno %d: %.2f\n", i + 1, nota[i]);
					}
					printf ("\n");
				} 				
				else {
					printf ("Nao ha notas cadastradas!!\n");
				}
				break;
				
			case 3:
				if(qnt){
				printf ("Maior e menor nota da turma:\n");
			
				float maior = nota[0];
				float menor = nota[0];
				
				for (i=1; i<8; i++){
					if (nota[i] > maior){
						maior = nota[i];
					}
					if (nota[i] < menor){
						menor = nota[i];
					}
				}
					printf ("A maior nota foi: %.2f\n", maior);
					printf ("A menor nota foi: %.2f\n", menor);					
				}
				else{
					printf ("Nao ha notas cadastradas!!\n");
				}
				break;
				
			case 4:
				if(qnt){
				 printf ("Lista dos alunos aprovados:\n");
					
				 float soma=0, media;
				 int aprovados=0, reprovados=0;
				
				for (i=0; i<8; i++){
					
					soma+=nota[i];
					
					if (nota[i] >= 7.0){
						aprovados++;	
					}
					else{
						reprovados++;	
					}
				}
			
				media = soma/8;
				
				printf ("Foram %i aprovados\n", aprovados);
				printf ("E teve %i reprovados\n", reprovados);
				printf ("Ja a media da turma foi %.2f\n\n", media);	
			}
				else{
					printf ("Nao ha notas cadastradas!!\n");
				}	
				break;
			
			case 5:
                printf("Sistema encerrado\n");
                break;
            default:
                printf("Opcao invalida. Redigite\n");
                break;
		
		} system("pause");
			
	} while (opcao != 5);
	
	return 0;
}
