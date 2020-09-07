#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum COR{preta=1, branca, prata};
enum CATEGORIA{hatch=1,sedan,suv,jipe};

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

struct CARRO{
    enum COR cor;
    enum CATEGORIA categoria;
    int ano;
    char renavam[11], placa[9], marca[50], modelo[50];
};

struct CLIENTE cliente[15];
struct CARRO carro[10];

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
    //char mode="r", filename="6.in";
    //FILE *fopen( const char * filename, const char * mode );
    remove("saida.txt");
    freopen("6.txt", "r", stdin);
    freopen("saida.txt", "w", stdout);
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
                //atualizarCliente();
                break;
            case 3:
                //listarCliente();
                break;
            case 4:
                //cadastrarCarro();
                break;
            case 5:
                //cadastrarCategoria();
                break;
            case 6:
                //locarCarro();
                break;
            case 7:
                //devolverCarro();
                break;
            case 8:
                //listarDadosLocacao();
                break;
            case 9:
                //listarLocacaoCliente();
                break;
            case 10:
               // listarLocacaoEmAberto();
                break;
            case 11:
              //  listarLocacaoPorFrequencia();
                break;
            default:
                erro(1);
                break;
        }
    }while(opcaoMenu != 0);

    return 0;
}

/* Função de cadastro boa

int cadastrarCliente(int i){
    union pessoaCadastro{
        char cpf[15], cnpj[19];
    };
    union pessoaCadastro pC;
    int j, tipoPessoa;

    if(i < 15){
        scanf(" %d", &tipoPessoa);

        switch(tipoPessoa){
            case 1:
                scanf(" %s", pC.cpf);

                for(j=0;j<i;j++){
                    if(strcmp(pC.cpf, cliente[j].pessoa.fisica) == 0){
                        erro(3);
                        return i;
                    }
                }

                strcpy(cliente[i].pessoa.fisica, pC.cpf);

                scanf(" %[^\n]%*c", cliente[i].nome);
                scanf(" %[^\n]%*c", cliente[i].endereco.rua);
                scanf(" %d", &cliente[i].endereco.numero);
                scanf(" %[^\n]%*c", cliente[i].endereco.bairro);
                scanf(" %[^\n]%*c", cliente[i].endereco.cidade);
                scanf(" %s", cliente[i].telefone);

                i++;

                printf("Cadastrado com Sucesso\n");
                break;
            case 2:
                scanf(" %s", pC.cnpj);

                for(j=0;j<i;j++){
                    if(strcmp(pC.cnpj, cliente[j].pessoa.juridica) == 0){
                        erro(3);
                        return i;
                    }
                }

                strcpy(cliente[i].pessoa.juridica, pC.cnpj);

                scanf(" %[^\n]%*c", cliente[i].nome);
                scanf(" %[^\n]%*c", cliente[i].endereco.rua);
                scanf(" %d", &cliente[i].endereco.numero);
                scanf(" %[^\n]%*c", cliente[i].endereco.bairro);
                scanf(" %[^\n]%*c", cliente[i].endereco.cidade);
                scanf(" %s", cliente[i].telefone);

                i++;

                printf("Cadastrado com Sucesso\n");
                break;
            default:
                erro(1);
                break;
        }
    }else{
        erro(2);
    }
    return i;
}*/

// Função de cadastro ruim
int cadastrarCliente(int i){
    int j, tipoPessoa;
    char fisJur[19];

    scanf(" %d", &tipoPessoa);
    scanf(" %s", fisJur);
    if(i < 15){
        switch(tipoPessoa){
            case 1:
                for(j=0;j<i;j++){
                    if(strcmp(fisJur, cliente[j].pessoa.fisica) == 0){
                        erro(3);
                        return i;
                    }
                }

                strcpy(cliente[i].pessoa.fisica, fisJur);

                scanf(" %[^\n]%*c", cliente[i].nome);
                scanf(" %[^\n]%*c", cliente[i].endereco.rua);
                scanf(" %d", &cliente[i].endereco.numero);
                scanf(" %[^\n]%*c", cliente[i].endereco.bairro);
                scanf(" %[^\n]%*c", cliente[i].endereco.cidade);
                scanf(" %s", cliente[i].telefone);

                i++;

                printf("Cadastrado com Sucesso\n");
                break;
            case 2:
                for(j=0;j<i;j++){
                    if(strcmp(fisJur, cliente[j].pessoa.juridica) == 0){
                        erro(3);
                        return i;
                    }
                }

                strcpy(cliente[i].pessoa.juridica, fisJur);

                scanf(" %[^\n]%*c", cliente[i].nome);
                scanf(" %[^\n]%*c", cliente[i].endereco.rua);
                scanf(" %d", &cliente[i].endereco.numero);
                scanf(" %[^\n]%*c", cliente[i].endereco.bairro);
                scanf(" %[^\n]%*c", cliente[i].endereco.cidade);
                scanf(" %s", cliente[i].telefone);

                i++;

                printf("Cadastrado com Sucesso\n");
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

//void atualizarCliente(){}

//void listarCliente(){}

//void cadastrarCarro(){}

//void cadastrarCategoria(){}

//void locarCarro(){}

//void devolverCarro(){}

//void listarDadosLocacao(){}

//void listarLocacaoCliente(){}

//void listarLocacaoEmAberto(){}

//void listarLocacaoPorFrequencia(){}

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

void sair(){
    exit(0);
}

