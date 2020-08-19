#include <stdio.h>

/*
    Faça uma programa que contenha uma sub-rotina que receba um número inteiro e positivo N como parâmetro e retorne a soma dos números inteiros existentes entre o número 1 e N (inclusive).

    Protótipo:
        #include <stdio.h>
        int soma(int n);
        int main(void)
        {
            int x;
            scanf("%d",&x);
            printf("%d", soma(x));
            return 0;
        }
        //INCLUA AQUI SUA FUNÇÃO
*/

int soma();

int main()
{
    int x;
    scanf(" %d", &x);
    printf("%d", soma(x));
    return 0;
}

int soma(int n){
    int i, soma=0;
    for(i=0;i<=n;i++){
        soma += i;
    }
    return soma;
}
