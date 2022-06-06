#include <stdio.h>
#include <ctype.h>

/*
    Faça um programa que receba a altura (em metro) e o sexo (M ou F) de uma pessoa e que calcule e mostre o seu peso ideal, utilizando as seguintes fórmulas:

    Masculino (72.7*h)-58
    Feminino  (62.1*h)-44.7

*/

int main()
{
    float h, pesoIdeal;
    char sexo;

    scanf("%f", &h);
    scanf(" %c", &sexo);
    
    sexo = toupper(sexo);
    if (sexo == 'F'){
        pesoIdeal = ((62.1 * h) - 44.7);
    }else if (sexo == 'M'){
        pesoIdeal = ((72.7 * h) - 58);
    }else {
        printf("Entranda Invalida");
    }

    printf("%.3f", pesoIdeal);
    
    return 0;
}
