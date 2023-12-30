/*!***************************************************************
 *	\brief  Arquivo de implementação de ground.
 *	\file ground.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/
#include "ground.hpp"
#include <sstream>
using std::string;

const char 
    Gd::BEG[6]="\033[",
    Gd::END[2]="m";

//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------
Gd::Ground():Ground(Clr(),"",Hlg()){}

Gd::Ground(Clr clr,const char* plan,Hlg hlg):
    Str(5),
    Colour(clr.red(),clr.green(),clr.blue()),
    Highlight(hlg)
{ 
    buf[HEAD]=BEG;
    buf[PLAN]=plan;
    buf[RGB]=clr.to_str();
    buf[HLG]=hlg.to_str();
    buf[TAIL]=END;
}

//------------------------------------------------------------------------------------------------
// Operator
//------------------------------------------------------------------------------------------------
//-------------------------------------
// Assign
//-------------------------------------
void Gd::operator=(Clr clr){   buf[RGB]=clr.to_str();  }

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
// Components
//------------------------------------------------------------------------------------------------
Hlg Gd::hlg(){ return *this; }
Clr  Gd::clr(){   return *this; }

//------------------------------------------------------------------------------------------------
// Function
//------------------------------------------------------------------------------------------------
string br(){ return "\033[0m"; }
