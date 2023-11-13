/*!*****************************************************
 *	\brief  Implementa cores e efeitos da lib mosaicos
 *	\file colour.cpp
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/

#include "colour.hpp"

bool Clr::check(nivel value){ return ( (value<0)||(value>255))?false:true;}

void Clr::red(nivel value){ (check(value))?(tom[RED]=value):throw; }        
void Clr::green(nivel value){(check(value))?(tom[GREEN]=value):throw;}   
void Clr::blue(nivel value){(check(value))?(tom[BLUE]=value):throw;}      
	
Clr::nivel Clr::red(){ return tom[RED];}
Clr::nivel Clr::green(){return tom[GREEN];}          
Clr::nivel Clr::blue(){ return tom[BLUE]; }            
	
/*/Luminosidade:
void Clr::contrast(nivel value){}
Clr::nivel Clr::contrast(){ return media(); }

int Clr::media(){
    int soma=tom[RED]+tom[GREEN]+tom[BLUE];
    return (soma*100)/(765);
}
*/

Cls::Red::Red():Colour(255,0,0){}
Cls::Green::Green():Colour(0,255,0){}
Cls::Blue::Blue():Colour(0,0,255){}




