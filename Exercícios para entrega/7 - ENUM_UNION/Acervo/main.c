#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum TIPO{
    livro=1,
    tese,
    periodico,
};
enum MODALIDADE{
    mestrado=1,
    doutorado,
};

struct LIVROS{
    int ano;
    char autor[30], titulo[30], editora[30], cidade[30];
};
struct TESES{
    enum MODALIDADE modalidade;
    int mes, ano;
    char autor[30], titulo[30], universidade[30], programaPos[30], orientador[30];
};

enum MODALIDADE mod;
enum TIPO tipo;

int cadastrarObra();
void consultarObra();

int main()
{
    int cont=0, opcaoMenu;
    do{
        scanf(" %d", &opcaoMenu);
        switch(opcaoMenu){
            case 1:
                cont = cadastrarObra(cont);
                break;
            case 2:
                consultarObra();
                break;
            case 3:
                printf("Fim de execucao\n");
                break;
        }

    }while( opcaoMenu != 3);
    return 0;
}

int cadastrarObra(int i){

    return i;
}

void consultarObra(){

}
