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
    int  aa, opcaoMenu, contador1=0, contador2=0, contador3=0, contador4=0;
    //float aa;
    aa = sizeof(cliente)/sizeof(cliente[0]);
    //printf("\n%d\n", aa);
    do{
        scanf(" %d", &opcaoMenu);

        switch(opcaoMenu){
            case 0:
                printf("Encerrando sistema");
                abort();
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
                //despachaPedido();
                break;
            case 6:
               // recebeuPedido();
                break;
            case 7:
               // pedidosSituacao();
                break;
            case 8:
             //   pedidosCliente();
                break;
            case 9:
              //  entregasMotoqueiros();
                break;
            default:
                printf("Opcao invalida\n");
                break;

        };
    }while(opcaoMenu != 0);

    return 0;
}

void cadastrarCliente(int i){
    int j, boo=0;
    char recebeTelefone[15];
    if(i >= a){
        printf("Numero maximo de clientes cadastrados\n");
    }else{
        scanf(" %[^\n]", &recebeTelefone);
        for(j=0;j<a;j++){
            if(recebeTelefone == cliente[j].telefone){
                boo = 1;
            }
        }
        if(boo == 1){
            printf("Cliente ja cadastrado\n");
        }else{
            strcpy(cliente[i].telefone , recebeTelefone);
            scanf(" %[^\n]", &cliente[i].nome);
            scanf(" %[^\n]", &cliente[i].endereco.rua);
            scanf(" %d", &cliente[i].endereco.numero);
            scanf(" %[^\n]", &cliente[i].endereco.bairro);
            //system("cls");
            printf("Cliente cadastrado com sucesso\n");
            //printf("%s\n%s\n%s\n%d\n%s\n",cliente[i].telefone, cliente[i].nome,cliente[i].endereco.rua,cliente[i].endereco.numero,cliente[i].endereco.bairro);
        }
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
            scanf(" %[^\n]", &motoqueiro[i].cad.telefone);
            scanf(" %[^\n]", &motoqueiro[i].cad.nome);
            scanf(" %[^\n]", &motoqueiro[i].cad.endereco.rua);
            scanf(" %d", &motoqueiro[i].cad.endereco.numero);
            scanf(" %[^\n]", &motoqueiro[i].cad.endereco.bairro);
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
            scanf(" %[^\n]", &pizza[i].nome);
            scanf(" %f", &pizza[i].preco);
            printf("Pizza cadastrada com sucesse\n");
        }
    }
}

void cadastrarPedido(int i){
    int j, verificador, recebeCodigoPizza;
    char recebeTelefone[15];
    if(i >= d){
        printf("Numero maximo de pedidos realizados\n");
    }else{
        scanf(" %[^\n]", &recebeTelefone);
        for(j=0;j<a;j++){
            if(recebeTelefone == cliente[j].telefone){
                printf("Cliente nao encontrado\n");
                return;
            }
        }
        scanf(" %d", &recebeCodigoPizza);
        for(
    }
//pedido[i].telefoneCliente;
//pedido[i].codigoPizza;
  //  pedido[i].situacao = 1;
   // pedido[i].codigoMotoqueiro = 0;
   // pedido[i].codigo = i;
}
/*
void despacharPedido(){
    int i, recebeCodigo;
    scanf(" %d", &recebeCodigo);

    scanf(" %d", &pedido[i].codigoMotoqueiro);
    pedido[i].situacao++;


*/
