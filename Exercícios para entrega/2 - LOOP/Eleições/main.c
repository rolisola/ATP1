#include <stdio.h>

/*
    Em uma eleição presidencial existem quatro candidatos. Os votos são informados por meio de código. Os códigos utilizados são:
      Número	  Destino
        1	    Candidato 1
        2	    Candidato 2
        3	    Candidato 3
        4	    Candidato 4
        5	    Voto nulo
        6	    Voto em branco

    Faça um programa que calcule e mostre:
        o total de votos para cada candidato;
        o total de votos nulos;
        o total de votos em branco;
        a percentagem de votos nulos sobre o total de votos;
        a percentagem de votos em branco sobre o total de votos.
    Para finalizar o conjunto de votos, tem-se o valor 0 (ZERO).

    Observações:
        As informações devem estar na ordem que foram listadas acima.
        As informações referente aos votos devem estar na mesma linha, na linha de baixo as duas informações referente a percentagem de votos nulos e brancos. Todas as informações devem estar separadas por espaço.
        Imprima o sinal de porcentagem ("%") após o valor das variáveis referente a este cálculo.
        Não restrinja o número de casas decimais das variáveis float.
    Exemplo:
        Entrada:
            1 2 3 4 5 6 0
        Saída:
            1 1 1 1 1 1
            16.666666% 16.666666%
*/

int main()
{
    int codigoCandidato=1, i=0, iCandidato1=0, iCandidato2=0, iCandidato3=0, iCandidato4=0, iNulo=0, iBranco=0;
    float porcentagemNulo, porcentagemBranco;

    while(scanf("%d", &codigoCandidato) && codigoCandidato != 0){
        if(codigoCandidato == 1){
            iCandidato1++;
        }else if(codigoCandidato == 2){
            iCandidato2++;
        }else if(codigoCandidato == 3){
            iCandidato3++;
        }else if(codigoCandidato == 4){
            iCandidato4++;
        }else if(codigoCandidato == 5){
            iNulo++;
        }else if(codigoCandidato == 6){
            iBranco++;
        }
        i++;
    }

    porcentagemNulo = ((float)iNulo*100/(float)i);
    porcentagemBranco = ((float)iBranco*100/(float)i);

    printf("%d %d %d %d %d %d", iCandidato1, iCandidato2, iCandidato3, iCandidato4, iNulo, iBranco);
    printf("\n%f%% %f%%", porcentagemNulo, porcentagemBranco);

    return 0;
}
