#include <stdio.h>
#include <stdlib.h>

void MatrizTransposta(int **A, int **At, int n, int m){
    int i, j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            At[i][j] = A[j][i];
            printf("%d", At[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n = 3, m = 2, i, j;
    int **A, **At;
    //memória pra matriz A
    A = malloc(n * sizeof(int));
    for(i = 0; i < n; i++){
        A[i] = malloc(m * sizeof(int));
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            A[i][j] = j + i;
            printf("%d", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    //memória pra matriz A transposta
    At = malloc(n * sizeof(int));
    for(i = 0; i < m; i++){
        At[i] = malloc(n * sizeof(int));
    }

    MatrizTransposta(A, At, n, m);

    //liberando as colunas e as linhas
    for(i = 0; i < n; i++){
        free(A[i]);
    }
    for(i = 0; i < m; i++){
        free(At[i]);
    }
    free(A);
    free(At);
    return 0;
}
