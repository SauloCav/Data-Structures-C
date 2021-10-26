#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

int main() {
	
	ArvoreeNo *arv = create(17);
	
	arv = inserir_filho(arv, 99);
	arv = inserir_filho(arv, 13);
	arv = inserir_filho(arv, 1);
	arv = inserir_filho(arv, 3);
	arv = inserir_filho(arv, 100);
	arv = inserir_filho(arv, 400);
	
	printf("\nEm ordem ");
	
	em_ordem(arv);
	
	printf("\n");
	isEmpty(arv);
	
	printf("\n");
	size(arv);
	
	printf("\n");
	printf("\n");
	find(arv, 13);
	find(arv, 17);
	find(arv, 1);
	find(arv, 400);
	find(arv, 4);
	
	clear(arv);
	
	isEmpty(arv);
	
}
