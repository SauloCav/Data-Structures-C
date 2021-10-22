#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "pilha.h"

int main(){
		
	int n;
		
	printf("Insira n: ");
	scanf("%d", &n);
	
	Pilha* pi = create(n);
	
	int i, x, y, j=0, bas, too, vaz, ret, tam, che, pos, limp;
	int v[n];
	
	printf("\n");
	
	for(i=0; i<n; i++){
		
		printf("Insira o elemento [%d]: ", i);
		scanf("%d", &x);
		add(pi, x);
		
	}

	tam = size(pi);
	printf("\nnumero de elementos da pilha: %d\n", tam);
	
	too = top(pi);
	printf("Topo: %d\n", too);
	
	bas = bottom(pi);
	printf("Base: %d\n", bas); 
	
	printf("\nInsira o elemento que voce deseja buscar na pilha: ");
	scanf("%d", &y);
	
	pos = find(pi, y, v, j);
	
	if(pos==-1){
		printf("\nElemento nao encontrado!");
	}
	
	if(pos>0){
		
		printf("Elemento %d encontrado em: ", y);
		
		for(i=0; i<pos; i++){
		
			printf("[%d] ", v[i], y);
		
		}
		
	}
	
	
	//checa se a pilha est� cheia
	che = isFull(pi);
	
	if(che==0){
			
		printf("\n\nPilha cheia? Falso!\n", vaz);
			
	}
	else{
			
		printf("\n\nPilha cheia? Verdadeiro!\n");
			
	}
	
	
	//checa se a pilha est� vazia	
	vaz = isEmpty(pi);
	
	if(vaz==0){
			
		printf("\n\nPilha vazia? Falso!\n", vaz);
			
	}
	else{
			
		printf("\n\nPilha vazia? Verdadeiro!\n");
			
	}
	
	
	//remove elemento do topo da pilha e checa o novo topo
	ret = pop(pi);
	
	too = top(pi);
	printf("\n\nNovo topo: %d\n", too);
	
	//esvazia a pilha e depois faz uma checagem
	limp = clear(pi);
	
	if(limp==1){
		
		printf("\n\nLimpando pilha.");
		Sleep(2000);
		printf(".");
		Sleep(2000);
		printf(".");
		Sleep(2000);
		printf(".");
	
		vaz = isEmpty(pi);
	
		if(vaz==0){
			
			printf("\n\nPilha vazia? Falso!\n", vaz);
			
		}
		else{
			
			printf("\n\nPilha vazia? Verdadeiro!\n");
			
		}
	
	}
		
	return 1;
		
}
