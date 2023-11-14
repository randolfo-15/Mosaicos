/*!*****************************************************
 *	\brief  Implementa cores e efeitos da lib mosaicos
 *	\file colour.cpp
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/

#include "colour.hpp"

/*
 //------------------------------------------------------------------------------------------
 // Luminosidade:
//------------------------------------------------------------------------------------------
 void Clr::contrast(nivel value){}
Clr::nivel Clr::contrast(){ return media(); }

int Clr::media(){
    int soma=tom[RED]+tom[GREEN]+tom[BLUE];
    return (soma*100)/(765);
}
*/

using namespace Cls;
Red::Red():Colour(255,0,0){}
Green::Green():Colour(0,255,0){}
Blue::Blue():Colour(0,0,255){}
