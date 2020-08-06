#include <stdio.h>
#include <stdlib.h>

/*
    Faça um programa que receba a idade de oito alunos e armazene-as em um vetor. Em um outro vetor armazene o código de cinco disciplinas. Em uma matriz armazena a quantidade de provas que cada aluno fez em cada disciplina. Calcule e mostre:
        -A quantidade de alunos com idade entre 18 e 25 anos, 18 <= x <= 25, que fizeram mais de duas provas em uma determinada disciplina, cujo código é digitado pelo usuário. O usuário poderá digitar um código não cadastrado; nesse caso, mostrar mensagem "Erro\n".
        -Uma listagem com o código dos alunos (posição no vetor) que fizeram menos de três provas em determinada disciplina, seguido da idade e do código da disciplina.
        -A média de idade dos alunos que não fizeram nenhuma prova em alguma disciplina. Cuidado para não contar duas vezes o mesmo aluno.

    Observações:
        -Será dado primeiramente a idade de todos os alunos, em seguida o código de todas as disciplinas e então a quantidade de provas de cada aluno em cada disciplina.
        -Imprima os resultados na ordem que foram requisitados, cada um em uma linha.
        -Não restrinja as casas decimais das variáveis com ponto flutuante.
    Exemplo 1:
        Entrada:
            19 1 59 54 25 14 29 5 55 829 741 452 223 5 0 0 6 3 6 4 0 3 0 3 6 5 2 4 3 6 5 1 6 6 6 1 6 6 4 6 3 4 1 3 0 1 1 6 2 0 3 2 3 55
        Saída:
            2
            0 19 829
            0 19 741
            1 1 741
            1 1 223
            2 59 452
            3 54 452
            4 25 741
            5 14 223
            6 29 829
            6 29 741
            6 29 452
            7 5 55
            7 5 829
            7 5 452
            13.500000
*/

int main()
{
    int i, j, idade[8], codigoDisciplina[5], matriz[8][5], pesquisaCodigoDisciplina, contadorProvas=0, somaIdade=0, verificador=0, contador=0, contadorCodigosDiferentes=0;
    float mediaIdade=0;

    for(i=0;i<8;i++){
        scanf(" %d", &idade[i]);
    }
    for(i=0;i<5;i++){
        scanf(" %d", &codigoDisciplina[i]);
    }
    for(i=0;i<8;i++){
        for(j=0;j<5;j++){
            scanf(" %d", &matriz[i][j]);
        }
    }
    scanf(" %d", &pesquisaCodigoDisciplina);

    for(i=0;i<5;i++){
        if(codigoDisciplina[i] == pesquisaCodigoDisciplina){
            //printf("\nCodigos iguais\n");
            for(j=0;j<8;j++){
                if((idade[j] >= 18) && idade[j] <= 25){
                    //printf("\nDentro da idade\n");
                    if(matriz[j][i] > 2){
                        contadorProvas++;
                    }else{
                        //printf("\nnao entrou no contador de provas %d ji%d i%d j%d\n", matriz[j][pesquisaCodigoDisciplina], matriz[j][i], i, j);
                    }
                }else{
                    //printf("\nFora da idade %d\n", idade[j]);
                }
            }
        }else{
            //printf("\nCodigos diferentes\n");
            contadorCodigosDiferentes++;
        }
    }

    if(contadorCodigosDiferentes == 5){
        printf("Erro\n");
    }else{
        printf("%d\n", contadorProvas);
    }

    for(i=0;i<8;i++){
        for(j=0;j<5;j++){
            if(matriz[i][j] < 3){
                printf("%d %d %d\n", i, idade[i], codigoDisciplina[j]);
            }
        }
    }

    for(i=0;i<8;i++){
        for(j=0;j<5;j++){
            if(verificador == 1){
                verificador = 0;
                break;
            }
            if(matriz[i][j] == 0){
                somaIdade += idade[i];
                contador++;
                verificador++;
            }
        }
    }

    mediaIdade = ((float)somaIdade/(float)contador);
    printf("%f", mediaIdade);

/*    printf("\n\n");
    for(i=0;i<8;i++){
        for(j=0;j<5;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
*/
    return 0;
}
