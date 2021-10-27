#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

//////////////////////// CREATE ///////////////////////////////////////////////////////////////////////////////////////////////////

ListaEncadeada *create() {
	
	 ListaEncadeada *lista = (ListaEncadeada *)malloc(sizeof (ListaEncadeada)); // 1 | 1

	 if(lista != NULL) { // 1
		 lista->inicio = NULL; // 1
		 lista->fim = NULL; // 1
		 lista->tamanho = 0; // 1
	 }

	 return lista; // 1
}

// Complexidade temporal: O(6) = O(c) (Constante)
// Complexidade espacial: O(1) = O(c) (Constante)

//////////////////////// ADD //////////////////////////////////////////////////////////////////////////////////////////////////////

int add(ListaEncadeada *lista, int valor) {
	 
	No* pnovo = (No*) malloc(sizeof(No)); // 1 | 1

	if(pnovo != NULL) { // 1
			 pnovo->valor = valor; // 1
			 pnovo->proximo = NULL; // 1

			 if(lista->inicio == NULL) { // 1
				lista->inicio = pnovo; // 1
			 } 
			 else {
				lista->fim->proximo = pnovo; // 1
			 }

			 lista->fim = pnovo; // 1
			 lista->tamanho++; // 1
			 return 1; // 1
	 }
	 
	 return 0; // 1
}

// Complexidade temporal: O(11) = O(c) (Constante)
// Complexidade espacial: O(1) = O(c) (Constante)

//////////////////////// REMOVE ///////////////////////////////////////////////////////////////////////////////////////////////////

int remove(ListaEncadeada *lista, int chave){
	
	 if (!isEmpty(lista)) { // 1 
		 
		 No *alvo = lista->inicio; // 1 | 1
		 No *anterior; // 1 | 1
		 
		 while(alvo != NULL && alvo->valor != chave) { // n
			anterior = alvo; // n
			alvo = alvo->proximo; // n
		 }

		 if(alvo != NULL) { // 1
			 if(alvo != lista->inicio) { // 1
				anterior->proximo = alvo->proximo; // 1
			 } 
			 else {
				lista->inicio = alvo->proximo; // 1
			 }

			 if(alvo == lista->fim) {
				lista->fim = anterior; // 1
			 }

			 lista->tamanho--; // 1
			 freeNo(alvo); // 1
			 return 1; // 1
			 
		 }
	 }
	 return 0; // 1
}

// Complexidade temporal: O(12+3n) = O(n) (LINEAR)
// Complexidade espacial: O(2) = O(c) (Constante)

//////////////////////// SIZE /////////////////////////////////////////////////////////////////////////////////////////////////////

int size(ListaEncadeada* lista){
	
	if(lista!=NULL && !isEmpty(lista)){ // 2
		return lista->tamanho; // 1
	}
	else{	
		return 0; // 1
	}
	
}

// Complexidade temporal: O(4) = O(c) (Constante)
// Complexidade espacial: O(0) = O(c) (Constante)

//////////////////////// FIND /////////////////////////////////////////////////////////////////////////////////////////////////////

int find(ListaEncadeada* lista, int c){
	
	int i, cc=-1, rec; // 3 | 3
	
	No *alvo = lista->inicio; // 1 | 1
	
	if(lista!=NULL && !isEmpty(lista)){ // 1
		
		for(i=0; i<lista->tamanho; i++){ // n

			if(i==0){ // n
				alvo = lista->inicio; // n
			}
			else{ 
				alvo = alvo->proximo; // n
			}

			rec = igualdade(alvo, c); // n
			
			if(rec==1){ // n
				cc = i; // 1
				break; // 1
			}
		}
		
		return cc; // 1
		
	}
	else{
		
		return -1; // 1
			
	}
	
}

// Complexidade temporal: O(9+6n) = O(n) (Linear)
// Complexidade espacial: O(4) = O(c) (Constante)

//////////////////////// ISEMPTY //////////////////////////////////////////////////////////////////////////////////////////////////

int isEmpty(ListaEncadeada* lista){
	
	if(lista == NULL){ // 1
		return 0; // 1	
	}
	
	if(lista->tamanho <= 0){ // 1	
		return 1; // 1
	}
	else{	
		return 0; // 1
	}
	
}

// Complexidade temporal: O(5) = O(c) (Constante)
// Complexidade espacial: O(0) = O(c) (Constante)

//////////////////////// CLEAR ////////////////////////////////////////////////////////////////////////////////////////////////////

void clear(ListaEncadeada* lista){
	
	lista->inicio=NULL; // 1
	lista->tamanho=0; // 1
	
}

// Complexidade temporal: O(2) = O(c) (Constante)
// Complexidade espacial: O(0) = O(c) (Constante)

//////////////////////// PRINTLISTAENCADEADA //////////////////////////////////////////////////////////////////////////////////////

void printListaEncadeada(ListaEncadeada* lista){
		 
	printf("\n----------IMPRIMINDO LISTA -------------\n\n");
		 
	printf("Lista [tamanho: %i, limite: quantidade de memoria alocavel] \n\n", lista->tamanho);
		 
	if(isEmpty(lista)){ // 1
		printf("Lista esta' vazia.\n");
	}	
	else{
		No *alvo = lista->inicio; // 1 | 1
		 
		while(alvo != NULL){ // n
			printNo(alvo); // 1
			alvo = alvo->proximo; // 1
		}	
	}
		
}

// Complexidade temporal: O(4+n) = O(n) (Linear)
// Complexidade espacial: O(1) = O(c) (Constante)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

