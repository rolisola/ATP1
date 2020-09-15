#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    float valorDevido, desconto;
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
int procurarCliente(int *tipoPessoa, union PESSOA pessoa);
void receberDadosCliente(int tipo, int *i);
void subMenuAtualizarCliente(int *subMenu, int *i);
void printarCliente(int *i);
int procurarCarro(char *renavam);
int verificarCor(enum COR cor);
int verificarCategoria(enum CATEGORIA categoria);
void receberDadosCategoria(int i);
int verificarData(int *dia, int *mes, int *ano);
int indiceDoCaralho(int *tipoPessoa, int *posicaoCliente, union PESSOA pessoa);


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
void listarFrequencia();

int main()
{
    int contadorCadastroCliente=0, contadorCadastroCarro=0, contadorCadastroLocacao=0, opcaoMenu, recebeCodigoLocacao;
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
                devolverCarro();
                break;
            case 8:
                scanf(" %d", &recebeCodigoLocacao);
                listarDadosLocacao(&recebeCodigoLocacao);
                break;
            case 9:
                listarLocacaoCliente();
                break;
            case 10:
                listarLocacaoEmAberto();
                break;
            case 11:
                listarFrequencia();
                break;
            /*case 12:
                printaPorraToda();
                break;*/
            default:
                erro(1);
                break;
        }
    }while(opcaoMenu != 0);

    return 0;
}

