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

class Str{

    protected:
        std::vector<std::string> buf;
        std::string my_str(std::string="");
        
    public:
        Str();
        Str(size_t);
        Str(std::string);
        
        friend std::string operator+(std::string,Str);
        std::string operator+(std::string);
        void operator=(std::string);
        void operator+=(std::string);
        friend std::ostream& operator<<(std::ostream&,Str);
};

std::string operator+(std::string,Str);
std::ostream& operator<<(std::ostream&,Str);

#endif //str.hpp
