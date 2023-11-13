/*!***************************************************************
 *	\brief  Arquivo de implementação Foreground.
 *	\file foreground.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/

#include "foreground.hpp"
#include "colour.hpp"
#include "ground.hpp"

Fg::Foreground():Ground(Cls::Red()){ init();}

Fg::Foreground(Colour new_clr):Ground(new_clr){ init();}

Fg::Foreground(Colour new_clr,Hl new_efc):
    Ground(new_clr),
    my_efc(new_efc)
    {init();}
        
void Fg::init(){
    clr[HEAD]=HEAD_FOREGROUND;
    clr[Efcts]=my_efc;
    assign(express());
}

void  Fg::standard(){clr[Efcts]=DEFAULT_FOREGROUND; }

Fg::colouring Fg::operator!(){return express(DEFAULT_FOREGROUND);}
