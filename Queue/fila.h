typedef struct fila Fila;

Fila* create(int n); //

int add(Fila* fi, int e); //

int pop(Fila* fi); //

int size(Fila* fi); //

int first(Fila* fi); //

int last(Fila* fi); //

int find(Fila* fi, int y, int *vetor, int j); //

int isFull(Fila* fi); //

int isEmpty(Fila* fi); //

void clear(Fila* fi); //

void printFila(Fila* fi); //

