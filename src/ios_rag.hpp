/*!*****************************************************
 *	\file ios_rag.hpp
* \brief Arquivo de definição da classe __IO__
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#ifndef IOS_RAG_HPP
#define IOS_RAG_HPP


#include <iostream>
#include "theme.hpp"

template <typename  T>
class IOs:public Theme{
    
    const char
        LEFT[6]="\033[D",
        RIGTH[6]="\033[C",
        UP[6]="\33[A",
        DOWN[6]="\33[B";
        
    public:
        IOs();
        void left(T,int=1);
        void rigth(T,int=1);
        void up(T,int=1);
        void down(T,int=1);
    
        void point(T,int ,int);
    
    protected:
        void move(T,int,const char*);
        void move(T,int,int);
};

//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------
template<class T> 
IOs<T>::IOs(){}

//------------------------------------------------------------------------------------------------
// Movement
//------------------------------------------------------------------------------------------------
 template<typename T>
 void IOs<T>::move(T t,int n,const char* arrow){ 
     while(n--) std::cout<<arrow;  
     std::cout<<bg()<<fg()<<t;
}

template<typename T> 
void IOs<T>::up(T t,int n){  move(t,n,UP); }

template<typename T> 
void IOs<T>::left(T t,int n){ move(t,n,LEFT);}

template<typename T> 
void IOs<T>::rigth(T t,int n){ move(t,n,RIGTH); }
 
template<typename  T> 
void IOs<T>::down(T t,int n){ move(t,n,DOWN); }

template<typename  T> 
void IOs<T>::point(T t,int m,int n){ 
    move(t,m,RIGTH);
    move(t,n,DOWN);
}

#endif //ios_rag.hpp
