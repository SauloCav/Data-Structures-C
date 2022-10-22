typedef struct lista Lista;

Lista* create(int n);

int add(Lista* li, int e);
int addAtPosition(Lista* li, int i, int x);
int remove(Lista* li, int x); 
int removeAtPosition(Lista* li, int i, int x);
int size(Lista* li);
int find(Lista* li, int y, int *vetor, int j);
int isFull(Lista* li);
int isEmpty(Lista* li);
int clear(Lista* li);

void printLista(Lista* li);
