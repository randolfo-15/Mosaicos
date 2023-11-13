/*!***************************************************************
 *	\brief  Arquivo de definição Foreground Background e Efeitos.
 *	\file colour.hpp
 * \author Randolfo Augusto
 * \date 20/09/22
 *****************************************************************/

#ifndef COLOUR_HPP
#define COLOUR_HPP

struct Colour{
	using nivel= unsigned char;
	using nivel_red=unsigned char;
	using nivel_green=unsigned char;
	using nivel_blue=unsigned char;
		
		const nivel MAX=255;
		
		Colour();
		Colour(nivel_red,nivel_blue,nivel_green);
		
		nivel  red=MAX,
				  green=MAX,
				  blue=MAX;
	private:	
		
		//int media();
		//Luminosidade:
		//void contrast(nivel);   ///< Set → brilho
		//nivel contrast();           ///< Get ← brilho
	
	// +,-,+=,-=,[] -> suporte a operadores
		
};using Clr = Colour;

namespace  Colors {
	
struct Red:public Colour{ Red();};
struct Green:public Colour{ Green();};
struct Blue:public Colour{ Blue();};

struct Yellow:public Colour{ Yellow();};
struct Magenta:public Colour{ Magenta();};
struct Cyan:public Colour{Cyan();};

struct White:public Colour{ White();};
struct Black:public Colour{ Black();};
struct Gray:public Colour{Gray();};

};namespace Cls =Colors;

#endif // colour.hpp
