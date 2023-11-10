/*!*****************************************************
 *	\file theme.hpp
*	\brief  Arquivo de definição de temas das janelas.
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/
 
#ifndef THEME_HPP
#define THEME_HPP

//#include <color.hpp>
#include "colour.hpp"
using colors=std::string;

/// Define o número de atributos de tema
constexpr int attributes=4; 

/// enumerador simbolico do conjunto de componentes de tema.
enum  components{
		TM_KEY,            ///< Foreground
		TM_BKG,           ///< Bakyground
		TM_BKG2,          ///< Bakyground modo seleção
		TM_EFFECT        ///< Efeito
	
};
	
/// Define um conjunto de cores e comportamentos de uma janela.
class Theme{
	/// Paleta de cores que define o tema
	colors palette[attributes]{
		Fg::WHITE_KEY,
		Bg::BLUE_BKG,
		Bg::RED_BKG,
		Ef::BOLD_KEY
		
	};
	
	public:		
		/// Construtor padrão.
		Theme();                                                                              
		
		/// Construtor custumizado. 
		Theme(colour key,colour bkg,colour bkg2,effect efc);  
		
		colour key();              ///< (Get) padrão para foreground. 
		colour bkg();             ///< (Get) padrão para background. 
		effect  eft();               ///< (Get) padrão para efeitos.
		colour bkg2();           ///< (Get) padrão para o modo seleção. 
		
		
		void key(colour);      ///< (Set) padrão para foreground. 
		void bkg(colour);     ///< (Set) padrão para background. 
		void eft(effect);        ///< (Set) padrão para efeitos.
		void bkg2(colour);   ///< (Set) padrão para o modo seleção. 
};using Tm=Theme;

#endif // theme.hpp
