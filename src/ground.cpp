/*!***************************************************************
 *	\brief  Arquivo de implementação de ground.
 *	\file ground.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/

#include "ground.hpp"

Gd::Ground(Colour new_clr){ copy(new_clr); }

void Gd::operator=(Colour new_clr){ copy(new_clr); }

ostream& operator<<(ostream& out,Ground& gd){ return out<<gd.expression(); }

void Gd::copy(Clr new_clr){
    clr[R]=to_string(new_clr.red());
    clr[G]=to_string(new_clr.green());
    clr[B]=to_string(new_clr.blue());
}

colouring Gd::expression(){ return clr[HEAD]+clr[PLAN]+";"+clr[R]+";"+clr[G]+";"+clr[B]+";"+clr[Efcts]+clr[SIG]; }

colouring Gd::expression(colouring efc){ return clr[HEAD]+efc+clr[SIG]; }
