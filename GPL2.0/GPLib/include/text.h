//#pragma once
//
//#include <SFML/Graphics.hpp>
//#include <string>
//#include <iostream>
//#include "gplObj.h"
//
//using namespace std;
//
//class text : gplObj
//{
//private: 
//	sf::Font *font;
//	int x;
//	int y;
//	unsigned int size;
//	unsigned int R;
//	unsigned int G;
//	unsigned int B;
//	unsigned int A;
//	bool bold;
//	bool italic;
//	bool underline;
//	sf::Text Text;
//	string _text;
//public:
//
//	////////////////////////////////////////////////////////////////////////////////////////////////////
//	/// <summary>	Cria o texto </summary>
//	////////////////////////////////////////////////////////////////////////////////////////////////////
//	text();
//
//	////////////////////////////////////////////////////////////////////////////////////////////////////
//	/// <summary>	Deleta o texto <see cref="text"/>. </summary>
//	////////////////////////////////////////////////////////////////////////////////////////////////////
//	~text(void);
//
//	////////////////////////////////////////////////////////////////////////////////////////////////////
//	/// <summary>	Carrega um arquivo de fonte para o texto </summary>
//	/// <param name="filename">Caminho do arquivo de fonte a ser carregado (TrueType, Type 1, CFF, OpenType, SFNT, X11 PCF, Windows FNT, BDF, PFR, Type 42)</param>
//	////////////////////////////////////////////////////////////////////////////////////////////////////
//	void load(string filename);
//
//	////////////////////////////////////////////////////////////////////////////////////////////////////
//	/// <summary>	Desenha o texto </summary>
//	///
//	/// <param name="text">			Texto a ser desenhado</param>
//	/// <param name="x">			Posi��o do texto no eixo X</param>
//	/// <param name="y">			Posi��o do texto no eixo Y </param>
//	/// <param name="size">			(Opcional) Tamanho do texto em pixels, padr�o � 10 px</param>
//	/// <param name="R">			(Opcional) Cor vermelha (0-255), padr�o � 255</param>
//	/// <param name="G">			(Opcional) Cor verde (0-255), padr�o � 255</param>
//	/// <param name="B">			(Opcional) Cor Azul (0-255), padr�o � 255</param>
//	/// <param name="A">			(Opcional) N�vel de Opacidade (0-255), padr�o � 255</param>
//	/// <param name="bold">			(Opcional) Negrito</param>
//	/// <param name="italic">   	(Opcional) Italico</param>
//	/// <param name="underline">	(Opcional) Sublinhado</param>
//	////////////////////////////////////////////////////////////////////////////////////////////////////
//	void draw(string text, int x, int y, unsigned int size = 10, unsigned int R = 255, unsigned int G = 255, unsigned int B = 255, unsigned int A = 255, bool bold = false, bool italic = false, bool underline = false);
//};
//
