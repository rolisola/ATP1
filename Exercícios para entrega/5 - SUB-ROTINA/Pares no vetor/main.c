#include <stdio.h>

/*
    Elabore uma sub-rotina que receba um vetor X de 30 números inteiros como parâmetro e retorne a quantidade de valores pares em X.

    Protótipo:
        #include <stdio.h>
        int qtdade(int *x, int tam_v);
        int main(void)
        {
            DECLARAÇÃO DAS VARIÁVEIS
            printf("%d", qtdade( PARÂMETROS ));
            return 0;
        }

        INCLUA AQUI SUAS FUNÇÕES
*/

int qtdade(int *x, int tam_v);

int main()
{
    const int tamanhoVetor=30;
    int i, vetor[tamanhoVetor];

    for(i=0;i<tamanhoVetor;i++){
        scanf(" %d", &vetor[i]);
    }

    printf("%d", qtdade(vetor, tamanhoVetor));

    return 0;
}

int qtdade(int *x, int tam_v){
    int quantidadePares=0;
    int i;

    for(i=0;i<tam_v;i++){
        if(x[i] % 2 == 0){
            quantidadePares++;
        }
    }

    return quantidadePares;
}
