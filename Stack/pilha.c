#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha {
	int limite;
	int contador; 
	int* dados;
} ;

//////////////////////// CREATE ///////////////////////////////////////////////////////////////////////////////////////////////////

Pilha* create(int n){
	
	Pilha* pi = (Pilha*) malloc(sizeof(Pilha)); // 1 | 1
	
	if(pi == NULL){ // 1
		return NULL; // 1
	}else{
		pi->dados = (int*) malloc(n * sizeof(int)); // 1 | n
		pi->limite = n; // 1
		pi->contador = 0; // 1
		return pi; // 1
	}
			
}

// Complexidade temporal: O(7) = O(c) (Constante)
// Complexidade espacial: O(n+1) = O(n) (Linear)

//////////////////////// ADD //////////////////////////////////////////////////////////////////////////////////////////////////////

int add(Pilha* pi, int e){
	
	if(pi!=NULL && pi->contador < pi->limite ) { // 1
		int posicaoDaInsercao = pi->contador; // 1 | 1
		pi->dados[posicaoDaInsercao] = e; // 1
		pi->contador++; // 1
		return 1; // 1
	}
	else{
		return 0; // 1
	}	
		
}

// Complexidade temporal: O(6) = O(c) (Constante)
// Complexidade espacial: O(1) = O(c) (Constante)


//////////////////////// POP //////////////////////////////////////////////////////////////////////////////////////////////////////

int pop(Pilha* pi){
	
	if(pi!=NULL && !isEmpty(pi)){ // 1
		pi->contador--; // 1
		return 1; // 1
	}
	else{	
		return 0; // 1
	}	
	
}

// Complexidade temporal: O(4) = O(c) (Constante)
// Complexidade espacial: O(0)

//////////////////////// SIZE /////////////////////////////////////////////////////////////////////////////////////////////////////

int size(Pilha* pi){
	
	if(pi!=NULL && !isEmpty(pi)){ // 1
		return pi->contador; // 1
	}
	else{	
		return 0; // 1
	}
	
}

// Complexidade temporal: O(3) = O(c) (Constante)
// Complexidade espacial: O(0)

//////////////////////// TOP //////////////////////////////////////////////////////////////////////////////////////////////////////

int top(Pilha* pi){
	
	if(pi!=NULL && !isEmpty(pi)){ // 1
		int posicaoDoUltimoInserido = pi->contador-1; // 1 | 1
		return pi->dados[posicaoDoUltimoInserido]; // 1
	}
	else{
		return 0; // 1
	}	
	
}

// Complexidade temporal: O(4) = O(c) (Constante)
// Complexidade espacial: O(1) = O(c) (Constante)

//////////////////////// BOTTOM ///////////////////////////////////////////////////////////////////////////////////////////////////

int bottom(Pilha* pi){

	if(pi!=NULL && !isEmpty(pi)){ // 1
		return pi->dados[0]; // 1
	}
	else{
		return 0; // 1
	}	

}

// Complexidade temporal: O(3) = O(c) (Constante)
// Complexidade espacial: O(0)

//////////////////////// FIND /////////////////////////////////////////////////////////////////////////////////////////////////////

int find(Pilha* pi, int y, int *vetor, int j){
	
	int i; // 1 | 1
	
	if(pi!=NULL && !isEmpty(pi)){ // 1
		
		int cont=0; // 1 | 1
		
		for(i=0; i<=pi->contador; i++){ // 1+2n
			
			if(pi->dados[i] == y){ // n
				
				vetor[j] = i; // n
				j++; // n
				cont++; // n
				
			}
			
		}
		
		if(j==0){ //1
			return -1; //1
		}
		else{
			return cont; //1
		}
		
	}
	else{	
		return 0; //1	
	}
	
}

// Complexidade temporal: O(8+6n) = O(n) (Linear)
// Complexidade espacial: O(2) = O(c) (Constante)

//////////////////////// ISFULL ///////////////////////////////////////////////////////////////////////////////////////////////////

int isFull(Pilha* pi){
	
	if(pi==NULL){ // 1
		return 0; // 1
	}
	else{

		if((pi->contador)==(pi->limite)){ // 1
			return 1; // 1
		}
		else{
			return 0; // 1
		}
		
	}
	
}

// Complexidade temporal: O(5) = O(c) (Constante)
// Complexidade espacial: O(0)

//////////////////////// ISEMPTY //////////////////////////////////////////////////////////////////////////////////////////////////

int isEmpty(Pilha* pi){
	
	if(pi == NULL){	// 1
		return 1; // 1
	}
	
	if(pi->contador <= 0){ // 1
		return 1; // 1
	}
		
	else{	
		return 0; // 1	
	}
	
}

// Complexidade temporal: O(5) = O(c) (Constante)
// Complexidade espacial: O(0)

//////////////////////// CLEAR ////////////////////////////////////////////////////////////////////////////////////////////////////

int clear(Pilha* pi){
	
	if(pi==NULL){ // 1
		return 0; // 1
	}
	else{
		free(pi); //1
		return 1; //1
	}
	
}

// Complexidade temporal: O(4) = O(c) (Constante)
// Complexidade espacial: O(0)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
