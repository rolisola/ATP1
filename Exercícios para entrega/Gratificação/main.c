#include <stdio.h>
#include <stdlib.h>

/*
    Um empresa decidiu dar uma gratificação de natal aos seus funcionários, baseada no número de horas extras e no número de horas que o funcionário faltou ao trabalho. O valor do prêmio é obtido pela consulta na tabela a seguir. Mostre a gratificação final.

    H = ( número de horas extras ) - ( 3/4 * (número de horas-falta) )

    H	            Gratificação
    Até 600	        R$ 100,00
    601 até 1200	R$ 200,00
    1201 até 1800	R$ 300,00
    1801 até 2400	R$ 400,00
    Acima de 2400	R$ 500,00
*/

int main()
{
    float h, gratificacao;
    int extraHoras, faltaHoras;

    printf("Digite o numero de horas extras do funcionario:\n");
    scanf("%d", &extraHoras);
    printf("Digite o numero de horas faltadas do funcionario:\n");
    scanf("%d", &faltaHoras);

    h = (extraHoras - (( 3 * faltaHoras) / 4));

    if(h <= 600){
        gratificacao = 100;
    }else if((h >= 601) && (h <= 1200)){
        gratificacao = 200;
    }else if((h >= 1201) && (h <= 1800)){
        gratificacao = 300;
    }else if((h >= 1801) && (h <= 2400)){
        gratificacao = 400;
    }else if(h > 2400){
        gratificacao = 500;
    }

    printf("%.2f", gratificacao);

    return 0;
}
