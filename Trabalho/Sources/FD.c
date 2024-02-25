#include <stdio.h>
#include <stdlib.h>
#include "FD.h"

Fila *cria_fila() {
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
}

void fila_push(Fila *f, int x) { 
    nodo *novo = (nodo *)malloc(sizeof(nodo));
    novo->info = x;
    novo->prox = NULL;
    if (f->fim != NULL) 
    f->fim->prox = novo;
    f->fim = novo;
    if (f->ini==NULL) 
    f->ini = novo;
}

int fila_pop(Fila *f) { 
    int x = f->ini->info;
    nodo *aux = f->ini->prox;
    if (f->fim == f->ini)
    f->fim = NULL;
    free(f->ini);
    f->ini = aux;
    return x;
}

void liberaFila(Fila *f){
    if(vazia(f)) return; 
    nodo *prox, *atual;
    atual = f->ini;
    while(atual != NULL){
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

int vazia(Fila *f) {
    return f->ini == NULL ? 1 : 0;
}
