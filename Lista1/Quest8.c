#include <stdio.h>

int ContaDigito(int n){
    if(n == 0) return 0;
    return 1 + ContaDigito(n/10);
}

int main(){
    printf("%d", ContaDigito(475));
}
