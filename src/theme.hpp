/*!*****************************************************
 *	\file theme.hpp
*	\brief  Arquivo de definição de temas das janelas.
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/
 
#ifndef THEME_HPP
#define THEME_HPP

#include "foreground.hpp"
#include "background.hpp"
#include <initializer_list>

/// Define um conjunto de cores e comportamentos de uma janela.
class Theme{
	friend Display;
	protected:
		std::vector<Fg>  fgs;
		std::vector<Bg> bgs;
		
		friend std::ostream& operator<<(std::ostream&,Theme);
		std::string operator()();
		
	public:		
		/// Construtor padrão.
		Theme();                                                                              
		Theme(Background,Foreground);  
		Theme(std::initializer_list<Bg>,std::initializer_list<Fg>);
		
		
		Foreground fg(int=0);         ///< (Get) padrão para foreground. 
		Background bg(int=0);        ///< (Get) padrão para background. 
		
		void fg(Highlight,int=0);    ///< (Set) padrão para foreground. 
		void fg(Colour,int=0);         ///< (Set) modificar a cor da letra.
		
		void bg(Colour,int=0);        ///< (Set) padrão para background. 
		
		
		
};using Tm=Theme;

std::ostream& operator<<(std::ostream&,Theme);

#endif // theme.hpp
