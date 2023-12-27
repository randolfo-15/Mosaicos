/*!***************************************************************
 *	\brief  Arquivo de implementação Foreground.
 *	\file foreground.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/

#include "foreground.hpp"

const char
    Fg::PLAN[6]="38;2;";

//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------
Fg::Foreground():Gd(Cls::White(),Fg::PLAN){}

Fg::Foreground(Highlight efc):Gd(Cls::White(),Fg::PLAN){*this=efc;}

Fg::Foreground(Colour new_clr):Ground(new_clr,Fg::PLAN){}

Fg::Foreground(Colour new_clr,Hlg efc):Ground(new_clr,Fg::PLAN,efc){}

//------------------------------------------------------------------------------------------------
// Operator
//------------------------------------------------------------------------------------------------
std::string Fg::operator!(){ return buf[HEAD]+"39"+buf[TAIL];}

