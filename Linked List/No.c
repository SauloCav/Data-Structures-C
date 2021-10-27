#include <stdio.h>
#include <stdlib.h>
#include "No.h"

//////////////////////// CREATENO /////////////////////////////////////////////////////////////////////////////////////////////////

No* createNo(int v, No* proximo){
 	
 	No * n = (No*) malloc(sizeof(No)); // 1 | 1
 	
 	n->valor = v; // 1 
 	n->proximo = proximo; // 1
 	
 	return n; // 1
 	
}

// Complexidade temporal: O(4) = O(c) (Constante)
// Complexidade espacial: O(1) = O(c) (Constante)

//////////////////////// PRINTNO //////////////////////////////////////////////////////////////////////////////////////////////////
 
void printNo(No* n){
 	
 	if(n != NULL && n->proximo != NULL) // 2
 		printf("No [valor: %i, proximo: %i]\n", n->valor, n->proximo->valor);
 	else if(n != NULL) // 1
 		printf("No [valor: %i, proximo: NULL]\n", n->valor);
 	else
 		printf("NULL\n");
 	
}

// Complexidade temporal: O(3) = O(c) (Constante)
// Complexidade espacial: O(0) = O(c) (Constante)

//////////////////////// IGUALDADE ////////////////////////////////////////////////////////////////////////////////////////////////

int igualdade(No* n, int c){
	
	if(c==n->valor){ // 1
		return 1; // 1
	}
	else{
		return 0; // 1
	} 
	
}

// Complexidade temporal: O(3) = O(c) (Constante)
// Complexidade espacial: O(0) = O(c) (Constante)

//////////////////////// FREENO ///////////////////////////////////////////////////////////////////////////////////////////////////
 
void freeNo(No* n){
 	free(n); // 1
}

// Complexidade temporal: O(1) = O(c) (Constante)
// Complexidade espacial: O(0) = O(c) (Constante)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

