/*!***************************************************************
 *	\brief  Arquivo de definição ground.
 *	\file ground.hpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/
#ifndef  GROUND_HPP
#define GROUND_HPP 

#include <ostream>
#include "colour.hpp"
#include "str.hpp"

/// Define a coloração de background de uma letra.
class Ground:public Str{ 
        public:
            using colouring=std::string;

            const char HEAD_GROUND[5]="\033",
                                END[2]="m";

        enum components{
            HEAD,       ///< Cabeçario padrão para cores (033)
            PLAN,       ///< Define em plano estamos (background | foreground)
            R,               ///< Tonalidade de Vermelho
            G,               ///< Tonalidade de Verde
            B,               ///< Tonalidade de azul
            Efcts,         ///< Define um conjunto de efeitos 
            SIG            ///< Siguino de termino de formula (m)
        };
        
public:
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
    
        friend std::ostream& operator<<(std::ostream& , const Ground&);
        colouring express();
        colouring express(colouring);
        
        virtual  void init()=0;
        

    private:
        void copy(Colour);
        
        // ... Devemos retringir os componentes da clasee string;
        
    
};using  Gd=Ground;

std::ostream& operator<<(std::ostream& ,Ground&);

#endif // ground.hpp
