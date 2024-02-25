#include <stdio.h>
#include <stdlib.h>
void Inserir(int *v, int x){
    int i, aux;
    v[5] = x;
    for(i = 4; i >= 0; i--){
        if(x < v[i]){
            aux = v[i];
            v[i] = x;
            v[i+1] = aux;
        }
    }
}
int main(){
    int *v, x, i;
    v = (int*)malloc(6*sizeof(int));
    for(i = 0; i < 5; i++){
        v[i] = i*2;
    }
    scanf("%d", &x);
    Inserir(v, x);
    for(i = 0; i < 6; i++){
        printf("%d", v[i]);
    }
    free(v);
}
