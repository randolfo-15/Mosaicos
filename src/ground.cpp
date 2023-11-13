/*!***************************************************************
 *	\brief  Arquivo de implementação de ground.
 *	\file ground.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/

#include "ground.hpp"

Gd::Ground(Colour new_clr){ copy(new_clr); }

void Gd::operator=(Colour new_clr){ copy(new_clr); }

std::ostream& operator<<(std::ostream& out,Ground& gd){ return out<<gd.express(); }

void Gd::copy(Clr new_clr){
    clr[R]=std::to_string(new_clr.red());
    clr[G]=std::to_string(new_clr.green());
    clr[B]=std::to_string(new_clr.blue());
}

Gd::colouring Gd::express(){ return clr[HEAD]+clr[PLAN]+";"+clr[R]+";"+clr[G]+";"+clr[B]+";"+clr[Efcts]+clr[SIG]; }

Gd::colouring Gd::express(colouring efc){ return clr[HEAD]+efc+clr[SIG]; }
