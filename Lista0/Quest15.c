#include <stdio.h>
#include <stdlib.h>

void ProdutoMatricial(int **A, int **B, int **C, int n, int m, int k){
    int i, j, l, somaprod;
    for(i = 0; i < n; i++){
        for(j = 0; j < k; j++){
            somaprod = 0;
            for(l = 0; l < m; l++){
                somaprod += A[i][l] * B[l][i];
            }
            C[i][j] = somaprod;
            printf("%d", C[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n = 2, m = 2, k = 2, i, j;
    int **A, **B, **C;
    //alocando A
    A = malloc(n * sizeof(int));
    for(i = 0; i < n; i++){
        A[i] = malloc(n * sizeof(int));
    }
    //preenchendo A
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            A[i][j] = 8;
        }
    }
    //alocando B
    B = malloc(m * sizeof(int));
    for(i = 0; i < m; i++){
        B[i] = malloc(n * sizeof(int));
    }
    //preenchendo B
    for(i = 0; i < m; i++){
        for(j = 0; j < k; j++){
            B[i][j] = 2;
        }
    }
    //alocando C
    C = malloc(n * sizeof(int));
    for(i = 0; i < n; i++){
        C[i] = malloc(k * sizeof(int));
    }

    ProdutoMatricial(A, B, C, n, m, k);

}
