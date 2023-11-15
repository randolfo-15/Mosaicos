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

struct Foreground:public Ground{
    static const char 
        PLAN[6],
        COLORLESS[5];

    Foreground();
    Foreground(Colour);
    Foreground(Colour,Highlight);
        
    void operator=(Highlight);
        
};using Fg= Foreground;

#endif // foreground.hpp
