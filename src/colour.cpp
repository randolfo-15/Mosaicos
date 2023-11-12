/*!*****************************************************
 *	\brief  Implementa cores e efeitos da lib mosaicos
 *	\file colour.cpp
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/

#include "colour.hpp"

//------------------------------------------------------------------------------
// Effect
//------------------------------------------------------------------------------

///@{

/*!Conjunto de efeitos:*/
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

///@}		

/*!
 *  Nesta consulta buscamos uma string iniciada com ([) e que possui um
 *  segundo caracter que varia  entre 1 -9, ou  que seja 49,  ou  0  seguido
 *  por um (;39m), ou finalizado com (m).
*/
Ef::quest="[\[][1-9][m]|[\[][4][9][m]|[\[][0][\;][3][9][m]";

//------------------------------- Method -------------------------------

Ef::Effect():effects(){}
			 
Ef::Effect(effect efc):effects(efc){ *this=efc; }

void Ef::operator=(effect efc){ (is_effect(efc))?(this->efc=efc):throw ; }
			 
ostream& operator<<(ostream& out, const Ef& ef){return out<<ef.efc;}
			 
bool Ef::is_effect(effect str){ return (regex_match(str,regex(quest)))?true:false; }

//------------------------------------------------------------------------------
// Foreground
//------------------------------------------------------------------------------
///@{
colour
	
Fg::BLACK="\033[30m",                   ///< default
Fg::RED="\033[31m",                       ///< #F00
Fg::GREEN="\033[32m",                  ///< #0F0
Fg::YELLOW="\033[33m",                ///< #FF0
Fg::BLUE="\033[34m",                     ///< #00F
Fg::MAGENT="\033[35m",                     ///< #F0F
Fg::CYAN="\033[36m",                     ///< #0FF
Fg::GRAY_LIGHT="\033[37m",              ///< #789 
Fg::RED_LIGHT="\033[91m",                 ///< #F66
Fg::GREEN_LIGHT="\033[92m",            ///< #6F6
Fg::YELLOW_LIGHT="\033[93m",          ///< #FF6
Fg::BLUE_LIGHT="\033[94m",               ///< #66F
Fg::MAGENT_LIGHT="\033[95m",         ///< #F6F
Fg::CYAN_LIGHT="\033[96m",               ///< #6FF
Fg::WHITE="\033[97m",                     ///< #FFF
Fg::GRAY="\033[90m",                       ///< #666
///@}

/*!
*  Nossa consulta consiste de  um termo iniciado com ([) seguido
*  por  um  caracter  que  varia  entre 3 e 9  e  por  outra caracter
*  que pode ser  qualquer  termo  entre  0 e 7  finalizando com (m). 
*/
Fg::quest="[\[][39][0-7][m]";

//------------------------------- Method -------------------------------

Fg::Foreground():colors(Ef::DEFAULT_KEY){}
			 
Fg::Foreground(colour clr):colors(clr){ *this=clr; }

void Fg::operator=(effect clr){ (is_colour(clr))?(this->clr=clr):throw ; }
			 
ostream& operator<<(ostream& out, const Fg& frg){return out<<frg.clr;}

bool Fg::is_colour(colour str){ return (regex_match(str,regex(quest)))?true:false; }

//------------------------------------------------------------------------------
// Background
//------------------------------------------------------------------------------
///@{
colour 

Bg::BLACK="\033[40m",                ///< default
Bg::GRAY_LIGHT="\033[47m",           ///< #666
Bg::RED_LIGHT="\033[101m",           ///< #F66
Bg::GREEN_LIGHT="\033[102m",      ///< #6F6
Bg::YELLOW_LIGHT="\033[103m",    ///< #FF6
Bg::BLUE_LIGHT="\033[104m",          ///< #66F
Bg::MAGENT_LIGHT="\033[105m",    ///< #F6F
Bg::CYAN_LIGHT="\033[106m",          ///< #6FF
Bg::RED="\033[41m",                      ///< #F00
Bg::GREEN="\033[42m",                 ///< #0F0
Bg::YELLOW="\033[43m",               ///< #FF0
Bg::BLUE="\033[44m",                     ///< #00F
Bg::MAGENT="\033[45m",                    ///< #F0F
Bg::CYAN="\033[46m",                     ///< #0FF
Bg::WHITE="\033[107m",                 ///< #FFF
Bg::GRAY="\033[100m",                   ///< #333
///@}

/*!
 *  Nesta consulta buscamos uma string iniciada com ([)
 *  seguida por 4 ou 10 e por um outro numero que varia 
 *  de 0 - 7finalizado com .
 */
Bg::quest="[\[][1][0][0-7][m]|[\]][4][0-7][m]";

//------------------------------- Method -------------------------------

Bg::Background():colors(Ef::DEFAULT_BKG){}
			 			 
Bg::Background(colour clr):colors(clr){ *this=clr; }

void Bg::operator=(colour clr){ (is_colour(clr))?(this->clr=clr):throw ; }
			 
ostream& operator<<(ostream& out, const Bg& bkg){return out<<bkg.clr;}
			 
bool Bg::is_colour(colour str){ return (regex_match(str,regex(quest)))?true:false; }	

