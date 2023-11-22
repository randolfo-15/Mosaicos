/*!*****************************************************
 *	\file display_rag.hpp
 * \brief Arquivo de definição da classe display,shadow,space
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#ifndef  DISPLAY_RAG_HPP
#define DISPLAY_RAG_HPP

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

///Alias de função iniciar Display:
class Display;
///Abrevição do nome da classe:
 



//Modos de corte de texto:
enum slice_mode{SMART,JOUST};
using slice_mode=enum slice_mode;



class Display{
//------------------------------------------------------------------------------------------------
// Fields
//------------------------------------------------------------------------------------------------
	struct Line{                                                     ///< Define a custumização de uma linha
		std::string str;
		std::string efc;
		int theme;
	};
	
	Theme tm=Theme(                                     ///< Tema do display                                     
		{
			Cls::Red(),                                       ///< Fundo principal 
		    Cls::Blue(),                                      ///< Fundo para titulos 
			Cls::Blue()-115                               ///< Fundo para subtitulos
		},
		{
			Cls::Green()
		}
	);                                
		
	enum Titles{
		NORMAL=0,                                               /// Background padrão
		TITLE=1,                                                      /// Background para títulos
		SUBTITLES=2                                              /// Background de subtitulos           
	};
	
	Bg shade=Cls::Black();                              ///< Cor da sombra.
	
	std::vector<Line> asst_buf;	                        ///< Buffer de tratamento de strings.
	std::vector<std::string> main_buf;             ///< Buffer de exibição.
	std::vector<Display*> dps;                            ///< Buffer para multplos display.

	bool shading=true;                                          /// Criar sombra.

	Rigth rigth=2;                                                     ///< Deslocamento para direita.
	Down down=2;                                                   ///< Deslocamento para baixo.
			   
	int sb_side=2;                                                      ///< Tamanho da sombra lateral.

	slice_mode corte=SMART;                                ///< Modo de organização de texto.

	int   
		w=21,                                                                ///< Largura do display.	
		x=2,                                                                   ///< Distanciamento horizontal.
		y=2,                                                                   ///< Distanciamento vertical.
		b=2;                                                                   ///< Espaçamento texto.

		const std::string fg_shadow="░";                 ///< Detable do sombreamento
//------------------------------------------------------------------------------------------------
// Methods
//------------------------------------------------------------------------------------------------		
		
//-------------------------------------------------------------
// Write
//-------------------------------------------------------------
public:
	void write(std::string);                                                                           ///< Mode de escrita padrão
	void write(Foreground,std::string);                                                     ///< foreground custumizado.
	void write(Background,std::string);                                                    ///< background custumizado.
	void write(Background,Foreground,std::string);                              ///< Com foreground e background custumizado.
	void write(Colour,std::string);                                                               ///< Com uma cor de letra especifica
	void write(Highlight,std::string);                                                          ///< Com um efeito de letra especifico.
	void write(Colour,Highlight,std::string);                                              ///< Com com uma cor e efeito de letra especifica.
	
private:
	void format(std::string str,std::string efc,int);                                   ///< Dividir texto e salvar linhas.
		
	std::string slice_text(std::string,size_t);                                               ///<  Fatiar bloco de texto.
		
	void write_aux_buffer(std::string,std::string,int,std::string="");    ///< Gravar em memoria auxiliar.

	void   update_width(int);                                                                            ///< Atualizar largura do display.
	
//-------------------------------------------------------------
// Show
//-------------------------------------------------------------	
	void draw();                                                        
				
	void draw_display();                   
		
	//Contar caracter especial:       
	int loop(const char *c);          
                                                        
	int size_line(const char *str);   

	//2 → Preenchaer linha
	void   draw_line(std::string,std::string,Bg);     
	
	void draw_shadow(int,int=1);
	
	//Checar tamanho do terminal:
	bool size_terminal(int);
	
	/// Preencher espaços:	
	std::string fill(int,Bg,std::string=" ");
		
	/// Motor de animação da janelas: 
	void engine();
	

	

	
public:

//------------------------------------------------------------------------------------------------
// Headings and subheadings
//------------------------------------------------------------------------------------------------

void title(std::string);

void subtitle(std::string,int=SUBTITLES);

//Fabricação:	
	Display();
	Display(Theme);
private:
	void init_theme();
public:
	
	//Exposição:	
	//0 → Mostrar display:
	void show();                   	
		
	/*void show(int grupo,int x,int y);*/
	
	//Atualizar Janela:
	void update();         
	
	//Configurações:
	/*        Display          */
	void shadow(bool);
	
	int side_shadow(int x=-1);

	/*        Espaciais        */	
		
	// → Saltar linha:
	void skip_line(int n=1);	

	///  Deslocamento horizontal:
	int dist_x(int x=-1);  
		
	/// Deslocamento vertical:
	int dist_y(int y=-1);

	// → Espaçamento texto:
	int spacing(int t=-1);

	// → Largura do display:
	int width(int w=-1);

	/*       Textuais          */
		
	//Texto no formato justificado:
	void distribution(slice_mode);
		
	//Nº de linhas:
	int n_lines();

	//Limpar display:
	void clear();	
		
	//Inserir texto:
	void insert(int pos,Highlight,std::string text);

	void remove(int);

//-------------------------------------------------------------
// Operations:
//-------------------------------------------------------------

	//Operação de fluso de display:
	friend Display* operator<<(Display*,Display&);
	friend Display* operator>>(Display*,Display&);
	
	//Auto-somar:
	void operator+=(Display&);
		
	//Auto-Subtrair
	void operator-=(Display&);

	Display* operator<<(Display&);
	Display* operator>>(Display&);
		
	//Find
	Display* operator[](int);

	//Número de displays:
	int n_dps();

	//Multiplicar:
	void operator*=(int);
	
	void set_color_shadow(Colour);

	//Size display:
	int size();

	//Ler dados:
	//static void read(Dp,std::vector<string>*questions,std::vector<string>*answers, int n=0);

};using Dp=Display;

//Inserir display:
Dp* operator<<(Dp*,Dp&);

//remover display:
Dp* operator>>(Dp*,Dp&);

#endif // display_rag.hpp
