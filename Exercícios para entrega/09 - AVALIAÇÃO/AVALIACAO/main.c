#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum TIPOESTABELECIMENTO{restaurante=1,fastfood,buteco};
enum TIPOCOMIDARESTAURANTE{brasileira=1,italiana,francesa,mexicana,outros};
enum TIPOSERVICO{aLaCarte=1,selfService};
enum TIPOCOMIDAFASTFOOD{pizzaria=1,sanduicheria,temakeria,cafeteria,creperia,diversos};
enum ESTRELAS{uma=1,duas,tres,quatro,cinco};

struct DADOSESTABELECIMENTO{
    char nome[50],localizacao[50],contato[50];
};
struct RESTAURANTE{
    enum TIPOCOMIDARESTAURANTE tipocomida;
    enum TIPOSERVICO tiposervico;
    struct DADOSESTABELECIMENTO estabelecimento;
};
struct FASTFOOD{
    enum TIPOCOMIDAFASTFOOD tipocomida;
    struct DADOSESTABELECIMENTO estabelecimento;
    char entrega;
};

union ESTABELECIMENTO{
    struct RESTAURANTE restaurante;
    struct FASTFOOD fastfood;
    struct DADOSESTABELECIMENTO buteco;
};

struct AVALIACOES{
    enum TIPOESTABELECIMENTO tipoEstabelecimeto;
    enum ESTRELAS estrela;
    union ESTABELECIMENTO dadosEstabelecimento;
};

void saidas(int valor);
void sair();
int cadastrarAvaliacao(int i, struct AVALIACOES *avaliacao, int matrizEstabelecimento[3][11], int matrizEstrela[5][11]);
void ListarNumeroEstabelecimentoPorTipo(int matrizEstabelecimento[3][11]);
void ListarNumeroEstabelecimentoDeTipoPorEstrela(struct AVALIACOES *avaliacao, int matrizEstrela[5][11]);
void ListarNumeroEstabelecimentoPorEstrela(struct AVALIACOES *avaliacao, int matrizEstrela[5][11]);
int main()
{
    remove("saida.txt");
    //freopen("saida.txt", "w", stdout);
    struct AVALIACOES avaliacao[10]={};

    int matrizEstabelecimento[3][11]={}, matrizEstrela[5][11]={}, menuOpcao, contadorCadastraAvaliacao=0;
    do{
        scanf(" %d", &menuOpcao);
        switch(menuOpcao){
            case 1:
                contadorCadastraAvaliacao = cadastrarAvaliacao(contadorCadastraAvaliacao, avaliacao, matrizEstabelecimento, matrizEstrela);
                break;
            case 2:
                ListarNumeroEstabelecimentoPorTipo(matrizEstabelecimento);
                break;
            case 3:
                ListarNumeroEstabelecimentoDeTipoPorEstrela(avaliacao, matrizEstrela);
                break;
            case 4:
                ListarNumeroEstabelecimentoPorEstrela(avaliacao, matrizEstrela);
                break;
            case 5:
                saidas(4);
                break;
            default:
                saidas(1);
                break;
        }
    }while(menuOpcao != 5);
    return 0;
}

