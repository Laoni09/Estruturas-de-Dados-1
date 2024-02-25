#include <stdio.h>

void imprimeDigitosInv(int n){
    if(n == 0) return;
    printf("%d\n", n % 10);
    imprimeDigitosInv(n / 10);
}

int main(){
    imprimeDigitosInv(123);
}
