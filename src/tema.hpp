/*!*****************************************************
 *	\file tema.hpp
*	\brief  Arquivo de definição de temas das janelas.
 * \author Randolfo Augusto
 * \date 20/09/22
 ******************************************************/
 
#ifndef TEMA_HPP
#define TEMA_HPP

#include <color.hpp>

constexpr int theme_attributes=4; ///< Define o número de atributos de tema

/// enumerador simbolico do conjunto de componentes de tema.
enum  components{
		TEMA_KEY,            ///< Foreground
		TEMA_BKG,           ///< Bakyground
		TEMA_EFFECT,      ///< Efeito
		TEMA_BKG2          ///< Bakyground modo seleção
};
	
/// Define um conjunto de cores e comportamentos de uma janela.
class Tema{
	
	string component[theme_attributes]; ///< Conjunto de atributos de tema.

	string check(components,cor_effect); ///< Método get_set geral para tratamento de atributos.
	
	public:		
		Tema();                                                                              ///< Construtor padrão.
		Tema(cor_effect key,cor bkg,cor bkg2,effect bold);  ///< Construtor custumizado. 
		
		string  key(cor value="");      ///< (Get,Set) padrão para foreground. 
		string  bkg(cor value="");     ///< (Get,Set) padrão para background. 
		string  bld(effect value="");  ///< (Get,Set) padrão para efeitos.
		string  bkg2(cor value="");	  ///< (Get,Set) padrão para o modo seleção. 
};

#endif // tema.hpp
