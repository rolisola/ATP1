#include <stdio.h>

/*
    Faça um programa para controlar o estoque de mercadorias de uma empresa. Inicialmente, o programa deverá preencher dois vetores com dez posições cada, onde o primeiro corresponde ao código do produto e o segundo ao total desse produto em estoque. Logo após, o programa deverá ler um conjunto indeterminado de dados contendo o código de um cliente e o código do produto que ele deseja comprar, juntamente com a quantidade. Código do cliente igual à zero indica fim do programa. O programa deverá verificar:
        Se o código do produto solicitado existe. Se existir, tentar atender ao pedido; caso contrário, exibir mensagem “Codigo inexistente”;
        Cada pedido feito por um cliente só pode ser atendido integralmente. Caso isso não seja possível, escrever a mensagem “Sem estoque suficiente para esta compra”. Se puder atendê-lo, escrever a mensagem “Pedido atendido. Obrigado e volte sempre”;
        Efetuar a atualização do estoque somente se o pedido for atendido integralmente;
        No final do programa, escrever os códigos dos produtos com seus respectivos estoques já atualizados.

    A saída do programa (printf) devem seguir os modelos abaixo:
        printf("Codigo inexistente\n");
        printf("Sem estoque suficiente para esta compra\n");
        printf("Pedido atendido. Obrigado e volte sempre\n");
        printf("%d: %d\n",codigo_produto, quantidade_produto);
*/

int main()
{
    const int tam=10;
    int i, codigoProduto[tam], totalProdutos[tam], recebeCodigoProduto, recebeQuantidadeProduto, recebeCodigoCliente;

    for(i=0;i<tam;i++){
        scanf(" %d", &recebeCodigoProduto);
        scanf(" %d", &recebeQuantidadeProduto);

        codigoProduto[i] = recebeCodigoProduto;
        totalProdutos[i] = recebeQuantidadeProduto;
    }

    do{
        scanf(" %d", &recebeCodigoCliente);
        scanf(" %d", &recebeCodigoProduto);
        scanf(" %d", &recebeQuantidadeProduto);

        if(recebeCodigoCliente == 0){
            break;
        }

        for(i=0;i<tam;i++){
            if(recebeCodigoProduto == codigoProduto[i]){
                break;
            }
        }

        if(i == tam){
            printf("Codigo inexistente\n");
        }else{
            if(recebeQuantidadeProduto > totalProdutos[i]){
                printf("Sem estoque suficiente para esta compra\n");
            }else{
                printf("Pedido atendido. Obrigado e volte sempre\n");

                totalProdutos[i] -= recebeQuantidadeProduto;
            }
        }
    }while(recebeCodigoCliente != 0);

    for(i=0;i<tam;i++){
        printf("%d: %d\n", codigoProduto[i], totalProdutos[i]);
    }
    return 0;
}
