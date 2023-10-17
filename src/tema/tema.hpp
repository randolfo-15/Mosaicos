 /*
  * Arquivo que define a estrutura de temas usado pelos mosaicos 
  *
  */
 
#ifndef TEMA_HPP
#define TEMA_HPP

#include "color.hpp"

class Tema{
	string key_tm,        // →key
		        bkg_tm,       // →bakyground
				bld_tm,        // →bold
		        bkg2_tm      // →2° backgound
	; 

	public:		
		Tema();
		Tema(cor_effect key,cor bkg,cor bkg2,effect bold);
		
		string  key(string str="");
		string  bkg(string str="");
		string  bld(string str="");
		string  bkg2(string str="");	
};

#endif // tema.hpp
