#include <stdio.h>
#include <stdlib.h>

/*
    A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, coletando dados sobre o salário e o número de filhos. A prefeitura deseja saber:

        a média do salário da população;
        a média do número de filhos;
        o maior salário;
        a percentagem de pessoas com salários até R$150,00.
    O final da leitura de dados dar-se-á com a entrada de um salário negativo.

    Observações:
        Utilize variáveis float para a leitura dos salários.
        As informações devem ser impressas na ordem que estão listadas acima, todas na mesma linha e separadas por espaços.
        Imprima o sinal de porcentagem ("%") após o valor da variável referente a este cálculo.
        Não restrinja o número de casas decimais das variáveis float.

    Exemplo:
        Entrada:
            150 2 500 2 -1
        Saída:
            325.000000 2.000000 500.000000 50.000000%
*/

int main()
{
    int i=0, nFilhos, somaNFilhos=0, contadorSalario=0;
    float salario=0, somaSalario=0, maiorSalario, mediaSalario, mediaNFilhos, porcentagem;

    do{
        scanf("%f", &salario);
        if(salario >= 0){
            scanf("%d", &nFilhos);
            somaSalario += salario;
            somaNFilhos += nFilhos;

            if(salario > maiorSalario){
                maiorSalario = salario;
            }
            if(salario <=150){
                ++contadorSalario;
            }

            i++;
        }
    }while(salario >= 0);

    mediaSalario = (somaSalario/i);
    mediaNFilhos = ((float)somaNFilhos/(float)i);
    porcentagem = ((contadorSalario*100)/(float)i);

    printf("%f %f %f %f%%", mediaSalario, mediaNFilhos, maiorSalario, porcentagem);

    return 0;
}
