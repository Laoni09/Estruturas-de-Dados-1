#include <stdio.h>
#include <string.h>

int comparador(char *str1, char *str2){
    int i, j = 0, op = 0;
    char maior[100], menor[100];
    if(strlen(str1) >= strlen(str2)){
        strcpy(maior, str1);
        strcpy(menor, str2);
    }
    if(strlen(str1) < strlen(str2)){
        strcpy(maior, str2);
        strcpy(menor, str1);
    }
    printf("%s", menor);
    printf("%s", maior);
    for(i = 0; i < strlen(menor); i++){
        for(; j < strlen(maior); j++){
            if(maior[j] == menor[i]) {
                    op = 1;
                    j++;
                    break;
            }
            if(maior[j] != menor[i] && op == 1) return 0;
        }
    }
    return 1;
}

int main(){
    char str1[100] = "baciaoiiii";
    char str2[100] = "ciaoip";

    printf("%d", comparador(&str1, &str2));
    return 0;
}
