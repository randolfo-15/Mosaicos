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
#include "effect.hpp"
#include "foreground.hpp"
#include "background.hpp"
	
/// Define um conjunto de cores e comportamentos de uma janela.
class Theme{
	/// Paleta de cores que define o tema
	Foreground my_key   = Colors::White();
	Background my_bkg  = Colors::Blue();
	Background my_bkg2= Colors::Red();

		
	public:		
		/// Construtor padrão.
		Theme();                                                                              
		
		/// Construtor custumizado. 
		Theme(
			Foreground key,
		    Background bkg,
			Background bkg2
		);  
		
		std::string key();      ///< (Get) padrão para foreground. 
		std::string bkg();     ///< (Get) padrão para background. 
		std::string bkg2();   ///< (Get) padrão para o modo seleção. 
		
		void key(Highlight);  ///< (Set) padrão para foreground. 
		void key(Colour);       ///< (Set) modificar a cor da letra.
		
		void bkg(Colour);            ///< (Set) padrão para background. 
		void bkg2(Colour);         ///< (Set) padrão para o modo seleção. 

};using Tm=Theme;

#endif // theme.hpp
