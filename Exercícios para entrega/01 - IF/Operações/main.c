#include <stdio.h>

/*
    Faça um programa que receba dois números e execute uma das operações listadas a seguir de acordo com a escolha do usuário. Se for digitada uma opção inválida mostrar a mensagem de erro abaixo e terminar a execução do programa. As opção são:

        Média entre os dois números
        Diferença do maior pelo menor
        O produto entre os dois números

        Saída normal:
        printf("%d",  variável );

        Mensagem de erro:
        printf("Entrada incorreta");
*/

int main()
{
    int n0, n1, resultado, operacao;

    scanf("%d", &n0);
    scanf("%d", &n1);
    scanf("%d", &operacao);

    if(operacao == 1){
        resultado = ((n0 + n1)/2);
        printf("%d", resultado);
    }else if(operacao == 2){
        n0 > n1 ? (resultado = n0 - n1) : (resultado = n1 - n0);
        printf("%d", resultado);
    }else if(operacao == 3){
        resultado = (n0 * n1);
        printf("%d", resultado);
    }else{
        printf("Entrada incorreta");
    }
    return 0;
}
