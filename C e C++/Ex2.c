#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct {
    int cod, qnt;
    float preco;
} Produto;

    int main(){
    Produto estoque[max];
    int totalProd = 0;
    int op = 0;
    int i =0;


    do{
        system("cls");
        printf ("--------Menu--------\n");
        printf ("1 - Cadastrar Produto\n");
        printf ("2 - Listar Produtos\n");
        printf ("3 - Sair\n");
        printf ("--------------------\n");
        
        printf ("Opcao: \n");
        scanf ("%d", &op);
        
         switch (op){
             case 1:
                 if (totalProd == max){
                 	printf ("\nLimite maximo de produtos em estoque ja foi atingido\n");
                 } 
				 else {
                 	printf ("\n---Cadastrar Produto---\n");
                 	
                 	printf ("Codigo: \n");
                 	scanf ("%i", &estoque[totalProd].cod);
                 
                 	printf ("Quantidade: \n");
                 	scanf ("%i", &estoque[totalProd].qnt);
                 
                 	printf ("Preco: \n");
                 	scanf ("%f", &estoque[totalProd].preco);
                 
                 totalProd++;
                 }
                 
			 	break;
			 case 2:	
			 	 if (totalProd == 0){
			 	 	printf ("\nNao ha produtos cadastrados aqui!");
				} else {
						printf ("-------------------------------\n");
					for (i = 0; i < totalProd; i++){
					
						printf ("Codigo do produto: %i\n", estoque[i].cod);
						printf ("Quantidade em estoque: %i\n", estoque[i].qnt);
						printf ("Preco do produto: %.2f\n", estoque[i].preco);
						printf ("-------------------------------\n");
					}
				}
			 	break;
			 	
			 case 3:
			 	printf("Sistema encerrado\n");
                break;
            default:
                printf("Opcao invalida. Redigite\n");
                break;
			
         }
        system("pause");
    } while (op !=3);

    return 0;
    }
