#include <stdlib.h>
#include <stdio.h>
#include "Arvore.h"
	
ArvoreeNo *create(int valor){
	
	ArvoreeNo *arv = (ArvoreeNo *)calloc(1, sizeof(ArvoreeNo));

	arv->cont = 1;
	arv->valor = valor;
	arv->filhoDireita = NULL;
	arv->filhoEsquerda = NULL;
	arv->contadorFilho = 1;
	return arv;
	
}

ArvoreeNo *inserir_filho(ArvoreeNo *arvore, int valor){
	
	if(!arvore){
		arvore = create(valor);
		return arvore;
	}
	else{
		ArvoreeNo *no = create(valor);
		ArvoreeNo *folha = arvore;
		while(folha){
			
			if(folha->contadorFilho){
				if(folha->valor > valor){
					folha->filhoEsquerda = no;
					folha->contadorFilho = 0;
					break;
				}
				else{
					folha->filhoDireita = no;
					folha->contadorFilho = 0;
					break;
				}
			}
			else{
				if(folha->valor > valor){
					if(folha->filhoEsquerda == NULL){
						folha->filhoEsquerda = no;
						break;
					}
					folha = folha->filhoEsquerda;
				}
				else{
					if(folha->filhoDireita == NULL){
						folha->filhoDireita = no;
						break;
					}
					folha = folha->filhoDireita;
				}
			}
			
		}
	}
	arvore->cont ++;
	return arvore;	
}

int size(ArvoreeNo *arvore){
	
	if((arvore!=NULL) && (arvore->cont > 0)){
		printf("\nNumero de elementos na arvore: %d", arvore->cont);
		return arvore->cont;
	}
	else{	
		return 0;
	}
	
}

int busca(ArvoreeNo *arvore, int valor){
	
	if(!arvore){
		return 0;
	}
	if(arvore->valor == valor){
		return arvore->valor;
	}
	else if(arvore->valor > valor){
		return busca(arvore->filhoEsquerda, valor);
	}
	else{
		return busca(arvore->filhoDireita, valor);
	}
	
}

int find(ArvoreeNo *arvore, int valor){
	
	int no = busca(arvore, valor);
	
	if(no == 0){
		printf("Valor solicitado %d nao encontrado!\n", valor);
		return NULL;
	}
	else{
		printf("Valor solicitado %d encontrado!\n", valor);
		return no;
	}
	
}

int isEmpty(ArvoreeNo *arvore){
	
	if(arvore == NULL){
		printf("\nArvore Vazia");
		return 0;
	}
	
	if(arvore->cont <= 0){
		printf("\nArvore Vazia");
		return 1;
	}	
	else{
		printf("\nArvore nao Vazia");
		return 0;
	}
	
}

void pre_ordem(ArvoreeNo *arvore){
	
	if(!arvore){
		return;
	}
	
	printf("%d ", arvore->valor);
	em_ordem(arvore->filhoEsquerda);
	em_ordem(arvore->filhoDireita);
	
}

void em_ordem(ArvoreeNo *arvore){
	
	if(!arvore){
		return;
	}
	
	em_ordem(arvore->filhoEsquerda);
	printf("%d ", arvore->valor);
	em_ordem(arvore->filhoDireita);
	
}

void pos_ordem(ArvoreeNo *arvore){
	
	if(!arvore){
		return;
	}
	
	em_ordem(arvore->filhoEsquerda);
	em_ordem(arvore->filhoDireita);
	printf("%d ", arvore->valor);
	
}

void clear(ArvoreeNo *arvore){
	
	if(!arvore){
		return;
	}
	
	clear(arvore->filhoDireita);
	clear(arvore->filhoEsquerda);
	free(arvore);
	
}

