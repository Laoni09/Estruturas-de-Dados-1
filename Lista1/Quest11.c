#include <stdio.h>

void ToBinary(int n){
    if(n == 0) return;
    ToBinary(n / 2);
    printf("%d", n % 2);
}

int main(){
    ToBinary(42);
}
