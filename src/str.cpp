/*!*****************************************************
 *	\file str.cpp
* \brief Arquivo de implementação do modelo de string usado
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#include "str.hpp"

//----------------------------------------------------------------------------------
// Construir
//----------------------------------------------------------------------------------

Str::Str(){}

Str::Str(size_t size){buf.reserve(size);}

Str::Str(std::string new_str){buf.push_back(new_str);}

//----------------------------------------------------------------------------------
// Converter
//----------------------------------------------------------------------------------
std::string Str::my_str(std::string soma){
    for(auto str:buf) soma+=str;
    return soma;
}
//----------------------------------------------------------------------------------
// Adicionar
//----------------------------------------------------------------------------------
std::string Str::operator+(std::string new_str){ return my_str()+new_str; }
    
std::string operator+(std::string new_str,Str str){ return new_str+str.my_str(); }
    
//----------------------------------------------------------------------------------
// Atribuir
//----------------------------------------------------------------------------------
/*
void Str::operator=(std::string new_str){
    buf.clear();
    buf.push_back(new_str);
}
    
void Str::operator+=(std::string new_str){buf.push_back(new_str);}
*/
//----------------------------------------------------------------------------------
// Exibir
//----------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& out,Str str){ return out<<str.my_str(); }

//----------------------------------------------------------------------------------
// Get
//----------------------------------------------------------------------------------
std::string Str::operator()(){return my_str();}
