//"Arquivo de cabeçalho"

#ifndef JOGODAVELHA_H
#define JOGODAVELHA_H

#define TAM 9

typedef struct jogo{
  char tabela[TAM];
  char vencedor;
} Jogo;

//Protótipos das funções
void resetarTabela(Jogo* jogo);
void exibirTabela(Jogo* jogo);
void trocarJogador(char* jogador);
int marcarJogada(Jogo* jogo, char jogador, int posicao);
int gameOver(Jogo* jogo);

#endif