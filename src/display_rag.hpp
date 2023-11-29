/*!*****************************************************
 *	\file display_rag.hpp
 * \brief Arquivo de definição da classe display,shadow,space
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#ifndef  DISPLAY_RAG_HPP
#define DISPLAY_RAG_HPP

#include <ostream>
#include "theme.hpp"
#include "directions_rag.hpp"


class Display{
//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------	
private:
	static int ID;														///< Contador universal de display
	 int id;																	///< Identificador de um display
	
	Theme tm=Theme(											///< Tema do display                                     
		{
			Cls::Red(),												///< Fundo principal 
			Cls::Blue(),											///< Fundo para titulos 
			Cls::Blue()-135										///< Fundo para subtitulos
		},
		{
			Fg(Cls::White()),									///< Foreground padrão para escrita
			Fg(Cls::White(),Efc::Bold()),				///< Foreground para títulos
			Fg(Cls::White(),Efc::Bold())				///< Foreground para subtitulos
		}										
	);
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
		b=2;																	///< Espaçamento texto.	
		
	void  update_width(int);									///< Atualizar largura do display.
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
	enum Titles{
		NORMAL=0,													/// Background padrão
		TITLE=1,															/// Background para títulos
		SUBTITLES=2												/// Background de subtitulos           
	};
	
	struct Line{														///< Estrutura para composção de uma linha.
		std::string str;												///< Contéudo da linha. 
		Theme tm;														///< Tema da linha.
		int tt=NORMAL;											///< Aponta o grau do titulo.
		
		std::string form(int =0);								///< Retorna a string colorida e com efeito.
	};
	std::string img;												///< Sequência de strings que formam o display.

	bool changer=false;										///< Checa se ouve alguma alteração no display.
	
//---------------------------------------
// Display Line Builders
//---------------------------------------
private:
	void split_rows(Line,std::string="");													///< Divide o contéudo das string por \n
	void draw_display(int=0);																	///< Lista o conjunto de linhas do buffer.
	
	std::string straighten(std::vector<std::string>::iterator,int);	///< Insere os detalhamentos de contorno da linha.
	std::string draw_line(Line*,Tm*,int b,int=0);									///< Desenha a linha.
	std::string build();																				///< Motor de animação da janelas.
	std::string end(int);																				///< Retorna encerramento de string.
	std::string side(Directions*);																///< Define distanciamento lateral.
	
	int accentuation(std::string,int=0);													///< Contanta número de caracteres especiais.
	int complete(std::string*,int w,int b);												///< Complementa de caracteres para desenhar a janela.
	int disregard(std::string,std::string,int=0);									///< Desconcidera um conjunto de caracteres.
	///int diff();																									///< Retorna a diferença de termos removidos
	
protected:
	std::string fill(int,Bg);																			///< Preencher espaços:
	std::string empty(int);																		///< Cria uma string vazia.
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
	std::vector<Line> lines;																		///< Buffer de tratamento de strings.
	std::vector<Display*> dps;																///< Conjunto  para multiplos display.
	std::vector<std::string> line_img;													///< Contem a imagem da linha atual.
public:
	void disassemble();																				///< Remove os displays apontados
	void clear();																							///< Limpa o display completamente.
//------------------------------------------------------------------------------------------------
// Operations:
//------------------------------------------------------------------------------------------------
//------------------------------------
// Assist
//------------------------------------	
private:
	void remove(int);																					///< Remove um display do buffer.
	Display remove(Display,int);																///< Renove um display de uma copia.

	Display copy(Display*,Display);															///< Copia os displays de um objeto display.
	
	int 	find(int,int,int=0);																			///< Pesquisa um display a parte de sua id;
	
	static bool compare(Display*,Display*);											///< Compara o número de linhas de dois display.
	
	int sort();																								///< Ordena os displays
//------------------------------------
// Show
//------------------------------------
public: 
	friend std::ostream& operator<<(std::ostream&,Display);	///< Exibe o contéudo do buffer
//------------------------------------
// Addition
//------------------------------------
public:
	void operator+=(Display);																	///< Adiciona um display a nossa direita.
	Display operator+(Display);																///< Soma o contéudo de displays
//------------------------------------
// Subtration
//------------------------------------	
public:
	void operator-=(Display);																	///< Adiciona um display a nossa direita.
	Display operator-(Display);																///< Soma o contéudo de displays
//------------------------------------
// Assign
//------------------------------------	
public:
	void operator=(Display);
	
};using Dp=Display;

std::ostream& operator<<(std::ostream&,Display);					///< Exibe o contéudo do buffer

#endif // display_rag.hpp
