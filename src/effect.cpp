/*!*****************************************************
 *	\file effect.cpp
* \brief Arquivo de implementação efeitos
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/
#include <iostream>
#include "effect.hpp"
using std::string;
using std::to_string;

//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------
Hlg::Highlight(){}

Hlg::Highlight(int efc){ buff.push_back(efc); }
//-------------------------------------
// Find
//-------------------------------------
int Hlg::find(int key,int i){ return (i>=buff.size())?(-1):(key==buff[i])?(i):find(key,i+1); }

//------------------------------------------------------------------------------------------------
// Operators
//------------------------------------------------------------------------------------------------
//-------------------------------------
//  Addition
//-------------------------------------
Hlg Hlg::operator+(Hlg efc){ 
    Hlg tmp=*this; 
    tmp+=efc;
    return tmp;
}
void Hlg::operator+=(Hlg hlg){ for(int key : hlg.buff) if(find(key)<0) buff.push_back(key) ; }

//-------------------------------------
// Subtration
//-------------------------------------
Hlg Hlg::operator-(Hlg efc){
    Hlg tmp=*this;
    tmp-=efc;
    return tmp;
}
void Hlg::operator-=(Hlg hlg){ int i; for(int key:hlg.buff) if((i=find(key))>=0) buff.erase(buff.begin()+i); }

//-------------------------------------
// Assign
//-------------------------------------
void Hlg::operator=(Highlight hlg){ buff.assign(hlg.buff.begin(),hlg.buff.end()); }

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
