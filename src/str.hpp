/*!*****************************************************
 *	\file str.hpp
* \brief Arquivo de definição do modelo de string usado
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/
#ifndef STR_HPP
#define STR_HPP

#include <string>
#include <vector>
#include <ostream>
class Display;
class Str{
    friend Display;
    protected:
        std::vector<std::string> buf;
        std::string str(std::string="");
        std::string operator()();
        
        Str();
        Str(size_t);
        Str(std::string);

        void operator+=(std::string);
        
    public:
        friend std::string operator+(std::string,Str);
        std::string operator+(std::string);
        
        friend std::ostream& operator<<(std::ostream&,Str);
};

std::string operator-(std::string,Str);
std::string operator+(std::string,Str);
std::ostream& operator<<(std::ostream&,Str);

#endif //str.hpp
