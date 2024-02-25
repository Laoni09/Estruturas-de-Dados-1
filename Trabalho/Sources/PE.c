#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "PE.h"
#define MAX 100

Pilha *cria_pilha() {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = -1;
    p->n_vetores = 0;
    return p;
}

void pilha_push(Pilha *p, int *x, int tam) {
    p->topo++;
    p->n_vetores++;
    p->v[p->topo] = x;
    p->tam[p->topo] = tam;
}

int *pilha_pop(Pilha *p, int *tam_vetor) {
    if(p->topo == -1){
        printf("Pilha vazia.");
        return 0;
    }
    int *ptr;
    ptr = p->v[p->topo];
    *tam_vetor = p->tam[p->topo];
    p->topo--;
    p->n_vetores--;
    return ptr;
}

int pilhaVazia(Pilha *p){
    if(p->topo == -1) return 1;
    return 0;
}

void liberaPilha(Pilha *p){
    free(p);
}

int retornaTamanho(Pilha *p){
    return p->n_vetores;
}