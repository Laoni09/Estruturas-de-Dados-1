#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#define MAX 100

typedef struct {
    int *v[MAX];
    int tam[MAX];
    int topo; // posicao do topo da pilha, inicialmente -1
    int n_vetores;
} Pilha;

Pilha *cria_pilha();
void pilha_push(Pilha *p, int *x, int tam);
int *pilha_pop(Pilha *p, int *tam_vetor);
int pilhaVazia(Pilha *p);
void liberaPilha(Pilha *p);
int retornaTamanho(Pilha *p);

#endif //PILHA_H_INCLUDED