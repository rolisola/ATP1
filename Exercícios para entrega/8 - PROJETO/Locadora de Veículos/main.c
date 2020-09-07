#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union PESSOA{
    char fisica[15], juridica[19];
};
struct ENDERECO{
    int numero;
    char rua[50], bairro[50], cidade[50];
};
struct CLIENTE{
    union PESSOA pessoa;
    struct ENDERECO endereco;
    char nome[50], telefone[15];
};
struct CLIENTE cliente[15];

void sair();
int cadastrarCliente();
void atualizarCliente();
void listarCliente();
void cadastrarCarro();
void cadastrarCategoria();
void locarCarro();
void devolverCarro();
void listarDadosLocacao();
void listarLocacaoCliente();
void listarLocacaoEmAberto();
void listarLocacaoPorFrequencia();
void erro();

int main()
{
    int contadorCadastroCliente=0, opcaoMenu;
    do{
        scanf(" %d", &opcaoMenu);
        switch(opcaoMenu){
            case 0:
                sair();
                break;
            case 1:
                contadorCadastroCliente = cadastrarCliente(contadorCadastroCliente);
                break;
            case 2:
                atualizarCliente();
                break;
            case 3:
                listarCliente();
                break;
            case 4:
                cadastrarCarro();
                break;
            case 5:
                cadastrarCategoria();
                break;
            case 6:
                locarCarro();
                break;
            case 7:
                devolverCarro();
                break;
            case 8:
                listarDadosLocacao();
                break;
            case 9:
                listarLocacaoCliente();
                break;
            case 10:
                listarLocacaoEmAberto();
                break;
            case 11:
                listarLocacaoPorFrequencia();
                break;
            default:
                erro(1);
                break;
        }
    }while(opcaoMenu != 0);

    return 0;
}

void sair(){
    exit(0);
}

int cadastrarCliente(int *i){
    int j, pessoa;
    char cpf[15];

    if(i < 15){
        scanf(" %d", &pessoa);

        switch(pessoa){
            case 1:
                scanf(" %s", cpf);
                for(j=0;j<i;j++){
                    strcmp(cpf, algo);
                }
                break;
            case 2:

                break;
            default:
                erro(1);
                break;
        }
    }else{
        erro(2);
    }
    return i;
}
/*
void atualizarCliente(){
}

void listarCliente(){
}

void cadastrarCarro(){
}

void cadastrarCategoria(){
}

void locarCarro(){
}

void devolverCarro(){
}

void listarDadosLocacao(){
}

void listarLocacaoCliente(){
}

void listarLocacaoEmAberto(){
}

void listarLocacaoPorFrequencia(){
}
*/
void erro(int erro){
    switch(erro){
        case 1:
            printf("ERRO: opcao invalida\n");
            break;
        case 2:
            printf("ERRO: sem espaco\n");
            break;
        case 3:
            printf("ERRO: ja cadastrado\n");
            break;
        case 4:
            printf("ERRO: nao cadastrado\n");
            break;
        case 5:
            printf("ERRO: locacao em aberto\n");
            break;
        case 6:
            printf("ERRO: data invalida\n");
            break;
        case 7:
            printf("ERRO: nenhuma locacao em aberto\n");
            break;
        case 8:
            printf("ERRO: locacao foi cancelada\n");
            break;
        case 9:
            printf("ERRO: nenhum dado cadastrado\n");
            break;
    }
}
