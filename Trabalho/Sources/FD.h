#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct Nodo{
    int info;
    int tam;
    struct Nodo *prox;
} nodo;

typedef struct {
    nodo *ini;
    nodo *fim;
} Fila;

Fila *cria_fila();
void fila_push(Fila *f, int x);
int fila_pop(Fila *f);
void liberaFila(Fila *f);
int vazia(Fila *f);

#endif //PILHA_H_INCLUDED