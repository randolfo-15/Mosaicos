/*!*****************************************************
 *	\file theme.cpp
 *	\brief  Arquivo de implementação da classe tema
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/

#include "theme.hpp" 
#include "colour.hpp"

//--------------------------------------------------------------
// Manufacture
//--------------------------------------------------------------

/*!
 * Por padrão as cores(blue,red,  definem  o  background e  o  foreground 
 *  white e o efeito em negrito) são o padrão da classe tema, no entanto esta 
 * coloração   tende  a  ter  mudança significativas   conforme o padrão de cores 
 * do terminal.
 * ______________________________________________________________________________________
 * \sa Tema(colour,colour,colour,effect);
 */
Tm::Theme(){}

/*!
 *  É possivel definir outro padrão de cores ao se custumizar o construtor
 *  e atribuir um novo jogo de cores e efeitos.
 * ____________________________________________________________________________________
 *  \param new_key cor usada em foreground.
 *  \param new_bkj  cor usada em background.
 *  \param new_bkg2 cor usado no background em modo selecão.
 */ 
Tm::Theme(Fg new_key,Bg new_bkg,Bg new_bkg2):
	my_key(new_key),
    my_bkg(new_bkg),
	my_bkg2(new_bkg2)
	{}

//--------------------------------------------------------------
// Get
//--------------------------------------------------------------
using str=std::string;	

str Tm::key(){ return my_key();  }              
		
str Tm::bkg(){ return my_bkg(); }
		
str Tm::bkg2(){ return my_bkg2(); } 

//--------------------------------------------------------------
// Set
//--------------------------------------------------------------

void Tm::key(Hlg efc){ my_key.effect(efc); }      
		
void Tm::bkg(Clr clr){  my_bkg=clr; }      
		
void Tm::bkg2(Clr clr){ my_bkg2=clr; }
		

