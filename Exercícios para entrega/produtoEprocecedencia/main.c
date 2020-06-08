#include <stdio.h>
#include <stdlib.h>
/*
    Faça um programa que receba o código de origem e mostre a sua procedência. A procedência obedece à tabela a seguir.

    Código	Procedência
    1	Sul
    2	Norte
    3	Leste
    4	Oeste
    5 ou 6	Noroeste
    7 ou 8 ou 9	Sudeste
    10 a 20	Centro-oeste
    21 a 30	Nordeste
*/
int main()
{
    int codigo;

    //printf("digite o codigo de origem:\n");
    scanf("%d",&codigo);

    if(codigo == 1){
        printf("Sul");
    }else if(codigo == 2){
        printf("Norte");
    }else if(codigo == 3){
        printf("Leste");
    }else if(codigo == 4){
        printf("Oeste");
    }else if((codigo == 5) || (codigo == 6)){
        printf("Noroeste");
    }else if((codigo == 7) || (codigo == 8) || (codigo == 9)){
        printf("Sudeste");
    }else if((codigo >= 10) && (codigo <= 20)){
        printf("Centro-oeste");
    }else if((codigo >= 21) && (codigo <= 30)){
        printf("Nordeste");
    }
    return 0;
}
