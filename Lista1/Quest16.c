#include <stdio.h>

int maior(int *v, int n){
    if(n == 0) return v[n];
    if(v[0] > v[1]) v[1] = v[0];
    maior(&v[1], n - 1);
}

int main(){
    int v[5] = {12, 2, 0, 1, 20};
    printf("%d", maior(&v, 5));
}
