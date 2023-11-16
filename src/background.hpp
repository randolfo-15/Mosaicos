/*!***************************************************************
 *	\brief  Arquivo de definição Background.
 *	\file background.hpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/
#ifndef  BACKGROUND_HPP
#define BACKGROUND_HPP

#include "ground.hpp"

struct Background:public Ground{
    static const char
        PLAN[6],
        CLSS[3];
                            
    Background();
    Background(Colour);

    private: void operator=(Highlight) override;

};using Bg=Background;

#endif // background.hpp
