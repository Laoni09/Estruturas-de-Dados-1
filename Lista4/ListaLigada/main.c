#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int info;
    struct Nodo *prox;
} nodo;

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

nodo *insereInicio(nodo *lista, int x){
    nodo *novo = criaNodo(x);
    novo->prox = lista;
    return novo;
}

nodo *insereFinal(nodo *lista, int x){
    nodo *novo = criaNodo(x);
    if(lista == NULL){
        lista = novo;
        return lista;
    }
    nodo *aux = lista;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    return lista;
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

nodo *busca(nodo *lista, int x){
    nodo *aux = lista;
    while(aux != NULL){
        if(aux->info == x) return aux;
        aux = aux->prox;
    }
    return NULL;
}

void insereApos(nodo *r, int x){
    nodo *novo = criaNodo(x);
    nodo *aux = r;
    if(r == NULL){
        r = novo;
        return;
    }
    novo->prox = r->prox;
    aux->prox = novo;
}

nodo *remover(nodo *lista, int x){
    nodo *aux = lista;
    nodo *remover = criaNodo(x);
    if(lista->info == x){
        remover = lista;
        lista = remover->prox;
    }
    while(aux->prox != NULL){
        if(aux->prox->info == x){
            remover = aux->prox;
            aux->prox = remover->prox;
        }else{
            aux = aux->prox;
        }
    }
    return lista;
}

nodo *removerRec(nodo *lista, int x){
    if(lista == NULL){
        return lista;
    }
    nodo *remover;
    if(lista->info == x){
        remover = lista;
        lista = remover->prox;
    }
    lista->prox = removerRec(lista->prox, x);
}

nodo *inverte(nodo *lista){
    nodo *listainv = novaLista();
    nodo *aux = lista;
    while(aux != NULL){
        listainv = insereInicio(listainv, aux->info);
        aux = aux->prox;
    }
    return listainv;
}

nodo *pivota(nodo *lista, int x){
    if(lista == NULL) return lista;
    if(lista->info >= x) lista = lista->prox;
    lista->prox = pivota(lista->prox, x);
}

void imprime(nodo *lista){
    if(lista == NULL) return;
    printf("%d ", lista->info);
    imprime(lista->prox);
}

void imprimeInverso(nodo *lista){
    if(lista == NULL) return;
    imprimeInverso(lista->prox);
    printf("%d ", lista->info);
}

int main(){
    int x;
    nodo *lista = novaLista();
    while(1){
        scanf("%d", &x);
        if(x == -1) break;
        lista = insereFinalRec(lista, x);
    }
    imprime(lista);
    printf("\n");
    lista = pivota(lista, 7);
    imprime(lista);
}