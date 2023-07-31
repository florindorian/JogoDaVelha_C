#include <stdio.h>
#include <stdlib.h>
#include "JogoDaVelha.h"

int main(void) {
  //VARIÁVEIS:
  char jogador = 'x'; //Pode ser 'x' ou 'o'. No caso, começa com o jogador 'x'
  int posicao, terminou=0, valido; //Posição escolhida na jogada, indicador de Game Over, e indicador de jogada válida, respectivamente
  
  Jogo jogo1; //Struct que guarda informações do jogo, como a tabela/tabuleiro e o vencedor
  jogo1.vencedor = 'n'; //Indica que ninguém ganhou o jogo ainda
  resetarTabela(&jogo1);

  do{
    printf("===============\n");
    printf(" Jogo da Velha \n");
    printf("===============\n");
    exibirTabela(&jogo1);
    //Teste de validade da jogada
    do{
      printf("\nJogador [%c]\n", jogador);
      printf("Posicao escolhida: "); scanf("%d", &posicao);
      printf("\n");
      valido = marcarJogada(&jogo1, jogador, posicao); //Retorna um número negativo se a jogada for inválida
      if (valido == -1){
        printf("Essa posicao ja foi escolhida. Escolha outra.\n");
      } else if(valido == -2){
        printf("Posicao invalida. Escolha novamente.\n");
      }
    } while (valido != 1);
    
    trocarJogador(&jogador); //Se jogador for 'x', a vez vai para 'o', e se for 'o', a vez vai para 'x'
    terminou = gameOver(&jogo1); //Testa se o jogo terminou
  } while(terminou == 0);

  //Término do jogo
  printf("===============\n");
  printf(" Jogo da Velha \n");
  printf("===============\n");
  exibirTabela(&jogo1);

  if (terminou == 1){
    printf("\nXXXXXXXXXX Fim de jogo XXXXXXXXXX\n");
    printf("O jogador [%c] venceu!!!\n", jogo1.vencedor);
  } else{
    printf("\nO jogo empatou.\n");
  }
  return 0;
}