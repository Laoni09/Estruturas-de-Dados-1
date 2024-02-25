#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "PD.h"
#define MAX 100

Pilha *cria_pilha() {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    p->n_vetores = 0;
    return p;
}

void pilha_push(Pilha *p, int *x, int tam) {
    nodopilha *novo;
    novo = (nodopilha*)malloc(sizeof(nodopilha));
    int i;
    novo->info = x;
    novo->tam = tam;
    novo->prox = p->topo;
    p->topo = novo;
    p->n_vetores++;
}

int *pilha_pop(Pilha *p, int *tam_vetor) {
    if(p->topo == NULL){
        printf("Pilha vazia.");
        return 0;
    }
    p->n_vetores--;
    int *ptr;
    *tam_vetor = p->topo->tam;
    ptr = p->topo->info;
    nodopilha *aux = p->topo->prox; 
    free(p->topo);
    p->topo = aux;
    return ptr;
}

int pilhaVazia(Pilha *p){
    if(p->topo == NULL) return 1;
    return 0;
}

void liberaPilha(Pilha *p){
    if(pilhaVazia(p)) return;
    nodopilha *prox, *atual;
    atual = p->topo;
    while(atual != NULL){
        prox = atual->prox;
        free(atual->info);
        free(atual);
        atual = prox;
    }
}

int retornaTamanho(Pilha *p){
    return p->n_vetores;
}