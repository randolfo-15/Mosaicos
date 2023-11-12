/*!***************************************************************
 *	\brief  Arquivo de definição Foreground Background e Efeitos.
 *	\file colour.hpp
 * \author Randolfo Augusto
 * \date 20/09/22
 *****************************************************************/

#ifndef COLOUR_HPP
#define COLOUR_HPP

#include <ostream>
using std::ostream;

#include <regex>
using std::regex;
using std::regex_match;

#include <string>
using effect  =const std::string;
using nivel= unsigned char;

class Colour{
public: 
	/*
	colour                      
		BLACK,                   ///< default
		RED,                        ///< #F00
		GREEN,                   ///< #0F0
		YELLOW,                ///< #FF0
		BLUE,                     ///< #00F
		MAGENTA,            ///< #F0F
		CYAN,                     ///< #0FF
		WHITE,                    ///< #FFF
		GRAY;                      ///< #666
	*/
	//bool is_colour(colors);
	//static const std::string quest;
	
	void red(nivel);
	void green(nivel);
	void blue(nivel);
	nivel red();
	nivel green();
	nivel blue();
	void contrast(nivel);
	nivel contrast();
	
	// +,-,+=,-=,[] -> suporte a operadores
	
};using Clr = Colour;

namespace  Colors {
struct Red:public Colour{Red();};
struct Green:public Colour{Green();};
struct Blue:public Colour{Blue();};
struct White:public Colour{White();};

	
};namespace Cls =Colors;

//------------------------------------------------------------------------------
// Effect
//------------------------------------------------------------------------------

/// Define quais efeitos uma letra possui.
struct Highlight{ 
	Highlight(effect); 
	
}; using Hl=Highlight;

namespace Effect{

		class Italic: public Highlight{};
		class Blink: public Highlight{};
		class Bold: public  Highlight{}; 
		class Dark: public  Highlight{};
		class Hidden:public Highlight{};
		class Reverse:public Highlight{};
		class Tachado:public Highlight{};
		class Underline:public Highlight{};
		
} namespace Efc = Effect;

#endif // colour.hpp
