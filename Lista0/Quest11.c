#include <stdio.h>
#include <stdlib.h>

int ProdutoInterno(int *a, int *b, int n){
    int i, soma = 0;
    printf("%d\n", a[4]);
    for(i = 0; i < n; i++){
        soma += a[i] * b[i];
    }
    return soma;
}
int main(){
    int i;
    int *a;
    int *b;
    a = (int*) malloc(6 * sizeof(int));
    b = (int*) malloc(6 * sizeof(int));
    for(i = 0; i < 6; i++){
        a[i] = i;
        b[i] = i;
        //printf("%d\n", a[i]);
    }
    int soma = ProdutoInterno(a, b, 5);
    printf("%d", soma);
}
