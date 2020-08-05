#include <stdio.h>
#include <stdlib.h>

/*
    Crie uma matriz para armazenar o tabuleiro do jogo da velha. Faça um programa que permita interagir com 2 jogadores, lendo suas jogadas e apresentando na tela apenas a situação final do tabuleiro. A partida será realizada entre os 2 jogadores, e o programa terá apenas as funções de:
        -Ler a jogada de cada jogador. Exemplo: Jogar na posição 1 1 (Linha 1, Coluna 1);
        -Verificar se a jogada é válida: não podemos jogar em uma posição onde já foi colocada uma peça ou estão fora do tabuleiro, se a jogada for inválida é necessário imprimir "Erro\n";
        -Verificar se o jogo acabou, ou seja, se tem algum vencedor (alguém completou linha, coluna ou diagonal) ou se o tabuleiro inteiro foi preenchido e não teve vencedores (Empate). Se houver um vencedor, é necessário imprimir qual foi o jogador vencedor, na linha de baixo, onde está a sequencia de símbolos que originou a vitória (Ex: "Linha 0", "Coluna 2") e por último, a situação do tabuleiro.

    Observações:
        O símbolo do primeiro jogador sempre séra o "x".

    Exemplo 1:
        Entrada:
            0 0
            0 1
            0 0
            1 1
            0 2
            3 3
            2 2
        Saída:
            Erro
            Erro
            Jogador 1 venceu
            Diagonal principal
            xoo
             x
              x
*/

int main()
{
    int i, j, linhaPrimeiroJogador, colunaPrimeiroJogador, linhaSegundoJogador, colunaSegundoJogador, validade, fimJogo=0;
    char  jogoDaVelha[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}, localSequencia;
    do{
        do{
            scanf(" %d %d", &linhaPrimeiroJogador, &colunaPrimeiroJogador);
            if((linhaPrimeiroJogador>=0 && linhaPrimeiroJogador<=2) && (colunaPrimeiroJogador>=0 && colunaPrimeiroJogador<=2)){
                validade = 1;
                if(jogoDaVelha[linhaPrimeiroJogador][colunaPrimeiroJogador] == 'x' || jogoDaVelha[linhaPrimeiroJogador][colunaPrimeiroJogador] == 'o'){
                    validade = 0;
                    printf("Erro\n");
                }else{
                    jogoDaVelha[linhaPrimeiroJogador][colunaPrimeiroJogador] = 'x';
                }
            }else{
                validade = 0;
                printf("Erro\n");
            }
        }while(validade == 0);
        do{
            scanf(" %d %d", &linhaSegundoJogador, &colunaSegundoJogador);
            if((linhaSegundoJogador>=0 && linhaSegundoJogador<=2) && (colunaSegundoJogador>=0 && colunaSegundoJogador<=2)){
                validade = 1;
                if(jogoDaVelha[linhaSegundoJogador][colunaSegundoJogador] == 'x' || jogoDaVelha[linhaSegundoJogador][colunaSegundoJogador] == 'o'){
                    validade = 0;
                    printf("Erro\n");
                }else{
                    jogoDaVelha[linhaSegundoJogador][colunaSegundoJogador] = 'o';
                }
            }else{
                validade = 0;
                printf("Erro\n");
            }
        }while(validade == 0);
        if(jogoDaVelha[0][0]=='x' && jogoDaVelha[0][1]=='x' && jogoDaVelha[0][2]=='x'){
            localSequencia = 'Linha 0';
            fimJogo = 1;
        }else if(jogoDaVelha[1][0]=='x' && jogoDaVelha[1][1]=='x' && jogoDaVelha[1][2]=='x'){
            localSequencia = 'Linha 1';
            fimJogo = 1;
        }else if(jogoDaVelha[2][0]=='x' && jogoDaVelha[2][1]=='x' && jogoDaVelha[2][2]=='x'){
            localSequencia = 'Linha 2';
            fimJogo = 1;
        }else if(jogoDaVelha[0][0]=='x' && jogoDaVelha[1][0]=='x' && jogoDaVelha[2][0]=='x'){
            localSequencia= 'Coluna 0';
            fimJogo = 1;
        }else if(jogoDaVelha[0][1]=='x' && jogoDaVelha[1][1]=='x' && jogoDaVelha[2][1]=='x'){
            localSequencia= 'Coluna 1';
            fimJogo = 1;
        }else if(jogoDaVelha[0][2]=='x' && jogoDaVelha[1][2]=='x' && jogoDaVelha[2][2]=='x'){
            localSequencia= 'Coluna 2';
            fimJogo = 1;
        }else if(jogoDaVelha[0][0]=='x' && jogoDaVelha[1][1]=='x' && jogoDaVelha[2][2]=='x'){
            localSequencia= 'Diagonal principal';
            fimJogo = 1;
        }else if(jogoDaVelha[0][2]=='x' && jogoDaVelha[1][1]=='x' && jogoDaVelha[2][0]=='x'){
            localSequencia = 'Diagonal secundaria';
            fimJogo = 1;
        }else if(jogoDaVelha[0][0]=='o' && jogoDaVelha[0][1]=='o' && jogoDaVelha[0][2]=='o'){
            localSequencia = 'Linha 0';
            fimJogo = 1;
        }else if(jogoDaVelha[1][0]=='o' && jogoDaVelha[1][1]=='o' && jogoDaVelha[1][2]=='o'){
            localSequencia = 'Linha 1';
            fimJogo = 1;
        }else if(jogoDaVelha[2][0]=='o' && jogoDaVelha[2][1]=='o' && jogoDaVelha[2][2]=='o'){
            localSequencia = 'Linha 2';
            fimJogo = 1;
        }else if(jogoDaVelha[0][0]=='o' && jogoDaVelha[1][0]=='o' && jogoDaVelha[2][0]=='o'){
            localSequencia= 'Coluna 0';
            fimJogo = 1;
        }else if(jogoDaVelha[0][1]=='o' && jogoDaVelha[1][1]=='o' && jogoDaVelha[2][1]=='o'){
            localSequencia= 'Coluna 1';
            fimJogo = 1;
        }else if(jogoDaVelha[0][2]=='o' && jogoDaVelha[1][2]=='o' && jogoDaVelha[2][2]=='o'){
            localSequencia= 'Coluna 2';
            fimJogo = 1;
        }else if(jogoDaVelha[0][0]=='o' && jogoDaVelha[1][1]=='o' && jogoDaVelha[2][2]=='o'){
            localSequencia= 'Diagonal principal';
            fimJogo = 1;
        }else if(jogoDaVelha[0][2]=='o' && jogoDaVelha[1][1]=='o' && jogoDaVelha[2][0]=='o'){
            localSequencia = 'Diagonal secundaria';
            fimJogo = 1;
        }else{
            localSequencia= 'Empate';
            fimJogo = 1;
        }
        printf("\n%d\n", fimJogo);
    }while(fimJogo == 1);


    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%c", jogoDaVelha[i][j]);
        }
        printf("\n");
    }

    return 0;
}
