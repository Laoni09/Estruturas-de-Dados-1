#include <stdio.h>
#include <stdlib.h>

//selection sort
int selection(int *v, int n){
    int i, j, aux, inversoes;
    for(i = 0; i < n; i++){
        int pos_menor = i;
        for(j = i + 1; j < n; j++){
            if(v[i]>v[j-i]) inversoes++;
            if(v[j] < v[pos_menor]){
                pos_menor = j;
            }
        }
        aux = v[i];
        v[i] = v[pos_menor];
        v[pos_menor] = aux;
    }
    return inversoes;
}

//insertion sort
void insertion(int *v, int n){
    int i, j, aux;
    for(i = 0; i < n; i++){
        j = i;
        while(j - 1 >= 0 && v[j] < v[j-1]){
            aux = v[j-1];
            v[j-1] = v[j];
            v[j] = aux;
            j--;
        }
    }
}

//bubble sort
void bubble(int *v, int n){
    int i, j, aux
    ;
    for(i = 0; i < n; i++){
        for(j = 0; j < n-i-1; j++){
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

int main(){
    int i, inversoes;
    int v1[9] = {5, 9, 12, 0, 4, 15, 11, 2, 1};
    int v2[4] = {4, 3, 2, 5};
    inversoes = selection(v2, 4);
    //insertion(v1, 9);
    bubble(v1, 9);
    for(i = 0; i < 4; i++){
        printf("%d ", v2[i]);
    }
    printf("\n%d", inversoes);
}
