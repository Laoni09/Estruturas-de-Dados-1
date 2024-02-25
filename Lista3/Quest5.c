#include <stdio.h>
#include <stdlib.h>
int selection(int *v, int i, int n){
    int j, aux;
    if(i == n) return;
    int pos_menor = i;
    for(j = i + 1; j < n; j++){
        if(v[j] < v[pos_menor]) pos_menor = j;
    }
    aux = v[i];
    v[i] = v[pos_menor];
    v[pos_menor] = aux;
    return selection(v, i+1, n);
}

int insertion(int *v, int i, int n){
    int j, aux;
    j = i;
    if(i == n) return;
    while(j - 1 >= 0 && v[j] < v[j-1]){
        aux = v[j-1];
        v[j-1] = v[j];
        v[j] = aux;
        j--;
    }
    return insertion(v, i + 1, n);
}

int bubble(int *v, int i, int n){
    int j, aux;
    if(i == n) return;
    for(j = 0; j < n - 1; j++){
        if(v[j] > v[j+1]){
            aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
        }
    }
    return bubble(v, i+1, n);
}

int main(){
    int i, x;
    int v[9] = {5, 9, 12, 0, 4, 15, 11, 2, 1};
    //selection(v, 0, 9);
    //insertion(v, 0, 9);
    bubble(v, 0, 9);
    for(i = 0; i < 9; i++){
        printf("%d ", v[i]);
    }
}
