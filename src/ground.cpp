/*!***************************************************************
 *	\brief  Arquivo de implementação de ground.
 *	\file ground.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/

#include "ground.hpp"

const char Gd::BEG[5]="\033[",
                    Gd::l_l[2]=";",
                    Gd::END[2]="m";

//------------------------------------------------------------------------------------------------
// Constrir
//------------------------------------------------------------------------------------------------
Gd::Ground(Clr clr,const char*plan,const char*clss,Hlg efc):
    Str(7),
    colorless(clss)
    { init(clr,plan,efc); }

void Gd::init(Clr clr,const char* plan,Hlg efc){
    buf[HEAD]=BEG;
    buf[PLAN]=plan;
    copy_colour(clr);
    buf[Efcts]=efc();
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

std::string Gd::operator!(){ return buf[HEAD]+colorless+buf[TAIL];}
