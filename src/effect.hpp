/*!*****************************************************
 *	\file effect.hpp
* \brief Arquivo de definição efeitos
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/
#ifndef EFFECT_HPP
#define EFFECT_HPP

#include "str.hpp"

class Highlight:public Str{

	public:
		Highlight();
	
		Highlight operator+(Highlight);
		void operator+=(Highlight);
	
	protected:
		const std::string SG=";";
		Highlight(std::string);
		
}; using Hlg=Highlight;

namespace Effect{
		struct Normal:public Highlight{Normal();};
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
