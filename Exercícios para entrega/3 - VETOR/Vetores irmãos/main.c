#include <stdio.h>
#include <stdlib.h>

/*
    Faça um programa que preencha um vetor com dez números inteiros e um segundo vetor com cinco números inteiros, calcule e mostre dois vetores resultantes. O primeiro vetor resultante será composto pela soma de cada número par do primeiro vetor somado a todos os números do segundo vetor. O segundo vetor resultante será composto pela quantidade de divisores que cada número ímpar do primeiro vetor tem no segundo vetor.

    Primeiro Vetor 4 7 5 8 2 15 9 6 10 11

    Segundo Vetor 3 4 5 8 2

    Primeiro vetor resultante
        26 30 24 ...    
    26 = 4 + (3 + 4 + 5 + 8 + 2)
    30 = 8 + (3 + 4 + 5 + 8 + 2)

    Segundo vetor resultante
        0 1 2 ...    
    0 = 7 não possui divisores
    1 = 5 é divisível apenas por 5
    2 = 15 é divisível por 3 e por 5

    A saída de todos valores resultantes devem seguir o modelo abaixo:
        printf("%d ",vetor_exemplo[i]);
*/

int main()
{
    int i, j, aa[10], ab[5], soma, vetorResultadoSoma[];
    
    for(i=0;i<10;i++){
        scanf(" %d", &aa[i]);
    }
    for(j=0;j<5;j++){
        scanf(" %d", &ab[j]);
    }

    for(i=0;<10;i++){
        if((aa[i]%2) == 0){
           
        }
    }

     for(j=0;j<5;j++){
                soma += ab[j];
            }
            vetorResultadoSoma[i] = i + soma;
    return 0;
}
