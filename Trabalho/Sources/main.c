#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "PE.h"
#include "FE.h"

void bucketSort(int *v, int n, int exp){
    int count[10];
    int i, j = 0, k = 0;

    Fila *buckets[10];
    for(i = 0; i < 10; i++){
        buckets[i] = cria_fila();
        count[i] = 0;
    }

    for(i = 0; i < n; i++){
        fila_push(buckets[(v[i]%(10*exp))/exp], v[i]);
        count[(v[i]%(10*exp))/exp]++;
    }

    for(i = 0; i < 10; i++){
        for(j = 0; j < count[i]; j++){
            v[k] = fila_pop(buckets[i]);
            k++;
        }
    }
    liberaFila(*buckets);
}

void radixSort(int *v, int n, int ndigitos){
    int i, j, exp = 1;
    for(i = 0; i < ndigitos; i++){
        bucketSort(v, n, exp);
        exp *= 10;
        printf("[");
        for(j = 0; j < n - 1; j++){
            printf("%d ", v[j]);
        }
        if(i != ndigitos - 1) printf("%d] =>\n", v[n-1]);
        else printf("%d].\n", v[n-1]);
    }
}

int contaDigitos(int x){
    int i = 0;
    while (x != 0)
    {
        x /= 10;
        i++;
    }
    return i;
}

int maiorNumero(int *vetor, int tam_vetor){
    int i, maior = 0;
    for(i = 0; i < tam_vetor; i++){
        if(vetor[i] > maior) maior = vetor[i];
    }
    return maior;
}

int main(){
    Pilha *p = cria_pilha();
    int tam_vetor, n_vetores = 0, n_digitos = 0, cond = 0, maior_numero;
    char condstr[20];
    int vetor[MAX];
    int *ptr;
    do {
        scanf("%s", &condstr);
        if(strcmp(condstr, "push") == 0) cond = 1;
        if(strcmp(condstr, "pop") == 0) cond = 2;
        else if(strcmp(condstr, "F") == 0) cond = 3;
        int x[MAX], *xptr, num = 0, i = 0, j;
        switch (cond)
        {
        case 1:
            while (1)
            {
                scanf("%d", &num);
                if(num == -1) break;
                x[i] = num;
                i++;
            }
            printf("[");
            for(j = 0; j < i - 1; j++){
                printf("%d ", x[j]);
            }
            printf("%d] empilhado.", x[i-1]);
            xptr = (int*)malloc(sizeof(int)*i);
            for(j = 0; j < i; j++){
                xptr[j] = x[j];
            }
            pilha_push(p, xptr, i);
            n_vetores = retornaTamanho(p);
            printf("\n\n");
            break;
        case 2:
            if(pilhaVazia(p)){
                printf("Pilha vazia.\n");
                break;
            }
            ptr = pilha_pop(p, &tam_vetor);
            n_vetores = retornaTamanho(p);
            for (i = 0; i < tam_vetor; i++)
            {
                vetor[i] = ptr[i];
            }
            printf("[");
            for(i = 0; i < tam_vetor - 1; i++){
                printf("%d ", vetor[i]);
            }
            printf("%d] =>\n", vetor[i]);
            maior_numero = maiorNumero(vetor, tam_vetor);
            n_digitos = contaDigitos(maior_numero);
            radixSort(vetor, tam_vetor, n_digitos);
            free(xptr);
            printf("\n");
            break;
        case 3:
            printf("%d vetores sem ordenar.", n_vetores);
            for(i = 0; i < n_vetores; i++){
                ptr = pilha_pop(p, &tam_vetor);
            }
            cond = -1;
            break;
        }
    } while(cond != -1);
    liberaPilha(p);
    free(ptr);
}
