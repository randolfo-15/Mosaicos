/*!*****************************************************
 *	\file clear_rag.hpp
* \brief Arquivo de definição da classe __Directions__
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#ifndef CLEAR_RAG_HPP
#define CLEAR_RAG_HPP

#include <string>
#include <ostream>
#include <iostream>
#include "directions_rag.hpp"

struct Clear{
    static std::string  total();
    static std::string part();
    static std::string part(int);
    
    friend std::ostream& operator<<(std::ostream&,Clear);
    protected:
        static std::string flag;
        Clear(char);
};

std::ostream& operator<<(std::ostream&,Clear);

struct Clear_screen:public Clear{ Clear_screen(); };using C_sn=Clear_screen;

struct Clear_line:public Clear{ Clear_line(); };using C_ln=Clear_line;

#endif // clear_rag.hpp
