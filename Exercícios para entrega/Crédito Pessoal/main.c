#include <stdio.h>
#include <stdlib.h>

/*
    Um banco concederá um crédito especial aos seus clientes de acordo com o saldo médio no último ano. Faça um programa que receba o saldo médio de um cliente e calcule e mostre o valor do crédito , de acordo com a tabela a seguir.

    Saldo médio	Percentual
    Até R$ 199,99	10% do saldo médio
    R$ 200,00 até R$ 299,99	20% do saldo médio
    R$ 300,00 até R$ 399,99	25% do saldo médio
    Acima de R$ 400,00	30% do saldo médio
    
    O printf deve ser escrito nesse formato:
        printf("%.2f ",  NOME DA VARIÁVEL  );
*/

int main()
{
    float saldoMedio, credito;

    printf("Digite o valor do saldo medio do cliente: \n");
    scanf("%f", &saldoMedio);

    if(saldoMedio <= 199.99){
        credito = (saldoMedio * 0.10);
    }else if((saldoMedio >= 200) && (saldoMedio <= 299.99)){
        credito = (saldoMedio * 0.20);
    }else if((saldoMedio >= 300) && (saldoMedio <= 399.99)){
        credito = (saldoMedio * 0.25);
    }else if(saldoMedio >= 400){
        credito = (saldoMedio * 0.30);
    }

    printf("O credito do cliente e: ");
    printf("%.2f", credito);

    return 0;
}
