#include <stdio.h>
#include <stdlib.h>

/*
    Faça um programa que preencha dois vetores de dez posições cada um, determine e mostre um terceiro contendo os elementos dos dois vetores anteriores ordenados de maneira decrescente.

    A saída de todos valores resultantes devem seguir o modelo abaixo:
        printf("%d ",vetor_exemplo[i]);
*/

int main()
{
    int i, j, a[10], b[10], c[20], temporario;
    
    for(i=0;i<10;i++){
        scanf(" %d", &a[i]);
    }
    for(i=0;i<10;i++){
        scanf(" %d", &b[i]);
    }

    for(i=0;i<10;i++){
        c[i] = a[i];
    }
    for(i=0;i<10;i++){
        c[10+i] = b[i];
    }
    for(i=0;i<20;i++){
        for (j=i+1;j<20;j++){
            if(c[i] < c[j]){
                temporario = c[i];
                c[i] = c[j];
                c[j] = temporario;
            }
        }
    }

    for(i=0;i<20;i++){
        printf("%d ", c[i]);
    }

    return 0;
}
