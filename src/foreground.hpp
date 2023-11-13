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
        const char HEAD_FOREGROUND[5]="38;2",
                            DEFAULT_FOREGROUND[5]="0;39";

        void init() override;
    
    public:
        Foreground();
        Foreground(Colour);
        Foreground(Colour,Highlight);
        
        colouring operator!() override;
        void standard() override;
        
    private:
        Highlight my_efc;

};using Fg= Foreground;

#endif // foreground.hpp
