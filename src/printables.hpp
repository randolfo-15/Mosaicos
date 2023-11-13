/*!*****************************************************
 *	\file printables.hpp
* \brief Arquivo de definição da classe __Printables__
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#ifndef  PRINTABLES_HPP 
#define PRINTABLES_HPP 

#include <iostream>
#include <vector>

//#include <tema.hpp>
#include "theme.hpp"

//using COR::EFFECT::DEFAULT_BKG;
//using COR::EFFECT::DEFAULT_KEY;

/// Define a cor do espaçamento.
//const string cor_space=DEFAULT_BKG+DEFAULT_KEY; 

/// Modos de tratamento de um trecho de texto.
 enum modos{
	       NORMAL,  ///< Padrão
		   BOLD,        ///< Letra alterada
		   SELECT,     ///< Fundo alterado
		   CUSTOM   ///< Custumizado
};

///Alias para função geral:
using Func_Obj=void (*)(void*);

///Alias para modos:
using MODO= enum modos;

///Função de loop generica:
using Fx_loop = bool (*)(int);

 ///@{
/*! Simplificação de chamada de classe*/ 
class Printables; 
using Pb=Printables; 
///@}

/// Caracteriza uma letra, quanto a cor e efeitos
class Printables{
	string spacing=cor_space+" "+cor_space;              ///< espaçamento inicial
	
	protected:
		Tm th;          ///< Value para tema.
		std::vector<std::string> buffer;   ///< Buffer de dados.
		

		void copy(std::vector<std::string>*);                                      ///< Copiar dados.
		void print(std::vector<std::string>*,int size_buffer,int=0);  ///< Mover pelo buffer.
			
public:
		Printables();                         
		Printables(Theme);          
		
		virtual void write(void* obj,Func_Obj fx=nullptr);          ///< Escrita generica.
		virtual void write(std::string,MODO,Func_Obj fx=nullptr);   ///< Escrita Padrão.
		
		virtual void read (void* obj,Func_Obj fx=nullptr);          ///< Leitura.
		
		virtual void  show(std::vector<std::string>* buffer);  ///< Descarrega o buffer, com espaçamento externo.
		virtual void show();                                                              ///< Descarrega buffer interno
		
		virtual void clear();  ///< Limpar beffer
		
		int  n_lines();              ///< Número de linhas atual.

		void  set_tema(Theme); ///< Alterar tema do printable
		Theme get_tema();		     ///< Obter atual tema do printable

		 void space(int); ///< Define o limite  espaçamento em relação ao texto.
		 int    space();      ///< Recebe o limite  espaçamento em relação ao texto.
	
};

#endif // printables.hpp
