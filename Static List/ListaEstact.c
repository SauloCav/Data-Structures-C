#include <stdio.h>
#include <stdlib.h>
#include "ListaEstact.h"

struct lista {
	int lim;
	int cont; 
	int* dados; 
	int* insercoes;
} ;

Lista* create(int n){
	
	Lista* li = (Lista*) malloc(sizeof(Lista));
	int i;
	
	if(li == NULL){
		return NULL;
	}
	else{
		li->dados = (int*) malloc(n * sizeof(int));
		li->insercoes = (int*) malloc(n * sizeof(int));
		li->lim = n;
		
		for(i=0; i<li->lim; i++){	
			li->insercoes[i] = 0;
		}
		
		return li;
	}
			
}

int add(Lista* li, int e){
	
	if(li!=NULL && li->cont < li->lim) {
		
		int ind=-1, i, c=0;
		
		for(i=0; i<li->lim; i++){	
			if((li->insercoes[i]==0)&&(c==0)){
				ind=i;
				c++;
			}
		}
		
		int posicaoDaInsercao = ind;
		li->dados[posicaoDaInsercao] = e;
		li->insercoes[posicaoDaInsercao] = 1;
		li->cont++;
		return 1;
	}
	else{
		return 0;
	}	
		
}

int addAtPosition(Lista* li, int i, int x){
	
	if((li!=NULL) && (li->cont < li->lim) && (i>=0) && (i<li->lim) && (li->insercoes[i] == 0)) {
		
		li->dados[i] = x;
		li->insercoes[i] = 1;
		li->cont++;
		
		return 1;
	}
	else{
		return 0;
	}	
		
}

int remove(Lista* li, int x){
	
	if((li!=NULL) && (!isEmpty(li))){
		
		int k=0, c=0;
		
		for(k=0; k<li->lim; k++){
			
			if(li->dados[k]==x){
				if(li->insercoes[k]!=0){
					li->insercoes[k] = 0;
					c++;
				}
			}
				
		}
		
		if(c==0){
			return -1;
		}
		else{
			li->cont=li->cont-c;
			return 1;
		}
		
	}
	else{	
		return 0;	
	}	
	
}

int removeAtPosition(Lista* li, int i, int x){
	
	if((li!=NULL) && (!isEmpty(li)) && (i>=0) && (i<li->lim) && (li->insercoes[i] == 1)) {
		
		int k=0, c=0;
		
		if(li->dados[i]==x){
			li->insercoes[i] = 0;
			c=5;
		}
		
		if(c==0){
			return -1;
		}
		else{
			li->cont--;
			return 1;
		}
	}
	else{
		return 0;
	}
	
}

int size(Lista* li){
	
	if(li!=NULL && !isEmpty(li)){
		return li->cont;
	}
	else{	
		return 0;
	}
	
}

int find(Lista* li, int y, int *vetor, int j){
	
	int i;
	
	if((li!=NULL) && (!isEmpty(li))){
		
		int cont=0;
		
		for(i=0; i<li->lim; i++){
			
			if(li->dados[i] == y){
				
				if(vetor[i]==0){
					vetor[j] = i;
					j++;
					cont++;
				}
				
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

int isFull(Lista* li){
	
	if(li==NULL){	
		return 0;	
	}
	else{

		if((li->cont)==(li->lim)){	
			return 1;	
		}
		else{
			return 0;	
		}
		
	}
	
}

int isEmpty(Lista* li){
	
	if(li == NULL){	
		return 1;	
	}
	
	if(li->cont <= 0){	
		return 1;	
	}
		
	else{	
		return 0;	
	}
	
}

int clear(Lista* li){
	
	if(li != NULL){	
		
		int i;
		
		for(i=0; i<li->lim; i++){	
			li->insercoes[i] = 0;
		}
		
		li->cont=0;
		return 1;	
	}	
	else{	
		return 0;	
	}
	
}

void printLista(Lista* li){
	
	int i=0;
	
	printf("\nLista Estatica: ");
	for(i=0; i<li->lim; i++){
		printf(" [%d]", i);
		if(li->insercoes[i]==1){
			printf("=%d ||", li->dados[i]);	
		}
		else{
			printf("  ||");
		}	
	}
	
}
