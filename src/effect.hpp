/*!*****************************************************
 *	\file effect.hpp
* \brief Arquivo de definição efeitos
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/
#ifndef EFFECT_HPP
#define EFFECT_HPP

#include "gd_rag.hpp"
#include <string>
#include <vector>

class Highlight{
	friend Ground;
//------------------------------------------------------------------------------------------------
//  Build
//------------------------------------------------------------------------------------------------
public:			Highlight();
protected: 	Highlight(int);
//------------------------------------------------------------------------------------------------
// Find
//------------------------------------------------------------------------------------------------
private: int find(int,int=0);
//------------------------------------------------------------------------------------------------
// Operator
//------------------------------------------------------------------------------------------------	
//-------------------------------------
// Addition
//-------------------------------------
public:
	virtual Highlight operator+(Highlight);
	virtual void operator+=(Highlight);
//-------------------------------------
// Subtration
//-------------------------------------
public:
	virtual Highlight operator-(Highlight);
	virtual void operator-=(Highlight);
//-------------------------------------
// Assign
//-------------------------------------
	virtual void operator=(Highlight);
//-------------------------------------
// Cast
//-------------------------------------
private: std::string to_str(std::string="");
//------------------------------------------------------------------------------------------------
// Field
//------------------------------------------------------------------------------------------------	
private:std::vector<int> buff;

}; using Hlg=Highlight;
//------------------------------------------------------------------------------------------------
// Derivation
//------------------------------------------------------------------------------------------------	
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
