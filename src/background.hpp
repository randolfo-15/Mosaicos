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
        const char HEAD_BACKGROUND[5]="48;2",
                            DEFAULT_BACKGROUND[3]="49";
        
        void init() override;
    
    public:
        Background();
        Background(Colour);
        
        void  standard() override;        
        colouring operator!() override;
        
};using Bg=Background;

#endif // background.hpp
