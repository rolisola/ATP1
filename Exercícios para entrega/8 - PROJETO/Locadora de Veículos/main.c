//FAZER NOVOS TESTES NO CADASTRO DE LOCAÇÃO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum COR{preta=1, branca, prata};
enum CATEGORIA{hatch=1, sedan, suv, jipe};

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
    char renavam[12], placa[9], marca[50], modelo[50];
};
struct CATEGORIACARRO{
    int pontosFidelidade;
    float valorDiaria;
};
struct DATA{
    int dia, mes, ano;
};
struct LOCACAO{
    union PESSOA pessoa;
    struct DATA dataRetirada;
    struct DATA dataDevolucao;
    int codigo, tipoCliente;
    char renavam[12];
};
struct VETORSEMSENTIDO{
    union PESSOA pessoa;
    int posicao, tipoPessoa;

};

struct CLIENTE cliente[15];
struct CARRO carro[10];
struct CATEGORIACARRO categCarro[4];
struct LOCACAO locacao[15][5];
struct VETORSEMSENTIDO indice[15];

//Funções extras
void erro(int erro);
int procurarCliente(int tipoPessoa, union PESSOA pessoa);
void receberDadosCliente(int tipo, int i);
void subMenuAtualizarCliente(int subMenu, int i);
void printarCliente(int i);
int procurarCarro(char *renavam);
int verificarCor(enum COR cor);
int verificarCategoria(enum CATEGORIA categoria);
void receberDadosCategoria(int i);
int indiceDoCaralho(int tipoPessoa, int posicaoCliente, union PESSOA pessoa);


void printaPorraToda();

//Funções principais
void sair();
int cadastrarCliente(int i);
void atualizarCliente();
void listarCliente();
int cadastrarCarro(int i);
void cadastrarCategoria();
int cadastrarLocacaoCarro(int i);
void devolverCarro();
void listarDadosLocacao();
void listarLocacaoCliente();
void listarLocacaoEmAberto();
void listarLocacaoPorFrequencia();

int main()
{
    int contadorCadastroCliente=0, contadorCadastroCarro=0, contadoCadastroCategoria=0, contadorCadastroLocacao=0, opcaoMenu;

    remove("saida.txt");
    //freopen("6.txt", "r", stdin);
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
                atualizarCliente();
                break;
            case 3:
                listarCliente();
                break;
            case 4:
                contadorCadastroCarro = cadastrarCarro(contadorCadastroCarro);
                break;
            case 5:
                cadastrarCategoria();
                break;
            case 6:
                contadorCadastroLocacao = cadastrarLocacaoCarro(contadorCadastroLocacao);
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
            case 12:
                printaPorraToda();
                break;
            default:
                erro(1);
                break;
        }
    }while(opcaoMenu != 0);

    return 0;
}

int procurarCliente(int tipoPessoa, union PESSOA pessoa){
    int i, posicaoPessoa;

    switch(tipoPessoa){
        case 1:
            for(i=0;i<15;i++){
                if(strcmp(cliente[i].pessoa.fisica, pessoa.fisica) == 0){
                    break;
                }
            }
            break;
        case 2:
            for(i=0;i<15;i++){
                if(strcmp(cliente[i].pessoa.juridica, pessoa.juridica) == 0){
                    break;
                }
            }
            break;
    }

    posicaoPessoa = (i == 15) ? -1 : i;

    return posicaoPessoa;
}

void receberDadosCliente(int tipo, int i){
    switch(tipo){
        case 1:
            scanf(" %[^\n]%*c", cliente[i].nome);
            scanf(" %[^\n]%*c", cliente[i].endereco.rua);
            scanf(" %d", &cliente[i].endereco.numero);
            scanf(" %[^\n]%*c", cliente[i].endereco.bairro);
            scanf(" %[^\n]%*c", cliente[i].endereco.cidade);
            scanf(" %s", cliente[i].telefone);
            break;
        case 2:
            scanf(" %[^\n]%*c", cliente[i].endereco.rua);
            scanf(" %d", &cliente[i].endereco.numero);
            scanf(" %[^\n]%*c", cliente[i].endereco.bairro);
            scanf(" %[^\n]%*c", cliente[i].endereco.cidade);
            break;
        case 3:
            scanf(" %s", cliente[i].telefone);
            break;
    }
}

