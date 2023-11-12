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

	
/// Define um conjunto de cores e comportamentos de uma janela.
class Theme{
	/// Paleta de cores que define o tema
	Fg my_key   = Fg::WHITE;
	Bg my_bkg  = Bg::BLUE;
	Bg my_bkg2= Bg::RED;
	Ef  my_efc    = Ef::BOLD_KEY;
		
	public:		
		/// Construtor padrão.
		Theme();                                                                              
		
		/// Construtor custumizado. 
		Theme(
			Foreground key,
		    Background bkg,
			Background bkg2,
		    Effect efc
		);  
		
		Foreground key();      ///< (Get) padrão para foreground. 
		Background bkg();     ///< (Get) padrão para background. 
		Background bkg2();   ///< (Get) padrão para o modo seleção. 
		Effect eft();                   ///< (Get) padrão para efeitos.
		
		void key(Foreground);      ///< (Set) padrão para foreground. 
		void bkg(Background);     ///< (Set) padrão para background. 
		void bkg2(Background);   ///< (Set) padrão para o modo seleção. 
		void eft(Effect);                   ///< (Set) padrão para efeitos.
		
};using Tm=Theme;

#endif // theme.hpp
