/*!*****************************************************
 *	\file theme.cpp
 *	\brief  Arquivo de implementação da classe tema
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/

#include "theme.hpp" 
#include "colour.hpp"
#include "tema.hpp"

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
 * ____________________________________________________________________________________
 *  \param key cor usada em foreground.
 *  \param bkj  cor usada em background.
 *  \param bkg2 cor usado no background em modo selecão.
 *  \param efeito efeito usado em foreground.
 */ 
Tm::Theme(colour new_key,colour new_bkg,colour new_bkg2,effect new_effect)
{
	palette[TM_KEY]       = new_key;
	palette[TM_BKG]      = new_bkg;
	palette[TM_BKG2]    = new_bkg2;
	palette[TM_EFFECT] = new_effect;
}

		colour Tm::key(){ return palette[TM_KEY]; }              
		
		colour Tm::bkg(){ return palette[TM_BKG]; }
		
		effect  Tm::eft(){ return palette[TM_EFFECT]; }
		
		colour Tm::bkg2(){ return palette[TM_BKG2]; } 
		
		
		void Tm::key(colour clr){ if(Fg::is_colour(clr)) palette[TM_KEY]=clr; }      
		
		void Tm::bkg(colour clr){}      
		
		void Tm::eft(effect efc){}        
		
		void Tm::bkg2(colour clr){} 

