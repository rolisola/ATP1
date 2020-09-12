#include <stdio.h>

/*
    Faça um programa que leia dois vetores (A e B) com cinco posições para números inteiros. O programa deve, então, subtrair o primeiro elemento de A do último de B, acumulando o valor, subtrair o segundo elemento de A do penúltimo de B, acumulando o valor, e assim por diante. Ao final, mostre o resultado de todas as subtrações realizadas.

    A saída de todos valores resultantes devem seguir o modelo abaixo:
        printf("%d ",vetor_exemplo[i]);
*/

int main()
{
    int i, a[5], b[5], c[5];

    for(i=0;i<5;i++){
        scanf(" %d", &a[i]);
    }
    for(i=0;i<5;i++){
        scanf(" %d", &b[i]);
    }

    for(i=0;i<5;i++){
        c[i] = (a[4-i] - b[i]);
    }

    for(i=4;i>=0;i--){
        printf("%d ", c[i]);
    }
    return 0;
}
