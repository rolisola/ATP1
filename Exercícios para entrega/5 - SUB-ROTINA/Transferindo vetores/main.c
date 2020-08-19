#include <stdio.h>
#include <stdlib.h>

/*
    Faça uma sub-rotina que receba um vetor X de 30 elementos inteiros como parâmetro e retorne dois vetores A e B. O vetor A deve conter os elementos de X que sejam maiores do que zero e o vetor B os elementos menores ou iguais à zero.

    Protótipo:
        #include <stdio.h>
        void maior_menor(int *x, int *a, int *b, int tam_v, int *cont_a, int *cont_b);
        int main(void)
        {
            //DECLARAÇÃO DAS VARIÁVEIS
            //PREENCHER VETOR X
            maior_menor(  PARÂMETRO  );
            //IMPRIMIR VETOR A
            //IMPRIMIR VETOR B
            return 0;
        }
        //INCLUA AQUI SUA FUNÇÃO

    Para imprimir vetor A e B, use:
        printf("%d ",  VARIÁVEL DO VALOR );
*/

void recebe_vetor();
void maior_menor(int *vetor, int tam);

int main()
{
    const int tamanho=30;
    int vetorX[tamanho];

    recebe_vetor(vetorX, tamanho);
    maior_menor(vetorX, tamanho);
    return 0;
}

void recebe_vetor(int *vetor, int tam){
    int i;

    for(i=0;i<tam;i++){
        scanf(" %d", &vetor[i]);
    }
}

void maior_menor(int *vetor, int tam){
    int i, contA=0, contB=0;
    int *vetorA = malloc(sizeof(int) * 1);
    int *vetorB = malloc(sizeof(int) * 1);

    for(i=0;i<tam;i++){
        if(vetor[i] > 0){
            contA++;
            vetorA = realloc(vetorA, contA * sizeof(int));
            vetorA[contA-1] = vetor[i];
        }else{
            contB++;
            vetorB = realloc(vetorB, contB * sizeof(int));
            vetorB[contB-1] = vetor[i];
        }
    }

    for(i=0;i<contA;i++){
        printf("%d ", vetorA[i]);
    }
    for(i=0;i<contB;i++){
        printf("%d ", vetorB[i]);
    }

    free(vetorA);
    free(vetorB);
}
