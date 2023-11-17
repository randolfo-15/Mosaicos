/*!***************************************************************
 *	\brief  Arquivo de definição Foreground.
 *	\file foreground.hpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/
#ifndef  FOREGROUND_HPP
#define FOREGROUND_HPP

#include "ground.hpp"

struct Foreground:public Ground{
    static const char
        PLAN[6],
        CLSS[5];

    Foreground();
    Foreground(Colour);
    Foreground(Colour,Highlight);
        
    void operator=(Highlight) override;
        
};using Fg= Foreground;

#endif // foreground.hpp
