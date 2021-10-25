#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "ListaEstact.h"

int main(){
	
	int n;
		
	printf("Insira n: ");
	scanf("%d", &n);
	
	//cria a Lista
	Lista* li = create(n);
	
	int i, x, y, z, j=0, ind, adi, adp, rem, vaz, ret, tam, che, pos, esc, cle;
	int v[n];
	
	do{
		
	fflush(stdin);
	
	printf("\n              -------------------------------- MENU --------------------------------");
	printf("\n              |  |1| Add                                                           |");
	printf("\n              |  |2| addAtPosition                                                 |");
	printf("\n              |  |3| Remove                                                        |");
	printf("\n              |  |4| removeAtPosition                                              |");
	printf("\n              |  |5| Size                                                          |");
	printf("\n              |  |6| Find                                                          |");
	printf("\n              |  |7| isFull                                                        |");
	printf("\n              |  |8| isEmpty                                                       |");
	printf("\n              |  |9| clear                                                         |");
	printf("\n              |  |10| printLista                                                   |");
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
			
			printf("\nInsira o elemento que voce deseja adicionar: ");
			scanf("%d", &x);
			printf("Insira o indice: ");
			scanf("%d", &ind);
			adp = addAtPosition(li, ind, x);
			
			if(adp==0){
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
		
		case (3):{
			
			printf("\nInsira o elemento que voce deseja remover: ");
			scanf("%d", &x);
			ret = remove(li, x);
			
			if((ret==0)||(ret==-1)){
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
		
		case (4):{
			
			printf("\nInsira o elemento que voce deseja remover: ");
			scanf("%d", &x);
			printf("Insira o indice: ");
			scanf("%d", &ind);
			rem = removeAtPosition(li, ind, x);
			
			if((rem==0)||(rem==-1)){
				printf("\n\nErro ao remover!");
			}
			else{
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
		
		case (5):{
			
			tam = size(li);
			
			if(rem==0){
				printf("\nLista Vazia ou Nula!");
			}
			else{
				printf("\nTamanho da Lista: %d", tam);
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
		
		case (6):{
			
			printf("\nInsira o elemento que voce deseja buscar na Lista: ");
			scanf("%d", &y);
			
			j=0;
			for(i=0; i<n; i++){
				v[i]=0;
			}
			
			pos = find(li, y, v, j);
	
			if(pos==-1){
				printf("\nElemento nao encontrado!");
			}
			
			if(pos==0){
				printf("\nLista Vazia ou Nula!");
			}
	
			if(pos>0){
		
				printf("Elemento %d encontrado em: ", y);
		
				for(i=0; i<pos; i++){
					printf("[%d] ", v[i], y);
				}
		
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
		
		case (7):{
			
			che = isFull(li);
	
			if(che==0){
				printf("\n\nLista nao cheia!\n", vaz);
			}
			else{
				printf("\n\nLista cheia!\n");
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
		
		case (8):{
			
			vaz = isEmpty(li);
	
			if(vaz==0){
				printf("\n\nLista nao vazia!\n", vaz);
			}
			else{	
				printf("\n\nLista vazia!\n");	
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
		
		case (9):{
			
			printf("\n\nLimpando Lista.");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			cle = clear(li);
			
			if(cle==0){
				printf("\n\nErro ao esvaziar a Lista!");
			}
			else{	
				printf("\n\nLista esvaziada com sucesso!");	
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
		
		case (10):{
			
			printLista(li);	
			
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
