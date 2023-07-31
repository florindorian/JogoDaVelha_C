#include "JogoDaVelha.h"
#include <stdio.h>

void resetarTabela(Jogo* jogo){
  for (int i=0; i<TAM; i++){
    jogo->tabela[i] = 48 + (i+1); //48 é o caractere '0' em ASCII
  }
}

//Função que exibe a tabela
void exibirTabela(Jogo* jogo){
  for (int i=0; i<TAM/3; i++){
    printf(" %c|%c|%c \n", jogo->tabela[3*i], jogo->tabela[3*i+1], jogo->tabela[3*i+2]);
    if (i < TAM/3 - 1){
      printf("--+-+--\n");
    }
  }
}

//Função que passa a vez para o outro jogador
void trocarJogador(char* jogador){
  if (*jogador == 'x')
    *jogador = 'o';
  else
    *jogador = 'x';
}

/* Função que:
 * 1) Testa se a posição escolhida já foi escolhida (retorno -1)
 * 2) Testa se a posição escolhida está fora do intervalo de 1 a 9 (retorno -2)
 * 3) Marca a jogada na tabela se ela for válida
 */
int marcarJogada(Jogo* jogo, char jogador, int posicao){
  if (jogo->tabela[posicao-1] == 'x' || jogo->tabela[posicao-1] == 'o')
    return -1; //Posição já marcada
  else if(posicao < 1 || posicao > 9){
    return -2; //Posição inválida
  }
  else{
    jogo->tabela[posicao-1] = jogador;
    return 1;
  }
}

/* Função que:
 * 1) Retorna 1 se alguém venceu e define o campo "vencedor" da struct Jogo
 * 2) Retorna 0 se ainda é possível jogar
 * 3) Retorna -1 se o jogo empatou
*/
int gameOver(Jogo* jogo){
  int empate;
  //Verifica se alguém venceu em uma linha
  for (int l=0; l<TAM; l+=3){
    if (jogo->tabela[l] == jogo->tabela[l+1] && jogo->tabela[l] == jogo->tabela[l+2]){
      if (jogo->tabela[l] == 'x')
        jogo->vencedor = 'x';
      else
        jogo->vencedor = 'o';
      //Retorno 1: Significa que alguém ganhou
      return 1;
    }
  }

  //Verifica se alguém venceu em uma coluna
  for (int c=0; c<TAM/3; c++){
    if (jogo->tabela[c] == jogo->tabela[c+3] && jogo->tabela[c] == jogo->tabela[c+6]){
      if (jogo->tabela[c] == 'x')
        jogo->vencedor = 'x';
      else
        jogo->vencedor = 'o';
      return 1;
    }
  }

  //Verifica se alguém venceu na diagonal principal
  if (jogo->tabela[0] == jogo->tabela[4] && jogo->tabela[0] == jogo->tabela[8]){
    if (jogo->tabela[0] == 'x')
      jogo->vencedor = 'x';
    else
      jogo->vencedor = 'o';
    return 1;
  }

  //Verifica se alguém venceu na diagonal secundária
  if (jogo->tabela[2] == jogo->tabela[4] && jogo->tabela[2] == jogo->tabela[6]){
    if (jogo->tabela[2] == 'x')
      jogo->vencedor = 'x';
    else
      jogo->vencedor = 'o';
    return 1;
  }

  //Verifica se o jogo empatou
  empate = 1;
  for (int i=0; i<TAM; i++){
    if (jogo->tabela[i] != 'x' && jogo->tabela[i] != 'o'){
      empate = 0;
      break;
    }
  }
  //Retorno -1: Significa que o jogo empatou
  if (empate == 1) return -1;
  
  //Retorno 0: Significa que o jogo não acabou ainda e que ainda há opções disponíveis para escolher
  return 0;
}