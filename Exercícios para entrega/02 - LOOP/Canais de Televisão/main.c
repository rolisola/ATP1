#include <stdio.h>

/*
    Foi feita uma pesquisa de audiência de canal de TV em várias casas de uma cidade, em um determinado dia. Para cada casa consultada, foi questionado qual era o canal assistido e o número de pessoas que estavam assistindo àquele canal. Se a televisão estivesse desligada, nada era anotado, ou seja, essa casa não entrava na pesquisa.

    Nesta cidade os únicos canais possível de serem sintonizados eram os listados na tabela abaixo.
        Canal	Número
      Noticias	  4
      Desenhos	  5
       Filmes	  7
       Séries	 12

    Faça um programa que:
        leia um número indeterminado de dados (o número do canal e o número de pessoas que estavam assistindo);
        calcule e mostre a porcentagem de audiência de cada canal em relação ao total de casas pesquisadas.
        Para encerrar a entrada de dados digite o número de canal 0 (ZERO).

    Observações:
        As variáveis devem ser impressas na ordem que estão listadas na tabela, todas na mesma linha e separadas por espaços.
        Imprima cada uma das variáveis com o sinal de porcentagem ("%") após seu valor.
        Não restrinja o número de casas decimais das variáveis float.
    Exemplo:
        Entrada:
            4 1 5 1 7 1 12 1 0
        Saída:
            25.000000% 25.000000% 25.000000% 25.000000%
*/

int main()
{
    int numeroCanal, i=0, numeroPessoas, iCanal4=0, iCanal5=0, iCanal7=0, iCanal12=0;
    float audienciaCanal4, audienciaCanal5, audienciaCanal7, audienciaCanal12;

    while(scanf(" %d", &numeroCanal) && (numeroCanal !=0)){
        scanf("%d", &numeroPessoas);
        if(numeroCanal == 4){
            iCanal4++;
        }else if(numeroCanal == 5){
            iCanal5++;
        }else if(numeroCanal == 7){
            iCanal7++;
        }else if(numeroCanal == 12){
            iCanal12++;
        }
        i++;
    }

    audienciaCanal4 = ((float)iCanal4*100/(float)i);
    audienciaCanal5 = ((float)iCanal5*100/(float)i);
    audienciaCanal7 = ((float)iCanal7*100/(float)i);
    audienciaCanal12 = ((float)iCanal12*100/(float)i);

    printf("%f%% %f%% %f%% %f%%", audienciaCanal4, audienciaCanal5, audienciaCanal7, audienciaCanal12);

    return 0;
}
