/*!*****************************************************
 *	\file printables.hpp
*	\brief  Caracteriza um termo, quanto a cor e efeitos
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#ifndef  PRINTABLES_HPP 
#define PRINTABLES_HPP 

#include <tema.hpp>

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

/// Caracteriza um termo, quanto a cor e efeitos
class Printables{
	protected:
		THEME*th;                                                               ///< Value para tema.
		vector<string> buffer;                                           ///< Buffer de dados.
		THEME modelo;                                                      ///< Modelo referencial.

		void copy(vector<string>*);                                  ///< Copiar dados.
		void loop(int i,int end,vector<string>*,string); ///< Mover pelo buffer.
	
	public:
		
		Printables();
		Printables(THEME*);
		~Printables();

		
		virtual void write(void* obj,Func_Obj fx=nullptr);          ///< Write
		virtual void write(string,MODO,Func_Obj fx=nullptr);   ///< Write
		
		virtual void read (void* obj,Func_Obj fx=nullptr);          ///< Read
		
		virtual void  show(string,vector<string>* buf=nullptr); ///< Show:
		
		virtual void clear();          ///< Remoção
		
		int  n_lines();                      ///< Gerais

		void  set_tema(THEME*); ///< Set printable
		THEME get_tema();		     ///< Get printable
};

#endif // printables.hpp
