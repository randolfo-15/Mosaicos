/*!***************************************************************
 *	\brief  Arquivo de definição Background.
 *	\file background.hpp
 * \author Randolfo Augusto
 * \date 20/11/23
 *****************************************************************/
#ifndef  BACKGROUND_RAG_HPP
#define BACKGROUND_RAG_HPP

#include "ground_rag.hpp"

struct Background:public Ground{
    Background();
    Background(Colour);
    std::string operator!() override;
    
    private: 
        void operator=(Highlight) override;
        static const char PLAN[6];
        
};using Bg=Background;

#endif // background_rag.hpp
