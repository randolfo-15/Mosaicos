/*!*****************************************************
 *	\file effect.cpp
* \brief Arquivo de implementação efeitos
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/
#include "effect.hpp"

Hlg::Highlight(){}

Hlg::Highlight(std::string efc):Str(efc){}

Hlg Hlg::operator+(Hlg efc){ return Hlg(my_str()+SG+efc.my_str()); }

void Hlg::operator+=(Hlg efc){ buf.push_back(SG+efc); }

using namespace Efc;

Normal::Normal():Hlg("0"){}

Bold::Bold():Hlg("1"){} 

Dark::Dark():Hlg("2"){}

Italic::Italic():Hlg("3"){}

Underline::Underline():Hlg("4"){}

Blink::Blink():Hlg("5"){}

Reverse::Reverse():Hlg("7"){} 

Hidden::Hidden():Hlg("8"){}

Tachado::Tachado():Hlg("9"){}


