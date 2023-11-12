/*!***************************************************************
 *	\brief  Arquivo de definição ground.
 *	\file ground.hpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/
#ifndef  GROUND_HPP
#define GROUND_HPP 

const char HEAD_GROUND[]="\033",
                    END[]="m";

#include "colour.hpp"
using colouring=std::string;

using std::to_string; 


enum components{
    HEAD,       ///< Cabeçario padrão para cores (033)
    PLAN,       ///< Define em plano estamos (background | foreground)
    R,               ///< Tonalidade de Vermelho
    G,               ///< Tonalidade de Verde
    B,               ///< Tonalidade de azul
    Efcts,         ///< Define um conjunto de efeitos 
    SIG            ///< Siguino de termino de formula (m)
};


/// Define a coloração de background de uma letra.
struct Ground{ 
        Ground(Colour);		
        
        void operator=(Colour);
        
        virtual void standard()=0; ///< Default system.
        virtual colouring operator!()=0;
        
    protected: 
        std::string clr[7]{
            HEAD_GROUND,    ///< HEAD
            "",                             ///< PLAN
            "",                             ///< R
            "",                             ///< G
            "",                             ///< B
            "",                             ///< Effects
            END                         ///< SIG
        };
    
        friend ostream& operator<<(ostream& , const Ground&);
        colouring expression();
        colouring expression(colouring);
        
        virtual  void init()=0;
        
    private:
        void copy(Colour);
    
};using  Gd=Ground;

ostream& operator<<(ostream& ,Ground&);

#endif // ground.hpp
