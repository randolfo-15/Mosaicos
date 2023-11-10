/*!*****************************************************
 *	\brief  Arquivo de definição de cores e recursos da lib
 *	\file colour.hpp
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/

#ifndef COLOUR_HPP
#define COLOUR_HPP

#include <iostream>
using colour = std::string;
using effect  = std::string;

//!	 Define a coloração de letras no terminal.
struct Foreground{
	
	/// Checa se uma string e um Foreground.
	static bool is_colour(colour);  
	
	static const colour                      
	
			 BLACK_KEY,                         ///< default
			 RED_KEY,                             ///< #F00
			 GREEN_KEY,                        ///< #0F0
			 YELLOW_KEY,                      ///< #FF0
			 BLUE_KEY,                           ///< #00F
			 MAGENT_KEY,                     ///< #F0F
			 CYAN_KEY,                           ///< #0FF
			 GRAY_LIGHT_KEY,              ///< #789 
			 RED_LIGHT_KEY,                 ///< #F66
             GREEN_LIGHT_KEY,            ///< #6F6
			 YELLOW_LIGHT_KEY,          ///< #FF6
			 BLUE_LIGHT_KEY,               ///< #66F
			 MAGENT_LIGHT_KEY,         ///< #F6F
			 CYAN_LIGHT_KEY,               ///< #6FF
			 WHITE_KEY,                          ///< #FFF
			 GRAY_KEY;                            ///< #666

	
};using Fg=Foreground; 

/// Define a coloração de background de uma letra.
struct Background{ 
	
	/// Checa se uma string e um Background.
	static bool is_colour(colour);
	
	static const colour
			 BLACK_BKG,                     ///< default
			 GRAY_LIGHT_BKG,           ///< #666
			 RED_LIGHT_BKG,             ///< #F66
             GREEN_LIGHT_BKG,        ///< #6F6
			 YELLOW_LIGHT_BKG,      ///< #FF6
			 BLUE_LIGHT_BKG,           ///< #66F
			 MAGENT_LIGHT_BKG,     ///< #F6F
			 CYAN_LIGHT_BKG,           ///< #6FF
             RED_BKG,                          ///< #F00
             GREEN_BKG,                     ///< #0F0
			 YELLOW_BKG,                   ///< #FF0
			 BLUE_BKG,                        ///< #00F
			 MAGENT_BKG,                  ///< #F0F
			 CYAN_BKG,                        ///< #0FF
			 WHITE_BKG,                      ///< #FFF
			 GRAY_BKG;                        ///< #333

	
};using  Bg=Background;

/// Define quais efeitos uma letra possui.
struct Effect{
	
	/// Checa se uma string e um efeito
	static bool is_effect(effect);
	
	static const effect
			ITALIC,
			 BLINK,
			 DEFAULT_BKG,
			 BOLD_KEY,
			 DARK,
			 UNDERLINE,
			 REVERSE,
			 HIDDEN,
			 TACHADO,
			 DEFAULT_KEY;

};using Ef=Effect;

#endif // colour.hpp
