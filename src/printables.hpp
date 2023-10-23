/*	
 * Objeto printable trata internamente configurações especiais de texto.
 *
 */

#ifndef  PRINTABLES_HPP 
#define PRINTABLES_HPP 

#include "tema.hpp" 
//#include <tema.hpp>

 enum modos{
	       NORMAL,  //Padrão
		   BOLD,        //Letra alterada
		   SELECT,     //Fundo alterado
		   CUSTOM   //Custumizado
};

//Alias para função geral:
using Func_Obj=void (*)(void*);

// Alias para modos:
using MODO= enum modos;

//Alias para Tema neutro:
using THEME= Tema;

//Função de loop generica:
using Fx_loop = bool (*)(int);


class Printables{
	protected:
		THEME*th;
		//Buffer de dados:
		vector<string> buffer; 

		//Modelo referencial
		THEME modelo;  

		//Copiar dados:
		void copy(vector<string>*);
		
		//Mover pelo buffer:
		void loop(int i,int end,vector<string>*,string);
	
	public:
		
		Printables();
		Printables(THEME*);
		~Printables();

		//Write:
		virtual void write(void* obj,Func_Obj fx=nullptr);   
		virtual void write(string,MODO,Func_Obj fx=nullptr);    
		
		//Read:
		virtual void read (void* obj,Func_Obj fx=nullptr);
		
		//Show:
		virtual void  show(string,vector<string>* buf=nullptr);
		
		//Remoção:
		virtual void clear();          
		
		//Gerais:
		int  n_lines();                
        
		
		//Get set(Tema):
		void  set_tema(THEME*);
		THEME get_tema();		
};

#endif // printables.hpp
