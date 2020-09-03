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
    int i, j, c1=0, c2=0, c3=0, v1[10], v2[5], soma=0;
    int *resultadoSoma, *v3, *divisores;

    for(i=0;i<10;i++){
        scanf(" %d", &v1[i]);
    }
    for(i=0;i<5;i++){
        scanf(" %d", &v2[i]);
    }

    for(i=0;i<5;i++){
        soma += v2[i];
    }
    for(i=0;i<10;i++){
        if((v1[i]%2) == 0){
            c1++;
        }
    }

    resultadoSoma = malloc(c1*sizeof(int));
    j=0;

    for(i=0;i<10;i++){
        if((v1[i]%2) == 0){
            resultadoSoma[j] = (v1[i]+soma);
            j++;
        }
    }

    c2 = 10-c1;
    v3 = malloc(c2*sizeof(int));
    divisores = malloc(c2*sizeof(int));
    j=0;

    for(i=0;i<10;i++){
        if((v1[i]%2) != 0){
            v3[j] = v1[i];
            j++;
        }
    }

    for(i=0;i<c2;i++){
        c3=0;
        for(j=0;j<5;j++){
            if(v3[i]%v2[j] == 0){
                c3++;
            }
        }
        divisores[i] = c3;
    }

    for(i=0;i<c1;i++){
        printf("%d ", resultadoSoma[i]);
    }
    for(i=0;i<c2;i++){
        printf("%d ", divisores[i]);
    }

    free(resultadoSoma);
    free(v3);
    free(divisores);

    return 0;
}
