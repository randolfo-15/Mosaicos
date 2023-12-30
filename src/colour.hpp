/*!***************************************************************
 *	\brief  Arquivo de definição Foreground Background e Efeitos.
 *	\file colour.hpp
 * \author Randolfo Augusto
 * \date 20/09/22
 *****************************************************************/
#ifndef COLOUR_HPP
#define COLOUR_HPP

#include "gd_rag.hpp"
#include <string>

using nivel= unsigned char;
using nivel_red=unsigned char;
using nivel_green=unsigned char;
using nivel_blue=unsigned char;

struct Colour{
	friend Ground;
//------------------------------------------------------------------------------------------------
//  Build
//------------------------------------------------------------------------------------------------
public:
	Colour();
	Colour(nivel_red,nivel_blue,nivel_green);

//-------------------------------------
// Setting
//-------------------------------------
public:
	void red(nivel);
	void green(nivel);
	void blue(nivel);
//-------------------------------------
// Getting
//-------------------------------------
public:
	nivel red(); 
	nivel green();
	nivel blue();
//------------------------------------------------------------------------------------------------
//  Operator
//------------------------------------------------------------------------------------------------
public:
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
//------------------------------------------------------------------------------------------------
//  Field
//------------------------------------------------------------------------------------------------
public:
	static const nivel 
		MAX,
		MIN,
		HALF,
	    BASE;

protected:	
	enum  RGB{RED,GREEN,BLUE};

	nivel rgb[3]={MAX,MAX,MAX};	
	static const nivel pixel[3];
//------------------------------------------------------------------------------------------------
// Calculation
//------------------------------------------------------------------------------------------------
private:
	nivel check(short);																							 ///< Verifica o Max, e Min aceito para uma cor
	
	Colour sum(const nivel*,const nivel*,bool,Colour=Colour(),int=0);	  	///< Somatorio de propriedades das cores.
//------------------------------------------------------------------------------------------------
// Cast
//------------------------------------------------------------------------------------------------
private:
	std::string to_str(int=0);																					///< Cast de cilour para Str
		
};using Clr = Colour;

//------------------------------------------------------------------------------------------------
// Derived
//------------------------------------------------------------------------------------------------
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
