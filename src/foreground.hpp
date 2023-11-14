/*!***************************************************************
 *	\brief  Arquivo de definição Foreground.
 *	\file foreground.hpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/
#ifndef  FOREGROUND_HPP
#define FOREGROUND_HPP

#include "colour.hpp"
#include "effect.hpp"
#include "ground.hpp"

class Foreground:public Ground{
    public:
        const char PLAN[6]="38;2;",
                            COLORLESS[5]="0;39";

        Foreground();
        Foreground(Colour);
        Foreground(Colour,Highlight);
        
};using Fg= Foreground;

#endif // foreground.hpp
