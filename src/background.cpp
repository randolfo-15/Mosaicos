/*!***************************************************************
 *	\brief  Arquivo de implementação Background.
 *	\file background.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/

#include "background.hpp"
#include "ground.hpp"

Bg::Background():Ground(Cls::Blue(),Bg::PLAN,COLORLESS){}

Bg::Background(Colour new_clr):Ground(new_clr,Bg::PLAN,COLORLESS){}
        
