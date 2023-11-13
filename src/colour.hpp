/*!***************************************************************
 *	\brief  Arquivo de definição Foreground Background e Efeitos.
 *	\file colour.hpp
 * \author Randolfo Augusto
 * \date 20/09/22
 *****************************************************************/

#ifndef COLOUR_HPP
#define COLOUR_HPP

class Colour{
	public:
		using nivel= unsigned char;
		enum tons{RED,GREEN,BLUE,MAX=255,MIN=0};

		nivel tom[3];

		static bool check(nivel);
	
	private:
			//int media();
			
	public: 
		
		Colour();
		Colour(nivel,nivel,nivel);
	
		// Tonalidade
		void red(nivel);        ///< Set → red;
		void green(nivel);   ///< Set → green
		void blue(nivel);      ///< Set → blue
	
		nivel red();               ///< Get ← red
		nivel green();          ///< Get  ← green
		nivel blue();            ///< Get   ← blue
	
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
