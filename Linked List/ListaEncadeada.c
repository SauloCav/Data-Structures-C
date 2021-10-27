#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

ListaEncadeada *create() {
	
	 ListaEncadeada *lista = (ListaEncadeada *)malloc(sizeof (ListaEncadeada));

	 if(lista != NULL) {
		 lista->inicio = NULL;
		 lista->fim = NULL;
		 lista->tamanho = 0;
	 }

	 return lista;
}

int add(ListaEncadeada *lista, int valor) {
	 
	No* pnovo = (No*) malloc(sizeof(No));

	if(pnovo != NULL) {
			 pnovo->valor = valor;
			 pnovo->proximo = NULL;

			 if(lista->inicio == NULL) {
				lista->inicio = pnovo;
			 } 
			 else {
				lista->fim->proximo = pnovo;
			 }

			 lista->fim = pnovo;
			 lista->tamanho++;
			 return 1;
	 }
	 
	 return 0;
}

int remove(ListaEncadeada *lista, int chave){
	
	 if (!isEmpty(lista)) {
		 
		 No *alvo = lista->inicio;
		 No *anterior;
		 
		 while(alvo != NULL && alvo->valor != chave) {
			anterior = alvo;
			alvo = alvo->proximo;
		 }

		 if(alvo != NULL) {
			 if(alvo != lista->inicio) {
				anterior->proximo = alvo->proximo;
			 } 
			 else {
				lista->inicio = alvo->proximo;
			 }

			 if(alvo == lista->fim) {
				lista->fim = anterior;
			 }

			 lista->tamanho--;
			 freeNo(alvo);
			 return 1;
			 
		 }
	 }
	 return 0;
}

int size(ListaEncadeada* lista){
	
	if(lista!=NULL && !isEmpty(lista)){
		return lista->tamanho;
	}
	else{	
		return 0;
	}
	
}

int find(ListaEncadeada* lista, int c){
	
	int i, cc=-1, rec;
	
	No *alvo = lista->inicio;
	
	if(lista!=NULL && !isEmpty(lista)){
		
		for(i=0; i<lista->tamanho; i++){

			if(i==0){
				alvo = lista->inicio;
			}
			else{ 
				alvo = alvo->proximo;
			}

			rec = igualdade(alvo, c);
			
			if(rec==1){
				cc = i;
				break;
			}
		}
		
		return cc;
		
	}
	else{
		
		return -1;
			
	}
	
}

int isEmpty(ListaEncadeada* lista){
	
	if(lista == NULL){
		return 0; 
	}
	
	if(lista->tamanho <= 0){ 
		return 1;
	}
	else{	
		return 0;
	}
	
}

void clear(ListaEncadeada* lista){
	
	lista->inicio=NULL; 
	lista->tamanho=0; 
	
}

void printListaEncadeada(ListaEncadeada* lista){
		 
	printf("\n----------IMPRIMINDO LISTA -------------\n\n");
		 
	printf("Lista [tamanho: %i, limite: quantidade de memoria alocavel] \n\n", lista->tamanho);
		 
	if(isEmpty(lista)){
		printf("Lista esta' vazia.\n");
	}	
	else{
		No *alvo = lista->inicio; 
		 
		while(alvo != NULL){
			printNo(alvo);
			alvo = alvo->proximo;
		}	
	}
		
}
