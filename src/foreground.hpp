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
    Foreground();
    Foreground(Colour);
    Foreground(Highlight);
    Foreground(Colour,Highlight);
    
    std::string operator!() override;                                                                    
    void operator=(Hlg) override;
    
    private: static const char PLAN[6];

};using Fg= Foreground;

#endif // foreground.hpp