int procurarCliente(int *tipoPessoa, union PESSOA pessoa){
    int i, posicaoPessoa;

    switch(*tipoPessoa){
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

void receberDadosCliente(int tipo, int *i){
    switch(tipo){
        case 1:
            scanf(" %[^\n]%*c", cliente[*i].nome);
            scanf(" %[^\n]%*c", cliente[*i].endereco.rua);
            scanf(" %d", &cliente[*i].endereco.numero);
            scanf(" %[^\n]%*c", cliente[*i].endereco.bairro);
            scanf(" %[^\n]%*c", cliente[*i].endereco.cidade);
            scanf(" %s", cliente[*i].telefone);
            break;
        case 2:
            scanf(" %[^\n]%*c", cliente[*i].endereco.rua);
            scanf(" %d", &cliente[*i].endereco.numero);
            scanf(" %[^\n]%*c", cliente[*i].endereco.bairro);
            scanf(" %[^\n]%*c", cliente[*i].endereco.cidade);
            break;
        case 3:
            scanf(" %s", cliente[*i].telefone);
            break;
    }
}

int cadastrarCliente(int i){
    union PESSOA pessoa;
    int recebeTipoPessoa;

    if(i < 15){
        scanf(" %d", &recebeTipoPessoa);
        switch(recebeTipoPessoa){
            case 1:
                scanf(" %s", pessoa.fisica);
                if(procurarCliente(&recebeTipoPessoa, pessoa) != -1){
                    erro(3);
                    break;
                }
                strcpy(cliente[i].pessoa.fisica, pessoa.fisica);
                receberDadosCliente(1, &i);

                i++;

                printf("Cadastrado com Sucesso\n");
                break;
            case 2:
                scanf(" %s", pessoa.juridica);
                if(procurarCliente(&recebeTipoPessoa, pessoa) != -1){
                    erro(3);
                    break;
                }
                strcpy(cliente[i].pessoa.juridica, pessoa.juridica);
                receberDadosCliente(1, &i);

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

void atualizarCliente(){
    union PESSOA pessoa;
    int recebeTipoPessoa, posicaoCliente, opcaoSubMenu;

    scanf(" %d", &recebeTipoPessoa);
    switch(recebeTipoPessoa){
        case 1:
            scanf(" %s", pessoa.fisica);
            posicaoCliente = procurarCliente(&recebeTipoPessoa, pessoa);
            if(posicaoCliente == -1){
                erro(4);
                break;
            }

            scanf(" %d", &opcaoSubMenu);
            switch(opcaoSubMenu){
                case 1:
                    receberDadosCliente(2, &posicaoCliente);
                    break;
                case 2:
                    receberDadosCliente(3, &posicaoCliente);
                    break;
                default:
                    erro(1);
                    return;
            }

            printf("Cadastrado com Sucesso\n");
            break;
        case 2:
            scanf(" %s", pessoa.juridica);
            posicaoCliente = procurarCliente(&recebeTipoPessoa, pessoa);
            if(posicaoCliente == -1){
                erro(4);
                break;
            }

            scanf(" %d", &opcaoSubMenu);
            switch(opcaoSubMenu){
                case 1:
                    receberDadosCliente(2, &posicaoCliente);
                    break;
                case 2:
                    receberDadosCliente(3, &posicaoCliente);
                    break;
                default:
                    erro(1);
                    return;
            }

            printf("Cadastrado com Sucesso\n");
            break;
        default:
            erro(1);
            break;
    }
}

void printarCliente(int *i){
    printf("nome: %s\n", cliente[*i].nome);
    printf("rua: %s\n", cliente[*i].endereco.rua);
    printf("num: %d\n", cliente[*i].endereco.numero);
    printf("bairro: %s\n", cliente[*i].endereco.bairro);
    printf("cidade: %s\n", cliente[*i].endereco.cidade);
    printf("telefone: %s\n", cliente[*i].telefone);
}

void listarCliente(){
    union PESSOA pessoa;
    int recebeTipoPessoa, posicaoCliente;

    scanf(" %d", &recebeTipoPessoa);
    switch(recebeTipoPessoa){
        case 1:
            scanf(" %s", pessoa.fisica);
            posicaoCliente = procurarCliente(&recebeTipoPessoa, pessoa);
            if(posicaoCliente == -1){
                erro(4);
                break;
            }

            printarCliente(&posicaoCliente);
            break;
        case 2:
            scanf(" %s", pessoa.juridica);
            posicaoCliente = procurarCliente(&recebeTipoPessoa, pessoa);
            if(posicaoCliente == -1){
                erro(4);
                break;
            }

            printarCliente(&posicaoCliente);
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

        scanf(" %u", &carro[i].categoria);
        if(verificarCategoria(carro[i].categoria) != 0){
            erro(1);
            return i;
        }

        scanf(" %u", &carro[i].cor);
        if(verificarCor(carro[i].cor) != 0){
            erro(1);
            return i;
        }

        strcpy(carro[i].renavam, recebeRenavam);

        scanf(" %s", carro[i].placa);
        scanf(" %[^\n]%*c", carro[i].marca);
        scanf(" %[^\n]%*c", carro[i].modelo);
        scanf(" %d", &carro[i].ano);

        i++;

        printf("Cadastrado com Sucesso\n");
    }else{
        erro(2);
    }
    return i;
}

void receberDadosCategoria(int i){
    scanf(" %f", &categCarro[i-1].valorDiaria);
    scanf(" %d", &categCarro[i-1].pontosFidelidade);
}

void cadastrarCategoria(){
    enum CATEGORIA recebeCategoria;

    scanf(" %u", &recebeCategoria);
    switch(recebeCategoria){
        case hatch:
            receberDadosCategoria(recebeCategoria);
            printf("Cadastrado com Sucesso\n");
            break;
        case sedan:
            receberDadosCategoria(recebeCategoria);
            printf("Cadastrado com Sucesso\n");
            break;
        case suv:
            receberDadosCategoria(recebeCategoria);
            printf("Cadastrado com Sucesso\n");
            break;
        case jipe:
            receberDadosCategoria(recebeCategoria);
            printf("Cadastrado com Sucesso\n");
            break;
        default:
            erro(1);
            break;
    }
}

int verificarData(int *dia, int *mes, int *ano){
    if((*dia >= 1 && *dia <= 31) && (*mes >= 1 && *mes <= 12)){
        if((*dia <= 29 && *mes == 2) && *mes == 2){
            return 0;
        }
        if((*dia <= 30) && (*mes == 4 || *mes == 6 || *mes == 9 || *mes == 11)){
            return 0;
        }
        if((*dia <=31) && (*mes == 1 || *mes == 3 || *mes == 5 || *mes == 7 || *mes == 8 || *mes == 10 || *mes == 12)){
            return 0;
        }
    }
    return 1;
}

int indiceDoCaralho(int *tipoPessoa, int *posicaoCliente, union PESSOA pessoa){
    int i;

    switch(*tipoPessoa){
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
                strcpy(indice[i].pessoa.fisica, cliente[*posicaoCliente].pessoa.fisica);
                indice[i].tipoPessoa = *tipoPessoa;
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
                strcpy(indice[i].pessoa.juridica, cliente[*posicaoCliente].pessoa.juridica);
                indice[i].tipoPessoa = *tipoPessoa;
                indice[i].posicao = i;
            }
            break;
    }
    return i;
}

int cadastrarLocacaoCarro(int i){
    union PESSOA pessoa;
    int j, k, posicaoCarro, recebeTipoPessoa, posicaoCliente, posicaoMatriz, diaRetirada, mesRetirada, anoRetirada;
    char recebeRenavam[12];

    scanf(" %s", recebeRenavam);
    posicaoCarro = procurarCarro(recebeRenavam);
    if(posicaoCarro != -1){
        for(j=0;j<15;j++){
            for(k=0;k<5;k++){
                if((strcmp(locacao[j][k].renavam, recebeRenavam) == 0) && (locacao[j][k].dataDevolucao.ano == 0)){
                    erro(5);
                    return i;
                }
            }
        }

        scanf(" %d", &recebeTipoPessoa);
        switch(recebeTipoPessoa){
            case 1:
                scanf(" %s", pessoa.fisica);
                posicaoCliente = procurarCliente(&recebeTipoPessoa, pessoa);
                if(posicaoCliente == -1){
                    erro(4);
                    break;
                }

                posicaoMatriz = indiceDoCaralho(&recebeTipoPessoa, &posicaoCliente, pessoa);
                for(k=0;k<5;k++){
                    if((locacao[posicaoMatriz][k].dataRetirada.ano != 0) && (locacao[posicaoMatriz][k].dataDevolucao.ano == 0)){
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
                    break;
                }

                scanf(" %d %d %d", &diaRetirada, &mesRetirada, &anoRetirada);
                if(verificarData(&diaRetirada, &mesRetirada, &anoRetirada) != 0){
                    erro(6);
                    break;
                }
                strcpy(locacao[posicaoMatriz][k].pessoa.fisica, cliente[posicaoCliente].pessoa.fisica);
                strcpy(locacao[posicaoMatriz][k].renavam, carro[posicaoCarro].renavam);
                locacao[posicaoMatriz][k].dataRetirada.dia = diaRetirada;
                locacao[posicaoMatriz][k].dataRetirada.mes = mesRetirada;
                locacao[posicaoMatriz][k].dataRetirada.ano = anoRetirada;
                locacao[posicaoMatriz][k].dataDevolucao.dia = 0;
                locacao[posicaoMatriz][k].dataDevolucao.mes = 0;
                locacao[posicaoMatriz][k].dataDevolucao.ano = 0;
                locacao[posicaoMatriz][k].tipoCliente = 1;
                locacao[posicaoMatriz][k].codigo = (1001+i);

                i++;

                printf("%d cadastrado com sucesso\n", locacao[posicaoMatriz][k].codigo);
                break;
            case 2:
                scanf(" %s", pessoa.juridica);
                posicaoCliente = procurarCliente(&recebeTipoPessoa, pessoa);
                if(posicaoCliente == -1){
                    erro(4);
                    break;
                }

                posicaoMatriz = indiceDoCaralho(&recebeTipoPessoa, &posicaoCliente, pessoa);
                for(k=0;k<5;k++){
                    if((locacao[posicaoMatriz][k].dataRetirada.ano != 0) && (locacao[posicaoMatriz][k].dataDevolucao.ano == 0)){
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
                    break;
                }

                scanf(" %d %d %d", &diaRetirada, &mesRetirada, &anoRetirada);
                if(verificarData(&diaRetirada, &mesRetirada, &anoRetirada) != 0){
                    erro(6);
                    break;
                }
                strcpy(locacao[posicaoMatriz][k].pessoa.juridica, cliente[posicaoCliente].pessoa.juridica);
                strcpy(locacao[posicaoMatriz][k].renavam, carro[posicaoCarro].renavam);
                locacao[posicaoMatriz][k].dataRetirada.dia = diaRetirada;
                locacao[posicaoMatriz][k].dataRetirada.mes = mesRetirada;
                locacao[posicaoMatriz][k].dataRetirada.ano = anoRetirada;
                locacao[posicaoMatriz][k].dataDevolucao.dia = 0;
                locacao[posicaoMatriz][k].dataDevolucao.mes = 0;
                locacao[posicaoMatriz][k].dataDevolucao.ano = 0;
                locacao[posicaoMatriz][k].tipoCliente = 1;
                locacao[posicaoMatriz][k].codigo = (1001+i);

                i++;

                printf("%d cadastrado com sucesso\n", locacao[posicaoMatriz][k].codigo);
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

int calcularDiferencaDatas(struct DATA *dataRetirada, struct DATA *dataDevolucao){
    struct tm dR={0}, dD={0};
    int diferenca;

    dR.tm_year = dataRetirada->ano-1900;
    dR.tm_mon = dataRetirada->mes;
    dR.tm_mday = dataRetirada->dia;
    dD.tm_year = dataDevolucao->ano-1900;
    dD.tm_mon = dataDevolucao->mes;
    dD.tm_mday = dataDevolucao->dia;

    time_t data1 = mktime(&dR);
    time_t data2 = mktime(&dD);

    diferenca = (int)difftime(data2, data1);
    diferenca = diferenca/86400;

    return diferenca;
}

void devolverCarro(){
    union PESSOA pessoa;
    struct DATA recebeDataDevolucao;
    int i, recebeTipoPessoa, posicaoCliente, posicaoMatriz, diferencaEmDias, posicaoCarro, posicaoCarroLocacaoAnterior;
    scanf(" %d", &recebeTipoPessoa);
    switch(recebeTipoPessoa){
        case 1:
            scanf(" %s", pessoa.fisica);
            posicaoCliente = procurarCliente(&recebeTipoPessoa, pessoa);
            if(posicaoCliente == -1){
                erro(4);
                break;
            }
            posicaoMatriz = indiceDoCaralho(&recebeTipoPessoa, &posicaoCliente, pessoa);
            for(i=0;i<5;i++){
                if((locacao[posicaoMatriz][i].codigo != 0) && (locacao[posicaoMatriz][i].dataDevolucao.ano == 0)){
                    break;
                }
            }
            if(i == 5){
                erro(7);
                break;
            }

            scanf(" %d %d %d", &recebeDataDevolucao.dia, &recebeDataDevolucao.mes, &recebeDataDevolucao.ano);
            if(verificarData(&recebeDataDevolucao.dia, &recebeDataDevolucao.mes, &recebeDataDevolucao.ano) != 0){
                erro(6);
                break;
            }

            diferencaEmDias = (int)calcularDiferencaDatas(&locacao[posicaoMatriz][i].dataRetirada, &recebeDataDevolucao);
            if(diferencaEmDias == 0){
                locacao[posicaoMatriz][i].codigo = 0;
                locacao[posicaoMatriz][i].renavam[0] = '\0';
                locacao[posicaoMatriz][i].dataRetirada.dia = 0;
                locacao[posicaoMatriz][i].dataRetirada.mes = 0;
                locacao[posicaoMatriz][i].dataRetirada.ano = 0;
                locacao[posicaoMatriz][i].dataDevolucao.dia = 0;
                locacao[posicaoMatriz][i].dataDevolucao.mes = 0;
                locacao[posicaoMatriz][i].dataDevolucao.ano = 0;

                printf("Locacao cancelada\n");
                break;
            }
            locacao[posicaoMatriz][i].dataDevolucao.dia = recebeDataDevolucao.dia;
            locacao[posicaoMatriz][i].dataDevolucao.mes = recebeDataDevolucao.mes;
            locacao[posicaoMatriz][i].dataDevolucao.ano = recebeDataDevolucao.ano;

            posicaoCarro = procurarCarro(locacao[posicaoMatriz][i].renavam);
            locacao[posicaoMatriz][i].valorDevido = (categCarro[carro[posicaoCarro].categoria-1].valorDiaria * (float)diferencaEmDias);
            if(i!=0){
                posicaoCarroLocacaoAnterior = procurarCarro(locacao[posicaoMatriz][i-1].renavam);
                locacao[posicaoMatriz][i].desconto = ((categCarro[carro[posicaoCarroLocacaoAnterior].categoria-1].pontosFidelidade * 50)/1000);
            }else{
                locacao[posicaoMatriz][i].desconto = 0;
            }
            if(locacao[posicaoMatriz][i].desconto > locacao[posicaoMatriz][i].valorDevido*0.3){
                locacao[posicaoMatriz][i].desconto = locacao[posicaoMatriz][i].valorDevido*0.3;
            }

            printf("Valor devido: %.2f\n", locacao[posicaoMatriz][i].valorDevido);
            printf("Desconto: %.2f\n", locacao[posicaoMatriz][i].desconto);
            break;
        case 2:
            scanf(" %s", pessoa.juridica);
            posicaoCliente = procurarCliente(&recebeTipoPessoa, pessoa);
            if(posicaoCliente == -1){
                erro(4);
                break;
            }
            posicaoMatriz = indiceDoCaralho(&recebeTipoPessoa, &posicaoCliente, pessoa);
            for(i=0;i<5;i++){
                if((locacao[posicaoMatriz][i].codigo != 0) && (locacao[posicaoMatriz][i].dataDevolucao.ano == 0)){
                    break;
                }
            }
            if(i == 5){
                erro(7);
                break;
            }

            scanf(" %d %d %d", &recebeDataDevolucao.dia, &recebeDataDevolucao.mes, &recebeDataDevolucao.ano);
            if(verificarData(&recebeDataDevolucao.dia, &recebeDataDevolucao.mes, &recebeDataDevolucao.ano) != 0){
                erro(6);
                break;
            }

            diferencaEmDias = (int)calcularDiferencaDatas(&locacao[posicaoMatriz][i].dataRetirada, &recebeDataDevolucao);
            if(diferencaEmDias == 0){
                locacao[posicaoMatriz][i].codigo = 0;
                locacao[posicaoMatriz][i].renavam[0] = '\0';
                locacao[posicaoMatriz][i].dataRetirada.dia = 0;
                locacao[posicaoMatriz][i].dataRetirada.mes = 0;
                locacao[posicaoMatriz][i].dataRetirada.ano = 0;
                locacao[posicaoMatriz][i].dataDevolucao.dia = 0;
                locacao[posicaoMatriz][i].dataDevolucao.mes = 0;
                locacao[posicaoMatriz][i].dataDevolucao.ano = 0;
                erro(8);
                break;
            }

            locacao[posicaoMatriz][i].dataDevolucao.dia = recebeDataDevolucao.dia;
            locacao[posicaoMatriz][i].dataDevolucao.mes = recebeDataDevolucao.mes;
            locacao[posicaoMatriz][i].dataDevolucao.ano = recebeDataDevolucao.ano;

            posicaoCarro = procurarCarro(locacao[posicaoMatriz][i].renavam);
            locacao[posicaoMatriz][i].valorDevido = (categCarro[carro[posicaoCarro].categoria-1].valorDiaria * (float)diferencaEmDias);
            if(i!=0){
                posicaoCarroLocacaoAnterior = procurarCarro(locacao[posicaoMatriz][i-1].renavam);
                locacao[posicaoMatriz][i].desconto = ((categCarro[carro[posicaoCarroLocacaoAnterior].categoria-1].pontosFidelidade * 50)/1000);
            }else{
                locacao[posicaoMatriz][i].desconto = 0;
            }
            if(locacao[posicaoMatriz][i].desconto > locacao[posicaoMatriz][i].valorDevido*0.3){
                locacao[posicaoMatriz][i].desconto = locacao[posicaoMatriz][i].valorDevido*0.3;
            }

            printf("Valor devido: %.2f\n", locacao[posicaoMatriz][i].valorDevido);
            printf("Desconto: %.2f\n", locacao[posicaoMatriz][i].desconto);
            break;
        default:
            erro(1);
            break;
    }
}

void printarLocacao(int *i,int *j){
    printf("codigo da locacao: %d\n", locacao[*i][*j].codigo);
    switch(locacao[*i][*j].tipoCliente){
        case 1:
            printf("cpf: %s\n", locacao[*i][*j].pessoa.fisica);
            break;
        case 2:
            printf("cnpj: %s\n", locacao[*i][*j].pessoa.juridica);
            break;
    }
    printf("nome: %s\n", cliente[procurarCliente(&locacao[*i][*j].tipoCliente, locacao[*i][*j].pessoa)].nome);
    printf("renavam: %s\n", locacao[*i][*j].renavam);
    printf("data retirada: %02d/%02d/%02d\n", locacao[*i][*j].dataRetirada.dia,locacao[*i][*j].dataRetirada.mes, locacao[*i][*j].dataRetirada.ano);
    printf("data entrega: %02d/%02d/%02d\n", locacao[*i][*j].dataDevolucao.dia, locacao[*i][*j].dataDevolucao.mes, locacao[*i][*j].dataDevolucao.ano);
}

void listarDadosLocacao(int *codigoLocacao){
    int i, j;

    for(i=0;i<15;i++){
        for(j=0;j<5;j++){
            if(locacao[i][j].codigo == *codigoLocacao){
                printarLocacao(&i, &j);
                return;
            }
        }
    }
    if(i == 15){
        erro(8);
    }
}

void listarLocacaoCliente(){
    union PESSOA pessoa;
    int i, cont=0, recebeTipoPessoa, posicaoCliente, posicaoMatriz, subMenu;

    scanf(" %d", &recebeTipoPessoa);
    switch(recebeTipoPessoa){
        case 1:
            scanf(" %s", pessoa.fisica);
            posicaoCliente = procurarCliente(&recebeTipoPessoa, pessoa);
            if(posicaoCliente == -1){
                erro(4);
                return;
            }
            posicaoMatriz = indiceDoCaralho(&recebeTipoPessoa, &posicaoCliente, pessoa);

            scanf(" %d", &subMenu);
            switch(subMenu){
                case 1:
                    for(i=0;i<5;i++){
                        if(locacao[posicaoMatriz][i].codigo != 0){
                            listarDadosLocacao(&locacao[posicaoMatriz][i].codigo);
                            i++;
                        }else{
                            cont++;
                        }
                    }
                    if(cont == 5){
                        erro(9);
                    }
                    break;
                case 2:
                    for(i=0;i<5;i++){
                        if((locacao[posicaoMatriz][i].codigo != 0) && (locacao[posicaoMatriz][i].dataDevolucao.dia != 0)){
                            listarDadosLocacao(&locacao[posicaoMatriz][i].codigo);
                            i++;
                        }else{
                            cont++;
                        }
                    }
                    if(cont == 5){
                        erro(9);
                    }
                    break;
                case 3:
                    for(i=0;i<5;i++){
                        if((locacao[posicaoMatriz][i].codigo != 0) && (locacao[posicaoMatriz][i].dataDevolucao.dia == 0)){
                            listarDadosLocacao(&locacao[posicaoMatriz][i].codigo);
                            i++;
                        }else{
                            cont++;
                        }
                    }
                    if(cont == 5){
                        erro(9);
                    }
                    break;
                default:
                    erro(1);
                    break;
            }
            break;
        case 2:
            scanf(" %s", pessoa.juridica);
            posicaoCliente = procurarCliente(&recebeTipoPessoa, pessoa);
            if(posicaoCliente == -1){
                erro(4);
                return;
            }
            posicaoMatriz = indiceDoCaralho(&recebeTipoPessoa, &posicaoCliente, pessoa);

            scanf(" %d", &subMenu);
            switch(subMenu){
                case 1:
                    for(i=0;i<5;i++){
                        if(locacao[posicaoMatriz][i].codigo != 0){
                            listarDadosLocacao(&locacao[posicaoMatriz][i].codigo);
                            i++;
                        }else{
                            cont++;
                        }
                    }
                    if(cont == 5){
                        erro(9);
                    }
                    break;
                case 2:
                    for(i=0;i<5;i++){
                        if((locacao[posicaoMatriz][i].codigo != 0) && (locacao[posicaoMatriz][i].dataDevolucao.dia != 0)){
                            listarDadosLocacao(&locacao[posicaoMatriz][i].codigo);
                            i++;
                        }else{
                            cont++;
                        }
                    }
                    if(cont == 5){
                        erro(9);
                    }
                    break;
                case 3:
                    for(i=0;i<5;i++){
                        if((locacao[posicaoMatriz][i].codigo != 0) && (locacao[posicaoMatriz][i].dataDevolucao.dia == 0)){
                            listarDadosLocacao(&locacao[posicaoMatriz][i].codigo);
                            i++;
                        }else{
                            cont++;
                        }
                    }
                    if(cont == 5){
                        erro(9);
                    }
                    break;
                default:
                    erro(1);
                    break;
            }
            break;
        default:
            erro(1);
            break;
    }
}

void listarLocacaoEmAberto(){
    int i, j, cont=0, recebeTipoPessoa;

    scanf(" %d", &recebeTipoPessoa);
    switch(recebeTipoPessoa){
        case 1:
            for(i=0;i<15;i++){
                for(j=0;j<5;j++){
                    if((locacao[i][j].tipoCliente == 1) && (locacao[i][j].codigo != 0) && (locacao[i][j].dataDevolucao.dia == 0)){
                        printarLocacao(&i, &j);
                        cont++;
                    }
                }
            }
            if(cont == 0){
                erro(9);
            }
            break;
        case 2:
            for(i=0;i<15;i++){
                for(j=0;j<5;j++){
                    if((locacao[i][j].tipoCliente == 2) && (locacao[i][j].codigo != 0) && (locacao[i][j].dataDevolucao.dia == 0)){
                        printarLocacao(&i, &j);
                        cont++;
                    }
                }
            }
            if(cont == 0){
                erro(9);
            }
            break;
        default:
            erro(1);
            break;
    }
}

int *contadorFrequencia(int tipoPessoa, int *vetorContador){
    int i, j;

    switch(tipoPessoa){
        case 1:
            for(i=0;i<15;i++){
                if(indice[i].tipoPessoa == 1){
                    for(j=0;j<5;j++){
                        switch(carro[procurarCarro(locacao[i][j].renavam)].categoria){
                            case hatch:
                                vetorContador[0]++;
                                break;
                            case sedan:
                                vetorContador[1]++;
                                break;
                            case suv:
                                vetorContador[2]++;
                                break;
                            case jipe:
                                vetorContador[3]++;
                                break;
                        }
                    }
                }
            }
            break;
        case 2:
            for(i=0;i<15;i++){
                if(indice[i].tipoPessoa == 2){
                    for(j=0;j<5;j++){
                        switch(carro[procurarCarro(locacao[i][j].renavam)].categoria){
                            case hatch:
                                vetorContador[0]++;
                                break;
                            case sedan:
                                vetorContador[1]++;
                                break;
                            case suv:
                                vetorContador[2]++;
                                break;
                            case jipe:
                                vetorContador[3]++;
                                break;
                        }
                    }
                }
            }
            break;
    }
    return vetorContador;
}

int comparador(const void *a, const void *b){
    int diferenca;

    diferenca = (*(int*)b - *(int*)a);

    return diferenca;
}

int *ordenador(int *frequencia, int *auxiliar, int *posicao){
    int i, j, k, l, m, verificador=0;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(frequencia[i] == auxiliar[j]){
                posicao[i] = j;
                break;
            }
        }
        for(j=0;j<4;j++){
            for(k=j+1;k<4;k++){
                if(posicao[j] == posicao[k]){
                    for(l=0;l<4;l++){
                        for(m=0;m<4;m++){
                            if(posicao[m] == l){
                                verificador = 1;
                                break;
                                }
						}
						if(verificador == 0){
							posicao[k] = l;
						}else{
							verificador = 0;
						}
					}
				}
			}
        }
    }
    return posicao;
}

void printarFrequencia(int *posicao, int *frequencia){
    for(int i=0;i<4;i++){
        if(posicao[i] == 0){
            printf("Categoria hatch: %d\n", frequencia[i]);
        }else if(posicao[i] == 1){
            printf("Categoria sedan: %d\n", frequencia[i]);
        }else if(posicao[i] == 2){
            printf("Categoria suv: %d\n", frequencia[i]);
        }else if(posicao[i] == 3){
            printf("Categoria jipe: %d\n", frequencia[i]);
        }
    }
}

void listarFrequencia(){
    int i, recebeTipoPessoa, vetorFrequencia[]={0,0,0,0}, vetorAuxiliar[4], vetorPosicao[4];
    int *ponteiro, *posicao;

    scanf(" %d", &recebeTipoPessoa);
    switch(recebeTipoPessoa){
        case 1:
            ponteiro = contadorFrequencia(recebeTipoPessoa, vetorFrequencia);
            for(i=0;i<4;i++){
                vetorAuxiliar[i] = vetorFrequencia[i];
            }
            qsort(vetorFrequencia, 4, sizeof(int), comparador);
            posicao = ordenador(vetorFrequencia, vetorAuxiliar, vetorPosicao);

            printarFrequencia(posicao, ponteiro);
            break;
        case 2:
            ponteiro = contadorFrequencia(recebeTipoPessoa, vetorFrequencia);
            for(i=0;i<4;i++){
                vetorAuxiliar[i] = vetorFrequencia[i];
            }
            qsort(vetorFrequencia, 4, sizeof(int), comparador);
            posicao = ordenador(vetorFrequencia, vetorAuxiliar, vetorPosicao);

            printarFrequencia(posicao, ponteiro);
            break;
        default:
            erro(1);
            break;
    }
}

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
            printf("ERRO: locacao cancelada\n");
            break;
        case 9:
            printf("ERRO: nada cadastrado\n");
            break;
        case 10:
            printf("ERRO: nenhum dado cadastrado\n");
            break;
    }
}

void sair(){
    exit(0);
}
/*
void printaPorraToda(){
    int i=0,j=0;
    printf("\nClientes\n");
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
    }
    printf("\n\nLocacao\n");
    for(i=0;i<15;i++){
        for(j=0;j<5;j++){
            if(locacao[i][j].codigo!=0){
                printf("%s\n", locacao[i][j].pessoa.juridica);
                printf("%d\n", locacao[i][j].tipoCliente);
                printf("%d\n", locacao[i][j].codigo);
                printf("%s\n", locacao[i][j].renavam);
                printf("%02d/%02d/%02d\n", locacao[i][j].dataRetirada.dia, locacao[i][j].dataRetirada.mes, locacao[i][j].dataRetirada.ano);
                printf("%02d/%02d/%02d\n\n", locacao[i][j].dataDevolucao.dia, locacao[i][j].dataDevolucao.mes, locacao[i][j].dataDevolucao.ano);
            }
        }
    }
}*/
