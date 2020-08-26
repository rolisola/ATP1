#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define vt 4
#define desc 20
#define dia 30
#define coluna 3

struct SERVICO{
    int codigo;
    char descricao[desc];
};
struct DESCRICAO{
    struct SERVICO servico;
    int codigo, numeroServico, codigoCliente;
    float valor;
};

struct SERVICO tipoServico[vt];
struct DESCRICAO historico[dia][coluna];

int main()
{
    //const int linha=30 , coluna=3;
    //const int coluna=3;

    int opcaoMenu,c1=0,c2=0,c3=0,c4=0,c5=0;

    inicializacao();

    do{
        switch(opcaoMenu){
            case 1:
                cadastrarTipoServico(c1);
                break;
            case 2:
                cadastrarServico(c2);
                break;
            case 3:
                consultaDia();
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("Fim da execucao\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }while(opcaoMenu != 6);
    return 0;
}

void inicializacao(){
    int i,j,k;
    for(i=0;i<vt;i++){
        tipoServico[i].codigo = 0;
        for(j=0;j<desc;j++){
            tipoServico[i].descricao[j] = "";
        }
    }
    for(i=0;i<dia;i++){
        for(j=0;j<coluna;j++){
            historico[i][j].codigo = 0;
            historico[i][j].codigoCliente = 0;
            historico[i][j].numeroServico = 0;
            historico[i][j].valor = 0;
            historico[i][j].servico.codigo = 0;
            for(k=0;k<desc;k++){
                historico[i][j].servico.descricao[k] = "";
            }
        }
    }
}

int cadastrarTipoServico(int i){
    int j, recebeCodigo;
    char recebeDescricao[20];
    for(j=0;j<vt;j++){
        if(tipoServico[j].codigo == 0){
            break;
        }
    }
    if(j == vt){
        printf("Cadastro de tipos de servicos lotado\n");
        goto saida;
    }
    scanf(" %d", recebeCodigo);
    for(j=0;j<vt;j++){
        if(recebeCodigo == tipoServico[j].codigo){
            printf("Ja existe tipo de servico cadastrado com esse codigo\n");
            goto saida;
        }
    }
    scanf(" %[^\n]", recebeDescricao);
    tipoServico[i].codigo = recebeCodigo;
    strcpy(tipoServico[i].descricao, recebeDescricao);
    printf("Tipo de servico cadastrado com sucesso\n");
    i++;
    saida:
        return i;
}

int cadastrarServico(int i){
    int j,k, recebeDia, recebeCodigoServico, recebeNumeroServico, recebeCodigoCliente;
    float recebeValor;
    scanf(" %d", &recebeDia);
    for(j=0;j<coluna;j++){
        if(historico[recebeDia-1][j].codigo == 0){
            break;
        }
    }
    if(j == coluna){
        printf("Todos os servicos prestados neste dia ja foram cadastrados\n");
        goto saida;
    }
    scanf(" %d", &recebeCodigoServico);
    for(j=0;j<vt;j++){
        if(tipoServico[j].codigo == recebeCodigoServico){
            break;
        }
    }
    if(j == vt){
        printf("Codigo de servico invalido\n");
        goto saida;
    }
    scanf(" %d", &recebeNumeroServico);
    scanf(" %f", &recebeValor);
    scanf(" %d", &recebeCodigoCliente);
    printf("Servico cadastrado com sucesso\n");
    i++;
    saida:
        return i;
}

void consultaDia(){
    int i, c=0, recebeDia, reduz;
    scanf(" %d", &recebeDia);
    reduz = (recebeDia-1);
    for(i=0;i<coluna;i++){
        if(historico[recebeDia-1][i].codigo != 0){
            printf("%d %d %.2f\n", historico[reduz][i].codigo, historico[reduz][i].numeroServico, historico[reduz][i].valor);
        }else{
            c++;
        }
    }
    if(c == coluna){
        printf("Nenhum servico foi prestado neste dia\n");
    }
}

void consultaValor(){
    int i,j;
    float recebeValorMinimo, recebeValorMaximo;
    scanf(" %f", &recebeValorMinimo);
    scanf(" %f", &recebeValorMaximo);
    for(i=0;i<dia;i++){
        for(j=0;j<coluna;j++){
            if((historico[i][j].valor >= recebeValorMinimo) && (historico[i][j].valor <= recebeValorMaximo)){
                printf("Dia: %d | %d | %d | %.2f | %d | %s", i-1, , num_serv, valor_serv, cod_cliente, descricao);
            }
        }
    }
}




