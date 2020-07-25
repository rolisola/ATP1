#include <stdio.h>
#include <stdlib.h>

/*
    Dado inicialmente um número N, faça um programa que receba a idade de N pessoas, calcule e mostre:
        a quantidade de pessoas em cada faixa etária de acordo com a tabela abaixo;
        a porcentagem de pessoas na primeira e na última faixa etária, com relação ao total de pessoas

        Faixa Etária	    Idade
            1ª	        Até 15 anos
            2ª	        De 16 a 30 anos
            3ª	        De 31 a 45 anos
            4ª	        De 46 a 60 anos
            5ª	        Acima de 61 anos

    Observações:
        Imprima os valores de cada faixa etária em uma linha, separados por espaço, e na linha de baixo o valor calculado. Não restrinja o número de casas depois da vírgula do valor calculado.
        Para imprimir o símbolo de porcentagem utilizando a função printf() utilize o seguinte comando:
            printf("%f%%", porcentagem);

        Exemplo:
            Entrada:
                3 10 68 15
            Saída:
                2 0 0 0 1
                100.000000%
*/
int main()
{
    int i, iFaixa1=0, iFaixa2=0, iFaixa3=0, iFaixa4=0, iFaixa5=0, numeroPessoas, idade;
    float porcentagemFaixa1e2;

    scanf("%d", &numeroPessoas);

    for(i=0;i<numeroPessoas;i++){
        scanf("%d", &idade);

        if(idade <= 15){
            iFaixa1++;
        }else if((idade >= 16) && (idade <= 30)){
            iFaixa2++;
        }else if((idade >= 31) && (idade <= 45)){
            iFaixa3++;
        }else if((idade >= 46) && (idade <= 60)){
            iFaixa4++;
        }else if(idade >= 61){
            iFaixa5++;
        }
    }

    porcentagemFaixa1e2 = ((((float)iFaixa1+(float)iFaixa5)*100)/numeroPessoas);

    printf("%d %d %d %d %d\n", iFaixa1, iFaixa2, iFaixa3, iFaixa4, iFaixa5);
    printf("%f%%", porcentagemFaixa1e2);

    return 0;
}
