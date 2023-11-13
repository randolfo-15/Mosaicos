/*!***************************************************************
 *	\brief  Arquivo de definição ground.
 *	\file ground.hpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/
#ifndef  GROUND_HPP
#define GROUND_HPP 

#include "str.hpp"
#include "colour.hpp"

/// Define a coloração de background de uma letra.
class Ground:public Str{ 
    public:
        void operator=(Colour);
        Ground operator!();
        
    protected: 
        Ground();
        Ground(Colour);
        
        const char 
            HEAD_GROUND[5]="\033[",
            l_l[2]=";",
            END[2]="m";

        enum components{
            HEAD,       ///< Cabeçario padrão para cores (033)
            PLAN,       ///< Define em plano estamos (background | foreground)
            R,               ///< Tonalidade de Vermelho
            G,               ///< Tonalidade de Verde
            B,               ///< Tonalidade de azul
            Efcts,         ///< Define um conjunto de efeitos 
            TAIL            ///< Siguino de termino de formula (m)
        };
        virtual  void init();
        
private:
        void copy_colour(Colour);
        std::string colorless;
        void init(Colour);
        
};using  Gd=Ground;

#endif // ground.hpp
