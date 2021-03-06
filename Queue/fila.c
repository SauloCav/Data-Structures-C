#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila {
	int lim;
	int cont; 
	int* dados; 
} ;

Fila* create(int n){
	
	Fila* fi = (Fila*) malloc(sizeof(Fila));
	
	if(fi == NULL){
		return NULL;
	}
	else{
		fi->dados = (int*) malloc(n * sizeof(int));
		fi->lim = n;
		return fi;
	}
			
}

int add(Fila* fi, int e){
	
	if(fi!=NULL && fi->cont < fi->lim) {
		int posicaoDaInsercao = fi->cont;
		fi->dados[posicaoDaInsercao] = e;
		fi->cont++;
		return 1;
	}
	else{
		return 0;
	}	
		
}

int pop(Fila* fi){
	
	if(fi!=NULL && !isEmpty(fi)){
		
		int i=0, j=0;
		
		int vetor[fi->cont];
		
		for(i=0; i<fi->cont; i++){
			
			vetor[i]=fi->dados[i];
			
		}
		
		for(i=1; i<(fi->cont); i++){
			
			fi->dados[j]=vetor[i];
			j++;
			
		}
		
		fi->cont--;
		
		return 1;
	}
	else{	
		return 0;	
	}	
	
}

int size(Fila* fi){
	
	if(fi!=NULL && !isEmpty(fi)){
		return fi->cont;
	}
	else{	
		return 0;
	}
	
}

int first(Fila* fi){

	if(fi!=NULL && !isEmpty(fi)){
		return fi->dados[0];
	}
	else{
		return 0;
	}	

}

int last(Fila* fi){
	
	if(fi!=NULL && !isEmpty(fi)){
		int posicaoDoUltimoInserido = fi->cont-1;
		return fi->dados[posicaoDoUltimoInserido];
	}
	else{
		return 0;
	}	
	
}

int find(Fila* fi, int y, int *vetor, int j){
	
	int i;
	
	if(fi!=NULL && !isEmpty(fi)){
		
		int cont=0;
		
		for(i=0; i<=fi->cont; i++){
			
			if(fi->dados[i] == y){
				
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

int isFull(Fila* fi){
	
	if(fi==NULL){	
		return 0;	
	}
	else{

		if((fi->cont)==(fi->lim)){	
			return 1;	
		}
		else{
			return 0;	
		}
		
	}
	
}

int isEmpty(Fila* fi){
	
	if(fi == NULL){	
		return 1;	
	}
	
	if(fi->cont <= 0){	
		return 1;	
	}
		
	else{	
		return 0;	
	}
	
}

void clear(Fila* fi){
	
	free(fi);
	
}

void printFila(Fila* fi){
	
	int i=0;
	
	printf("\nFila: ");
	for(i=0; i<fi->cont; i++){
		
		printf("[%d] ", fi->dados[i]);
		
	}
	
}
