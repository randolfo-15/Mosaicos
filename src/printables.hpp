/*!*****************************************************
 *	\file printables.hpp
* \brief Arquivo de definição da classe __Printables__
 * \author Randolfo Augusto
 * \date 18/10/22
 ******************************************************/

#ifndef  PRINTABLES_HPP 
#define PRINTABLES_HPP 



template <typename T>
class Printables:public IOs<T>{
	/*
	protected:
		void copy(std::vector<std::string>*);                                       ///< Copiar dados.
		void print(std::vector<std::string>*,int size_buffer,int=0);  ///< Mover pelo buffer.
		
		virtual void  show(std::vector<std::string>* buffer);           ///< Descarrega o buffer, com espaçamento externo.	
	*/
	public:
		Printables();
		Printables(int side);
		Printables(int top,int side);
		Printables(Background,Foreground,int);
		Printables(Background,Foreground,int,int);
		Printables(std::initializer_list<Bg>,std::initializer_list<Fg>);
		Printables(std::initializer_list<Bg>,std::initializer_list<Fg>,int);
		Printables(std::initializer_list<Bg>,std::initializer_list<Fg>,int,int);
		
		void operator<<(T);
		
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
	
};template <typename T> using Pb=Printables<T>;

//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------
template <typename T>
Printables<T>::Printables():IOs<T>(){}

template <typename T>		
Printables<T>::Printables(int side):IOs<T>(side){}

template <typename T>		
Printables<T>::Printables(int  top,int side):IOs<T>(top,side){}

template <typename T>		
Printables<T>::Printables(Bg bg,Fg fg,int  side):IOs<T>(side),Tm(bg,fg){}

template <typename T>		
Printables<T>::Printables(Bg bg,Fg fg,int top,int side):IOs<T>(top,side),Tm(bg,fg){}

template <typename T>		
Printables<T>::Printables(std::initializer_list<Bg> bg,std::initializer_list<Fg> fg):IOs<T>(),Tm(bg,fg){}

template <typename T>		
Printables<T>::Printables(std::initializer_list<Bg> bg,std::initializer_list<Fg> fg,int side):IOs<T>(side),Tm(bg,fg){}

template <typename T>		
Printables<T>::Printables(std::initializer_list<Bg> bg,std::initializer_list<Fg> fg,int top,int side):IOs<T>(top,side),Tm(bg,fg){}

template <typename T>		
void Printables<T>::operator<<(T t){}

#endif // printables.hpp
