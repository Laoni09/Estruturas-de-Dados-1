#include <stdio.h>
int Exp(int n){
    if(n == 0) return 1;
    return 2 * Exp(n - 1);
}

int main(){
    printf("%d", Exp(3));
}
