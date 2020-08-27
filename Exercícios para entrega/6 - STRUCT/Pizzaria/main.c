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
    int codigo, codigoPizza, codigoMotoqueiro, situacao;
    char telefoneCliente[15];
};

#define a 5
#define b 2
#define c 3
#define d 6

struct Pessoa cliente[a];
struct Motoboy motoqueiro[b];
struct Pizza pizza[c];
struct Pedido pedido[d];

int cadastrarCliente();
int cadastrarMotoqueiro();
int cadastrarPizza();
int cadastrarPedido();
void despacharPedido();
void recebeuPedido();
void situacao();
void pedidosSituacao();
void pedidosCliente();
void entregasMotoqueiros();
//void printaStruct();

int main()
{
    int opcaoMenu, contador1=0, contador2=0, contador3=0, contador4=0;
    
    do{
        scanf(" %d", &opcaoMenu);

        switch(opcaoMenu){
            case 0:
                printf("Encerrando sistema\n");
                break;
            case 1:
                contador1 = cadastrarCliente(contador1);
                break;
            case 2:
                contador2 = cadastrarMotoqueiro(contador2);
                break;
            case 3:
                contador3 = cadastrarPizza(contador3);
                break;
            case 4:
                contador4 = cadastrarPedido(contador4);
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
/*
            case 10:
                printaStruct();
                break;
*/
            default:
                printf("Opcao invalida\n");
                break;
        };
    }while(opcaoMenu != 0);

    return 0;
}

int cadastrarCliente(int i){
    int j, verificador=1;
    char recebeTelefone[15];

    if(i >= a){
        printf("Numero maximo de clientes cadastrados\n");
        fflush(stdin);
        return i;
    }else{
        scanf(" %[^\n]", recebeTelefone);
        for(j=0;j<a;j++){
            verificador = strcmp(recebeTelefone, cliente[j].telefone);
            if(verificador == 0){
                printf("Cliente ja cadastrado\n");
                fflush(stdin);
                return i;
            }
        }
        if(verificador != 0){
            strcpy(cliente[i].telefone , recebeTelefone);
            scanf(" %[^\n]", cliente[i].nome);
            scanf(" %[^\n]", cliente[i].endereco.rua);
            scanf(" %d", &cliente[i].endereco.numero);
            scanf(" %[^\n]", cliente[i].endereco.bairro);
            printf("Cliente cadastrado com sucesso\n");
            i++;
            return i;
        }
    }
    return i;
}

int cadastrarMotoqueiro(int i){
    int j, verificador=0, recebeCodigo;

    if(i >= b){
        printf("Numero maximo de motoqueiros cadastrados\n");
        fflush(stdin);
        return i;
    }else{
        scanf(" %d", &recebeCodigo);
        for(j=0;j<b;j++){
            if(recebeCodigo == motoqueiro[j].codigo){
                verificador = 1;
                break;
            }else{
                verificador = 0;
            }
        }
        if(verificador == 1){
            printf("Motoqueiro ja cadastrado\n");
            fflush(stdin);
            return i;
        }else{
            motoqueiro[i].codigo = recebeCodigo;
            scanf(" %[^\n]", motoqueiro[i].cad.telefone);
            scanf(" %[^\n]", motoqueiro[i].cad.nome);
            scanf(" %[^\n]", motoqueiro[i].cad.endereco.rua);
            scanf(" %d", &motoqueiro[i].cad.endereco.numero);
            scanf(" %[^\n]", motoqueiro[i].cad.endereco.bairro);
            printf("Motoqueiro cadastrado com sucesso\n");
            i++;
            return i;
        }
    }
}

int cadastrarPizza(int i){
    int j, boo=0, recebeCodigo;

    if(i >= c){
        printf("Numero maximo de pizzas cadastrados\n");
        fflush(stdin);
        return i;
    }else{
        scanf(" %d", &recebeCodigo);
        for(j=0;j<c;j++){
            if(recebeCodigo == pizza[j].codigo){
                boo = 1;
            }
        }
        if(boo == 1){
            printf("Pizza ja cadastrada\n");
            fflush(stdin);
            return i;
        }else{
            pizza[i].codigo = recebeCodigo;
            scanf(" %[^\n]", pizza[i].nome);
            scanf(" %f", &pizza[i].preco);
            printf("Pizza cadastrada com sucesso\n");
            i++;
            return i;
        }
    }
}

int cadastrarPedido(int i){
    int j, verificador, recebeCodigoPizza;
    char recebeTelefone[15];

    if(i >= d){
        printf("Numero maximo de pedidos realizados\n");
        fflush(stdin);
        return i;
    }else{
        scanf(" %[^\n]", recebeTelefone);
        for(j=0;j<a;j++){
            verificador = strcmp(recebeTelefone, cliente[j].telefone);
            if(verificador == 0){
                break;
            }
        }
        if(j == a){
            printf("Cliente nao encontrado\n");
            return i;
        }
        scanf(" %d", &recebeCodigoPizza);
        for(j=0;j<c;j++){
            if(recebeCodigoPizza == pizza[j].codigo){
                break;
            }
        }
        if(j == c){
            printf("Pizza nao cadastrada\n");
            return i;
        }
        strcpy(pedido[i].telefoneCliente, recebeTelefone);
        pedido[i].codigoPizza = recebeCodigoPizza;
        pedido[i].situacao = 1;
        pedido[i].codigoMotoqueiro = 0;
        pedido[i].codigo = i;
        printf("Pedido cadastrado\n");
        i++;
        return i;
    }
}

