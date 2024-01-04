/*!*****************************************************
 *	\brief  Implementa cores e efeitos da lib mosaicos
 *	\file colour.cpp
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/

#include "colour_rag.hpp"
using std::string;
using std::to_string;

const nivel 
    Clr::MAX=255,
    Clr::MIN=0,
    Clr::HALF=127,
    Clr::BASE=3,
    Clr::pixel[3]={1,1,1};

//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------    
Clr::Colour(){}

Clr::Colour(nivel r,nivel g,nivel b){ rgb[RED]=r; rgb[GREEN]=g; rgb[BLUE]=b; }

//------------------------------------------------------------------------------------------------
// Setting
//------------------------------------------------------------------------------------------------

void Clr::red(nivel value){ rgb[RED]=value; }

void Clr::green(nivel value){rgb[GREEN]=value;}

void Clr::blue(nivel value){rgb[BLUE]=value;}
	
//------------------------------------------------------------------------------------------------
// Getting
//------------------------------------------------------------------------------------------------	
nivel Clr::red(){ return rgb[RED];} 

nivel Clr::green(){ return rgb[GREEN]; }

nivel Clr::blue(){return rgb[BLUE];}

//------------------------------------------------------------------------------------------------
// Addition
//------------------------------------------------------------------------------------------------
Colour Clr::operator+(Clr clr){ return sum(this->rgb,clr.rgb,true); }

Colour Clr::operator+(nivel n){ nivel pixels[BASE]={n,n,n}; return sum(rgb,pixels,true); }

void Clr::operator+=(nivel n){ nivel pixels[BASE]={n,n,n}; *this=sum(rgb,pixels,true); }

void Clr::operator++(){*this=sum(rgb,pixel,true);}

void Clr::operator++(int){ *this=sum(rgb,pixel,true); }

void Clr::operator+=(Clr clr){*this=sum(this->rgb,clr.rgb,true);}

//------------------------------------------------------------------------------------------------
// Subtraion
//------------------------------------------------------------------------------------------------
Colour Clr::operator-(Clr clr){return sum(this->rgb,clr.rgb,false);}

Colour Clr::operator-(nivel n){ nivel pixels[BASE]={n,n,n}; return sum(rgb,pixels,false);}

void Clr::operator-=(nivel n){ nivel pixels[BASE]={n,n,n}; *this= sum(rgb,pixels,false);}

void Clr::operator--(){*this=sum(rgb,pixel,false);}

void Clr::operator--(int){ *this=sum(rgb,pixel,false); }

void Clr::operator-=(Clr clr){ *this=sum(this->rgb,clr.rgb,false); }

//------------------------------------------------------------------------------------------------
// Assign
//------------------------------------------------------------------------------------------------

void Clr::operator=(Clr clr){ for(int i=0;i<BASE;i++) rgb[i]=clr.rgb[i]; }

Clr Clr::sum(const nivel* clr0,const nivel* clr1,bool operation, Clr clr,int i){ 
    for(;i<BASE;i++) clr.rgb[i]=(operation)?((clr0[i]+clr1[i])/2):(check(clr0[i]-clr1[i]));  
    return clr;
}

nivel Clr::check(short n){ return (n<0)?0:n; }
//------------------------------------------------------------------------------------------------
// Cast
//------------------------------------------------------------------------------------------------
string Clr::to_str(int i){ return (i<2)? to_string(rgb[i])+";"+to_str(i+1):to_string(rgb[i]); }

//------------------------------------------------------------------------------------------------
// Derivedcopy_colour(cl);
//------------------------------------------------------------------------------------------------
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
