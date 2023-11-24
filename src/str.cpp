/*!*****************************************************
 *	\file str.cpp
* \brief Arquivo de implementação do modelo de string usado
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#include "str.hpp"
using std::string;

//----------------------------------------------------------------------------------
// Build
//----------------------------------------------------------------------------------

Str::Str(){}

Str::Str(size_t size){buf.resize(size);}

Str::Str(string new_str){buf.push_back(new_str);}

//----------------------------------------------------------------------------------
// Cast
//----------------------------------------------------------------------------------
string Str::str(){
    string soma;
    for(auto st:buf) soma+=st;
    return soma; 
}

//----------------------------------------------------------------------------------
// Addition
//----------------------------------------------------------------------------------
string Str::operator+(string new_str){ return str()+new_str; }
    
string operator+(string new_str,Str st){ return new_str+st.str(); }

void Str::operator+=(string st){ buf.push_back(st); }
        
//----------------------------------------------------------------------------------
// Show
//----------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& out,Str st){ return out<<st.str(); }

