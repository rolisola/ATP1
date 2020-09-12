#include <stdio.h>

/*
    Dado dois números inteiros M e N, faça um programa que calcule e mostre a soma de todos os números primos dentro do intervalo [ M , N ].

    Exemplo:
        Entrada:
            1 10
        Saída:
            17
*/

int main()
{
    int i=1, j, numeroInicial, numeroFinal, naoSeiComoChamarEssaVariavel, somaNumeroPrimo=0;

    scanf("%d %d", &numeroInicial, &numeroFinal);
    while(i <= numeroFinal){
        if(i >= numeroInicial){
            naoSeiComoChamarEssaVariavel = 0;
            for(j=1;j<=i;j++){
                if(i%j == 0){
                    naoSeiComoChamarEssaVariavel++;
                }
            }
            if(naoSeiComoChamarEssaVariavel == 2){
                somaNumeroPrimo += i;
            }
        }
        i++;
    }

    printf("%d", somaNumeroPrimo);

    return 0;
}
