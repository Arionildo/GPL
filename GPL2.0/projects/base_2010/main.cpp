#include <gpl.h>

void main()
{
	// Se��o de carregamento de assets

	gplInit(800,600,"Minha Janela",true,false);	// Inicializa a biblioteca

	while (!isKeyPressed(KEY::Escape))		// Loop principal do jogo
    {
		// L�gica do Jogo
		
		gplFlush();		// Atualiza a tela - �ltima coisa a ser chamada dentro do loop
    }
}