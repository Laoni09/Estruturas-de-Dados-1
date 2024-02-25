#include <stdio.h>

int Potencia(int x, int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return Potencia(x, k / 2) * Potencia(x, k / 2);
    if(k % 2 != 0) return x * Potencia(x, k - 1);
}

int main(){
    printf("%d", Potencia(2, 6));
}
