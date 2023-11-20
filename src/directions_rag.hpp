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
    
    void size(int);
    int size();
    
    void operator++();
    void operator--();
    
    void operator=(int);
    int operator+(int);
    std::string operator+(std::string);
    std::string operator+(Directions);
    
    int operator-(int);
    int operator*(int);
    int operator/(int);
    
    void operator+=(int);
    void operator-=(int);
    void operator*=(int);
    void operator/=(int);
    
    friend int operator+(int,Directions);
    friend std::string operator+(std::string,Directions);
    friend int operator-(int,Directions);
    friend int operator*(int,Directions);
    friend int operator/(int,Directions);
    
    protected:
        Directions(char,int=1);
        
    private:
        void init(int=1,char=' ');
        
        enum body{HEAD,SIZE,TAIL,BASE=3};
        int my_size;
        
};using Dt=Directions;

std::string operator+(std::string,Directions);
int operator+(int,Directions);
int operator-(int,Directions);
int operator*(int,Directions);
int operator/(int,Directions);


struct Left: public Directions{ Left(int=1); };
struct Rigth:public Directions{ Rigth(int=1); };
struct Up: public Directions{ Up(int=1); };
struct Down: public Directions{ Down(int=1); };

#endif //directions_rag.hpp
