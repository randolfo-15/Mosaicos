/*!*****************************************************
 *	\file effect.cpp
* \brief Arquivo de implementação efeitos
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/
#include "effect.hpp"
using std::string;
using std::to_string;

//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------
Hlg::Highlight(){}

Hlg::Highlight(int efc){ buff.push_back(efc); }

//------------------------------------------------------------------------------------------------
// Addition
//------------------------------------------------------------------------------------------------
Hlg Hlg::operator+(Hlg efc){ 
    Hlg tmp=*this; 
    tmp+=efc;
    return tmp;
}

void Hlg::operator+=(Hlg other){ for(int efc : other.buff) buff.push_back(efc) ; }

//------------------------------------------------------------------------------------------------
// Subtration
//------------------------------------------------------------------------------------------------
Hlg Hlg::operator-(Hlg efc){
    Hlg tmp=*this;
    tmp-=efc;
    return tmp;
}

void Hlg::operator-=(Hlg efc){ for(int efc:efc.buff) buff.erase(std::find(buff.begin(),buff.end(),efc)); }

//------------------------------------------------------------------------------------------------
// Cast
//------------------------------------------------------------------------------------------------
string Hlg::to_str(){ 
    string my_str;
    for(int efc:buff) my_str+=";"+to_string(efc); 
    return my_str;
}

//------------------------------------------------------------------------------------------------
// Derived
//------------------------------------------------------------------------------------------------
using namespace Efc;

Normal::Normal():Hlg(0){}

Bold::Bold():Hlg(1){} 

Dark::Dark():Hlg(2){}

Italic::Italic():Hlg(3){}

Underline::Underline():Hlg(4){}

Blink::Blink():Hlg(5){}

Reverse::Reverse():Hlg(7){} 

Hidden::Hidden():Hlg(8){}

Tachado::Tachado():Hlg(9){}
