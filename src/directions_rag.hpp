/*!*****************************************************
 *	\file directions_rag.hpp
* \brief Arquivo de definição da classe __Directions__
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#ifndef DIRECTIONS_RAG_HPP
#define DIRECTIONS_RAG_HPP

#include "str.hpp"

struct Directions:public Str{
    Directions();
    Directions(int);
    
    void value(int);
    int value();
    
    protected:
        Directions(char,int=1);
        
    private:
        char flag='B';
        int size=1;
        
};using Dt=Directions;

std::ostream& operator<<(std::ostream&,Directions);

struct Left: public Directions{ Left(); };
struct Rigth:public Directions{ Rigth(); };
struct Up: public Directions{ Up(); };
struct Down: public Directions{ Down(); };

/*
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
        IOs(int);
        IOs(int,int);
        
        void left(int=1);
        void rigth(int=1);
        void up(int=1);
        void down(int=1);
        void point(int top=1,int side=1);
        
        int top();
        int side();
        void top(int);
        void side(int);        
       
    protected:
        void moves(int,const char*);
        void moves(int,int);
        std::string br();
        
        int horizontal=0,
			  vertical=0;
};

//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------
template<class T> 
IOs<T>::IOs(){}

template<class T> 
IOs<T>::IOs(int side):vertical(side){}

template<class T> 
IOs<T>::IOs(int top,int side):horizontal(top),vertical(side){}

//------------------------------------------------------------------------------------------------
// Movement
//------------------------------------------------------------------------------------------------
template<typename T>
std::string IOs<T>::br(){ return "\033[0m"; }

template<typename T> 
void IOs<T>::up(int n){  moves(n,UP); }

template<typename T> 
void IOs<T>::left(int n){ moves(n,LEFT);}

template<typename T> 
void IOs<T>::rigth(int n){ moves(n,RIGTH); }
 
template<typename  T> 
void IOs<T>::down(int n){ moves(n,DOWN); }

template<typename  T> 
void IOs<T>::point(int m,int n){ moves(m,n); }

template<typename T>
void IOs<T>::moves(int n,const char* arrow){ while(n--) std::cout<<arrow;  }

template<typename  T> 
void IOs<T>::moves(int m,int n){ 
    while(m--)std::cout<<DOWN;
    while(n--) std::cout<<RIGTH;
}

//------------------------------------------------------------------------------------------------
// Getting
//------------------------------------------------------------------------------------------------
template<typename  T> 
int IOs<T>::top(){return horizontal;}

template<typename  T> 
int IOs<T>::side(){return vertical;}

//------------------------------------------------------------------------------------------------
// Setting
//------------------------------------------------------------------------------------------------
template<typename  T> 
void IOs<T>::top(int hl){ horizontal=hl;}

template<typename  T> 
void IOs<T>::side(int vl){ vertical=vl; }
*/
#endif //directions_rag.hpp
