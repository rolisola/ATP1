#include <stdio.h>
#include <stdlib.h>

/*
    Faça um programa que leia um valor N, inteiro e positivo, calcule e mostre o valor da seguinte soma:
        Soma = 1 + 1/2 + 1/3 + 1/4 + ... + 1/N
    Exemplo:
        Entrada:
            5
        Saída:
            2.283334
*/

int main()
{
    int i, valor;
    float soma=0;

    printf("Insira um valor inteiro positivo: ");
    scanf("%d", &valor);
    for(i=1;i<=valor;i++){
        soma = soma + 1/(float)i;
    }

    printf("\nA soma é: ");
    printf("%f", soma);

    return 0;
}
