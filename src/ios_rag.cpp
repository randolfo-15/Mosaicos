/*!*****************************************************
 *	\file ios_rag.cpp
* \brief Arquivo de implementação da classe __IO__
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#include "ios_rag.hpp"
using std::cout;
using std::to_string;

IOs::IOs(){}
    
void left(int n){ cout<<"\033["+to_string(n)+"D";}
void rigth(int n){ cout<<"\033["+to_string(n)+"C";}
void down(int n){ cout<<"\033["+to_string(n)+"B";}
void up(int n){ cout<<"\033["+to_string(n)+"A";}

void point(int m,int n){ cout<<"\033["+to_string(n)+";"+to_string(n)+"H";}
