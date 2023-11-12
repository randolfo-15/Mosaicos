/*!***************************************************************
 *	\brief  Arquivo de implementação Foreground.
 *	\file foreground.cpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/

#include "foreground.hpp"


Fg::Foreground():Ground(Cls::White;){}

Fg::Foreground(colour new_clr):Ground(new_clr){}

Fg::Foreground(colour new_clr,effect new_efc):
    Ground(new_clr),
    my_efc(new_efc)
    {}
        
colour Fg::cast_ground() {return "";}

colour Fg::standard(){ return "\033[0;39m";}
