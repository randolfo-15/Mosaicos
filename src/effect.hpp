/*!*****************************************************
 *	\file effect.hpp
* \brief Arquivo de definição efeitos
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/
#ifndef EFFECT_HPP
#define EFFECT_HPP

#include "str.hpp"

/*
effect 

Ef::ITALIC="\033[3m",
Ef::BLINK="\033[5m",
Ef::DEFAULT_BKG="\033[49m",
Ef::BOLD_KEY="\033[1m",
Ef::DARK="\033[2m",
Ef::UNDERLINE="\033[4m",
Ef::REVERSE="\033[7m",
Ef::HIDDEN="\033[8m",
Ef::TACHADO="\033[9m",
Ef::DEFAULT_KEY="\033[0;39m",
*/



struct Highlight:public Str{
public:
	Highlight();
	
	// ... ?
	
}; using Hl=Highlight;

namespace Effect{

		struct Italic: public Highlight{};
		struct Blink: public Highlight{};
		struct Bold: public  Highlight{}; 
		struct Dark: public  Highlight{};
		struct Hidden:public Highlight{};
		struct Reverse:public Highlight{};
		struct Tachado:public Highlight{};
		struct Underline:public Highlight{};
			
} namespace Efc = Effect;

#endif //effect.hpp
