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

//Modos de corte de texto:
enum slice_mode{SMART,JOUST};
using slice_mode=enum slice_mode;

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
	
	std::string image;											///< Sequência de strings que formam o display.
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
//------------------------------------------------------------------------------------------------
private:
	static const char BOLD[];								///< String do comando bold
	
	struct Line{														///< Estrutura para composção de uma linha.
		std::string str;												///< Contéudo da linha. 
		std::string efc;												///< Efeito da linha.
		int theme;														///< Tipo de linha(Titulo,subtitulos,normal)
	};
	
	enum Titles{
		NORMAL=0,													/// Background padrão
		TITLE=1,															/// Background para títulos
		SUBTITLES=2												/// Background de subtitulos           
	};
//---------------------------------------
// Display Line Builders
//---------------------------------------
private:
	slice_mode corte=SMART;																///< Modo de organização de texto.
	
	void format(std::string str,std::string efc,int=NORMAL);		///< Dividir texto e salvar linhas.
		
	std::string slice_text(std::string,size_t);										///<  Fatiar bloco de texto.
		
	void salve(std::string,std::string,int,std::string="");				///< Gravar em memoria auxiliar.

	void   update_width(int);																	///< Atualizar largura do display.
//---------------------------------------
// Writes
//---------------------------------------
public:
	void write(std::string);																	///< Mode de escrita padrão
	void write(Foreground,std::string);												///< foreground custumizado.
	void write(Background,std::string);												///< background custumizado.
	void write(Background,Foreground,std::string);						///< Com foreground e background custumizado.
	void write(Colour,std::string);														///< Com uma cor de letra especifica
	void write(Highlight,std::string);													///< Com um efeito de letra especifico.
	void write(Colour,Highlight,std::string);										///< Com com uma cor e efeito de letra especifica.
//---------------------------------------
// Headings
//---------------------------------------
private:
	bool check_bg(int);
public:
	void title(std::string,int=TITLE);													///< Titulo padrão
	void title(Foreground,std::string,int=TITLE);								///< Titulo com alguma modificação a nivel foreground
	void title(Highlight,std::string,int=TITLE);									///< Titulo recebendo algum padrão de realce
	
	void subtitle(std::string,int=SUBTITLES);									///< Subtitulo padrão
	void subtitle(Foreground,std::string,int=SUBTITLES);				///< Subtitulo com alguma modificação a nivel foreground
	void subtitle(Highlight,std::string,int=SUBTITLES);					///< Subtitulo	 recebendo algum padrão de realce
	
	///static void read(Dp,std::vector<string>*questions,std::vector<string>*answers, int n=0);    \warning
	
	void distribution(slice_mode);                                                                                                            ///< \warning
		
	void insert(int pos,Highlight,std::string text);                                                                                 ///< \warning

	void remove(int);	                                                                                                                                  ///< \warning
//------------------------------------------------------------------------------------------------
// Memory
//------------------------------------------------------------------------------------------------		
private:
	std::vector<Line> asst_buf;							///< Buffer de tratamento de strings.
	std::vector<std::string> main_buf;				///< Buffer de exibição.
	std::vector<Display*> dps;							///< Buffer para multplos display.
	
public:
	int n_lines();														///< Número de linhas de um display.
	int n_dps();															///< Número de display associados.
	void clear();														///< Limpa contéudo do display.

//------------------------------------------------------------------------------------------------
// Show
//------------------------------------------------------------------------------------------------	
private:
	enum prints{
		DFT,                                                                                             ///< Exibe contéudo do buffer.
		STR,                                                                                             ///< Exibe uma string
		BKG,                                                                                            ///< Exibir com background modificado.
		FRG,                                                                                             ///< Exibir com foreground modificado.
		BFG                                                                                              ///< Exibir foreground  e background modificado.
	};



	void draw_display();                   
		
	int loop(const char *c);                                                                  ///< Contar caracter especial:          
                                                        
	int size_line(const char *str);                                                                 

	void   draw_line(std::string,std::string,Bg);     
	
	bool size_terminal(int);                                                                  ///< \warning
	
	std::string fill(int,Bg);                                                                    ///< Preencher espaços:
		
	void build();                                                                          ///< Motor de animação da janelas:
	
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

#endif // display_rag.hpp
