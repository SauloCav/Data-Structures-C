#include <stdio.h>
#include <stdlib.h>
#include "repositorio.h"

struct repositorio{
	Comp** dados;
	int n;
	int k;
};

struct CompraRealizada{
	int codigo;
	float valor;
};

Repo* criarRepositorio(int n){
	
	Repo* re = (Repo*) malloc(sizeof(Repo));
 	
 	re->n = n;
 	re->k = 0;
 	
 	re->dados = (Comp**) malloc(sizeof(Comp*) * n+1);
	 	
 	return re;
	
}

int adicionar(Repo* re, int cod, float val){
	
	if((re != NULL) && (re->k < re->n)) {
			
		Comp *co = criaCompra(cod, val);
		int i = 0;
		int posicao = re->k;
		
		for(i = 0; i < re->k; i++){
			if(val < re->dados[i]->valor){ 
				posicao = i;
				break;
			}
		}
		
		int j=0;
		Comp *newVetor = (Comp*) malloc(sizeof(Comp)*re->n+1);
		
		if(posicao != re->k){
			for(i=re->k+1; i>posicao; i--){
				newVetor = re->dados[i-1];
				re->dados[i-1] = re->dados[i]; 
				re->dados[i] = newVetor; 
			}	
		}
		
		re->dados[posicao] = co;
		re->k++;
		return 1;
				
	}
	else{	
		return 0;
	}
	
}

Comp* tratar(Repo* re){
	
	if((re != NULL) && (re->k > 0)){
		
		Comp *newVetor = (Comp*) malloc(sizeof(Comp)*re->n+1);
		
		newVetor = re->dados[re->k];
		
		re->dados[re->k] = NULL;
		re->k--;
		printf("\nCompra tratada: Codigo: [%d], Valor: [%.2f]\n", re->dados[re->k]->codigo, re->dados[re->k]->valor);
		return newVetor;
		
	}
	else{
		
		return 0;
		
	}
	
}

int tamanho(Repo* re){
	
	if((re!=NULL) && (re->k>0)){
		printf("\nNumero de compras registradas no Repositorio: %d", re->k);
		return re->k;
	}
	else{
		printf("\nNumero de compras registradas no Repositorio: 0");
		return 0;
	}
	
}

int pesquisarValor(Repo* re, float val){
	
    int i = 0;
    int j = re->k-1;
    int meio; /
    
    while(i <= j){
    	
        meio = (i + j)/2;
        
        if(val == re->dados[meio]->valor){
        	printf("\nCompra buscada por meio do valor: Codigo: [%d], Valor: [%.2f], Posicao: [%d]\n", re->dados[meio]->codigo, re->dados[meio]->valor, i);
        	return meio;
		} 
        if(val < re->dados[meio]->valor){
        	j = meio-1;
		} 
        else{
        	i = meio+1;
		}
               
     }
     
     return -1;
	
}

int pesquisarCodigo(Repo* re, int cod){
	
	int i = 0;
	
	for(i=0; i<=re->n; i++){ 
		
		if(re->dados[i]->codigo == cod){
			printf("\nCompra buscada por meio do codigo: Codigo: [%d], Valor: [%.2f], Posicao: [%d]\n", re->dados[i]->codigo, re->dados[i]->valor, i);
			return i;
		}
		
	}
	
	return -1;
	
}

bool estaCheio(Repo* re){
	
	if(re==NULL){
		printf("\nRepositorio Nao Cheio!");
		return false;
	}
	else{

		if((re->k)==(re->n)){
			printf("\nRepositorio Cheio!");
			return true;
		}
		else{
			printf("\nRepositorio Nao Cheio!");
			return false;	
		}
		
	}
		
}

bool estaVazio(Repo* re){
	
	if(re == NULL){
		printf("\nRepositorio Vazio!");
		return true; 
	}
	else{
		
		if(re->k <= 0){
			printf("\nRepositorio Vazio!");
			return true;
		
		else{
			printf("\nRepositorio nao Vazio!");
			return false;	
		}
		
	}
	
}

void esvaziar(Repo* re){
	
	free(re);
	
}

void printRespositorio(Repo* re){
	
	int i = 0;
	
	if((re!=NULL) && (re->k>0)){
		
		printf("\nLista de Compras:\n");
		for(i=0; i<re->k; i++){
			printf("Codigo: [%d], Valor: [%.2f]\n", re->dados[i]->codigo, re->dados[i]->valor);
		}
		
	}
	else{
		printf("\nLista de Compras Vazia!");
	}
	
}

Comp* criaCompra(int cod, float val){
	
	Comp *c = (Comp*) malloc(sizeof(Comp));
	
	c->codigo = cod;
	c->valor = val;
	
	return c;
	
}
