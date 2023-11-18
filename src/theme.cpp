/*!*****************************************************
 *	\file theme.cpp
 *	\brief  Arquivo de implementação da classe tema
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/

#include "theme.hpp" 
#include "colour.hpp"
using std::string;
using Bgs=std::initializer_list<Bg>;
using Fgs=std::initializer_list<Fg>;

//--------------------------------------------------------------
// Build
//--------------------------------------------------------------
Tm::Theme(){
	fgs[0]=Cls::White();
	bgs[0]=Cls::Blue();
}

Tm::Theme(Fg new_fg,Bg new_bg){
	fgs.push_back(new_fg);
	bgs.push_back(new_bg);
}

Tm::Theme(Bgs baks,Fgs fors){
	bgs.assign(baks.begin(),baks.end());
	bgs.assign(fors.begin(),fors.end());
}

//--------------------------------------------------------------
// Getting
//--------------------------------------------------------------
Fg Tm::fg(int i){ return fgs[i];  }              
		
Bg Tm::bg(int i){ return bgs[i]; }
		
//--------------------------------------------------------------
// Setting
//--------------------------------------------------------------
void Tm::fg(Hlg efc,int i){ fgs[i]=efc; }      
		
void Tm::fg(Clr clr,int i){ fgs[i]=clr; }
		
void Tm::bg(Clr clr,int i){bgs[i]=clr;}      
		

