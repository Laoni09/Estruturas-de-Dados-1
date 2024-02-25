#include <stdio.h>

int Soma(int *v, int n){
    if(n == 0) return 0;
    return v[n] + Soma(&v, n - 1);
}

int main(){
    int v[5] = {3, 2, 3, 1, 2};
    printf("%d", Soma(&v, 5));
}
