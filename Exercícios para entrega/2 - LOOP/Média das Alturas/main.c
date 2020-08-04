#include <stdio.h>
#include <stdlib.h>

/*
    Faça um programa que receba a idade e a altura de várias pessoas e que calcule e mostre a média das alturas das pessoas com mais de 50 anos. Para encerrar a entrada de dados digite idade menor ou igual a zero.

    Observações:
        Utilize variável do tipo float para a leitura dos valores de altura.
        Não restrinja o número de casas decimais das variáveis float.
    Exemplo:
        Entrada:
            60 1.50 20 1.60 -1
        Saída:
            1.500000
*/


int main()
{
    int i, idade;
    float altura, somaAltura=0, mediaAltura;

    do{
        scanf("%d", &idade);

        if(idade > 0){
            scanf("%f", &altura);

            if(idade > 50){
                somaAltura += altura;
                i++;
            }
        }
    }while(idade > 0);

    mediaAltura = (somaAltura/(float)i);

    printf("%f", mediaAltura);

    return 0;
}
