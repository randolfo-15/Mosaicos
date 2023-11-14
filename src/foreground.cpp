/*!***************************************************************
 *	\brief  Arquivo de implementação Foreground.
 *	\file foreground.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/

#include "foreground.hpp"

Fg::Foreground():Ground(Cls::Red(),Fg::PLAN,COLORLESS){}

Fg::Foreground(Colour new_clr):Ground(new_clr,Fg::PLAN,COLORLESS){}

Fg::Foreground(Colour new_clr,Hlg efc):Ground(new_clr,Fg::PLAN,COLORLESS,efc){}
