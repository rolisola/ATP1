#include <stdio.h>

/*
    Cada espectador de um cinema respondeu a um questionário no qual constava sua idade e a sua opinião (Tabela abaixo) em relação ao filme assistido. Faça um programa que receba a idade e a opinião de 15 espectadores e que calcule e mostre:

        a média das idades das pessoas que responderam ótimo;
        a quantidade de pessoas que responderam regular;
        a percentagem de pessoas que responderam bom entre todos os espectadores analisados.

        Opinião	    Símbolo
        Regular	       1
        Bom	           2
        Ótimo	       3

    Observações:
        Os resultados deverão ser impressos na ordem que foram listados acima, separados por espaço.
        Insira o sinal de porcentagem após a variável referente a este cálculo.

    Exemplo:
        Entrada:
            67 3 71 3 74 3 31 3 ...
        Saída:
            59.200001 7 20.000000%
*/

int main()
{
    int i, idade, entrada, qtdRegular=0, qtdOtimo=0, somaIdade=0, qtdBom=0;
    double mediaBom, mediaIdade;

    for(i=0; i<15; i++){
        scanf("%d %d", &idade, &entrada);
        if(entrada == 1){
            qtdRegular += 1;
        }else if(entrada == 2){
            qtdBom += 1;
        }else if(entrada == 3){
            qtdOtimo += 1;
            somaIdade += idade;
        }
    }
    
    mediaIdade = ((float)somaIdade/(float)qtdOtimo);
    mediaBom = (((float)qtdBom*100)/15);

    printf("%f %d %f%%", mediaIdade, qtdRegular, mediaBom);

    return 0;
}
