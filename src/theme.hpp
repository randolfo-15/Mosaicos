/*!*****************************************************
 *	\file theme.hpp
*	\brief  Arquivo de definição de temas das janelas.
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/
 
#ifndef THEME_HPP
#define THEME_HPP

//#include <exception>

//#include <color.hpp>
#include "colour.hpp"
#include "foreground.hpp"
#include "background.hpp"
	
/// Define um conjunto de cores e comportamentos de uma janela.
class Theme{
	/// Paleta de cores que define o tema
	Foreground my_key   = Colors::White();
	Background my_bkg  = Colors::Blue();
	Background my_bkg2= Colors::Red();
	Highlight      my_efc    = Effect::Bold();
		
	public:		
		/// Construtor padrão.
		Theme();                                                                              
		
		/// Construtor custumizado. 
		Theme(
			Foreground key,
		    Background bkg,
			Background bkg2,
		    Highlight efc
		);  
		
		Foreground key();      ///< (Get) padrão para foreground. 
		Background bkg();     ///< (Get) padrão para background. 
		Background bkg2();   ///< (Get) padrão para o modo seleção. 
		Highlight eft();            ///< (Get) padrão para efeitos.
		
		void key(Foreground);      ///< (Set) padrão para foreground. 
		void bkg(Background);     ///< (Set) padrão para background. 
		void bkg2(Background);   ///< (Set) padrão para o modo seleção. 
		void eft(Highlight);            ///< (Set) padrão para efeitos.
		
};using Tm=Theme;

#endif // theme.hpp
