#include <stdio.h>
#include <stdlib.h>

/*
    O sistema de avaliação de uma determinada disciplina obedece aos seguintes critérios:
        durante o semestre são dadas três notas;
        a nota final é obtida pela média aritmética das três notas;
        é considerado aprovado o aluno que obtiver a nota final superior ou igual a 6 e que tiver comparecido a um mínimo de 40 aulas.

    Faça um programa que inicialmente leia um valor N inteiro que representa o número de alunos da disciplina em seguida leia um conjunto de dados contendo o número de matrícula, as três notas e a frequência (número de aulas frequentadas) de N alunos.

    Calcule e mostre:
        para cada aluno o número de matrícula, a nota final e a mensagem "Aprovado" ou "Reprovado";
        a maior e a menor nota da turma;
        o total de alunos reprovados;
        a percentagem de alunos reprovados por frequência abaixo da mínima necessária.
    Observações:
        As informações de cada aluno deverão ser printadas uma em baixo da outra e ao final as outra informações pedidas todas na mesma linha separadas por espeço.
        Insira o sinal de porcentagem após a variável referente a este cálculo.
    Exemplo:
        Entrada:
            11 606 7.000000 3.000000 2.000000 131 548 7.000000 7.000000 5.000000 97 697 ...
        Saída:
            606 4.000000 Reprovado
            548 6.333333 Aprovado
            ...
            ...
            ...
            9.666667 3.000000 6 27.272728%
*/

int main()
{
    int numeroAlunos, matricula, frequencia, totalReprovados=0, i=0, abaixoFrequencia=0;
    float n1, n2, n3, mediaNotas, menorNota=10, maiorNota=0, repFreq=0;

    scanf("%d", &numeroAlunos);

    i = numeroAlunos;

    while(i > 0){
        scanf("%d", &matricula);
        scanf("%f", &n1);
        scanf("%f", &n2);
        scanf("%f", &n3);
        scanf("%d", &frequencia);

        mediaNotas = ((n1+n2+n3)/3);

        if(mediaNotas < menorNota){
            menorNota = mediaNotas;
        }
        if(mediaNotas > maiorNota){
            maiorNota = mediaNotas;
        }
        if((mediaNotas >= 6) && (frequencia >= 40)){
            printf("%d %f Aprovado\n", matricula, mediaNotas);
        }else{
            printf("%d %f Reprovado\n", matricula, mediaNotas);
            totalReprovados++;
        }
        if(frequencia <40){
            abaixoFrequencia++;
        }

        i--;
        repFreq = ((float)abaixoFrequencia*100)/(float)numeroAlunos;
    }

    printf("%f %f %d %f%%", maiorNota, menorNota, totalReprovados, repFreq);

    return 0;
}
