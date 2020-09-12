#include <stdio.h>

/*
    Uma escola deseja saber se existem alunos cursando, simultaneamente, as disciplinas de Lógica e Linguagem de Programação. Coloque os números das matrículas dos alunos que cursam Lógica em um vetor, no máximo quinze alunos. Coloque os números das matrículas dos alunos que cursam Linguagem de Programação em outro vetor, no máximo dez alunos. Mostre o número das matrículas que aparecem nos dois vetores (seguindo a ordem em que as matriculas aparecem no vetor de Linguagem de Programação).

    A saída do programa (printf) devem seguir os modelos abaixo:
        printf("%d ", vetor_exemplo[i]);
*/

int main()
{
    int i, j, matriculaLogica[15], matriculaLinguagemDeProgramacao[10];

    for(i=0;i<15;i++){
        scanf("%d", &matriculaLogica[i]);
    }
    for(j=0;j<10;j++){
        scanf("%d", &matriculaLinguagemDeProgramacao[j]);
    }

    for(j=0;j<10;j++){
        for(i=0;i<15;i++){
            if (matriculaLogica[i] == matriculaLinguagemDeProgramacao[j]){
                printf("%d ", matriculaLogica[i]);
            }
        }
    }

    return 0;
}
