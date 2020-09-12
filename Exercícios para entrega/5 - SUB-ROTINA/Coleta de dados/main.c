#include <stdio.h>
#include <ctype.h>

/*
    Foi realizada uma pesquisa entre quinze habitantes de uma região. Foram coletados, em ordem, estes dados de cada habitante: idade, sexo (H ou M), salário e número de filhos. Faça uma sub-rotina que leia esses dados armazenando-os em vetores. Depois, crie sub-rotinas que recebam esses vetores como parâmetro e retornem a média de salário entre os habitantes, a menor e a maior idade do grupo e a quantidade de mulheres com três filhos que recebem até R$ 500,00. Utilize uma sub-rotina para cada cálculo.

    Protótipo:
    #include <stdio.h>
    void le_dados(int *idade, char *sexo, float *salario, int *filhos, int tam_v);
    float media(float *salario, int tam_v);
    void idades(int *idade, int *maior, int *menor, int tam_v);
    int qtdade(chr *sexo, int *filhos, float *salario, int tam_v);
    int main(void)
    {
        //DECLARAÇÃO DAS VARIÁVEIS
        le_dados( PARÂMETROS );
        printf("%.2f ", media(x));
        printf("%d ", menor);
        printf("%d ", maior);
        printf("%d", qtdade( PARÂMETROS ));
        return 0;
    }
    INCLUA AQUI SUAS FUNÇÕES
*/

void le_dados(int *idade, char *sexo, float *salario, int *filhos, int tam_v);
float media(float *salario, int tam_v);
void idades(int *idade, int tam_v);
int qtdade(char *sexo, int *filhos, float *salario, int tam_v);


int main()
{
    const int qtd=15;
    int numeroFilhos[qtd], idade[qtd];
    float salario[qtd];
    char sexo[qtd];

    le_dados(idade, sexo, salario, numeroFilhos, qtd);
    printf("%.2f ", media(salario, qtd));
    idades(idade, qtd);
    printf("%d", qtdade(sexo, numeroFilhos, salario, qtd));

    return 0;
}

void le_dados(int *idade, char *sexo, float *salario, int *filhos, int tam_v){
    int i;

    for(i=0;i<tam_v;i++){
        scanf(" %d %c %f %d", &idade[i], &sexo[i], &salario[i], &filhos[i]);
        sexo[i] = toupper(sexo[i]);
    }
}

float media(float *salario, int tam_v){
    int i;
    float soma=0, media;

    for(i=0;i<tam_v;i++){
        soma += salario[i];
    }

    media = soma/tam_v;

    return media;
}

void idades(int *idades, int tam_v){
    int i, maior=0, menor=989999;

    for(i=0;i<tam_v;i++){
        if(idades[i] > maior){
            maior = idades[i];
        }
        if(idades[i] < menor){
            menor = idades[i];
        }
    }

    printf("%d %d ", menor, maior);
}

int qtdade(char *sexo, int *filhos, float *salario, int tam_v){
    int i, contador=0;

    for(i=0;i<tam_v;i++){
         if((sexo[i] == 'M') && (filhos[i] == 3) && (salario[i] <= 500)){
             contador++;
         }
    }

    return contador;
}
