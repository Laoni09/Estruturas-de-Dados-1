#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void bucketSort(int *v, int n, int exp){
    int buckets[10][9999];
    //vetor que conta quantos n�meros tem cada bucket
    int count[10];
    int i, j = 0, k = 0;
    //preenche o vetor count com zeros
    for(i = 0; i < 10; i++){
        count[i] = 0;
    }
    //printf("numero: %d ", (v[0]%(10*exp))/exp);
    //coloca cada numero em seu respectivo bucket
    for(i = 0; i < n; i++){
        buckets[(v[i]%(10*exp))/exp][count[(v[i]%(10*exp))/exp]] = v[i];
        count[(v[i]%(10*exp))/exp]++;
    }
    //ordena os buckets
    for(i = 0; i < 10; i++){
        insertion(buckets[i], count[i]);
    }
    //concatena os buckets
    int nb = 0; //numero do bucket
    for(i = 0; i < 10; i++){
        for(j = 0; j < count[nb]; j++){
            v[k] = buckets[nb][j];
            //printf("v[%d] recebe %d\n", k, buckets[nb][j]);
            k++;
        }
        nb++;
    }
}

void radixSort(int *v, int n, int ndigitos){
    int i, j, exp = 1;
    for(i = 0; i < ndigitos; i++){
        bucketSort(v, n, exp);
        exp *= 10;
        for(j = 0; j < n; j++){
            printf("%d ", v[j]);
        }
        printf("\n");
    }
}

 int main(){
    int i;
    int v[6] = {4367, 6462, 1128, 3692, 9815, 6359};
    radixSort(v, 6, 4);
    /*for(i = 0; i < 9; i++){
        printf("%d ", v[i]);
    }*/
 }
