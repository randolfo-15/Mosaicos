/*!***************************************************************
 *	\brief  Arquivo de implementação Foreground.
 *	\file foreground.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/

#include "foreground.hpp"


const char
    Fg::PLAN[6]="38;2;",
    Fg::CLSS[5]="0;39";

//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------
Fg::Foreground():Ground(Cls::Green(),Fg::PLAN,CLSS){}

Fg::Foreground(Colour new_clr):Ground(new_clr,Fg::PLAN,CLSS){}

Fg::Foreground(Colour new_clr,Hlg efc):Ground(new_clr,Fg::PLAN,CLSS,efc){}

//------------------------------------------------------------------------------------------------
// Assign
//------------------------------------------------------------------------------------------------
void Fg::operator=(Hlg efc){buf[Efcts]=efc();}
