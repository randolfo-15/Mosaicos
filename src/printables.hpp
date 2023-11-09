/*!*****************************************************
 *	\file printables.hpp
*	\brief  Implementa o conceito da classe printables
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#ifndef  PRINTABLES_HPP 
#define PRINTABLES_HPP 

#include <tema.hpp>

using COR::EFFECT::DEFAULT_BKG;
using COR::EFFECT::DEFAULT_KEY;

const string cor_space=DEFAULT_BKG+DEFAULT_KEY; ///< Define a cor do espaçamento.

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

///Alias para Tema neutro:
using THEME= Tema;

///Função de loop generica:
using Fx_loop = bool (*)(int);

/// Caracteriza uma letra, quanto a cor e efeitos
class Printables{
	string spacing=cor_space+" "+cor_space;              ///< espaçamento inicial
	
	protected:
		THEME*th;                                                               ///< Value para tema.
		vector<string> buffer;                                           ///< Buffer de dados.
		THEME modelo;                                                      ///< Modelo referencial.

		void copy(vector<string>*);                                  ///< Copiar dados.
		void loop(vector<string>*,int size_buffer,int=0);  ///< Mover pelo buffer.
		
		virtual void  show(string spacing,vector<string>* buffer=nullptr);  ///< Descarrega o buffer, com espaçamento especifico.

public:
		
		Printables();                         ///< Criar printable com tema default
		Printables(THEME*);          ///< Criar printable com tema especifico:
		~Printables();

		
		virtual void write(void* obj,Func_Obj fx=nullptr);          ///< Write
		virtual void write(string,MODO,Func_Obj fx=nullptr);   ///< Write
		
		virtual void read (void* obj,Func_Obj fx=nullptr);          ///< Read
		
		virtual void show();  ///< Método simplificado de descarregar contéudo do buffer
		
		virtual void clear();  ///< Limpar beffer
		
		int  n_lines();              ///< Número de linhas atual.

		void  set_tema(THEME*); ///< Alterar tema do printable
		THEME get_tema();		     ///< Obter atual tema do printable

		 void space(int); ///< Define o limite  espaçamento do texto.
		 int    space();      ///< Recebe o limite  espaçamento do texto.
	
};

#endif // printables.hpp
