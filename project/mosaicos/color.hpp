/*
 * Arquivo de definição de cores e recursos da lib
 *
 */

#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::ostream;

#include <vector>
using std::vector;

namespace COR{
	namespace KEY{
			 const string 
			 BLACK_KEY="\033[30m",
			 RED_KEY="\033[31m",
             GREEN_KEY="\033[32m",
			 YELLOW_KEY="\033[33m",
			 BLUE_KEY="\033[34m",
			 MAGENT_KEY="\033[35m",
			 CYAN_KEY="\033[36m",
			 GRAY_LIGHT_KEY="\033[37m",
			 RED_LIGHT_KEY="\033[91m",
             GREEN_LIGHT_KEY="\033[92m",
			 YELLOW_LIGHT_KEY="\033[93m",
			 BLUE_LIGHT_KEY="\033[94m",
			 MAGENT_LIGHT_KEY="\033[95m",
			 CYAN_LIGHT_KEY="\033[96m",
			 WHITE_KEY="\033[97m",
			 GRAY_KEY="\033[90m";
	}
	namespace BKG{
             const string
			 BLACK_BKG="\033[40m",
			 GRAY_LIGHT_BKG="\033[47m",
			 RED_LIGHT_BKG="\033[101m",
             GREEN_LIGHT_BKG="\033[102m",
			 YELLOW_LIGHT_BKG="\033[103m",
			 BLUE_LIGHT_BKG="\033[104m",
			 MAGENT_LIGHT_BKG="\033[105m",
			 CYAN_LIGHT_BKG="\033[106m",
             RED_BKG="\033[41m",
             GREEN_BKG="\033[42m",
			 YELLOW_BKG="\033[43m",
			 BLUE_BKG="\033[44m",
			 MAGENT_BKG="\033[45m",
			 CYAN_BKG="\033[46m",
			 WHITE_BKG="\033[107m",
			 GRAY_BKG="\033[100m";
	}
	namespace EFFECT{
			const string 
			 ITALIC="\033[3m",
			 BLINK="\033[5m",
			 DEFAULT_BKG="\033[49m",
			 BOLD_KEY="\033[1m",
			 DARK="\033[2m",
			 UNDERLINE="\033[4m",
			 REVERSE="\033[7m",
			 HIDDEN="\033[8m",
			 TACHADO="\033[9m",
			 DEFAULT_KEY="\033[0;39m";
	}
}

using cor=std::string;
using cor_effect=std::string;
using effect=std::string;

namespace color{
	using namespace COR::BKG;
	using namespace COR::KEY;
	using namespace COR::EFFECT;
}

#endif // color.hpp
