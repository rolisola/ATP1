#include <stdio.h>

/*
    Elabore uma sub-rotina que leia um número não determinado de valores positivos e retorne a média aritmética desses valores. A condição de parada se dá ao entrar um valor negativo.

    Protótipo:
        #include <stdio.h>
        float media(void);
        int main(void)
        {
            printf("%.2f", media());
            return 0;
        }
        INCLUA AQUI SUA FUNÇÃO
*/

float media();

int main()
{
    printf("%.2f", media());

    return 0;
}

float media(void){
    int i=-1, recebeValor, soma=0;
    float media;

    do{
        i++;
        soma += recebeValor;
        scanf(" %d", &recebeValor);
    }while(recebeValor>=0);

    media = ((float)soma/i);

    return media;
}
