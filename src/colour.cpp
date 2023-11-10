/*!*****************************************************
 *	\brief  Implementa cores e efeitos da lib mosaicos
 *	\file colour.cpp
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/

#include "colour.hpp"
	
bool Bg::is_colour(colour){ return true; }	

bool Fg::is_colour(colour){ return true; }
	
bool Ef::is_effect(effect){ return true; }


const colour
	
//Foreground

            Fg::BLACK_KEY="\033[30m",                         ///< default
            Fg::RED_KEY="\033[31m",                             ///< #F00
            Fg::GREEN_KEY="\033[32m",                        ///< #0F0
            Fg::YELLOW_KEY="\033[33m",                      ///< #FF0
            Fg::BLUE_KEY="\033[34m",                           ///< #00F
            Fg::MAGENT_KEY="\033[35m",                     ///< #F0F
            Fg::CYAN_KEY="\033[36m",                           ///< #0FF
            Fg::GRAY_LIGHT_KEY="\033[37m",              ///< #789 
            Fg::RED_LIGHT_KEY="\033[91m",                 ///< #F66
            Fg::GREEN_LIGHT_KEY="\033[92m",            ///< #6F6
            Fg::YELLOW_LIGHT_KEY="\033[93m",          ///< #FF6
            Fg::BLUE_LIGHT_KEY="\033[94m",               ///< #66F
            Fg::MAGENT_LIGHT_KEY="\033[95m",         ///< #F6F
            Fg::CYAN_LIGHT_KEY="\033[96m",               ///< #6FF
            Fg::WHITE_KEY="\033[97m",                          ///< #FFF
            Fg::GRAY_KEY="\033[90m",                             ///< #666

// Background
			
			 Bg::BLACK_BKG="\033[40m",                     ///< default
			 Bg::GRAY_LIGHT_BKG="\033[47m",           ///< #666
			 Bg::RED_LIGHT_BKG="\033[101m",           ///< #F66
             Bg::GREEN_LIGHT_BKG="\033[102m",      ///< #6F6
			 Bg::YELLOW_LIGHT_BKG="\033[103m",    ///< #FF6
			 Bg::BLUE_LIGHT_BKG="\033[104m",          ///< #66F
			 Bg::MAGENT_LIGHT_BKG="\033[105m",    ///< #F6F
			 Bg::CYAN_LIGHT_BKG="\033[106m",          ///< #6FF
             Bg::RED_BKG="\033[41m",                            ///< #F00
             Bg::GREEN_BKG="\033[42m",                       ///< #0F0
			 Bg::YELLOW_BKG="\033[43m",                     ///< #FF0
			 Bg::BLUE_BKG="\033[44m",                          ///< #00F
			 Bg::MAGENT_BKG="\033[45m",                    ///< #F0F
			 Bg::CYAN_BKG="\033[46m",                          ///< #0FF
			 Bg::WHITE_BKG="\033[107m",                      ///< #FFF
			 Bg::GRAY_BKG="\033[100m";                        ///< #333

			 const effect 
			 
// EFFECT
			 Ef::ITALIC="\033[3m",
			 Ef::BLINK="\033[5m",
			 Ef::DEFAULT_BKG="\033[49m",
			 Ef::BOLD_KEY="\033[1m",
			 Ef::DARK="\033[2m",
			 Ef::UNDERLINE="\033[4m",
			 Ef::REVERSE="\033[7m",
			 Ef::HIDDEN="\033[8m",
			 Ef::TACHADO="\033[9m",
			 Ef::DEFAULT_KEY="\033[0;39m";
	
