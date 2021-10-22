#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha {
	int limite;
	int contador; 
	int* dados;
} ;

Pilha* create(int n){
	
	Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
	
	if(pi == NULL){
		return NULL;
	}else{
		pi->dados = (int*) malloc(n * sizeof(int));
		pi->limite = n; 
		pi->contador = 0;
		return pi;
	}
			
}

int add(Pilha* pi, int e){
	
	if(pi!=NULL && pi->contador < pi->limite ) {
		int posicaoDaInsercao = pi->contador;
		pi->dados[posicaoDaInsercao] = e;
		pi->contador++;
		return 1;
	}
	else{
		return 0;
	}	
		
}

int pop(Pilha* pi){
	
	if(pi!=NULL && !isEmpty(pi)){
		pi->contador--;
		return 1;
	}
	else{	
		return 0;
	}	
	
}

int size(Pilha* pi){
	
	if(pi!=NULL && !isEmpty(pi)){
		return pi->contador;
	}
	else{	
		return 0;
	}
	
}

int top(Pilha* pi){
	
	if(pi!=NULL && !isEmpty(pi)){
		int posicaoDoUltimoInserido = pi->contador-1;
		return pi->dados[posicaoDoUltimoInserido];
	}
	else{
		return 0;
	}	
	
}

int bottom(Pilha* pi){

	if(pi!=NULL && !isEmpty(pi)){
		return pi->dados[0];
	}
	else{
		return 0;
	}	

}

int find(Pilha* pi, int y, int *vetor, int j){
	
	int i;
	
	if(pi!=NULL && !isEmpty(pi)){
		
		int cont=0;
		
		for(i=0; i<=pi->contador; i++){
			
			if(pi->dados[i] == y){
				
				vetor[j] = i;
				j++;
				cont++;
				
			}
			
		}
		
		if(j==0){
			return -1;
		}
		else{
			return cont;
		}
		
	}
	else{	
		return 0;	
	}
	
}

int isFull(Pilha* pi){
	
	if(pi==NULL){
		return 0;
	}
	else{

		if((pi->contador)==(pi->limite)){
			return 1;
		}
		else{
			return 0;
		}
		
	}
	
}

int isEmpty(Pilha* pi){
	
	if(pi == NULL){
		return 1;
	}
	
	if(pi->contador <= 0){
		return 1;
	}
		
	else{	
		return 0; 
	}
	
}

int clear(Pilha* pi){
	
	if(pi==NULL){ 
		return 0; 
	}
	else{
		free(pi);
		return 1;
	}
	
}
