/*!***************************************************************
 *	\brief  Arquivo de implementação Foreground.
 *	\file foreground.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/

#include "foreground.hpp"
#include "ground.hpp"

const char 
    Fg::PLAN[6]="38;2;",
    Fg::COLORLESS[5]="0;39";

Fg::Foreground():Ground(Cls::Red(),Fg::PLAN,COLORLESS){}

Fg::Foreground(Colour new_clr):Ground(new_clr,Fg::PLAN,COLORLESS){}

Fg::Foreground(Colour new_clr,Hlg efc):Ground(new_clr,Fg::PLAN,COLORLESS,efc){}

void Fg::operator=(Hlg efc){buf[Efcts]=efc();}
