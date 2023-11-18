/*!*****************************************************
 *	\file scaniables.hpp
* \brief Arquivo de definição da classe __Scaniables__
 * \author Randolfo Augusto
 * \date 18/10/22
 ******************************************************/

#include "ios_rag.hpp"

template <typename T>
class Scaniables:public IOs<T>{
    	public:
		Scaniables();
		Scaniables(int side);
		Scaniables(int top,int side);
		Scaniables(Background,Foreground,int);
		Scaniables(Background,Foreground,int,int);
		Scaniables(std::initializer_list<Bg>,std::initializer_list<Fg>);
		Scaniables(std::initializer_list<Bg>,std::initializer_list<Fg>,int);
		Scaniables(std::initializer_list<Bg>,std::initializer_list<Fg>,int,int);
        
};template <typename T> using Sb=Scaniables<T>;

//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------
template <typename T>
Scaniables<T>::Scaniables():IOs<T>(){}

template <typename T>		
Scaniables<T>::Scaniables(int side):IOs<T>(side){}

template <typename T>		
Scaniables<T>::Scaniables(int  top,int side):IOs<T>(top,side){}

template <typename T>		
Scaniables<T>::Scaniables(Bg bg,Fg fg,int  side):IOs<T>(side),Tm(bg,fg){}

template <typename T>		
Scaniables<T>::Scaniables(Bg bg,Fg fg,int top,int side):IOs<T>(top,side),Tm(bg,fg){}

template <typename T>		
Scaniables<T>::Scaniables(std::initializer_list<Bg> bg,std::initializer_list<Fg> fg):IOs<T>(),Tm(bg,fg){}

template <typename T>		
Scaniables<T>::Scaniables(std::initializer_list<Bg> bg,std::initializer_list<Fg> fg,int side):IOs<T>(side),Tm(bg,fg){}

template <typename T>		
Scaniables<T>::Scaniables(std::initializer_list<Bg> bg,std::initializer_list<Fg> fg,int top,int side):IOs<T>(top,side),Tm(bg,fg){}
