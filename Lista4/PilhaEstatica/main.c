#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    int v[MAX];
    int topo;
} pilha;

pilha *criaPilha(){
    pilha *p = (pilha*)malloc(sizeof(pilha));
    p->topo = -1;
}

int pilhaVazia(pilha *p){
    if(p->topo == -1) return 1;
    return 0;
}

void push(pilha *p, int x){
    p->topo++;
    p->v[p->topo] = x;
}

int pop(pilha *p){
    if(pilhaVazia(p)){
        printf("Pilha vazia!\n");
        return -1;
    }
    int x = p->v[p->topo];
    p->topo--;
    return x;
}

int main(){

}