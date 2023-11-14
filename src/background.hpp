/*!***************************************************************
 *	\brief  Arquivo de definição Background.
 *	\file background.hpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/
#ifndef  BACKGROUND_HPP
#define BACKGROUND_HPP

#include "ground.hpp"

class Background:public Ground{
    public:
        const char PLAN[6]="48;2;",
                            COLORLESS[3]="49";
                            
        Background();
        Background(Colour);
        
};using Bg=Background;

#endif // background.hpp
