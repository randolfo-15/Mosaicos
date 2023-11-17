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
#include "effect.hpp"


/// Define a coloração de background de uma letra.
class Ground:public Str{
    public:
        void operator=(Colour);
        std::string operator!();
        std::string operator()();
        
    protected: 
        Ground(Colour,const char* plan,const char* clss,Highlight=Hlg());
        
        static const char 
            BEG[6],
            l_l[2],
            END[2];

        enum components{
            HEAD,       ///< Cabeçario padrão para cores (033)
            PLAN,       ///< Define em plano estamos (background | foreground)
            R,               ///< Tonalidade de Vermelho
            G,               ///< Tonalidade de Verde
            B,               ///< Tonalidade de azul
            Efcts,         ///< Define um conjunto de efeitos 
            TAIL            ///< Siguino de termino de formula (m)
        };
        
        virtual void operator=(Highlight)=0;
    private:
        void copy_colour(Colour);
        void init(Colour,const char*,Hlg);
        
        std::string colorless;
        
};using  Gd=Ground;

#endif // ground.hpp
