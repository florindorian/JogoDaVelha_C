<h1 align="center">
	Jogo da Velha em <span style="color: blue;">C</span>
</h1>

<p align="center">
	<img loading="lazy" src="https://img.shields.io/badge/status-EM_DESENVOLVIMENTO-green">
	<a href="https://opensource.org/licenses/MIT">
		<img loading="lazy" src="https://img.shields.io/badge/licence-MIT-blue">
	</a>
</p>

## 🎮Como o jogo funciona
Assim como em um jogo da velha tradicional, há dois jogadores (x e o) e a partida começa com o jogador x. Cada jogador, na sua vez, deve escolher um número de 1 a 9 que representa uma posição na tabela do Jogo da Velha e, caso ele esteja disponível, esse número é substituído na tabela pelo caractere que representa aquele jogador, isto é, 'x' ou 'o'. O jogo termina quando for possível formar uma linha horizontal, vertical ou diagonal com exatamente três letras iguais (o vencedor é o jogador representado por essa letra) ou quando todas as posições tiverem sido preenchidas sem que alguém tenha ganhado.

## 💻Sistemas testados
Para o conhecimento do leitor, este código foi testado em um sistema operacional de 64 bits com o Windows 11 e com o Ubuntu 22.04.

## 🛠️Compilação
Antes de rodar o programa, é necessário usar o arquivo makefile para automatizar a compilação do código fonte e gerar o executável. Se você estiver no Windows, é necessário que você tenha instalado o compilador GCC, que pode ser obtido por meio do [MinGW](https://sourceforge.net/projects/mingw/), e o utilitário [GnuWin32](https://gnuwin32.sourceforge.net/packages/make.htm) (esse último permite usar o makefile) e ter as respectivas variáveis de ambiente devidamente configuradas. Se estiver no Ubuntu, os dois podem ser instalados por meio do pacote `build-essential` digitando o comando abaixo no terminal:

> sudo apt install build-essential

Se o seu sistema for Windows, a variável SO no início do makefile deve ser definida como "windows":

> SO = windows

Se for Linux, defina a variável SO como "linux":

> SO = linux

Salve o arquivo. Em seguida, certifique-se de que você está no diretório raíz deste projeto, abra o terminal e use o comando:

> make all

Então, o executável do programa será gerado. Para rodá-lo, use no terminal o comando:
No windows:

> jogo.exe

No Linux:

> ./jogo

Observe que outro produto da compilação foi a pasta objects (com os códigos objetos), que pode ser excluída após o término da criação do executável caso queira. Basta usar:

> make clean

## 📄Licença
Este projeto está sob a licença do MIT. Consulte o arquivo LICENSE para obter mais detalhes.