void despacharPedido(){
    int i, recebeCodigoPedido, recebeCodigoMotoqueiro;

    scanf(" %d", &recebeCodigoPedido);
    for(i=0;i<d;i++){
        if(recebeCodigoPedido == pedido[i].codigo){
            break;
        }
    }
    if(i == d){
        printf("Pedido nao encontrado\n");
        return;
    }else{
        switch(pedido[recebeCodigoPedido].situacao){
            case 1:
                scanf(" %d", &recebeCodigoMotoqueiro);
                for(i=0;i<b;i++){
                    if(recebeCodigoMotoqueiro == motoqueiro[i].codigo){
                        break;
                    }
                }
                if(i == b){
                    printf("Motoqueiro nao encontrado\n");
                    return;
                }
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
}

void recebeuPedido(){
    int i, verificador, recebeCodigoPedido;

    scanf(" %d", &recebeCodigoPedido);
    for(i=0;i<d;i++){
        if(recebeCodigoPedido == pedido[i].codigo){
            verificador = 0;
            break;
        }else{
            verificador = 1;
        }
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
    int i, verificador=0;

    for(i=0;i<d;i++){
        if(recebeSituacao == pedido[i].situacao){
            printf("Pedido: %d\n", pedido[i].codigo);
            printf("Cliente: %s\n", pedido[i].telefoneCliente);
            printf("Pizza: %d\n", pedido[i].codigoPizza);
            printf("Motoq: %d\n", pedido[i].codigoMotoqueiro);
        }else{
            verificador++;
        }
    }
    if(verificador == d){
        printf("Sem itens nessa situacao\n");
    }
}

void pedidosSituacao(){
    int recebeSituacao;

    scanf(" %d", &recebeSituacao);
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
    int i, contador=0, verificador;
    char recebeTelefone[15];

    scanf(" %[^\n]", recebeTelefone);
    for(i=0;i<a;i++){
        verificador = strcasecmp(recebeTelefone, cliente[i].telefone);
        if(verificador == 0){
            break;
        }
    }
    if(i == a){
        printf("Cliente nao encontrado\n");
        return;
    }else{
        for(i=0;i<d;i++){
            verificador = strcasecmp(recebeTelefone, pedido[i].telefoneCliente);
            if(verificador == 0){
                printf("Pedido: %d\n", pedido[i].codigo);
                printf("Situacao: %d\n", pedido[i].situacao);
                printf("Pizza: %d\n", pedido[i].codigoPizza);
                printf("Motoq: %d\n", pedido[i].codigoMotoqueiro);
            }else{
                contador++;
            }
        }
        if(contador == d){
            printf("Cliente sem pedidos\n");
        }
    }
}

void entregasMotoqueiros(){
    int i, verificador=0, recebeCodigoMotoqueiro;
    
    scanf(" %d", &recebeCodigoMotoqueiro);
    for(i=0;i<b;i++){
        if(recebeCodigoMotoqueiro == motoqueiro[i].codigo){
            break;
        }
    }
    if(i == b){
        printf("Motoqueiro nao encontrado\n");
        return;
    }
    for(i=0;i<d;i++){
        if(recebeCodigoMotoqueiro == pedido[i].codigoMotoqueiro){
            printf("Pedido: %d\n", pedido[i].codigo);
            printf("Situacao: %d\n", pedido[i].situacao);
        }else{
            verificador++;
        }
    }
    if(verificador == d){
        printf("Motoqueiro sem pedidos\n");
    }
}

/*
void printaStruct(){
    int i;
    printf("\nClientes:\n");
    for(i=0;i<a;i++){
        printf("Cliente %d\n", i);
        printf("Telefone: %s\n", cliente[i].telefone);
        printf("Nome: %s\n", cliente[i].nome);
        printf("Rua: %s\n", cliente[i].endereco.rua);
        printf("Numero: %d\n", cliente[i].endereco.numero);
        printf("Bairro: %s\n", cliente[i].endereco.bairro);
    }
    printf("\nEntregadores:\n");
    for(i=0;i<b;i++){
        printf("Entregador %d\n", i);
        printf("Codigo: %d\n", motoqueiro[i].codigo);
        printf("Telefone: %s\n", motoqueiro[i].cad.telefone);
        printf("Nome: %s\n", motoqueiro[i].cad.nome);
        printf("Rua: %s\n", motoqueiro[i].cad.endereco.rua);
        printf("Numero: %d\n", motoqueiro[i].cad.endereco.numero);
        printf("Bairro: %s\n", motoqueiro[i].cad.endereco.bairro);
    }
    printf("\nPizzas\n");
    for(i=0;i<c;i++){
        printf("Pizza %d\n", i);
        printf("Codigo: %d\n", pizza[i].codigo);
        printf("Nome: %s\n", pizza[i].nome);
        printf("Preco: %.2f\n", pizza[i].preco);
    }
    printf("\nPedidos\n");
    for(i=0;i<d;i++){
        printf("Pedido %d\n", i);
        printf("Codigo: %d\n", pedido[i].codigo);
        printf("Telefone: %s\n", pedido[i].telefoneCliente);
        printf("Pizza: %d\n", pedido[i].codigoPizza);
        printf("Motoq: %d\n", pedido[i].codigoMotoqueiro);
        printf("Situacao: %d\n", pedido[i].situacao);
    }
}
*/
