#include <stdio.h>

enum TIPOPUBLICACAO{
    livro=1,
    tese,
    periodico,
};
enum POSGRAD{
    mestrado=1,
    doutorado,
};

struct LIVROS{
    int ano;
    char autor[30], titulo[30], editora[30], cidade[30];
};
struct TESES{
    enum POSGRAD modalidade;
    int mes, ano;
    char autor[30], titulo[30], universidade[30], programaPosGrad[30], orientador[30];
};
struct PERIODICOS{
    int volume, mes, ano, numeroPaginas;
    char titulo[30], editora[30], cidade[30];
};

union PUBLICACAO{
    struct LIVROS livro;
    struct TESES teses;
    struct PERIODICOS periodico;
};

struct ACERVO{
    enum TIPOPUBLICACAO tipos;
    union PUBLICACAO publicacao;
};

int cadastrarObra();
void consultarObra();

int main()
{
    int i=0, opcaoMenu;
    struct ACERVO acervo[5];

    do{
        scanf(" %d", &opcaoMenu);
        switch(opcaoMenu){
            case 1:
                i = cadastrarObra(i, acervo);
                break;
            case 2:
                consultarObra(acervo);
                break;
            case 3:
                printf("Fim de execucao\n");
                break;
        }

    }while( opcaoMenu != 3);

    return 0;
}

int cadastrarObra(int i, struct ACERVO *a){
    int recebeOpcaoCadastro;
    
    if(i < 5){
        scanf(" %d", &recebeOpcaoCadastro);
        a[i].tipos = (enum TIPOPUBLICACAO)recebeOpcaoCadastro;
        switch(a[i].tipos){
            case livro:
                scanf(" %[^\n]", a[i].publicacao.livro.autor);
                scanf(" %[^\n]", a[i].publicacao.livro.titulo);
                scanf(" %d", &a[i].publicacao.livro.ano);
                scanf(" %[^\n]", a[i].publicacao.livro.editora);
                scanf(" %[^\n]", a[i].publicacao.livro.cidade);

                printf("-----Livro Cadastrado!-----\n");
                break;
            case tese:
                scanf(" %[^\n]", a[i].publicacao.teses.autor);
                scanf(" %[^\n]", a[i].publicacao.teses.titulo);
                scanf(" %d", &a[i].publicacao.teses.mes);
                scanf(" %d", &a[i].publicacao.teses.ano);
                scanf(" %[^\n]", a[i].publicacao.teses.universidade);
                scanf(" %[^\n]", a[i].publicacao.teses.programaPosGrad);
                scanf(" %[^\n]", a[i].publicacao.teses.orientador);
                scanf(" %u", &a[i].publicacao.teses.modalidade);

                printf("-----Tese Cadastrada!-----\n");
                break;
            case periodico:
                scanf(" %[^\n]", a[i].publicacao.periodico.titulo);
                scanf(" %d", &a[i].publicacao.periodico.volume);
                scanf(" %d", &a[i].publicacao.periodico.mes);
                scanf(" %d", &a[i].publicacao.periodico.ano);
                scanf(" %[^\n]", a[i].publicacao.periodico.editora);
                scanf(" %[^\n]", a[i].publicacao.periodico.cidade);
                scanf(" %d", &a[i].publicacao.periodico.numeroPaginas);

                printf("-----Periodico Cadastrado!-----\n");
                break;
        }

        i++;
    }else{
        printf("Limite de cadastros excedido!\n");
    }
    return i;
}

void consultarObra(struct ACERVO *a){
    int i, recebeConsulta;
    enum TIPOPUBLICACAO tiPu;

    scanf(" %d", &recebeConsulta);
    tiPu = recebeConsulta;

    for(i=0;i<5;i++){
        if(tiPu == a[i].tipos){
            switch(tiPu){
                case livro:
                    printf("Autor: %s\n", a[i].publicacao.livro.autor);
                    printf("Titulo: %s\n", a[i].publicacao.livro.titulo);
                    printf("Ano: %d\n", a[i].publicacao.livro.ano);
                    printf("Editora: %s\n", a[i].publicacao.livro.editora);
                    printf("Cidade: %s\n", a[i].publicacao.livro.cidade);
                    printf("-----------------\n");
                    break;
                case tese:
                    printf("Autor: %s\n", a[i].publicacao.teses.autor);
                    printf("Titulo: %s\n", a[i].publicacao.teses.titulo);
                    printf("Mes: %d\n", a[i].publicacao.teses.mes);
                    printf("Ano: %d\n", a[i].publicacao.teses.ano);
                    printf("Universidade: %s\n", a[i].publicacao.teses.universidade);
                    printf("Programa: %s\n", a[i].publicacao.teses.programaPosGrad);
                    printf("Orientador: %s\n", a[i].publicacao.teses.orientador);
                    printf("Graduacao: %u\n", a[i].publicacao.teses.modalidade);
                    printf("-----------------\n");
                    break;
                case periodico:
                    printf("Titulo: %s\n", a[i].publicacao.periodico.titulo);
                    printf("Volume: %d\n", a[i].publicacao.periodico.volume);
                    printf("Mes: %d\n", a[i].publicacao.periodico.mes);
                    printf("Ano: %d\n", a[i].publicacao.periodico.ano);
                    printf("Editora: %s\n", a[i].publicacao.periodico.editora);
                    printf("Cidade: %s\n", a[i].publicacao.periodico.cidade);
                    printf("Numero de paginas: %d\n", a[i].publicacao.periodico.numeroPaginas);
                    printf("-----------------\n");
                    break;
            }
        }
    }
}

