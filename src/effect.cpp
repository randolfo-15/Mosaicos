/*!*****************************************************
 *	\file effect.cpp
* \brief Arquivo de implementação efeitos
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/
#include "effect.hpp"

/* 

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


Hl::Highlight(){}

Hl::Highlight(std::string efc):Str(efc){}

Hl Hl::operator+(Hl efc){ return Hl(my_str()+SG+efc.my_str()); }

void Hl::operator+=(Hl efc){ buf.push_back(SG+efc); }
