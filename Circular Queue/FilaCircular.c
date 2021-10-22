#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "FilaCircular.h"

struct filaCircular{
	
	int lim; 
	int* dados; 
	int o;
	int f;

};

Fila* create(int n){
	
	Fila* fi = (Fila*) malloc(sizeof(Fila));
	
	if(fi == NULL){
		return NULL;
	}
	else{
		fi->dados = (int*) malloc(n * sizeof(int));
		fi->lim = n;
		fi->o = -1;
		fi->f = -1;
		return fi;
	}
			
}

int add(Fila* fi, int e){
	
	if((fi!=NULL) && (!isFull(fi))){
	
		if(fi->o == -1){
			fi->o = 0;
			fi->f = 0;
		}
		else{
			if(fi->f == (fi->lim-1)){
				fi->f = 0;
			}	
			else{
				fi->f = fi->f+1;
			}
		}
		
		fi->dados[fi->f] = e;
		
		return 1;
		
	}
	else{
		
		return 0;
		
	}
	
}

int remove(Fila* fi){
	
	if(!isEmpty(fi)){
	
		if(fi->o == fi->f){
			fi->o = -1;
			fi->f = -1;
		}
		else{
			if(fi->o == fi->lim-1){
				fi->o = 0;
			}
			else{
				fi->o = fi->o+1;
			}
		}
		
		return 1;
		
	}
	else{
		
		return 0;
		
	}

}

int isFull(Fila* fi){
	
	if(fi==NULL){
		
		return 0;
			
	}
	else{
		
		if((fi->o == 0) && (fi->f == (fi->lim-1)) || (fi->o == (fi->f+1))){
			return 1;
		}
		else{	
			return 0;
		}
		
	}
	
}

int isEmpty(Fila* fi){
	
	if(fi==NULL){
		
		return 0;
			
	}
	else{
		
		if(fi->o == -1){
			return 1;
		}
		else{	
			return 0;
		}
		
	}
	
}

void printFila(Fila* fi){
	
	int ff = fi->f;
	int oo = fi->o;
	
	if(fi==NULL){
		
		return;
		
	}
	else{
		
		if(!isEmpty(fi)){
		
		printf("\nFila{ | ");
		if(oo <= ff){
			while(oo <= ff){
			
				printf("%d | ", fi->dados[oo]);
				oo++;
				
			}
		}
		else{
			while(oo <= ((fi->lim)-1)){
			
				printf("%d | ", fi->dados[oo]);
				oo++;
				
			}	
			
			oo = 0;
			
			while(oo <= ff){
			
				printf("%d | ", fi->dados[oo]);
				oo++;
				
			}	
			
		}
		
		printf("}\n");
		
		}
		else{
			
			printf("\nFila Vazia!!");
			
		}
			
	}
		
}
