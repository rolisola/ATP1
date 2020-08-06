#include <stdio.h>
#include <stdlib.h>

/*
    Uma escola deseja controlar as médias das disciplinas cursadas por seus alunos. Sabe-se que nessa escola existem duas turmas, com cinco alunos cada, e cada aluno cursa duas disciplinas. Crie um programa que armazene essas médias em uma matriz 2 X 5 X 2. Depois da leitura, ele deverá calcular e mostrar:
        -A média geral de cada aluno;
        -A média de cada turma.

    Observações:
        -Utilize variáveis do tipo float para guardar os valores das notas.
        -Imprima resultados na ordem que foram requisitadas.
        -Imprima "Turma 1", "Turma 2" e "Media das turmas" antes que imprimir os calculos feitos.
        -Restrinja para duas casas decimais os valores das variáveis com ponto flutuante.

    Exemplo 1:
        Entrada:
            0.575423 3.381873 8.674222 6.372938 2.935807 0.489270 1.818124 5.330500 3.205205 5.637847 3.561091 1.539610 2.578546 7.143830 1.442889 5.412057 4.005748 3.339758 6.998766 2.411695
        Saída:
            Turma 1
            1.98
            7.52
            1.71
            3.57
            4.42
            Turma 2
            2.55
            4.86
            3.43
            3.67
            4.71
            Media das turmas
            3.84
            3.84
*/

int main()
{
    int i, j, k, verificador=0;
    float recebeNota, matriz[2][5][2], somaAluno, mediaAluno, somaTurma, mediaTurma[2];

    for(i=0;i<2;i++){
        for(j=0;j<5;j++){
            for(k=0;k<2;k++){
                do{
                    scanf(" %f", &recebeNota);
                    if((recebeNota >= 0) && (recebeNota <=10)){
                        matriz[i][j][k] = recebeNota;
                        verificador = 1;
                    }else{
                       verificador = 0;
                    }
                }while(verificador == 0);
            }
        }
    }

    for(i=0;i<2;i++){
        printf("Turma %d\n", i+1);
        somaTurma = 0;
        for(j=0;j<5;j++){
            somaAluno = 0;
            for(k=0;k<2;k++){
                somaAluno += matriz[i][j][k];
                somaTurma += matriz[i][j][k];
            }
            mediaAluno = somaAluno/k;
            printf("%.2f\n", mediaAluno);
        }
        mediaTurma[i] = (somaTurma/((float)j*(float)k));
    }
    printf("Media das turmas\n");
    for(i=0;i<2;i++){
        printf("%.2f\n", mediaTurma[i]);
    }

    return 0;
}
