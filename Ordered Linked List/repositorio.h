#include <stdio.h>
#include <stdlib.h>

typedef struct repositorio Repo;
typedef struct CompraRealizada Comp;

Comp* criaCompra(int cod, float val);

Repo* criarRepositorio(int n);

int adicionar(Repo* re, int cod, float val);

Comp* tratar(Repo* re);

int tamanho(Repo* re);

int pesquisarValor(Repo* re, float val);

int pesquisarCodigo(Repo* re, int cod);

bool estaCheio(Repo* re);

bool estaVazio(Repo* re);

void esvaziar(Repo* re);

void printRespositorio(Repo* re);
