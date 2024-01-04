/*!***************************************************************
 *	\brief  Arquivo de definição ground.
 *	\file ground.hpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/
#ifndef  GROUND_RAG_HPP
#define GROUND_RAG_HPP 

#include "str_rag.hpp"
#include "colour_rag.hpp"
#include "effect_rag.hpp"

class Ground:public Str,public Colour, public Highlight{    
//------------------------------------------------------------------------------------------------
//  Build
//------------------------------------------------------------------------------------------------ 
public:        Ground();                                                                                        ///< Construtor padrão.
protected:  Ground(Colour,const char* plan,Highlight=Hlg());                ///< Construtor para derivados.
//-------------------------------------
// Setting
//-------------------------------------
public:
    void operator=(Colour) override;                                                           ///< Atribui cor ao ground
    void operator=(Highlight) override;                                                       ///< Atribui efeito ao ground.
//-------------------------------------
// Getting
//-------------------------------------
public:   
    Clr  clr();                                                                                               ///< Obterm cor do ground.
    Hlg hlg();                                                                                              ///< Obtem highlight do ground
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
// Deny    
//-------------------------------------    
    virtual std::string operator!();                                                  ///< Desligar coloração ou efeito.
    
};using  Gd=Ground;

//------------------------------------------------------------------------------------------------
// Function
//------------------------------------------------------------------------------------------------
std::string br();

#endif // ground_rag.hpp
