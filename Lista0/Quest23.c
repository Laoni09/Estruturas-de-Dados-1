#include <stdio.h>
#include <stdlib.h>

typedef struct Coordenada{
    int i;
    int j;
} Coordenada;

int Oceano(Coordenada **A, Coordenada *B){
    int i, j;
    for(i )
}

int main(){
    int i, j, n = 2, m = 3;
    Coordenada **A, *B;
    //alocando a matriz A
    A = malloc(n * sizeof(Coordenada));
    for(i = 0; i < m; i++){
        A[i] = malloc(m * sizeof(Coordenada));
    }
    //alocando o vetor B
    B = malloc(n * m * sizeof(Coordenada));
    //preenchendo A com coordenadas
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            A[i][j].i = i;
            A[i][j].j = j;
        }
    }
    printf("Quantidade de navios: %d", Oceano(A, B));
}
