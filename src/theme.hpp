/*!*****************************************************
 *	\file theme.hpp
*	\brief  Arquivo de definição de temas das janelas.
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/
 
#ifndef THEME_HPP
#define THEME_HPP

#include "colour.hpp"
#include "effect.hpp"
#include "foreground.hpp"
#include "background.hpp"
	
/// Define um conjunto de cores e comportamentos de uma janela.
class Theme{
	/// Paleta de cores que define o tema
	Foreground my_key   = Colors::White();
	Background my_bkg1= Colors::Blue();
	Background my_bkg2= Colors::Red();

		
	public:		
		/// Construtor padrão.
		Theme();                                                                              
		
		/// Construtor custumizado. 
		Theme(
			Foreground key,
		    Background bkg1,
			Background bkg2
		);  
		
		Foreground key();        ///< (Get) padrão para foreground. 
		Background bkg1();     ///< (Get) padrão para background. 
		Background bkg2();     ///< (Get) padrão para o modo seleção. 
		
		void key(Highlight);  ///< (Set) padrão para foreground. 
		void key(Colour);       ///< (Set) modificar a cor da letra.
		
		void bkg1(Colour);            ///< (Set) padrão para background. 
		void bkg2(Colour);         ///< (Set) padrão para o modo seleção. 

};using Tm=Theme;

#endif // theme.hpp
