/*!*****************************************************
 *	\file effect.hpp
* \brief Arquivo de definição efeitos
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/
#ifndef EFFECT_HPP
#define EFFECT_HPP

#include "str.hpp"
#include <vector>

class Highlight:public Str{
	public:
		const char SG[2]=";";
	
		Highlight();
	
		Highlight operator+(Highlight);
		void operator+=(Highlight);
	
	protected:
		Highlight(std::string);
}; using Hl=Highlight;

namespace Effect{

		struct Italic: public Highlight{ Italic(); };
		struct Blink: public Highlight{ Blink(); };
		struct Bold: public  Highlight{ Bold(); }; 
		struct Dark: public  Highlight{Dark(); };
		struct Hidden:public Highlight{ Hidden(); };
		struct Reverse:public Highlight{ Reverse(); };
		struct Tachado:public Highlight{Tachado(); };
		struct Underline:public Highlight{Underline(); };
			
} namespace Efc = Effect;

#endif //effect.hpp
