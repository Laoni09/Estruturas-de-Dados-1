#include <stdio.h>
int Fatorial(int n){
    if(n == 0) return 1;
    return n * Fatorial(n - 1);
}

int main(){
    printf("%d", Fatorial(5));
}
