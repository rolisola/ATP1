#include <stdio.h>

/*
    Faça um programa que receba a idade, peso, altura, cor dos olhos e a cor dos cabelos de 20  pessoas e que calcule e mostre:
        a quantidade de pessoas com idade superior a 50 anos e peso inferior a 60 quilos;
        a média das idades das pessoas com altura superior a 1,50m;
        a porcentagem de pessoas com olhos azuis entre todas as pessoas analisadas;
        a quantidade de pessoas ruivas e que não possuem olhos azuis.

    As cores serão lidas utilizando apenas um caractere (símbolo), utilize a tabela abaixo para     se orientar:

        Cor do olho	    Símbolo	    Cor de Cabelo   Símbolo
            Azul	        A	        Preto	        P
            Preto	        P	        Castanho        C
            Verde	        V	        Louro	        L
            Castanho	    C	        Ruivo	        R

    Observações:
        Utilize variáveis float pra os valores de peso e altura.
        Os resultados deverão ser impressos na ordem em que foram listados acima, separados por     espaço. Não restrinja o número de casas depois da vírgula das variáveis float e insira o    sinal de porcentagem após a variável referente a este cálculo.

    Exemplo:
        Entrada:
            79 51.000000 1.470000 A R ...
        Saída:
            7 61.200001 30.000000% 4
*/

int main()
{
    int i=0,iIdadePeso=0, iAltura=0, iCorOlho=0, iOlhoCabelo=0, idade;
    float peso, altura, somaIdade, mediaIdadeAltura, porcentagemOlhoAzul;
    char corOlho, corCabelo;

    for(i=0;i<20;i++){
        scanf("%d %f %f %c %c", &idade, &peso, &altura, &corOlho, &corCabelo);
        if((idade > 50) && (peso < 60)){
            iIdadePeso++;
        }
        if(altura > 1.5){
            somaIdade += idade;
            iAltura++;
        }
        if(corOlho == 'A'){
            iCorOlho++;
        }
        if((corCabelo == 'R') && (corOlho != 'A')){
            iOlhoCabelo++;
        }
    }

    mediaIdadeAltura = ((float)somaIdade/(float)iAltura);
    porcentagemOlhoAzul = (((float)iCorOlho*100)/20);

    printf("%d %f %f%% %d", iIdadePeso, mediaIdadeAltura, porcentagemOlhoAzul, iOlhoCabelo);

    return 0;
}
