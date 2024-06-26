/*!*****************************************************
 *	\file clear.cpp
* \brief Arquivo de implementação da classe __Clear__
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#include "clear_rag.hpp"
#include "directions_rag.hpp"
using std::string;

string Clear::flag=" ";

//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------
Clear::Clear(char cr){flag=cr;}

//------------------------------------------------------------------------------------------------
// Methods
//------------------------------------------------------------------------------------------------
string  Clear::total(){ return "\033[2"+flag; }

string Clear::part(){return "\033[1"+flag;}

string Clear::part(int n){
    std::cout<<Up(n);
    return "\033[0"+flag;
}

std::ostream& operator<<(std::ostream& out,Clear cl){ return out<<cl.total();}

//------------------------------------------------------------------------------------------------
// Derived
//------------------------------------------------------------------------------------------------

C_sn::Clear_screen():Clear('J'){}
C_ln::Clear_line():Clear('K'){}
