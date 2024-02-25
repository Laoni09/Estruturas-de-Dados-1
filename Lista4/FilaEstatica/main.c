#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    int v[MAX];
    int ini, fim;
}Fila;

Fila *criaFila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = 0;
    return f;
}

int vazia(Fila *f) {
    return f->ini == f->fim ? 1 : 0;
}

void push(Fila *f, int x){
    f->v[f->fim] = x;
    f->fim = (f->fim + 1)%MAX;
}

int pop(Fila *f){
    int x = f->v[f->ini];
    f->ini = (f->ini + 1)%MAX;
}

int main(){

}