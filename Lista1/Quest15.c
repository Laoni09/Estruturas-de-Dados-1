#include <stdio.h>

int busca(int *v, int n, int x){
    if(n == 0) return 0;
    if(v[0] == x) return 1;
    busca(&v[1], n - 1, x);
}

int main(){
    int v[5] = {3, 2, 3, 1, 2};
    printf("%d", busca(&v, 5, 5));
}
