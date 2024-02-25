#include <stdio.h>

int strtam(char *s){
    if(s[0] == '\0') return 0;
    return 1 + strtam(&s[1]);
}

int main(){
    char str[20] = "hello";
    printf("%d", strtam(&str));
}
