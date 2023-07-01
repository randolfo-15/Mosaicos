#pragma once

#ifdef __unix__
#define sys 0
#elif 
#define sys 1
#endif

#include "printables.hpp"
#include <algorithm>
#include <unistd.h> 
#include <sys/wait.h>

#include <fstream>
using std::ifstream;
#include <cstdlib>

#include <sstream>
using std::stringstream;

//Alias de função iniciar Display:
class Display;

//Abrevição do nome da classe:
using Dp=Display; 

//------------------------------------------------------------
//Funções de suporte:
//-------------------------------------------------------------
void collect_char(string*,char,int i,int end);


//-------------------------------------------------------------
//(Texto)
//-------------------------------------------------------------

class Texto{
	friend Dp;
	string line;
	MODO modo;
	Func_Obj fx;
	
	Texto(string,MODO,Func_Obj);
};

//Modos de corte de texto:
enum slice_mode{SMART,JOUST};
using slice_mode=enum slice_mode;

//-------------------------------------------------------------
//(Espaço)
//-------------------------------------------------------------

class Space{
	friend Dp;
	string spc_str;
	int    spc_int;
	char   spc_chr;
	
	void init(int,char);
	int  value(int n=-1);
};

//-------------------------------------------------------------
//(Shadow)
//-------------------------------------------------------------
using COR::BKG::GRAY_BKG;
using COR::EFFECT::DEFAULT_BKG;
using COR::EFFECT::DEFAULT_KEY;
using COR::BKG::WHITE_BKG;

class Shadow{
	friend Dp;
	string cor=COR::BKG::GRAY_LIGHT_BKG;
	bool  start=true;

	Shadow();	
	Shadow(string);
	string shade(int);
	public:
		int size_shadow();
};

//-------------------------------------------------------------
//-------------------------------------------------------------
class Display:public Printables{
	//Operação de fluso de display:
	friend Dp* operator<<(Dp*,Dp&);
	friend Dp* operator>>(Dp*,Dp&);

	//Buffer auxiliar:
		vector<Texto> buffer_aux;	                     
		vector<Display*> dps;

	//Sombriamento:
		Shadow sb,
			   no_sb;

	//Espaciais:
		Space w_dp, // → Largura do display.	
		      x_dp, // → Distanciamento horizontal.
			  y_dp, // → Distanciamento vertical.
		      b_dp; // → Espaçamento texto.
	
	//Tamanho sombra:
		int sb_side=2;

	//Modos de Texto:	
		slice_mode corte=SMART;

	//Inicialização:
		void init_default();
		void init_compnents();

	//Escrita:
		//1 → Dividir texto e salvar linhas:
		void format(string,size_t,MODO,Func_Obj);
		
		//½ → Contar letras:
		int n_letter(const char*);

		//2 → Fatiar bloco de texto:
		string slice_text(string,size_t);
		
		//3 → Gravar em memoria auxiliar:	
		void write_aux_buffer(string,MODO,Func_Obj);

		//4 → Atualizar largura:
		void   update_width(int);         
	
	//Exposição:
		//Salvar figura no buffer:
		void draw();
				
		//1 → Listar linhas:
		void move_buffer(int i,int end);                   
		
		//Contar caracter especial:       //|
		int loop(const char *c);          //|
                                          //|
		int size_line(const char *str);   //|

		//2 → Preenchaer linha
		void   format_line(size_t,string,MODO,Func_Obj);     
		
		//3 → Sombrear base:
		void   base_shading();             
	
	//Checar tamanho do terminal:
	bool size_terminal(int);
	
	//Erro ao criar display:
	void erro_exec(string str="Broken display");
	
	public:
	//Fabricação:	
		Display();
		Display(THEME*);
		Display(void (*)(Display*));
		//Funçao de heard ?

	//Iniciar:
		void init_mode(void (*)(Display*));

	//0 → Escrita:
		void write(string,
				   MODO m=NORMAL,
				   Func_Obj fy=nullptr
		) override;
	
	//Exposição:	
		//0 → Mostrar display:
		void show();                  	
		
		void show(int grupo,int x,int y);
		
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
		void clear() override;	
		
		//Inserir texto:
		void insert(int pos,
					string text,
					MODO m=NORMAL,
					Func_Obj fx=nullptr 
		);

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
	
		void set_color_shadow(string cor);

		//Size display:
		int size_display();

		//Ler dados:
		static void read(Dp,vector<string>*questions,vector<string>*answers, int n=0);

};
//Inserir display:
Dp* operator<<(Dp*,Dp&);

//remover display:
Dp* operator>>(Dp*,Dp&);
