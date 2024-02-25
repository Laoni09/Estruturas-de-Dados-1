#include <stdio.h>

void imprimeDigitos(int n){
    if(n == 0) return;
    imprimeDigitos(n / 10);
    printf("%d\n", n % 10);
}

int main(){
    imprimeDigitos(123);
}
