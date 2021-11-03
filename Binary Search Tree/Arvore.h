struct no{
	
	int valor;
	int cont;
	int contadorFilho;
	struct no *filhoEsquerda;
	struct no *filhoDireita;
	
};typedef struct no ArvoreeNo;
	
ArvoreeNo *create(int valor);

ArvoreeNo *inserir_filho(ArvoreeNo *arvore, int valor);

int size(ArvoreeNo *arvore);

int busca(ArvoreeNo *arvore, int valor);

int find(ArvoreeNo *arvore, int valor);

int isEmpty(ArvoreeNo *arvore);

void pre_ordem(ArvoreeNo *arvore);
	
void em_ordem(ArvoreeNo *arvore);

void pos_ordem(ArvoreeNo *arvore);

void clear(ArvoreeNo *arvore);
