#include <stdio.h>

int Potencia(int x, int k){
    if(k == 0) return 1;
    return x * Potencia(x, k - 1);
}

int main(){
    printf("%d", Potencia(3, 2));
}
