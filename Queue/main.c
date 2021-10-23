#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "fila.h"

int main(){
	
	int n;
		
	printf("Insira n: ");
	scanf("%d", &n);
	
	
	//cria a fila
	Fila* fi = create(n);
	
	int i, x, y, j=0, bas, too, vaz, ret, tam, che, pos;
	int v[n];
	
	printf("\n");
	
	
	//preenche a fila
	for(i=0; i<n; i++){
		
		printf("Insira o elemento [%d]: ", i);
		scanf("%d", &x);
		add(fi, x);
		
	}
	
	printFila(fi);
	
	//retorna o tamanho da pilha
	tam = size(fi);
	printf("\nnumero de elementos da fila: %d\n", tam);
	
	
	//retorna o primeiro elemento da fila
	too = first(fi);
	printf("First: %d\n", too);
	
	
	//retorna o ultimo elemento da fila	
	bas = last(fi);
	printf("Last: %d\n", bas); 
	
	
	//busca por um elemento na fila e retorna a posição
	printf("\nInsira o elemento que voce deseja buscar na fila: ");
	scanf("%d", &y);
	
	pos = find(fi, y, v, j);
	
	if(pos==-1){
		
		printf("\nElemento nao encontrado!");
		
	}
	
	if(pos>0){
		
		printf("Elemento %d encontrado em: ", y);
		
		for(i=0; i<pos; i++){
		
			printf("[%d] ", v[i], y);
		
		}
		
	}
	
	
	//checa se a fila está cheia
	che = isFull(fi);
	
	if(che==0){
			
		printf("\n\nFila cheia? Falso!\n", vaz);
			
	}
	else{
			
		printf("\n\nFila cheia? Verdadeiro!\n");
			
	}
	
	
	//checa se a fila está vazia	
	vaz = isEmpty(fi);
	
	if(vaz==0){
			
		printf("\n\nFila vazia? Falso!\n", vaz);
			
	}
	else{
			
		printf("\n\nFila vazia? Verdadeiro!\n");
			
	}
	
	//remove elemento do inicio da fila
	ret = pop(fi);
	
	printf("\nPilha apos a remocao do primeiro elemento: ");
	printFila(fi);
	
	
	//esvazia a fila e depois faz uma checagem se funcionou
	printf("\n\nLimpando fila.");
	Sleep(2000);
	printf(".");
	Sleep(2000);
	printf(".");
	Sleep(2000);
	printf(".");
	clear(fi);
	
	vaz = isEmpty(fi);
	
	if(vaz==0){
			
		printf("\n\nFila vazia? Falso!\n", vaz);
			
	}
	else{
			
		printf("\n\nFila vazia? Verdadeiro!\n");
			
	}
		
}
