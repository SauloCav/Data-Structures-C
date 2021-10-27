#include <stdio.h>
#include <stdlib.h>
#include "No.h"
 
typedef struct {
	 No *inicio;
	 No *fim;
	 int tamanho;
} ListaEncadeada;

ListaEncadeada* create();

int add(ListaEncadeada* lista, int valor);

int remove(ListaEncadeada *lista, int chave);

int find(ListaEncadeada* lista, int c);

int isEmpty(ListaEncadeada* lista);

int size(ListaEncadeada* lista);

void clear(ListaEncadeada* lista);

void printListaEncadeada(ListaEncadeada* listaEncadeada);
