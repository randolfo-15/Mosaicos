/*!***************************************************************
 *	\brief  Arquivo de implementação de ground.
 *	\file ground.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/

#include "ground.hpp"

//------------------------------------------------------------------------------------------------
// Constrir
//------------------------------------------------------------------------------------------------
Gd::Ground(Clr clr):Str(7){ init(clr); }

void Gd::init(Clr clr){
    buf[HEAD]=HEAD_GROUND;
    copy_colour(clr);
    buf[TAIL]=END;
}

void Gd::copy_colour(Clr new_clr){
    buf[R]=std::to_string(new_clr.red)+l_l;
    buf[G]=std::to_string(new_clr.green)+l_l;
    buf[B]=std::to_string(new_clr.blue)+l_l;
}

//------------------------------------------------------------------------------------------------
// Atribuir
//------------------------------------------------------------------------------------------------
void Gd::operator=(Clr clr){ copy_colour(clr); }
Gd Gd::operator!(){
    Gd copy=*this;
    copy.buf[Efcts]="";
    return copy;
}
