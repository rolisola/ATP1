#include <stdio.h>
#include <stdlib.h>

/*
    Faça um programa que receba três números e mostre o maior.
*/

int main()
{
    int n0, n1, n2;

    printf("Digite os 3 valores:\n");
    scanf("%d %d %d", &n0, &n1, &n2);

    if((n0 >= n1) && (n0 >= n2)){
        printf("%d", n0);
    }else if((n1 >= n0) && (n1 >= n2)){
        printf("%d", n1);
    }else if((n2 >= n0) && (n2 >= n1)){
        printf("%d", n2);
    }

    return 0;
}
