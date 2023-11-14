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
void Gd::operator=(Gd gd){  }

std::string Gd::operator!(){ return buf[HEAD]+colorless+buf[TAIL];}

Hlg Gd::effect(){return Hlg(buf[Efcts]);}
void Gd::effect(Hlg efc){ buf[Efcts]=efc(); }

