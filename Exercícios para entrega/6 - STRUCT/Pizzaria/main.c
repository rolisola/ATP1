#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Endereco{
    int numero;
    char rua[50], bairro[50];
};
struct Pessoa{
    struct Endereco endereco;
    char telefone[15], nome[50];
};
struct Motoboy{
    struct Pessoa cad;
    int codigo;
};
struct Pizza{
    int codigo;
    char nome[50];
    float preco;
};
struct Pedido{
    int codigo, codigoPizza,codigoMotoqueiro, situacao;
    char telefoneCliente[15];
};

#define a 5
#define b 2
#define c 3
#define d 6

//const int a=5, b=2, c=3, d=6;

struct Pessoa cliente[a];
struct Motoboy motoqueiro[b];
struct Pizza pizza[c];
struct Pedido pedido[d];

void cadastrarCliente();
void cadastrarMotoqueiro();
void cadastrarPizza();
void cadastrarPedido();
void despacharPedido();
void recebeuPedido();
void pedidosSituacao();
void pedidosCliente();
void entregasMotoqueiros();

int main()
{
    int opcaoMenu, contador1=0, contador2=0, contador3=0, contador4=0;
    //float aa;
    //aa = sizeof(cliente)/sizeof(cliente[0]);
    //printf("\n%d\n", aa);
    do{
        scanf(" %d", &opcaoMenu);

        switch(opcaoMenu){
            case 0:
                printf("Encerrando sistema\n");
                return 0;
                break;
            case 1:
                cadastrarCliente(contador1);
                contador1++;
                break;
            case 2:
                cadastrarMotoqueiro(contador2);
                contador2++;
                break;
            case 3:
                cadastrarPizza(contador3);
                contador3++;
                break;
            case 4:
                cadastrarPedido(contador4);
                contador4++;
                break;
            case 5:
                despacharPedido();
                break;
            case 6:
                recebeuPedido();
                break;
            case 7:
                pedidosSituacao();
                break;
            case 8:
                pedidosCliente();
                break;
            case 9:
                entregasMotoqueiros();
                break;
            default:
                printf("Opcao invalida\n");
                break;

        };
    }while(opcaoMenu != 0);

    return 0;
}

void cadastrarCliente(int i){
    int j;
    char recebeTelefone[15];
    if(i >= a){
        printf("Numero maximo de clientes cadastrados\n");
        return;
    }else{
        scanf(" %[^\n]", recebeTelefone);
        for(j=0;j<a;j++){
            if(strcmp(recebeTelefone, cliente[j].telefone) == 0){
                printf("Cliente ja cadastrado\n");
                fflush(stdin);
                return;
            }
        }
        strcpy(cliente[i].telefone , recebeTelefone);
        scanf(" %[^\n]", cliente[i].nome);
        scanf(" %[^\n]", cliente[i].endereco.rua);
        scanf(" %d", &cliente[i].endereco.numero);
        scanf(" %[^\n]", cliente[i].endereco.bairro);
        printf("Cliente cadastrado com sucesso\n");
    }
}

void cadastrarMotoqueiro(int i){
    int j, boo=0, recebeCodigo;
    if(i >= b){
        printf("Numero maximo de motoqueiros cadastrados\n");
    }else{
        scanf(" %d", &recebeCodigo);
        for(j=0;j<b;j++){
            if(recebeCodigo == motoqueiro[i].codigo){
                boo = 1;
            }
        }
        if(boo == 1){
            printf("Motoqueiro ja cadastrado\n");
        }else{
            motoqueiro[i].codigo = recebeCodigo;
            scanf(" %[^\n]", motoqueiro[i].cad.telefone);
            scanf(" %[^\n]", motoqueiro[i].cad.nome);
            scanf(" %[^\n]", motoqueiro[i].cad.endereco.rua);
            scanf(" %d", &motoqueiro[i].cad.endereco.numero);
            scanf(" %[^\n]", motoqueiro[i].cad.endereco.bairro);
            printf("Motoqueiro cadastrado com sucesso\n");
        }
    }
}

void cadastrarPizza(int i){
    int j, boo=0, recebeCodigo;
    //printf("saindo da funcao");
    //return;
    if(i >= c){
        printf("Numero maximo de pizzas cadastrados\n");
    }else{
        scanf(" %d", &recebeCodigo);
        for(j=0;j<c;j++){
            if(recebeCodigo == pizza[j].codigo){
                printf("Pizza ja cadastrada\n");
                boo = 1;
                return;
            }
        }
        if(boo == 1){
            printf("Pizza ja cadastrada\n");
        }else{
            pizza[i].codigo = recebeCodigo;
            //scanf(" %d", &pizza[i].codigo);
            scanf(" %[^\n]", pizza[i].nome);
            scanf(" %f", &pizza[i].preco);
            printf("Pizza cadastrada com sucesso\n");
        }
    }
}

