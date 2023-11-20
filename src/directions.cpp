/*!*****************************************************
 *	\file directions_rag.cpp
* \brief Arquivo de implementação da classe __Directions__
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#include "directions_rag.hpp"
using std::string;
using std::to_string;

//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------

Dt::Directions():Str(BASE){ init(); }

Dt::Directions(int n):Str(BASE){ init(n); }

Dt::Directions(char arrow,int n):Str(BASE){ init(n,arrow); }

void Dt::init(int n,char arrow){
    buf[HEAD]="\033[";
    buf[SIZE]=to_string(my_size=n);
    buf[TAIL]=arrow;
}

//------------------------------------------------------------------------------------------------
// Operations
//------------------------------------------------------------------------------------------------
void Dt::operator=(int n){ size(n); }

std::string Dt::operator+(std::string st){return str()+st;}
std::string operator+(std::string st,Directions dt){ return st+dt.str(); }

std::string Dt::operator+(Directions dt){return dt+"";}

int Dt::operator+(int n){ return my_size+n;}
int operator+(int n,Directions dt){return dt.my_size+n;}
void Dt::operator+=(int n){my_size+=n;}

int Dt::operator-(int n){ return my_size-n;}
int operator-(int n,Directions dt){ return dt.my_size-n; }
void Dt::operator-=(int n){my_size-=n;}

int Dt::operator*(int n){ return my_size*n; }
int operator*(int n,Directions dt){ return dt.my_size*n; }
void Dt::operator*=(int n){my_size*=n;}

int Dt::operator/(int n){ return my_size/n; }
int operator/(int n,Directions dt){return dt.my_size/n;}
void Dt::operator/=(int n){my_size/=n;}   
   
void Dt::operator++(){ my_size+=1; }
void Dt::operator--(){ my_size-=1; }  

//------------------------------------------------------------------------------------------------
// Setting
//------------------------------------------------------------------------------------------------
void Dt::size(int n){ buf[SIZE]=to_string(my_size=n); }

//------------------------------------------------------------------------------------------------
// Getting
//------------------------------------------------------------------------------------------------
int Dt::size(){return my_size;}

//------------------------------------------------------------------------------------------------
// Derived
//------------------------------------------------------------------------------------------------
Up::Up(int n):Dt('A',n){}
Left::Left(int n):Dt('D',n){}
Rigth::Rigth(int n):Dt('C',n){}
Down::Down(int n):Dt('B',n){}
