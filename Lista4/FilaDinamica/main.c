#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int info;
    struct Nodo *prox;
}nodo;

nodo *criaNodo(int x){
    nodo *novo = (nodo*)malloc(sizeof(nodo));
    novo->info = x;
    return novo;
}

typedef struct{
    nodo *ini;
    nodo *fim;
}Fila;

Fila *criaFila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
}

int vazia(Fila *f){
    return f->ini == NULL ? 1 : 0;
}

void push(Fila *f, int x){
    nodo *novo = criaNodo(x);
    if(f->fim != NULL)
        f->fim->prox = novo;
    f->fim = novo;
    if(f->fim == NULL) 
        f->ini = novo;
}

int pop(Fila *f){
    int x = f->ini->info;
    f->ini = f->ini->prox;
    nodo *aux = f->ini->prox;
    if(f->fim == f->ini)
        f->fim = NULL;
    free(f->ini);
    f->ini = aux;
    return x;
}

int main(){
    
}