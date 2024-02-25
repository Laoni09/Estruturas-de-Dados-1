#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int c = 30;

    int *v[3] = {&a, &b, &c}; // Vetor de ponteiros para inteiros

    int *ptr = *&v[2]; // ptr aponta para o valor apontado pelo terceiro elemento de v

    printf("Valor apontado por v[2]: %d\n", *ptr); // Imprime o valor apontado por v[2]

    return 0;
}
