struct no{
 	int valor;
	struct no *proximo;
 } ;

typedef struct no No;
 
No* createNo(int v, No* proximo);
 
void printNo(No* no);

int igualdade(No* n, int c);
 
void freeNo(No *no);
