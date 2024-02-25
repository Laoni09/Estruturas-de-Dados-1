#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int info;
    struct Nodo *prox;
    struct Nodo *ant;
}nodo;

nodo *novaLista(){
    nodo *lista = NULL;
    return lista;
}

nodo *criaNodo(int x){
    nodo *novo = (nodo*)malloc(sizeof(nodo));
    novo->info = x;
    novo->prox = NULL;
    novo->ant = NULL;
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
    novo->ant = aux;
    aux->prox = novo;
    return lista;
}

void vaievolta(nodo *lista){
    nodo *aux = lista;
    while(aux->prox != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("%d\n", aux->info);
    while(aux->ant != NULL){
        printf("%d ", aux->info);
        aux = aux->ant;
    }
    printf("%d", aux->info);
}

void vaievoltaRec(nodo *lista){
    if(lista == NULL){
        printf("\n");
        return;
    }
    printf("%d ", lista->info);
    vaievoltaRec(lista->prox);
    printf("%d ", lista->info);
}

nodo *swap(nodo *A, nodo *B){
    if (A->ant != NULL){
        A->ant->prox = B;
    }

    if (B->prox != NULL){
        B->prox->ant = A;
    }

    A->prox = B->prox;
    B->ant = A->ant;
    B->prox = A;
    A->ant = B;
    return B;
}

/*nodo *bubble(nodo *lista){
    nodo *aux = lista;
    nodo *i = lista;
    while(i != NULL){
        aux = lista;
        nodo *j = lista;
        while(j != NULL){
            nodo *ptr1 = aux;
            nodo *ptr2 = aux->prox;
            if(ptr1->info > ptr2->info){
                aux = swap(ptr1, ptr2);
            }
            printf("j ");
            aux = aux->prox;
            j = j->prox;
        }
        printf("\ni");
        i = i->prox;
    }
    return lista;
}*/

void imprime(nodo *lista){
    if(lista == NULL) return;
    printf("%d ", lista->info);
    imprime(lista->prox);
}

int main(){
    int x;
    nodo *lista = novaLista();
    while(1){
        scanf("%d", &x);
        if(x == -1) break;
        lista = insereFinal(lista, x);
    }
    printf("\n");
    //lista = bubble(lista);
    //lista = swap(lista, lista->prox);
    imprime(lista);
}