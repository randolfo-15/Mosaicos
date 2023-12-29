/*!***************************************************************
 *	\brief  Arquivo de implementação de ground.
 *	\file ground.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/
#include <iostream>
#include "ground.hpp"
#include <sstream>
using std::string;
using std::to_string;

const char 
    Gd::BEG[6]="\033[",
    Gd::END[2]="m";

//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------
Gd::Ground():Ground(Clr(),"",Hlg()){}

Gd::Ground(Clr clr,const char* plan,Hlg efc):
    Str(7),
    Colour(clr.red(),clr.green(),clr.blue()),
    Highlight(efc)
{ 
    buf[HEAD]=BEG;
    buf[PLAN]=plan;
    buf[RGB]=to_str(&clr);
    buf[HLG]=efc.to_str();
    buf[TAIL]=END;
}

//------------------------------------------------------------------------------------------------
// Operator
//------------------------------------------------------------------------------------------------
//-------------------------------------
// Assign
//-------------------------------------
void Gd::operator=(Clr clr){   buf[RGB]=to_str(&clr); }

void Gd::operator=(Hlg hlg){ buf[HLG]=hlg.to_str(); }

//-------------------------------------
// Addition
//-------------------------------------
    void Gd::operator+=(Highlight hlg){ this->Hlg::operator+=(hlg); buf[HLG]=this->Hlg::to_str();}
    Highlight Gd::operator+(Highlight hlg){return this->Hlg::operator+(hlg);}
    
    Colour Gd::operator+(Colour clr){ return this->Clr::operator+(clr); }
    Colour Gd::operator+(nivel n){ return  this->Clr::operator+(n); }
    void Gd::operator+=(Colour clr){ this->Clr::operator+=(clr); }
	void Gd::operator+=(nivel n){this->Clr::operator+=(n); }
	void Gd::operator++(int){ this->Clr::operator++(1); }
	void Gd::operator++(){ this->Clr::operator++();  }

//-------------------------------------
// Subtration
//-------------------------------------
    void Gd::operator-=(Highlight hlg){ this->Hlg::operator-=(hlg); buf[HLG]=this->Hlg::to_str();}
    Highlight Gd::operator-(Highlight hlg){return this->Hlg::operator-(hlg);}
    
    Colour Gd::operator-(Colour clr){ return this->Clr::operator-(clr); }
    Colour Gd::operator-(nivel n){ return  this->Clr::operator-(n); }
	void Gd::operator-=(Colour clr){ this->Clr::operator-=(clr); }
	void Gd::operator-=(nivel n){ this->Clr::operator-=(n); }
	void Gd::operator--(int){ this->Clr::operator--(1); }
	void Gd::operator--(){ this->Clr::operator--();  }

//------------------------------------------------------------------------------------------------
// Deny
//------------------------------------------------------------------------------------------------
std::string Gd::operator!(){ return buf[HEAD]+"0"+buf[TAIL];}

//------------------------------------------------------------------------------------------------
// Getting
//------------------------------------------------------------------------------------------------
Hlg Gd::highlight(){ return *this; }

Clr Gd::colour(){  return *this; }
//------------------------------------------------------------------------------------------------
// Cast
//------------------------------------------------------------------------------------------------
string Gd::to_str(Clr* c){ return to_str(c->red())+";"+to_str(c->green())+";"+to_str(c->blue()); }

string Gd::to_str(nivel tone){ return to_string(tone) ; }