int cadastrarCliente(int i){
    union PESSOA pessoa;
    int tipoPessoa;

    if(i < 15){
        scanf(" %d", &tipoPessoa);
        switch(tipoPessoa){
            case 1:
                scanf(" %s", pessoa.fisica);
                if(procurarCliente(tipoPessoa, pessoa) != -1){
                    erro(3);
                    return i;
                }
                strcpy(cliente[i].pessoa.fisica, pessoa.fisica);
                receberDadosCliente(1, i);

                i++;

                printf("Cadastrado com Sucesso CPF\n");
                break;
            case 2:
                scanf(" %s", pessoa.juridica);
                if(procurarCliente(tipoPessoa, pessoa) != -1){
                    erro(3);
                    return i;
                }
                strcpy(cliente[i].pessoa.juridica, pessoa.juridica);
                receberDadosCliente(1, i);

                i++;

                printf("Cadastrado com Sucesso CNPJ\n");
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

void subMenuAtualizarCliente(int subMenu, int i){
    switch(subMenu){
        case 1:
            receberDadosCliente(2, i);
            break;
        case 2:
            receberDadosCliente(3, i);
            break;
        default:
            erro(1);
            break;
    }
}

void atualizarCliente(){
    union PESSOA pessoa;
    int tipoPessoa, posicaoCliente, opcaoSubMenu;

    scanf(" %d", &tipoPessoa);
    switch(tipoPessoa){
        case 1:
            scanf(" %s", pessoa.fisica);
            posicaoCliente = procurarCliente(tipoPessoa, pessoa);
            if(posicaoCliente == -1){
                erro(4);
                return;
            }

            scanf(" %d", &opcaoSubMenu);
            subMenuAtualizarCliente(opcaoSubMenu, posicaoCliente);

            printf("Cadastrado com Sucesso ATT CPF\n");
            break;
        case 2:
            scanf(" %s", pessoa.juridica);
            posicaoCliente = procurarCliente(tipoPessoa, pessoa);
            if(posicaoCliente == -1){
                erro(4);
                return;
            }

            scanf(" %d", &opcaoSubMenu);
            subMenuAtualizarCliente(opcaoSubMenu, posicaoCliente);

            printf("Cadastrado com Sucesso ATT CNPJ\n");
            break;
        default:
            erro(1);
            break;
        }
}

void printarCliente(int i){
    printf("nome: %s\n", cliente[i].nome);
    printf("rua: %s\n", cliente[i].endereco.rua);
    printf("num: %d\n", cliente[i].endereco.numero);
    printf("bairro: %s\n", cliente[i].endereco.bairro);
    printf("cidade: %s\n", cliente[i].endereco.cidade);
    printf("telefone: %s\n", cliente[i].telefone);
}

void listarCliente(){
    union PESSOA pessoa;
    int tipoPessoa, posicaoCliente;

    scanf(" %d", &tipoPessoa);
    switch(tipoPessoa){
        case 1:
            scanf(" %[^\n]%*c", pessoa.fisica);
            posicaoCliente = procurarCliente(tipoPessoa, pessoa);
            if(posicaoCliente == -1){
                erro(4);
                return;
            }

            printarCliente(posicaoCliente);
            break;
        case 2:
            scanf(" %[^\n]%*c", pessoa.juridica);
            posicaoCliente = procurarCliente(tipoPessoa, pessoa);
            if(posicaoCliente == -1){
                erro(4);
                return;
            }

            printarCliente(posicaoCliente);
            break;
        default:
            erro(1);
            break;
    }
}

int procurarCarro(char *renavam){
    int i, posicaoCarro;

    for(i=0;i<10;i++){
        if(strcmp(carro[i].renavam, renavam) == 0){
            break;
        }
    }

    posicaoCarro = (i == 10) ? -1 : i;

    return posicaoCarro;
}

int verificarCor(enum COR cor){
    return ((cor >= 1) && (cor <= 3)) ? 0 :  1;
}

int verificarCategoria(enum CATEGORIA categoria){
    return ((categoria >= 1) && (categoria <= 4)) ? 0 : 1;
}

int cadastrarCarro(int i){
    char recebeRenavam[12];

    if(i < 10){
        scanf(" %s", recebeRenavam);
        if(procurarCarro(recebeRenavam) != -1){
            erro(3);
            return i;
        }

        scanf(" %u", &carro[i].cor);
        if(verificarCor(carro[i].cor) != 0){
            erro(1);
            return i;
        }

        scanf(" %u", &carro[i].categoria);
        if(verificarCategoria(carro[i].categoria) != 0){
            erro(1);
            return i;
        }

        strcpy(carro[i].renavam, recebeRenavam);

        scanf(" %s", carro[i].placa);
        scanf(" %[^\n]%*c", carro[i].marca);
        scanf(" %[^\n]%*c", carro[i].modelo);
        scanf(" %d", &carro[i].ano);

        i++;

        printf("Cadastrado com Sucesso CARRO\n");
    }else{
        erro(2);
    }

    return i;
}

void receberDadosCategoria(int i){
    scanf(" %f", &categCarro[i].valorDiaria);
    scanf(" %d", &categCarro[i].pontosFidelidade);
}

void cadastrarCategoria(){
    enum CATEGORIA recebeCategoria;

    scanf(" %u", &recebeCategoria);
    switch(recebeCategoria){
        case hatch:
            receberDadosCategoria(recebeCategoria-1);
            printf("Cadastrado com Sucesso CATEG\n");
            break;
        case sedan:
            receberDadosCategoria(recebeCategoria-1);
            printf("Cadastrado com Sucesso CATEG\n");
            break;
        case suv:
            receberDadosCategoria(recebeCategoria-1);
            printf("Cadastrado com Sucesso CATEG\n");
            break;
        case jipe:
            receberDadosCategoria(recebeCategoria-1);
            printf("Cadastrado com Sucesso CATEG\n");
            break;
        default:
            erro(1);
            break;
    }
}

int indiceDoCaralho(int tipoPessoa, int posicaoCliente, union PESSOA pessoa){
    int i;

    switch(tipoPessoa){
        case 1:
            for(i=0;i<15;i++){
                if(strcmp(indice[i].pessoa.fisica, pessoa.fisica) == 0){
                    break;
                }
            }
            if(i == 15){
                for(i=0;i<15;i++){
                    if(indice[i].pessoa.fisica[0] == '\0'){
                        break;
                    }
                }
                strcpy(indice[i].pessoa.fisica, cliente[posicaoCliente].pessoa.fisica);
                indice[i].tipoPessoa = tipoPessoa;
                indice[i].posicao = i;
            }
            break;
        case 2:
            for(i=0;i<15;i++){
                if(strcmp(indice[i].pessoa.juridica, pessoa.juridica) == 0){
                    break;
                }
            }
            if(i == 15){
                for(i=0;i<15;i++){
                    if(indice[i].pessoa.juridica[0] == '\0'){
                        break;
                    }
                }
                strcpy(indice[i].pessoa.juridica, cliente[posicaoCliente].pessoa.juridica);
                indice[i].tipoPessoa = tipoPessoa;
                indice[i].posicao = i;
            }
            break;
    }

    return i;
}

int cadastrarLocacaoCarro(int i){
    union PESSOA pessoa;
    int j, k, posicaoCarro, tipoPessoa, posicaoCliente, posicaoMatriz;
    char recebeRenavam[12];
    scanf(" %s", recebeRenavam);
    posicaoCarro = procurarCarro(recebeRenavam);
    if(posicaoCarro != -1){
        for(j=0;j<15;j++){
            for(k=0;k<5;k++){
                if((strcmp(locacao[j][k].renavam, recebeRenavam) == 0) && (strcmp(locacao[j][k].dataDevolucao.ano, "0000") == 0)){
                    erro(5);
                    return i;
                }
            }
        }
        scanf(" %d", &tipoPessoa);
        switch(tipoPessoa){
            case 1:
                scanf(" %s", pessoa.fisica);
                posicaoCliente = procurarCliente(tipoPessoa, pessoa);
                if(posicaoCliente == -1){
                    erro(4);
                    return i;
                }
                posicaoMatriz = indiceDoCaralho(tipoPessoa, posicaoCliente, pessoa);
                for(k=0;k<5;k++){
                    if(locacao[posicaoMatriz][k].dataDevolucao.ano == 0){
                        erro(5);
                        return i;
                    }
                }
                for(k=0;k<5;k++){
                    if(locacao[posicaoMatriz][k].renavam[0] == '\0'){
                        break;
                    }
                }
                if(k == 5){
                    erro(2);
                    return i;
                }
                scanf(" %d", locacao[posicaoMatriz][k].dataRetirada.dia);
                scanf(" %d", locacao[posicaoMatriz][k].dataRetirada.mes);
                scanf(" %d", locacao[posicaoMatriz][k].dataRetirada.ano);
                strcpy(locacao[posicaoMatriz][k].pessoa.fisica, cliente[posicaoCliente].pessoa.fisica);
                strcpy(locacao[posicaoMatriz][k].renavam, carro[posicaoCarro].renavam);
                locacao[posicaoMatriz][k].dataDevolucao.dia = 0;
                locacao[posicaoMatriz][k].dataDevolucao.mes = 0;
                locacao[posicaoMatriz][k].dataDevolucao.ano = 0;
                locacao[posicaoMatriz][k].tipoCliente = 1;
                locacao[posicaoMatriz][k].codigo = (1001+i);
                i++;
                printf("%d cadastrado com sucesso LOCACAO\n", locacao[posicaoMatriz][k].codigo);
                break;
            case 2:
                scanf(" %s", pessoa.juridica);
                posicaoCliente = procurarCliente(tipoPessoa, pessoa);
                if(posicaoCliente == -1){
                    erro(4);
                    return i;
                }
                posicaoMatriz = indiceDoCaralho(tipoPessoa, posicaoCliente, pessoa);
                for(k=0;k<5;k++){
                    if(locacao[posicaoMatriz][k].dataDevolucao.ano == 0){
                        erro(5);
                        return i;
                    }
                }
                for(k=0;k<5;k++){
                    if(locacao[posicaoMatriz][k].renavam[0] == '\0'){
                        break;
                    }
                }
                if(k == 5){
                    erro(2);
                    return i;
                }
                scanf(" %d", locacao[posicaoMatriz][k].dataRetirada.dia);
                scanf(" %d", locacao[posicaoMatriz][k].dataRetirada.mes);
                scanf(" %d", locacao[posicaoMatriz][k].dataRetirada.ano);
                strcpy(locacao[posicaoMatriz][k].pessoa.juridica, cliente[posicaoCliente].pessoa.juridica);
                strcpy(locacao[posicaoMatriz][k].renavam, carro[posicaoCarro].renavam);
                locacao[posicaoMatriz][k].dataDevolucao.dia = 0;
                locacao[posicaoMatriz][k].dataDevolucao.mes = 0;
                locacao[posicaoMatriz][k].dataDevolucao.ano = 0;
                locacao[posicaoMatriz][k].tipoCliente = 1;
                locacao[posicaoMatriz][k].codigo = (1001+i);
                i++;
                printf("%d cadastrado com sucesso LOCACAO\n", locacao[posicaoMatriz][k].codigo);
                break;
            default:
                erro(1);
                break;
        }
    }else{
        erro(4);
    }
    return i;
}

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

void printaPorraToda(){
    int i=0,j=0;
    /*printf("\nClientes\n");
    for(i=0;i<15;i++){
        printf("%s\n", cliente[i].pessoa.juridica);
        printf("%s\n", cliente[i].nome);
        printf("%s\n", cliente[i].endereco.rua);
        printf("%d\n", cliente[i].endereco.numero);
        printf("%s\n", cliente[i].endereco.bairro);
        printf("%s\n", cliente[i].endereco.cidade);
        printf("%s\n\n", cliente[i].telefone);
    }
    printf("\nCarros\n");
    for(i=0;i<10;i++){
        printf("%s\n", carro[i].renavam);
        printf("%u\n", carro[i].cor);
        printf("%u\n", carro[i].categoria);
        printf("%s\n", carro[i].marca);
        printf("%s\n", carro[i].modelo);
        printf("%s\n", carro[i].placa);
        printf("%d\n\n", carro[i].ano);
    }
    printf("\nCategorias\n");
    for(i=0;i<4;i++){
        printf("%d\n", categCarro[i].pontosFidelidade);
        printf("%.2f\n", categCarro[i].valorDiaria);
    }*/
    printf("\n\nLocacao\n");
    for(i=0;i<15;i++){
        printf("\n%s\n", locacao[i][j].pessoa.juridica);
        printf("%d\n", locacao[i][j].tipoCliente);
        for(i=0;i<15;i++){
            printf("%d\n", locacao[i][j].codigo);
            printf("%s\n", locacao[i][j].renavam);
            printf("%02d/%02d/%02d\n", locacao[i][j].dataRetirada.dia, locacao[i][j].dataRetirada.mes, locacao[i][j].dataRetirada.ano);
            printf("%02d/%02d/%02d\n\n", locacao[i][j].dataDevolucao.dia, locacao[i][j].dataDevolucao.mes, locacao[i][j].dataDevolucao.ano);
        }
    }
}
