#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

int main() {
	
	ListaEncadeada * lista = create();
	int tam, loc;
	
	printListaEncadeada(lista);
	
	add(lista, 10);
	
	printListaEncadeada(lista);

	add(lista, 5);
	
	printListaEncadeada(lista);
	
	add(lista, 15);

	add(lista, 25);

	add(lista, 50);
	
	printListaEncadeada(lista);
	
	printf("\n------------------------------------------");
	loc = find(lista, 25);
	printf("\nPosicao do valor informado: %d\n", loc);
	printf("------------------------------------------\n");
	
	tam = size(lista);
	
	printf("\ntamanho da lista: %d\n", tam);
	
	remove(lista, 10);

	printListaEncadeada(lista);
	
	remove(lista, 25);
	
	printf("\n------------------------------------------");
	loc = find(lista, 15);
	printf("\nPosicao do valor informado: %d\n", loc);
	printf("------------------------------------------\n");
	
	printListaEncadeada(lista);
	
	remove(lista, 5);
	
	clear(lista);
	
	printListaEncadeada(lista);
	
	return 0;
}
