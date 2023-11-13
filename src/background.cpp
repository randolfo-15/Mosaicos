/*!***************************************************************
 *	\brief  Arquivo de implementação Background.
 *	\file background.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/

#include "background.hpp"

Bg::Background():Ground(Cls::Blue()){ init(); }

Bg::Background(Colour new_clr):Ground(new_clr){ init(); }
        
void Bg::init(){
    clr[HEAD]=HEAD_BACKGROUND;
    assign(express());
}
        
void Bg::standard(){ clr[Efcts]=DEFAULT_BACKGROUND; }

Bg::colouring Bg::operator!(){ return express(DEFAULT_BACKGROUND); }
