typedef struct pilha Pilha;

Pilha* create(int n);

int add(Pilha* pi, int e);

int pop(Pilha* pi);

int size(Pilha* pi);

int top(Pilha* pi);

int bottom(Pilha* pi);

int find(Pilha* pi, int y, int *vetor, int j);

int isFull(Pilha* pi);

int isEmpty(Pilha* pi);

int clear(Pilha* pi);
