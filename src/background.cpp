/*!***************************************************************
 *	\brief  Arquivo de implementação Background.
 *	\file background.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/

#include "background.hpp"

Bg::Background():Ground(Cls::Blue()){ init(); }

Bg::Background(Colour new_clr):Ground(new_clr){ init(); }
        
void Bg::init(){clr[HEAD]=HEAD_BACKGROUND;}
        
void Bg::standard(){ clr[Efcts]=DEFALT_BACKGROUND; }

colouring Bg::operator!(){ return expression(DEFALT_BACKGROUND); }
