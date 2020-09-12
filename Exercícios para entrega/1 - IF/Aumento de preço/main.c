#include <stdio.h>
#include <ctype.h>

/*
    Faça um programa que receba o preço, a categoria (1, 2 ou 3) e a situação (R ou N) de um produto. Calcule o valor do aumento de preço e utilizando a Tabela 2 recalcule para os casos apresentados, caso não o aumento esteja fora do escopo da tabela, deve-se tomar o valor calculado. Mostre o valor do aumento e o valor final.

    Preço	                    Categoria	% de aumento
    Menor ou igual a R$ 25,00	    1	        5%
    Menor ou igual a R$ 25,00	    2	        8%
    Menor ou igual a R$ 25,00	    3	        10%
    Maior que R$ 25,00	            1	        12%
    Maior que R$ 25,00	            2	        15%
    Maior que R$ 25,00	            3	        18%
    Aumento	Situação    Aumento     recalculado
    Até R$ 0,99             R	    R$ 1,00
    Até R$ 0,99	            N	    R$ 2,00
    Acima R$ 99,00	        R	    R$ 10,00
    Acima R$ 99,00	        N	    R$ 20,00

    Exemplo 1:
        Entrada:
            5.00 2 N
        Saída:
            2.00 7.00

    Exemplo 2:
        Entrada:
            10.00 3 N
        Saída:
            1.00 11.00
*/

int main()
{
    float preco, aumento, final;
    char situacao;
    int categoria;

    scanf("%f", &preco);
    scanf("%d", &categoria);
    scanf(" %c", &situacao);

    situacao = toupper(situacao);

    if(categoria == 1){
        aumento = (preco <= 25) ? (preco * 0.05) : (preco * 0.12);
    }else if(categoria == 2){
        aumento = (preco <= 25) ? (preco * 0.08) : (preco * 0.15);
    }else if(categoria == 3){
        aumento = (preco <= 25) ? (preco * 0.10) : (preco * 0.18);
    }else{
        printf("Categoria inexistente!\n");
    }

    if(aumento <= 0.99){
        if(situacao == 'R'){
            aumento = 1;
        }else if(situacao == 'N'){
            aumento = 2;
        }
    }else if(aumento >= 99){
        if(situacao == 'R'){
            aumento = 10;
        }else if(situacao == 'N'){
            aumento = 20;
        }
    }

    final = (preco + aumento);

    printf("%.2f %.2f", aumento, final);

    return 0;
}
