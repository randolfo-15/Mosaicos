/*!***************************************************************
 *	\brief  Arquivo de implementação de ground.
 *	\file ground.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/

#include "ground.hpp"
#include <sstream>
using std::stoi;


const char 
    Gd::BEG[6]="\033[",
    Gd::END[2]="m";

//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------
Gd::Ground():Ground(Clr(),"",Hlg()){}

Gd::Ground(Clr cl,const char* plan,Hlg efc):
    Str(7)
{ 
    buf[HEAD]=BEG;
    buf[PLAN]=plan;
    buf[RGB]=cl();
    buf[HLG]=efc();
    buf[TAIL]=END;
}

//------------------------------------------------------------------------------------------------
// Assign
//------------------------------------------------------------------------------------------------
void Gd::operator=(Clr new_clr){ buf[RGB]=new_clr(); }

void Gd::operator=(Hlg efc){buf[HLG]=efc();}

//------------------------------------------------------------------------------------------------
// Deny
//------------------------------------------------------------------------------------------------
std::string Gd::operator!(){ return buf[HEAD]+"0"+buf[TAIL];}

//------------------------------------------------------------------------------------------------
// Getting
//------------------------------------------------------------------------------------------------
std::string Gd::operator()(){return str();}

Clr Gd::colour(){  return cast_colour(); }

Clr Gd::cast_colour(Clr clr,std::string tmp,int cor){ 
    std::stringstream sstr(buf[RGB]);
    while(getline(sstr,tmp,';')) switch (cor++) {
            case(Clr::RED):      clr.red(stoi(tmp));      break;
            case(Clr::GREEN): clr.green(stoi(tmp)); break;
            case(Clr::BLUE):    clr.blue(stoi(tmp));    break; 
    } return clr;
}
