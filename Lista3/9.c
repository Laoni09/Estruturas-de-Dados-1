#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

    for (z = i; z <= f; z++) c[z] = v[z];
  z = i;

  while (iv <= m && ic <= f) {
    //Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente.

    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}

void sort(int *v, int *c, int i, int f){
    if (i >= f) return;
    int m = (i + f)/2;

    sort(v, c, i, m);
    sort(v, c, m + 1, f);

    merge(v, c, i, m, f);
}

void mergesort(int *v, int n) {
    int *c = (int*)malloc(n*sizeof(int));
    sort(v, c, 0, n - 1);
    free(c);
}

int main(){
    int i;
    int v[9] = {5, 9, 12, 0, 4, 15, 11, 2, 1};
    //selection(v, 4);
    //insertion(v1, 9);
    //bubble(v, 9);
    mergesort(v, 9);
    for(i = 0; i < 9; i++){
        printf("%d ", v[i]);
    }
}
