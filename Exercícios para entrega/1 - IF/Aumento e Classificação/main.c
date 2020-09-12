#include <stdio.h>

/*
    Faça um programa que receba o preço de um produto, calcule e mostre, de acordo com as tabelas a seguir, o novo preço e a classificação.

    Preço	                Aumento Percentual
    Até R$ 49,99	                5%
    R$ 50,00 até R$ 99,99	        10%
    Acima de R$ 100,00	            15%

    Novo preço	            Classificação
    Até R$ 79,99	            Barato
    R$ 80,00 até R$ 119,99	    Normal
    R$ 120,00 até R$ 199,99	    Caro
    Acima de R$ 200,00	        Muito Caro

    O printf do novo preço deve seguir o modelo:

    printf("%.2f\n",  VARIÁVEL DO NOVO PREÇO  );

    O printf da classificação deve seguir a exata escrita da tabela.
*/

int main()
{
    float preco, novopreco;

    scanf("%f", &preco);
    if(preco <= 49.99){
        novopreco = (preco * 1.05);
    }else if((preco >= 50) && (preco <= 99.99)){
        novopreco = (preco * 1.10);
    }else if(preco >= 100){
        novopreco = (preco * 1.15);
    }

    printf("%.2f\n", novopreco);

    if(novopreco <= 79.99){
        printf("Barato\n");
    }else if((novopreco >= 80) && (novopreco <= 119.99)){
        printf("Normal\n");
    }else if((novopreco >= 120) && (novopreco <= 199.99)){
        printf("Caro\n");
    }else if(novopreco >= 200){
        printf("Muito Caro\n");
    }
    return 0;
}
