/*!*****************************************************
 *	\file theme.cpp
 *	\brief  Arquivo de implementação da classe tema
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/

#include "theme.hpp" 

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
 *  \param new_efeito efeito usado em foreground.
 */ 
Tm::Theme(Fg new_key,Bg new_bkg,Bg new_bkg2,Ef new_effect):
	my_key(new_key),
    my_bkg(new_bkg),
	my_bkg2(new_bkg2),
	my_efc(new_effect)
	{}

//--------------------------------------------------------------
// Get
//--------------------------------------------------------------
	
Ef Tm::eft(){ return my_efc; }
	
Fg Tm::key(){ return my_key;  }              
		
Bg Tm::bkg(){ return my_bkg; }
		
Bg Tm::bkg2(){ return my_bkg2; } 

//--------------------------------------------------------------
// Set
//--------------------------------------------------------------

void Tm::eft(Ef new_efc) { my_efc=new_efc; }        

void Tm::key(Fg new_key){ my_key=new_key; }      
		
void Tm::bkg(Bg new_bkg){  my_bkg=new_bkg; }      
		
void Tm::bkg2(Bg new_bkg){ my_bkg2=new_bkg; }
		

