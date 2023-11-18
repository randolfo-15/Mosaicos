/*!*****************************************************
 *	\file printables.hpp
* \brief Arquivo de definição da classe __Printables__
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#ifndef  PRINTABLES_HPP 
#define PRINTABLES_HPP 

#include "ios_rag.hpp"


/// Produzir textos coloridos, e que suportem efeitos.
class Printables:public IOs{
	/*
	protected:
		void copy(std::vector<std::string>*);                                       ///< Copiar dados.
		void print(std::vector<std::string>*,int size_buffer,int=0);  ///< Mover pelo buffer.
		
		virtual void  show(std::vector<std::string>* buffer);           ///< Descarrega o buffer, com espaçamento externo.	
	*/
	public:
		Printables();
		
	private:
		
		///< Escrita que preserva as ultimas caractesriticas de Fg, e Bg.
		
		//     Field: Bg,Fg → dft
		// → Write(str)
		// → Write(Bg,str) ?
		// → Write(Fg,str) ?
		// → Write(Fg,Bg,str) ?
		
		// → Read(str)
		// → Read(Bg,str) ?
		// → Read(Fg,str) ?
		// → Read(Fg,Bg,str) ?
		
		// Ter novas abordagens:
		//virtual void show();  Pb
		// scan() → Sc
		
		// virtual void clear();  ///< Limpar beffer ? mas limpar o que
		
		//int  n_lines();   → Método de break(brk). Ou ! , para printable → Pb

		 // Onde posicionar ? → ios_rag
		//point(shot,shot), pos[][] sib -> [][] , Horizontal, vertical
		//point(short), pos[] sib   ->  [],  , Horizontal
	
};using Pb=Printables;

#endif // printables.hpp
