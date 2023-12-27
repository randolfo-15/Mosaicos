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

class Ground:public Str{    
//------------------------------------------------------------------------------------------------
//  Build
//------------------------------------------------------------------------------------------------ 
public:         Ground();                                                                                        ///< Construtor padrão.
protected:  Ground(Colour,const char* plan,Highlight=Hlg());                ///< Construtor para derivados.

//------------------------------------------------------------------------------------------------
// Colour
//------------------------------------------------------------------------------------------------ 
public:    Colour colour();                                                                                 ///< Obterm cor do ground.
private:  Colour cast_colour(Clr=Clr(),std::string="",int=0);                     ///< Converge string em cor.
    
//------------------------------------------------------------------------------------------------
//  Fields
//------------------------------------------------------------------------------------------------
private:
        static const char 
            BEG[6],     ///< Inicializa corpo do ground.
            END[2];     ///< Finaliza corpo do ground.

protected:
    enum components{
            HEAD,       ///< Cabeçario padrão para cores (033)
            PLAN,       ///< Define em plano estamos (background | foreground)
            RGB,          ///< Tonalidade
            HLG,          ///< Define um conjunto de efeitos 
            TAIL          ///< Siguino de termino de formula (m)
    };
    

//------------------------------------------------------------------------------------------------
// Operator
//------------------------------------------------------------------------------------------------ 
public:
    void operator=(Colour);                                                                                 ///< Atribui cor ao ground
    void operator=(Highlight);                                                                            ///< Atribui efeito ao ground.
    virtual std::string operator!();                                                                    ///< Desligar coloração ou efeito.
    
protected: std::string operator()();                                                                ///< cast de ground para string
    
};using  Gd=Ground;

#endif // ground.hpp