void cadastrarPedido(int i){
    int j, verificador, recebeCodigoPizza;
    char recebeTelefone[15];
    if(i >= d){
        printf("Numero maximo de pedidos realizados\n");
    }else{
        scanf(" %[^\n]", recebeTelefone);
        for(j=0;j<a;j++){
            verificador = (recebeTelefone != cliente[j].telefone) ? 1 : 0;
        }
        if(verificador == 1){
            printf("Cliente nao encontrado\n");
            return;
        }
        strcpy(pedido[i].telefoneCliente, recebeTelefone);
        scanf(" %d", &recebeCodigoPizza);
        for(j=0;j<c;j++){
            verificador = (recebeCodigoPizza != pizza[j].codigo) ? 1 : 0;
        }
        if(verificador == 1){
            printf("Pizza nao cadastrada\n");
            return;
        }
        pedido[i].codigoPizza = recebeCodigoPizza;
        pedido[i].situacao = 1;
        pedido[i].codigoMotoqueiro = 0;
        pedido[i].codigo = i;
        printf("Pedido cadastrado\n");
    }
}

void despacharPedido(){
    int i, verificador=0, recebeCodigoPedido, recebeCodigoMotoqueiro;
    scanf(" %d", &recebeCodigoPedido);
    for(i=0;i<d;i++){
        verificador = (recebeCodigoPedido != pedido[i].codigo) ? 1 : 0;
    }
    if(verificador == 1){
        printf("Pedido nao encontrado\n");
        return;
    }
    scanf(" %d", &recebeCodigoMotoqueiro);
    for(i=0;i<b;i++){
        verificador = (recebeCodigoMotoqueiro != motoqueiro[i].codigo) ? 1 : 0;
    }
    if(verificador == 1){
        printf("Motoqueiro nao encontrado\n");
        return;
    }
    switch(pedido[recebeCodigoPedido].situacao){
        case 1:
            pedido[recebeCodigoPedido].situacao = 2;
            pedido[recebeCodigoPedido].codigoMotoqueiro = recebeCodigoMotoqueiro;
            printf("Despachando pedido\n");
            break;
        case 2:
            printf("Pedido ja despachado\n");
            break;
        case 3:
            printf("Pedido ja entregue\n");
            break;
    }
}

void recebeuPedido(){
    int i, verificador, recebeCodigoPedido;
    scanf(" %d", &recebeCodigoPedido);
    for(i=0;i<d;i++){
        verificador = (recebeCodigoPedido != pedido[i].codigo) ? 1 : 0;
    }
    if(verificador == 1){
        printf("Pedido nao encontrado\n");
        return;
    }
    switch(pedido[recebeCodigoPedido].situacao){
        case 2:
            pedido[recebeCodigoPedido].situacao = 3;
            printf("Pedido entregue\n");
            break;
        case 3:
            printf("Entrega ja realizada\n");
            break;
    }
}

void situacao(int recebeSituacao){
    int i, verificador;
    for(i=0;i<d;i++){
        verificador = (recebeSituacao != pedido[i].situacao) ? 1 : 0;
        if(recebeSituacao == pedido[i].situacao){
            printf("Pedido: %d\n", pedido[i].codigo);
            printf("Cliente: %s\n", pedido[i].telefoneCliente);
            printf("Pizza: %d\n", pedido[i].codigoPizza);
            printf("Motoq: %d\n", pedido[i].codigoMotoqueiro);
        }
    }
    if(verificador == 1){
        printf("Sem itens nessa situacao\n");
    }
}

void pedidosSituacao(){
    int recebeSituacao;
    scanf(" %d", &recebeSituacao);
    //if((recebeSituacao >= 1) && (recebeSituacao <= 3))
    switch(recebeSituacao){
        case 1:
           situacao(recebeSituacao);
           break;
        case 2:
            situacao(recebeSituacao);
            break;
        case 3:
            situacao(recebeSituacao);
            break;
        default:
            printf("Opcao invalida\n");
            break;
    }
}

void pedidosCliente(){
    int i, verificador;
    char recebeTelefone[15];
    scanf(" %[^\n]", recebeTelefone);
    for(i=0;i<a;i++){
        verificador = (recebeTelefone != cliente[i].telefone) ? 1 : 0;
    }
    if(verificador == 1){
        printf("Cliente nao encontrado\n");
        return;
    }
    for(i=0;i<d;i++){
        if(recebeTelefone == pedido[i].telefoneCliente){
            printf("Pedido: %d\n", pedido[i].codigo);
            printf("Situacao: %d\n", pedido[i].situacao);
            printf("Pizza: %d\n", pedido[i].codigoPizza);
            printf("Motoq: %d\n", pedido[i].codigoMotoqueiro);
        }else{
            verificador = 2;
        }
    }
    if(verificador == 2){
        printf("Cliente sem pedidos\n");
    }
}

void entregasMotoqueiros(){
    int i, verificador, recebeCodigoMotoqueiro;
    scanf(" %d", &recebeCodigoMotoqueiro);
    for(i=0;i<b;i++){
        verificador = (recebeCodigoMotoqueiro != motoqueiro[i].codigo) ? 1 : 0;
    }
    if(verificador == 1){
        printf("Motoqueiro nao encontrado\n");
        return;
    }
    for(i=0;i<d;i++){
        if(recebeCodigoMotoqueiro == pedido[i].codigoMotoqueiro){
            printf("Pedido: %d\n", pedido[i].codigo);
            printf("Situacao: %d\n", pedido[i].situacao);
        }else{
            verificador = 2;
        }
    }
    if(verificador == 2){
        printf("Motoqueiro sem pedidos\n");
    }
}