int cadastrarAvaliacao(int i, struct AVALIACOES *avaliacao, int matrizEstabelecimento[3][11], int matrizEstrela[5][11]){
    enum TIPOESTABELECIMENTO recebeTipoEstabelecimento;
    int j;

    if(i < 10){
        do{
            scanf(" %u", &recebeTipoEstabelecimento);
            switch(recebeTipoEstabelecimento){
                case restaurante:
                    avaliacao[i].tipoEstabelecimeto = recebeTipoEstabelecimento;
                    scanf(" %[^\n]%*c", avaliacao[i].dadosEstabelecimento.restaurante.estabelecimento.nome);
                    scanf(" %[^\n]%*c", avaliacao[i].dadosEstabelecimento.restaurante.estabelecimento.localizacao);
                    scanf(" %[^\n]%*c", avaliacao[i].dadosEstabelecimento.restaurante.estabelecimento.contato);

                    do{
                        scanf(" %u", &avaliacao[i].dadosEstabelecimento.restaurante.tipocomida);
                        if((avaliacao[i].dadosEstabelecimento.restaurante.tipocomida < 1) || (avaliacao[i].dadosEstabelecimento.restaurante.tipocomida > 5)){
                            saidas(1);
                        }
                    }while((avaliacao[i].dadosEstabelecimento.restaurante.tipocomida < 1) || (avaliacao[i].dadosEstabelecimento.restaurante.tipocomida > 5));

                    do{
                        scanf(" %u", &avaliacao[i].dadosEstabelecimento.restaurante.tiposervico);
                        if((avaliacao[i].dadosEstabelecimento.restaurante.tiposervico < 1) || (avaliacao[i].dadosEstabelecimento.restaurante.tiposervico > 2)){
                            saidas(1);
                        }
                    }while((avaliacao[i].dadosEstabelecimento.restaurante.tiposervico < 1) || (avaliacao[i].dadosEstabelecimento.restaurante.tiposervico > 2));
                    break;
                case fastfood:
                    avaliacao[i].tipoEstabelecimeto = recebeTipoEstabelecimento;
                    scanf(" %[^\n]%*c", avaliacao[i].dadosEstabelecimento.fastfood.estabelecimento.nome);
                    scanf(" %[^\n]%*c", avaliacao[i].dadosEstabelecimento.fastfood.estabelecimento.localizacao);
                    scanf(" %[^\n]%*c", avaliacao[i].dadosEstabelecimento.fastfood.estabelecimento.contato);

                    do{
                        scanf(" %u", &avaliacao[i].dadosEstabelecimento.fastfood.tipocomida);
                        if((avaliacao[i].dadosEstabelecimento.fastfood.tipocomida < 1) || (avaliacao[i].dadosEstabelecimento.fastfood.tipocomida > 6)){
                            saidas(1);
                        }
                    }while((avaliacao[i].dadosEstabelecimento.fastfood.tipocomida < 1) || (avaliacao[i].dadosEstabelecimento.fastfood.tipocomida > 6));

                    do{
                        scanf(" %c", &avaliacao[i].dadosEstabelecimento.fastfood.entrega);
                        if((avaliacao[i].dadosEstabelecimento.fastfood.entrega == 's') || (avaliacao[i].dadosEstabelecimento.fastfood.entrega == 'n')){
                            break;
                        }
                        saidas(1);
                    }while((avaliacao[i].dadosEstabelecimento.fastfood.entrega != 's') || (avaliacao[i].dadosEstabelecimento.fastfood.entrega != 'n'));
                    break;
                case buteco:
                    avaliacao[i].tipoEstabelecimeto = recebeTipoEstabelecimento;
                    scanf(" %[^\n]%*c", avaliacao[i].dadosEstabelecimento.buteco.nome);
                    scanf(" %[^\n]%*c", avaliacao[i].dadosEstabelecimento.buteco.localizacao);
                    scanf(" %[^\n]%*c", avaliacao[i].dadosEstabelecimento.buteco.contato);
                    break;
                default:
                    saidas(1);
                    break;
            }
        }while((recebeTipoEstabelecimento < 1) || (recebeTipoEstabelecimento > 3));

        avaliacao[i].tipoEstabelecimeto = recebeTipoEstabelecimento;

        do{
            scanf(" %u", &avaliacao[i].estrela);
            if((avaliacao[i].estrela < 1) || (avaliacao[i].estrela > 5)){
                saidas(1);
            }
        }while((avaliacao[i].estrela < 1) || (avaliacao[i].estrela > 5));

        for(j=1;j<=11;j++){
            if(matrizEstabelecimento[recebeTipoEstabelecimento-1][j] == 0){
                matrizEstabelecimento[recebeTipoEstabelecimento-1][j] = i;
                matrizEstabelecimento[recebeTipoEstabelecimento-1][0]++;
                break;
            }
        }
        for(j=1;j<=11;j++){
            if(matrizEstrela[avaliacao[i].estrela-1][j] == 0){
                matrizEstrela[avaliacao[i].estrela-1][j] = i;
                matrizEstrela[avaliacao[i].estrela-1][0]++;
                break;
            }
        }
        i++;

        saidas(2);
    }else{
        saidas(3);
    }
    return i;
}

void ListarNumeroEstabelecimentoPorTipo(int matrizEstabelecimento[3][11]){
    printf("Restaurantes: %d\n", matrizEstabelecimento[0][0]);
    printf("Fast-Food: %d\n", matrizEstabelecimento[1][0]);
    printf("Butecos: %d\n", matrizEstabelecimento[2][0]);
}

void ListarNumeroEstabelecimentoDeTipoPorEstrela(struct AVALIACOES *avaliacao, int matrizEstrela[5][11]){
    enum TIPOESTABELECIMENTO recebeTipoEstabelecimento;
    int i, j, seila, contador[5]={};

    do{
        scanf(" %u", &recebeTipoEstabelecimento);
        if((recebeTipoEstabelecimento < 1) || (recebeTipoEstabelecimento > 3)){
            saidas(1);
        }
    }while((recebeTipoEstabelecimento < 1) || (recebeTipoEstabelecimento > 3));

    for(i=0;i<5;i++){
        for(j=1;j<11;j++){
            seila = matrizEstrela[i][j];
            if((seila != 0) && (avaliacao[seila].tipoEstabelecimeto == recebeTipoEstabelecimento)){
                contador[i]++;
            }
        }
    }
    //esta verificação é para caso a posicao 0 da avaliacao não falte na contagem
    if(avaliacao[0].dadosEstabelecimento.restaurante.estabelecimento.nome[0] != '\0' && (avaliacao[0].tipoEstabelecimeto == recebeTipoEstabelecimento)){
        contador[0]++;
    }
    for(i=0;i<5;i++){
        printf("Estrelas: %d: %d\n", i+1, contador[i]);
    }
}

void ListarNumeroEstabelecimentoPorEstrela(struct AVALIACOES *avaliacao, int matrizEstrela[5][11]){
    int i;

    for(i=0;i<5;i++){
        printf("Estrelas: %d: %d\n", i+1, matrizEstrela[i][0]);
    }
}

void saidas(int valor){
    switch(valor){
        case 1:
            printf("Entrada invalida\n");
            break;
        case 2:
            printf("Avaliacao realizada com sucesso\n");
            break;
        case 3:
            printf("Vetor cheio\n");
            break;
        case 4:
            printf("Encerrando...");
            exit(0);
            break;
    }
}
