/*!***************************************************************
 *	\brief  Arquivo de definição Background.
 *	\file background.hpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/
#ifndef  BACKGROUND_HPP
#define BACKGROUND_HPP

#include "ground.hpp"

const char HEAD_BACKGROUND[]="48;2";
const char DEFALT_BACKGROUND[]="49";

class Background:public Ground{

    void init() override;
    
    public:
        Background();
        Background(Colour);
        
        void  standard() override;        
        virtual colouring operator!() override;
        
};using Bg=Background;

#endif // background.hpp
