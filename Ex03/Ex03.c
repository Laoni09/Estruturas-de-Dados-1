#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int info;
    struct Nodo *prox;
    struct Nodo *ant;
}nodo;

typedef struct {
    nodo *topo;
}Pilha;

nodo *criaNodo(int x){
    nodo *novo = (nodo*)malloc(sizeof(nodo));
    novo->info = x;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

Pilha *criaPilha(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(Pilha *p, int x){
    nodo *novo = criaNodo(x);
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(Pilha *p) {
    if (p->topo == NULL) return 0;
    int x = p->topo->info;
    nodo *aux = p->topo->prox; // e se estiver vazia?
    free(p->topo);
    p->topo = aux;
    return x;
}

int main(){
    char exp[100];
    Pilha *p = criaPilha();
    scanf("%s", &exp);
    int i = 0, a, b, result;
    do
    {
        switch (exp[i])
        {
        case '+':
            a = pop(p);
            b = pop(p);
            result = a + b;
            push(p, result);
            break;
        
        case '*':
            a = pop(p);
            b = pop(p);
            result = a * b;
            push(p, result);
            break;
        default:
            push(p, exp[i] - '0');
        }
        i++;
    } while (exp[i] != '\0');
    result = pop(p);
    printf("%d", result);
}