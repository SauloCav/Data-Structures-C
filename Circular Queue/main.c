#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "FilaCircular.h"

int main(){
	
	int n;
		
	printf("Insira n: ");
	scanf("%d", &n);

	Fila* li = create(n);
	
	int i, esc, ret, adi, che, vaz, x;
	
	do{
		
	fflush(stdin);
	
	printf("\n              -------------------------------- MENU --------------------------------");
	printf("\n              |  |1| Add                                                           |");
	printf("\n              |  |2| Remove                                                        |");
	printf("\n              |  |3| isFull                                                        |");
	printf("\n              |  |4| isEmpty                                                       |");
	printf("\n              |  |5| printFila                                                     |");
	printf("\n              |  |0| Sair                                                          |");
	printf("\n              ----------------------------------------------------------------------\n\n");
	
	printf("                                   Escolha uma das opcoes: ");
	scanf("%d", &esc);
	
	if(esc==0){
		system("cls");
	}
	
	switch(esc){
		
		case (0):{
			break;
		}
		
		case (1):{
			
			printf("\nInsira o elemento que voce deseja adicionar: ");
			scanf("%d", &x);
			adi = add(li, x);
			
			if(adi==0){
				printf("\n\nErro ao adicionar!");
			}
			else{
				printf("\n\nElemento adicionado com sucesso!");
			}
			
			printf("\n\n");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			
			system("cls");
			break;
		}
		
		case (2):{
			
			ret = remove(li);
			
			if(ret==0){
				printf("\n\nErro ao remover!");
			}
			if(ret==1){
				printf("\n\nElemento removido com sucesso!");
			}
			
			printf("\n\n");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			
			system("cls");
			break;
		}
		
		case (3):{
			
			che = isFull(li);
	
			if(che==0){
				printf("\n\nFila nao cheia!\n", vaz);
			}
			else{
				printf("\n\nFila cheia!\n");
			}
			
			printf("\n\n");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			
			system("cls");
			break;
		}
		
		case (4):{
			
			vaz = isEmpty(li);
	
			if(vaz==0){
				printf("\n\nFila nao vazia!\n", vaz);
			}
			else{	
				printf("\n\nFila vazia!\n");	
			}
			
			printf("\n\n");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			
			system("cls");
			break;
		}
		
		case (5):{
			
			printFila(li);
			
			printf("\n\n");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf(".");
			
			system("cls");
			break;
		}
	
		default:{
			system("cls");
			break;
		}
		
	}
	
	}while(esc!=0);

}
