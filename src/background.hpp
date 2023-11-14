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
    
    /// Background não suporta gerar efeitos, logo são isolados.
    void operator=(Highlight) override;
    
    public:
        static const char 
            PLAN[6],
            COLORLESS[3];
                            
        Background();
        Background(Colour);

};using Bg=Background;

#endif // background.hpp
