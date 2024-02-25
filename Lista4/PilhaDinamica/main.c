#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int info;
    struct Nodo *prox;
} nodo;

typedef struct{
    nodo *topo;
}pilha;

nodo *novaLista(){
    nodo *lista = NULL;
    return lista;
}

nodo *criaNodo(int x){
    nodo *novo = (nodo*)malloc(sizeof(nodo));
    novo->info = x;
    novo->prox = NULL;
    return novo;
}

nodo *insereFinalRec(nodo *lista, int x){
    nodo *novo = criaNodo(x);
    if(lista == NULL){
        lista = novo;
        return lista;
    }
    lista->prox = insereFinalRec(lista->prox, x);
    return lista;
}

pilha *criaPilha(){
    pilha *p = (pilha*)malloc(sizeof(pilha));
    p->topo = NULL;
    return p;
}

int pilhaVazia(pilha *p){
    if(p->topo == NULL) return 1;
    return 0;
}

void push(pilha *p, int x){
    nodo *novo = criaNodo(x);
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(pilha *p){
    if(pilhaVazia(p)){
        printf("Pilha vazia\n");
        return -1;
    }
    int x = p->topo->info;
    nodo *aux = p->topo->prox;
    free(p->topo);
    p->topo = aux;
    return x;
}

void imprimeLista(nodo *lista){
    pilha *p = criaPilha();
    p->topo = lista;
    while(p->topo != NULL){
        printf("%d ", pop(p));
    }
}
int main(){
    int x;
    nodo *lista = novaLista();
    while(1){
        scanf("%d", &x);
        if(x == -1) break;
        lista = insereFinalRec(lista, x);
    }
    imprimeLista(lista);
}