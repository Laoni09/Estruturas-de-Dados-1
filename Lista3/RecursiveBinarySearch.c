#include <stdio.h>

int buscabinaria(int *v, int n, int x){
    int i = 0;
    int f = n - 1;
    while(i <= f){
        int meio = (i + f)/2;
        if(x == v[meio]) return 1;
        if(x < v[meio]) f = meio - 1;
        if(x > v[meio]) i = meio + 1;
    }
    return 0;
}

int buscabinariarecursiva(int *v, int i, int f, int x){
    if(i == f) return 0;
    int meio = (i + f)/2;
    if(x > v[meio]) return buscabinariarecursiva(v, meio + 1, f, x);
    if(x < v[meio]) return buscabinariarecursiva(v, i, meio - 1, x);
    if(x == v[meio]) return 1;
}

int main(){
    int i;
    int v[9] = {0, 3, 5, 8, 12, 16, 21, 40, 70};
    printf("%d", buscabinariarecursiva(v, 0, 8, 12));
}
