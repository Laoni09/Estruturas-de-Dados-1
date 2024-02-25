#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#define MAX 100

typedef struct NodoPilha{
    int *info;
    int tam;
    struct NodoPilha *prox;
} nodopilha;

typedef struct {
    nodopilha *topo;
    int n_vetores;
} Pilha;

Pilha *cria_pilha();
void pilha_push(Pilha *p, int *x, int tam);
int *pilha_pop(Pilha *p, int *tam_vetor);
int pilhaVazia(Pilha *p);
void liberaPilha(Pilha *p);
int retornaTamanho(Pilha *p);

#endif //PILHA_H_INCLUDED