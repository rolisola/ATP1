#include <stdio.h>
#include <stdlib.h>

/*
    Faça uma sub-rotina que receba uma matriz 10X10 e determine o maior elemento acima da diagonal principal. Este valor deverá ser mostrado no programa principal.

    Protótipo:
        #include <stdio.h>
        int elemento(int mat[][10], int linhas, int colunas); OU int elemento(int *mat, int linhas, int colunas);
        int main(void)
        {
            //DECLARAÇÃO DAS VARIÁVEIS
            //PREENCHE MATRIZ
            printf("%d", elemento( PARÂMETROS ));
            return 0;
        }
        //INCLUA AQUI SUA FUNÇÃO
*/

int elemento(int mat[10][10], int linhas, int colunas);

int main()
{
    const int lin=10, col=10;
    int i, j, matriz[lin][col];

    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            scanf(" %d", &matriz[i][j]);
        }
    }

    printf("%d", elemento(matriz, lin, col));

    return 0;
}

int elemento(int mat[10][10], int linhas, int colunas){
    int i, j, maior=0;

    for(i=0;i<linhas;i++){
        for(j=i+1;j<colunas;j++){
            if(mat[i][j] > maior){
                maior = mat[i][j];
            }
        }
    }

    return maior;
}
