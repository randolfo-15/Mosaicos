/*!*****************************************************
 *	\file printables.hpp
* \brief Arquivo de definição da classe __Printables__
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#ifndef  PRINTABLES_HPP 
#define PRINTABLES_HPP 

//#include <tema.hpp>
#include "tema.hpp"

using COR::EFFECT::DEFAULT_BKG;
using COR::EFFECT::DEFAULT_KEY;

/// Define a cor do espaçamento.
const string cor_space=DEFAULT_BKG+DEFAULT_KEY; 

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
		THEME th;          ///< Value para tema.
		vec_str buffer;   ///< Buffer de dados.
		

		void copy(vec_str*);                                      ///< Copiar dados.
		void print(vec_str*,int size_buffer,int=0);  ///< Mover pelo buffer.
			
public:
		Printables();                         
		Printables(THEME);          
		
		virtual void write(void* obj,Func_Obj fx=nullptr);          ///< Escrita generica.
		virtual void write(string,MODO,Func_Obj fx=nullptr);   ///< Escrita Padrão.
		
		virtual void read (void* obj,Func_Obj fx=nullptr);          ///< Leitura.
		
		virtual void  show(vec_str* buffer);  ///< Descarrega o buffer, com espaçamento externo.
		virtual void show();                              ///< Descarrega buffer interno
		
		virtual void clear();  ///< Limpar beffer
		
		int  n_lines();              ///< Número de linhas atual.

		void  set_tema(THEME); ///< Alterar tema do printable
		THEME get_tema();		     ///< Obter atual tema do printable

		 void space(int); ///< Define o limite  espaçamento em relação ao texto.
		 int    space();      ///< Recebe o limite  espaçamento em relação ao texto.
	
};

#endif // printables.hpp
