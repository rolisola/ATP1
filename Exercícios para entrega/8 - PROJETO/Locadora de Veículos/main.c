#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcaoMenu;
    do{
        switch(opcaoMenu){
            case 0:
                sair();
                break;
            case 1:
                cadastrarCliente();
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
                erro();
                break;
        }
    }while(opcaoMenu != 0);

    return 0;
}
