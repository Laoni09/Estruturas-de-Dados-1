#include <stdio.h>

typedef struct Data{
    int dia;
    int mes;
    int ano;
} Data;

int AnoBi(Data data){
    if(data.ano % 4 == 0 && data.ano % 100 != 0) return 1;
    if(data.ano % 400 == 0) return 1;
    return 0;
}

int VerificaData(Data data){
    if(data.ano < 1 && data.mes < 1) return 0;
    int DiasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(AnoBi(data)) DiasPorMes[1] = 29;
    if(data.dia < 1 && data.dia > DiasPorMes[data.mes - 1]) return 0;
    return 1;
}

int main(){
    Data data;
    data.ano = 2016;
    data.mes = 02;
    data.dia = 30;

    printf("%d", VerificaData(data));
}
