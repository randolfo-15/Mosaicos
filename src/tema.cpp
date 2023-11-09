/*!*****************************************************
 *	\file tema.cpp
 *	\brief  Arquivo de implementação da classe tema
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/

#include <tema.hpp> 

/*!
 * Por padrão as cores(blue,red,  definem  o  background e  o  foreground 
 *  white e o efeito em negrito) são o padrão da classe tema, no entanto esta 
 * coloração   tende  a  ter  mudança significativas   conforme o padrão de cores 
 * do terminal.
 * ______________________________________________________________________________________
 * \sa Tema(cor_effect,cor,cor,effect)
 */
Tema::Tema():
Tema
(	COR::KEY::WHITE_KEY,
	COR::BKG::BLUE_BKG,
	COR::BKG::RED_BKG,
	COR::EFFECT::BOLD_KEY
){}

/*!
 *  É possivel definir outro padrão de cores ao se custumizar o construtor
 * ____________________________________________________________________________________
 *  \param key cor usada em foreground.
 *  \param bkj  cor usada em background.
 *  \param bkg2 cor usado no background em modo selecão.
 *  \param efeito efeito usado em foreground.
 */ 
Tema::Tema(cor_effect new_key,cor new_bkg,cor new_bkg2,effect new_effect)
{
	component[TEMA_KEY]=new_key;
	component[TEMA_BKG]=new_bkg;
	component[TEMA_EFFECT]=new_effect;
	component[TEMA_BKG2]=new_bkg2;
}


/*!
 * Caso new_value seja um valor  distinto  do atual e definido, atribuimos um novo 
 * valor a nosso componete.
 * ____________________________________________________________________________________
 * \param value index do atributo atual
 * \param new_value novo valor do atributo
 * \return valor do componente atual.
 */
string Tema::check(components value,cor_effect new_value){
	if( (component[value] != "" ) && (component[value]!=new_value) )  component[value]=new_value;
	return component[value];
}


string  Tema::key(cor new_value){ return check(TEMA_KEY,new_value); }            

string  Tema::bkg(cor new_value){ return check(TEMA_BKG,new_value ); }         

string  Tema::bld(effect new_value){ return check(TEMA_EFFECT,new_value); } 

string  Tema::bkg2(cor new_value){ return check(TEMA_BKG2,new_value ); }	



