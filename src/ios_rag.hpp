/*!*****************************************************
 *	\file ios_rag.hpp
* \brief Arquivo de definição da classe __IO__
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#ifndef IOS_RAG_HPP
#define IOS_RAG_HPP


#include <iostream>
#include "str.hpp"
#include "foreground.hpp"
#include "background.hpp"


class IOs{
    
    public:
        IOs();
        void left(int);
        void rigth(int);
        void up(int);
        void down(int);
    
        void point(int ,int);
    
    protected:
        
};


#endif //ios_rag.hpp
