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
#include "colour.hpp"
#include "effect.hpp"
#include "theme.hpp"
#include "directions_rag.hpp"
#include "clear_rag.hpp"

///Alias de função iniciar Display:
class Display;
///Abrevição do nome da classe:
using Dp=Display; 

//------------------------------------------------------------
//Funções de suporte:
//-------------------------------------------------------------
void collect_char(std::string*,char,int i,int end);

//-------------------------------------------------------------
// Textos
//-------------------------------------------------------------
class Line{
	friend Dp;
	std::string str;
	Foreground fg;
	
	Line(Highlight,std::string);
};

//Modos de corte de texto:
enum slice_mode{SMART,JOUST};
using slice_mode=enum slice_mode;


//-------------------------------------------------------------
//-------------------------------------------------------------
class Display{
	// Theme:
	Theme tm;
	Bg shade=Colour(110,110,110);
	
	std::string fill(int,Bg);
	
	//Operação de fluso de display:
	friend Dp* operator<<(Dp*,Dp&);
	friend Dp* operator>>(Dp*,Dp&);

	//Buffer auxiliar:
		std::vector<Line> asst_buf;	
		std::vector<std::string> main_buf;
		std::vector<Dp*> dps;

	//Sombriamento:
		//Shadow sb;
			   bool sb_on=true;

	// Directions:
			   Rigth rigth=2;
			   Down down=2;
			   
	//Tamanho sombra:
		int sb_side=2;

	//Modos de Texto:	
		slice_mode corte=SMART;

		//Espaciais:
		int   
			w, // → Largura do display.	
			x, // → Distanciamento horizontal.
			y, // → Distanciamento vertical.
			b; // → Espaçamento texto.

		
	//Inicialização:
		void init_default();
		void init_compnents();
		
		void engine();
		
	//Escrita:
		//1 → Dividir texto e salvar linhas:
		void format(std::string,size_t,Hlg);
		
		//½ → Contar letras:
		int n_letter(const char*);

		//2 → Fatiar bloco de texto:
		std::string slice_text(std::string,size_t);
		
		//3 → Gravar em memoria auxiliar:	
		void write_aux_buffer(std::string,Hlg);

		//4 → Atualizar largura:
		void   update_width(int);         
	
	//Exposição:
		//Salvar figura no buffer:
		void draw();
				
		//1 → Listar linhas:
		void move_buffer(int=0);                   
		
		//Contar caracter especial:       //|
		int loop(const char *c);          //|
                                          //|
		int size_line(const char *str);   //|

		//2 → Preenchaer linha
		void   format_line(size_t,std::string,Fg);     
		
		//3 → Sombrear base:
		void   base_shading();             
	
	//Checar tamanho do terminal:
	bool size_terminal(int);
	
	//Erro ao criar display:
	void erro_exec(std::string str="Broken display");
	
	public:
	//Fabricação:	
		Display();
		Display(Theme);

	//Iniciar:
		/*void init_mode(void (*)(Display*));*/

	//0 → Escrita:
		void write(Hlg,std::string);
	
	//Exposição:	
		//0 → Mostrar display:
		void show();                   	
		
		/*void show(int grupo,int x,int y);
		*/
		//Atualizar Janela:
		void update();         
	
	//Configurações:
	    /*        Display          */
		void shadow(bool x=true);
		int side_shadow(int x=-1);

		/*        Espaciais        */	
		
		// → Saltar linha:
		void skip_line(int n=1);	

		// → Deslocamento horizontal:
		int dist_x(int x=-1);  
		
		// → Deslocamento vertical:
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

		/*  Aritmetica de displays:  */

		//Auto-somar:
		void operator+=(Display&);
		
		//Auto-Subtrair
		void operator-=(Display&);

		Dp* operator<<(Dp&);
		Dp* operator>>(Dp&);
		
		//Find
		Dp* operator[](int);

		//Número de displays:
		int n_dps();

		//Multiplicar:
		void operator*=(int);
	
		void set_color_shadow(Colour);

		//Size display:
		int size_display();

		//Ler dados:
		//static void read(Dp,std::vector<string>*questions,std::vector<string>*answers, int n=0);

};
//Inserir display:
Dp* operator<<(Dp*,Dp&);

//remover display:
Dp* operator>>(Dp*,Dp&);

#endif // display_rag.hpp
