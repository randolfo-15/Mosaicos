/*!*****************************************************
 *	\file display_rag.hpp
 * \brief Arquivo de definição da classe display,shadow,space
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#ifndef  DISPLAY_RAG_HPP
#define DISPLAY_RAG_HPP

#include <ostream>
#include <unistd.h> 
#include <sys/wait.h>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include "background.hpp"
#include "colour.hpp"
#include "effect.hpp"
#include "foreground.hpp"
#include "theme.hpp"
#include "directions_rag.hpp"
#include "clear_rag.hpp"

class Display{
//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------	
private:
	Theme tm=Theme(											///< Tema do display                                     
		{
			Cls::Red(),												///< Fundo principal 
			Cls::Blue(),											///< Fundo para titulos 
			Cls::Blue()-135										///< Fundo para subtitulos
		},
			{ Cls::White() }										///< Foreground padrão
	);
	
	std::string img;												///< Sequência de strings que formam o display.
	bool changer=true;											///< Checa se ouve alguma alteração no display.
//---------------------------------------
// Builders
//---------------------------------------
public:	
	Display();															///< Construtor padrão.
	Display(Theme);												///< Construtor para um tema especifico.
//------------------------------------------------------------------------------------------------
// Proportions
//------------------------------------------------------------------------------------------------	
private:
	Rigth rigth=2;													///< Deslocamento para direita.
	Down down=2;													///< Deslocamento para baixo.
	int   
		w=21,																///< Largura do display.	
		x=2,																	///< Distanciamento horizontal.
		y=2,																	///< Distanciamento vertical.
		b=2;																	///< Espaçamento texto.	
		
	bool size_terminal(int);									///< Calcula a dimenção do terminal atual. \warning
	
	void  update_width(int);									///< Atualizar largura do display.

//---------------------------------------
// Draw display
//---------------------------------------	
	int accentuation(std::string);						///< Contanta número de caracteres especiais.
	int loop(const char *c);									///< Método auxiliar para contagem de caracteres
	int complement(std::string);							///< Complementa de caracteres para desenhar a janela
//---------------------------------------
// Setting
//---------------------------------------
public:
	void horizontal(int);											///< Atualiza o valor do distanciamento horizontal.
	void vertical(int ); 												///< Atualiza o valor do distanciamento vertical.
	void width(int);													///< Atualiza a largura do display.
	void edge(int);													///< Atualiza o distanciamento em relação a borda.
//---------------------------------------
// Getting
//---------------------------------------
public:
	int horizontal();													///< Retorna o valor do distanciamento horizontal.
	int vertical();														///< Retorna o valor do distanciamento vertical.
	int width();															///< Retorna a largura do display.
	int edge();															///< Retorna o espaçamento em relação a borda.
//------------------------------------------------------------------------------------------------
// Write
//-----------------------------------------------------------------------------------------------
private:
	static const Hlg bold;

	enum Titles{
		NORMAL=0,													/// Background padrão
		TITLE=1,															/// Background para títulos
		SUBTITLES=2												/// Background de subtitulos           
	};
	
	struct Line{														///< Estrutura para composção de uma linha.
		std::string str;												///< Contéudo da linha. 
		Bg bg;																///< Background da linha
		Fg fg;																///< Foreground da linha.
		int type=NORMAL;										///< Aponta o grau do titulo.
		
		std::string operator()();								///< Retorna a string colorida e com efeito.
	};
//---------------------------------------
// Display Line Builders
//---------------------------------------
private:
	void split_rows(Line,std::string="");													///< Divide o contéudo das string por \n
	
	void draw_display();																				///< Lista o conjunto de linhas do buffer auxiliar.
	void draw_contour();																			///< Insere os detalhamentos de contorno da linha.
	void draw_line(Line&,int);																	///< Desenha a linha.
	
	std::string build();																				///< Motor de animação da janelas.
	
protected:
	std::string fill(int,Bg);																			///< Preencher espaços:
	std::string show();																				///< retorna a imagem do distema atual.
//---------------------------------------
// Writes
//---------------------------------------
public:
	void write(std::string);																		///< Mode de escrita padrão
	void write(Foreground,std::string);													///< foreground custumizado.
	void write(Background,std::string);													///< background custumizado.
	void write(Background,Foreground,std::string);							///< Com foreground e background custumizado.
	void write(Colour,std::string);															///< Com uma cor de letra especifica
	void write(Highlight,std::string);														///< Com um efeito de letra especifico.
	void write(Colour,Highlight,std::string);											///< Com com uma cor e efeito de letra especifica.
//---------------------------------------
// Headings
//---------------------------------------
private:
	bool check_bg(int);
public:
	void title(std::string,int=TITLE);														///< Titulo padrão
	void title(Foreground,std::string,int=TITLE);									///< Titulo com alguma modificação a nivel foreground
	void title(Highlight,std::string,int=TITLE);										///< Titulo recebendo algum padrão de realce
	
	void subtitle(std::string,int=SUBTITLES);										///< Subtitulo padrão
	void subtitle(Foreground,std::string,int=SUBTITLES);					///< Subtitulo com alguma modificação a nivel foreground
	void subtitle(Highlight,std::string,int=SUBTITLES);						///< Subtitulo	 recebendo algum padrão de realce
//------------------------------------------------------------------------------------------------
// Memory
//------------------------------------------------------------------------------------------------		
private:
	std::vector<Line> lines;									///< Buffer de tratamento de strings.
	std::vector<Display*> dps;							///< Buffer para multplos display.
	
public:
	void clear();														///< Limpa contéudo do display.
	
//------------------------------------------------------------------------------------------------
// Operations:
//------------------------------------------------------------------------------------------------
public:
	friend Display* operator<<(Display*,Display&);
	friend Display* operator>>(Display*,Display&);
	void operator+=(Display&);
	void operator-=(Display&);
	Display* operator<<(Display&);
	Display* operator>>(Display&);
	Display* operator[](int);                 //Find.
	void operator*=(int);                       //Multiplicar.
	
	friend std::ostream& operator<<(std::ostream&,Display);

};using Dp=Display;

Dp* operator<<(Dp*,Dp&);  //Inserir display:
Dp* operator>>(Dp*,Dp&);  //remover display:

std::ostream& operator<<(std::ostream&,Display);

///static void read(Dp,std::vector<string>*questions,std::vector<string>*answers, int n=0);    \warning

#endif // display_rag.hpp
