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
    Background();
    Background(Colour);
    std::string operator!() override;
    
    private: 
        void operator=(Highlight);
        static const char PLAN[6];
        
};using Bg=Background;

#endif // background.hpp
