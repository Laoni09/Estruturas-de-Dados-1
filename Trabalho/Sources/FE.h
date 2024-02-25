#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#define MAX 100

typedef struct {
    int v[MAX];
    int ini, fim;
} Fila;

Fila *cria_fila();
void fila_push(Fila *f, int x);
int fila_pop(Fila *f);
void liberaFila(Fila *f);
int vazia(Fila *f);

#endif //PILHA_H_INCLUDED
//arrumar a derreferencia do n_vetores(ok) e libera filha e libera pilha