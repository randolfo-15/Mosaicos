/*!***************************************************************
 *	\brief  Arquivo de definição Foreground Background e Efeitos.
 *	\file colour.hpp
 * \author Randolfo Augusto
 * \date 20/09/22
 *****************************************************************/
#ifndef COLOUR_HPP
#define COLOUR_HPP

#include <string>

struct Colour{
	
	using nivel= unsigned char;
	using nivel_red=unsigned char;
	using nivel_green=unsigned char;
	using nivel_blue=unsigned char;
		
	Colour();
	
	Colour(nivel_red,nivel_blue,nivel_green);
	
	void red(nivel);
	void green(nivel);
	void blue(nivel);
	
	nivel red(); 
	nivel green();
	nivel blue();
	
	virtual Colour operator+(Colour);
	virtual Colour operator+(nivel);
	virtual void operator+=(Colour);
	virtual void operator+=(nivel);
	virtual void operator++();
	virtual void operator++(int); 
	
	virtual Colour operator-(Colour);
	virtual Colour operator-(nivel);
	virtual void operator-=(Colour);
	virtual void operator-=(nivel);
	virtual void operator--();
	virtual void operator--(int);
	
	virtual void operator=(Colour);
	
	
	protected:
		enum  RGB{RED,GREEN,BLUE};
		
		static const nivel 
		MAX,
		MIN,
		HALF,
	    BASE;
		
	private:
		/// Verifica o Max, e Min aceito para uma cor
		nivel check(short);
		
		/// Somatorio de propriedades das cores.
		Colour sum(const nivel*,const nivel*,bool,Colour=Colour(),int=0); 

		static const nivel pixel[3];
		
		protected: nivel rgb[3]={MAX,MAX,MAX};
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
