#include <stdio.h>
#include <stdlib.h>

/*
    Faça um programa que leia um vetor A de vinte posições. Em seguida, compacte o vetor, retirando os valores nulos e negativos. Armazene esse resultado no vetor B. Mostre o vetor B.

    A saída de todos valores resultantes devem seguir o modelo abaixo:
        printf("%d ",vetor_exemplo[i]);
*/

int main()
{
    int i,j, cont=0, a[20], *b;

    for(i=0;i<20;i++){
        scanf(" %d", &a[i]);
        if(a[i] > 0){
            cont++;
        }
    }

    b = malloc(cont * sizeof(int));
    j=0;

    for(i=0;i<20;i++){
        if(a[i] > 0){
            b[j] = a[i];
            j++;
        }
    }

    for(i=0;i<cont;i++){
        printf("%d ", b[i]);
    }

    free(b);
    
    return 0;
}
