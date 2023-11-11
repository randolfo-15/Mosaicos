/*!***************************************************************
 *	\brief  Arquivo de definição Foreground Background e Efeitos.
 *	\file colour.hpp
 * \author Randolfo Augusto
 * \date 20/09/22
 *****************************************************************/

#ifndef COLOUR_HPP
#define COLOUR_HPP

#include <ostream>
#include <regex>
using std::regex;
using std::regex_match;

#include <iostream>
using colour =const std::string;
using effect  =const std::string;
using effects  =std::string;
using colors = std::string;
using std::ostream;

/// Define quais efeitos uma letra possui.
struct Effect{
	
	/// Checa se uma string e um efeito
	static bool is_effect(effect);
	
	static  effect
	
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
	
			 Effect();
			 
			 Effect(effect);
			 
			 void operator=(effect);
			 
			 effect cast_str();
			 
	private: 
		/// Modelo de pesquisa regex.
		static const std::string quest; 
		
		/// Define um efeito.
		effects efc;
		
		friend ostream& operator<<(ostream& , const Effect&);
		
};using Ef=Effect;

/// Imprime em cout um efeito.
ostream& operator<<(ostream& , const Effect&);

//!	 Define a coloração de letras no terminal.
struct Foreground{
	
	/// Checa se uma string e um Foreground.
	static bool is_colour(colour);  
	
	static  colour                      
	
			 BLACK,                   ///< default
			 RED,                        ///< #F00
			 GREEN,                   ///< #0F0
			 YELLOW,                ///< #FF0
			 BLUE,                     ///< #00F
			 MAGENT,                     ///< #F0F
			 CYAN,                     ///< #0FF
			 GRAY_LIGHT,              ///< #789 
			 RED_LIGHT,                 ///< #F66
             GREEN_LIGHT,            ///< #6F6
			 YELLOW_LIGHT,          ///< #FF6
			 BLUE_LIGHT,               ///< #66F
			 MAGENT_LIGHT,         ///< #F6F
			 CYAN_LIGHT,               ///< #6FF
			 WHITE,                    ///< #FFF
			 GRAY;                      ///< #666

			 Foreground();
			 
			 Foreground(colour);
			 
			 void operator=(colour);
			 
			 colour cast_str();
			 
			 private: 
				
				 /// Modelo de pesquisa regex.
				 static const std::string quest; 
			
				/// Define  um background
				 colors clr=Ef::DEFAULT_KEY;
	
				 friend ostream& operator<<(ostream& , const Foreground&);
				 
};using Fg=Foreground; 

ostream& operator<<(ostream& , const Foreground&);

/// Define a coloração de background de uma letra.
struct Background{ 
	
	/// Checa se uma string e um Background.
	static bool is_colour(colour);
	
	static  colour
	
			 BLACK,                ///< default
			 GRAY_LIGHT,           ///< #666
			 RED_LIGHT,             ///< #F66
             GREEN_LIGHT,        ///< #6F6
			 YELLOW_LIGHT,      ///< #FF6
			 BLUE_LIGHT,           ///< #66F
			 MAGENT_LIGHT,     ///< #F6F
			 CYAN_LIGHT,           ///< #6FF
             RED,                    ///< #F00
             GREEN,               ///< #0F0
			 YELLOW,             ///< #FF0
			 BLUE,                   ///< #00F
			 MAGENT,                  ///< #F0F
			 CYAN,                   ///< #0FF
			 WHITE,                 ///< #FFF
			 GRAY;                   ///< #333
			
			 Background();
			 
			 Background(colour);
			 
			 void operator=(colour);
			
			 colour cast_str();
			 
			 private: 
				/// Modelo de pesquisa regex.
				 static const std::string quest;
				 
				 colors clr=Ef::DEFAULT_BKG;

				 friend ostream& operator<<(ostream& , const Background&);
				 
};using  Bg=Background;

ostream& operator<<(ostream& , const Background&);

#endif // colour.hpp
