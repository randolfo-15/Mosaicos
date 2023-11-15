/*!*****************************************************
 *	\brief  Implementa cores e efeitos da lib mosaicos
 *	\file colour.cpp
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/

#include "colour.hpp"

const Clr::nivel 
    Clr::MAX=255,
    Clr::MIN=0,
    Clr::HALF=127,
    Clr::BASE=3,
    Clr::pixel[3]={1,1,1};

Clr::Colour(){}
    
Clr::Colour(Colour& clr){ *this=clr; }

Clr::Colour(Colour&& clr){ *this=clr; }    
    
void Clr::red(nivel value){ rgb[RED]=value; }

void Clr::green(nivel value){rgb[GREEN]=value;}

void Clr::blue(nivel value){rgb[BLUE]=value;}
	
Clr::nivel Clr::red(){ return rgb[RED];} 

Clr::nivel Clr::green(){ return rgb[GREEN]; }

Clr::nivel Clr::blue(){return rgb[BLUE];}

Colour Clr::operator+(Clr clr){ return sum(this->rgb,clr.rgb,true); }

Colour Clr::operator+(nivel n){ nivel pixels[BASE]={n,n,n}; return sum(rgb,pixels,true); }

void Clr::operator+=(nivel n){ nivel pixels[BASE]={n,n,n}; *this=sum(rgb,pixels,true); }

void Clr::operator++(){*this=sum(rgb,pixel,true);}

void Clr::operator+=(Clr clr){*this=sum(this->rgb,clr.rgb,false);}

Colour Clr::operator-(Clr clr){return sum(this->rgb,clr.rgb,true);}

Colour Clr::operator-(nivel n){ nivel pixels[BASE]={n,n,n}; return sum(rgb,pixels,false);}

void Clr::operator-=(nivel n){ nivel pixels[BASE]={n,n,n}; *this= sum(rgb,pixels,false);}

void Clr::operator--(){*this=sum(rgb,pixel,false);}

void Clr::operator-=(Clr clr){ *this=sum(this->rgb,clr.rgb,false); }

void Clr::operator=(Clr clr){ for(int i=0;i<BASE;i++) rgb[i]=clr.rgb[i]; }

Clr Clr::sum(const nivel* clr0,const nivel* clr1,bool operation, Clr clr,int i){ 
    for(;i<BASE;i++) clr.rgb[i]=(operation)?(clr0[i]+clr1[i]):(clr0[i]-clr1[i]);  return clr;
}

using namespace Cls;

Red::Red():Clr(MAX,MIN,MIN){}
Green::Green():Clr(MIN,MAX,MIN){}
Blue::Blue():Clr(MIN,MIN,MAX){}

Yellow::Yellow():Clr(MAX,MAX,MIN){}
Cyan::Cyan():Clr(MIN,MAX,MAX){}
Magenta::Magenta():Clr(MAX,MIN,MAX){}


White::White():Clr(){}
Black::Black():Clr(MIN,MIN,MIN){}
Gray::Gray():Clr(HALF,HALF,HALF){}
