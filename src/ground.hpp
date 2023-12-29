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

class Ground:public Str,public Colour,public Highlight{    
//------------------------------------------------------------------------------------------------
//  Build
//------------------------------------------------------------------------------------------------ 
public:        Ground();                                                                                        ///< Construtor padrão.
protected:  Ground(Colour,const char* plan,Highlight=Hlg());                ///< Construtor para derivados.

//------------------------------------------------------------------------------------------------
// Colour
//------------------------------------------------------------------------------------------------ 
public:   
    Clr  colour();                                                                                                   ///< Obterm cor do ground.
    Hlg highlight();                                                                                              ///< Obtem highlight do ground
//-------------------------------------
// Cast
//-------------------------------------
private:  
    std::string to_str(Clr*);                                                                               ///< Cast colour para string.
    std::string to_str(nivel);                                                                              ///< Cast de colour para string
//------------------------------------------------------------------------------------------------
//  Fields
//------------------------------------------------------------------------------------------------
private:
        static const char 
            BEG[6],     ///< Inicializa corpo do ground.
            END[2];     ///< Finaliza corpo do ground.

protected:
    enum components{
            HEAD,        ///< Cabeçario padrão para cores (033)
            PLAN,        ///< Define em plano estamos (background | foreground)
            RGB,          ///< Tonalidade
            HLG,          ///< Define um conjunto de efeitos 
            TAIL           ///< Siguino de termino de formula (m)
    };

//------------------------------------------------------------------------------------------------
// Operator
//------------------------------------------------------------------------------------------------ 

//-------------------------------------
// Addition
//-------------------------------------
public:
    Highlight operator+(Highlight) override;
    void operator+=(Highlight) override;
    
    Colour operator+(Colour) override;
	Colour operator+(nivel) override;
	void operator+=(Colour) override;
	void operator+=(nivel) override;
	void operator++(int) override;
    void operator++() override;
    
//-------------------------------------
// Subtration
//-------------------------------------
public:	
    Highlight operator-(Highlight) override;
    void operator-=(Highlight) override;
    
    Colour operator-(Colour) override;
	Colour operator-(nivel) override;
	void operator-=(Colour) override;
	void operator-=(nivel) override;
    void operator--(int) override;
	void operator--() override;

//-------------------------------------
// Assign
//-------------------------------------
public:
    void operator=(Colour) override;                                                                ///< Atribui cor ao ground
    void operator=(Highlight) override;                                                           ///< Atribui efeito ao ground.
//-------------------------------------
// Deny    
//-------------------------------------    
    virtual std::string operator!();                                                                    ///< Desligar coloração ou efeito.
    
};using  Gd=Ground;

#endif // ground.hpp
