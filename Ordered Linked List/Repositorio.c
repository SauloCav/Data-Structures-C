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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Repo* criarRepositorio(int n){
	
	Repo* re = (Repo*) malloc(sizeof(Repo)); // 1 | 1
 	
 	re->n = n; // 1
 	re->k = 0; // 1
 	
 	re->dados = (Comp**) malloc(sizeof(Comp*) * n+1); // 1 | n
	 	
 	return re; // 1
	
}

// Complexidade temporal: O(5) = O(c) (Constante)
// Complexidade espacial: O(1+n) = O(n) (Linear)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int adicionar(Repo* re, int cod, float val){
	
	if((re != NULL) && (re->k < re->n)) { // 2
			
		Comp *co = criaCompra(cod, val); // 1
		int i = 0; // 1 | 1
		int posicao = re->k; // 1 | 1
		
		for(i = 0; i < re->k; i++){	// 2 + 2n
			if(val < re->dados[i]->valor){ // 2n
				posicao = i; // 1
				break; // 1
			}
		}
		
		int j=0; // 1 | 1
		Comp *newVetor = (Comp*) malloc(sizeof(Comp)*re->n+1); // 1 | 1
		
		if(posicao != re->k){ // 1
			for(i=re->k+1; i>posicao; i--){ // 2 + 2n
				newVetor = re->dados[i-1]; // 2n | n
				re->dados[i-1] = re->dados[i]; // 3n
				re->dados[i] = newVetor; // 2n
			}	
		}
		
		re->dados[posicao] = co; // 2
		re->k++; // 1
		return 1; // 1
				
	}
	else{	
		return 0; // 1
	}
	
}

// Complexidade temporal: O(18+13n) = O(n) (Linear)
// Complexidade espacial: O(4+n) = O(n) (Linear)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Comp* tratar(Repo* re){
	
	if((re != NULL) && (re->k > 0)){ // 1
		
		Comp *newVetor = (Comp*) malloc(sizeof(Comp)*re->n+1); // 1 | 1
		
		newVetor = re->dados[re->k]; // 2
		
		re->dados[re->k] = NULL; // 2
		re->k--; // 1
		printf("\nCompra tratada: Codigo: [%d], Valor: [%.2f]\n", re->dados[re->k]->codigo, re->dados[re->k]->valor); // 2
		return newVetor; // 1
		
	}
	else{
		
		return 0; // 1
		
	}
	
}

// Complexidade temporal: O(11) = O(c) (Constante)
// Complexidade espacial: O(1) = O(c) (Constante)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int tamanho(Repo* re){
	
	if((re!=NULL) && (re->k>0)){ // 1
		printf("\nNumero de compras registradas no Repositorio: %d", re->k);
		return re->k; // 1
	}
	else{
		printf("\nNumero de compras registradas no Repositorio: 0");
		return 0; // 1
	}
	
}

// Complexidade temporal: O(3) = O(c) (Constante)
// Complexidade espacial: O(0) = O(c) (Constante)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pesquisarValor(Repo* re, float val){
	
    int i = 0; // 1 | 1
    int j = re->k-1; // 1 | 1
    int meio; // | 1
    
    while(i <= j){ // log(n)
    	
        meio = (i + j)/2; // 3
        
        if(val == re->dados[meio]->valor){ // 2log(n)
        	printf("\nCompra buscada por meio do valor: Codigo: [%d], Valor: [%.2f], Posicao: [%d]\n", re->dados[meio]->codigo, re->dados[meio]->valor, i); // 2
        	return meio; // 1
		} 
        if(val < re->dados[meio]->valor){ // 2log(n)
        	j = meio-1; // 2log(n)
		} 
        else{
        	i = meio+1; // 2log(n)
		}
               
     }
     
     return -1; // 1
	
}

// Complexidade temporal: O(9+9log(n)) = O(log(n)) (Logaritmica)
// Complexidade espacial: O(3) = O(c) (Constante)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pesquisarCodigo(Repo* re, int cod){
	
	int i = 0; // 1 | 1
	
	for(i=0; i<=re->n; i++){ // 2 + 2n
		
		if(re->dados[i]->codigo == cod){ // 2n
			printf("\nCompra buscada por meio do codigo: Codigo: [%d], Valor: [%.2f], Posicao: [%d]\n", re->dados[i]->codigo, re->dados[i]->valor, i); // 2
			return i; // 1
		}
		
	}
	
	return -1; // 1
	
}

// Complexidade temporal: O(7+4n) = O(n) (Linear)
// Complexidade espacial: O(1) = O(c) (Constante)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool estaCheio(Repo* re){
	
	if(re==NULL){ // 1
		printf("\nRepositorio Nao Cheio!");
		return false; // 1
	}
	else{

		if((re->k)==(re->n)){ // 1
			printf("\nRepositorio Cheio!");
			return true; // 1
		}
		else{
			printf("\nRepositorio Nao Cheio!");
			return false; // 1	
		}
		
	}
		
}

// Complexidade temporal: O(5) = O(c) (Constante)
// Complexidade espacial: O(0) = O(c) (Constante)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool estaVazio(Repo* re){
	
	if(re == NULL){ // 1
		printf("\nRepositorio Vazio!");
		return true; // 1	
	}
	else{
		
		if(re->k <= 0){ // 1
			printf("\nRepositorio Vazio!");
			return true; // 1	
		}
		
		else{
			printf("\nRepositorio nao Vazio!");
			return false; // 1	
		}
		
	}
	
}

// Complexidade temporal: O(5) = O(c) (Constante)
// Complexidade espacial: O(0) = O(c) (Constante)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void esvaziar(Repo* re){
	
	free(re); // 1
	
}

// Complexidade temporal: O(1) = O(c) (Constante)
// Complexidade espacial: O(0) = O(c) (Constante)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printRespositorio(Repo* re){
	
	int i = 0; // 1 | 1
	
	if((re!=NULL) && (re->k>0)){ // 1
		
		printf("\nLista de Compras:\n");
		for(i=0; i<re->k; i++){ // 2 + 2n
			printf("Codigo: [%d], Valor: [%.2f]\n", re->dados[i]->codigo, re->dados[i]->valor); // 2n
		}
		
	}
	else{
		printf("\nLista de Compras Vazia!");
	}
	
}

// Complexidade temporal: O(4+4n) = O(n) (Linear)
// Complexidade espacial: O(1) = O(c) (Constante)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Comp* criaCompra(int cod, float val){
	
	Comp *c = (Comp*) malloc(sizeof(Comp)); // 1 | 1
	
	c->codigo = cod; // 1
	c->valor = val; // 1
	
	return c; // 1
	
}

// Complexidade temporal: O(4) = O(c) (Constante)
// Complexidade espacial: O(1) = O(c) (Constante)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

