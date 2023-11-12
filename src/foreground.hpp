/*!***************************************************************
 *	\brief  Arquivo de definição Foreground.
 *	\file foreground.hpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/
#ifndef  FOREGROUND_HPP
#define FOREGROUND_HPP

#include "colour.hpp"
#include "ground.hpp"

class Foreground:public Ground{
    
    public:
        Foreground();
        Foreground(Colour);
        Foreground(Colour,Efc::Highlight);
        
        
        void standard() override;
        
        effect efc();          ///< Get ← effect
        void efc(effect);   ///<  Set → effect
        
    private:
        effect my_efc;

};using Fg= Foreground;

#endif // foreground.hpp
