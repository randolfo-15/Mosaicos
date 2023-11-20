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
	bgs.resize(1);
	fgs.resize(1);
}

Tm::Theme(Bg new_bg,Fg new_fg){
	fgs.push_back(new_fg);
	bgs.push_back(new_bg);
}

Tm::Theme(Bgs baks,Fgs fors){
	bgs.assign(baks.begin(),baks.end());
	fgs.assign(fors.begin(),fors.end());
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
		
//--------------------------------------------------------------
// Show
//--------------------------------------------------------------		
std::ostream& operator<<(std::ostream& out,Theme tm){ return out<<tm.bgs[0]<<tm.fgs[0]; }
