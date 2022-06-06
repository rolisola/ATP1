#include <stdio.h>
/*
    Faça um programa que receba:

    código do produto comprado;
    quantidade comprada de um produto
    Seguindo a tabela, calcule e mostre em ordem:

    preço unitário do produto comprado seguindo a Tabela 1 /var 1/
    preço total da nota /var2/
    valor do desconto, seguindo a Tabela 2 e aplicando sobre o preço total da nota /var3/
    preço final da nota depois do desconto /var4/
    Código	Preço
    1 a 10	R$ 10,00
    11 a 20	R$ 15,00
    21 a 30	R$ 20,00
    31 a 40	R$ 30,00
    Preço total da nota	% de desconto
    Até R$ 249,99	5%
    Entre 250,00 e R$ 499,99	10%
    Acima de R$ 500,00	15%
    printf("%.2f %.2f %.2f %.2f", var1 ,  var2,  var3,  var4 );
*/

int main()
{
    int codigo, quantidade;
    float unitario, total, desconto, final; 
    
    scanf("%d", &codigo);
    scanf("%d", &quantidade);

    if((codigo >= 1) && (codigo <=10)){
        unitario = 10;
    }else if((codigo >= 11) && (codigo <= 20)){
        unitario = 15;
    }else if((codigo >= 21) && (codigo <= 31)){
        unitario = 20;
    }else if((codigo >= 31) && (codigo <= 40)){
        unitario = 30;
    }

    total = (quantidade * unitario);

    if(total <= 249.99){
        desconto = (total * 0.05);
    }else if((total >= 250) && (total <= 499.99)){
        desconto = (total * 0.1);
    }else if(total >= 500){
        desconto = (total * 0.15);
    }

    final = (total - desconto);

    printf("%.2f %.2f %.2f %.2f", unitario, total, desconto, final);

    return 0;
}
