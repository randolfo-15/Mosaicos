/*!*****************************************************
 *	\file printables.cpp
 * \brief Arquivo de Implementação da classe __Printables__
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#include "printables.hpp"

//--------------------------------------------------------
//Fabricação:
//--------------------------------------------------------

Printables::Printables(){}

Printables::Printables(Tm tm):th(tm){}

//--------------------------------------------------------
//Show:
//--------------------------------------------------------
/*! Exibir
 * ======
 * Mostrar o contéudo do buffer interno de modo custumizado.
 * __________________________________________________________________________________
 *  \sa show(vec_str*)
 */
void Printables::show(){ print(&buffer,buffer.size()); }

/*! Exibir
 * ======
 * Mostrar o contéudo do buffer externo de modo custumizado.
 * __________________________________________________________________________________
 *  \param buf Conjunto de linhas externas que requer tratamento.
 *  \sa show(vec_str*)
 */
void Printables::show(std::vector<std::string>* buf){ print(buf,buf->size()); }

/*! Loop
 * =====
 *  Método recursivo que visa percorrer todas as linhas do buffer e exibir uma
 *  por  vez, levando em concideração seu espaçamento.
 * __________________________________________________________________________________
 *  \param buf conjuto de linhas.
 *  \param last_line número total de linhas.
 *  \param line contador de linhas.
 */
void Printables::print(std::vector<std::string>*buf,int last_line,int line){
	if(line>=last_line) return;
	std::cout<<spacing<<buf->at(line)<<'\n';	
	print(buf,last_line,line+1);
}

//--------------------------------------------------------
//Geral:
//--------------------------------------------------------

void Printables::copy(std::vector<std::string>* copy){ *copy=buffer; } 

int Printables::n_lines(){return buffer.size();} 

void Printables::clear(){ buffer.clear(); } 

//--------------------------------------------------------
//Write:
//--------------------------------------------------------

/*! Escrita
 * =======
 * Recebe como padrão uma função que define como realizar a alteração
 * de dados de um objeto qualquer.
 * 
 * \note Método de   finalidade  gênerica,   logo  suporta  trabalhar com 
 *            qualquer tipo de classe que satisfaça seus parametros.
 * __________________________________________________________________________________
 * \param obj objeto qualquer .
 * \param fx função que trata o obj.
 */
void Printables::write(void* obj,Func_Obj fx){ fx(obj); }

/*! Escrita Padrão:
 * =============
 *  Método padrão para tratamento de casos de escrita, suporta configurar 
 *  o background  de  uma linha  segundo  dois  tons, que variam conforme  
 * a definição  do  tema,  e  aplicar  o  efeito BOLD,  mantendo  o modo
 *  __NORMAL__ como padrão.
 * __________________________________________________________________________________
 * \param line contéudo puro de uma linha.
 * \param modo Define como caracterizar uma linha.
 * \param fx Função para casos de tratamento custumizado para uma linha.
 */
void Printables::write(std::string line,MODO modo,Func_Obj fx){
	
	switch (modo){
		case CUSTOM: fx(&line);                                break;
		case BOLD:   line=th.bkg() +th.bld()+line;   break;
		case SELECT: line=th.bkg2()+th.key()+line; break;
		default:          line=th.bkg() +th.key()+line;
	}
	
	buffer.push_back(line);
}

//--------------------------------------------------------
//Read:
//--------------------------------------------------------

/*! Leitura
 * =======
 * Recebe como padrão uma função que define como realizar a Leitura
 * de dados de um objeto qualquer.
 * 
 * \note Método de   finalidade  gênerica,  logo  suporta  trabalhar com 
 *            qualquer tipo de classe que satisfaça seus parametros.
 * __________________________________________________________________________________
 * \param obj objeto qualquer .
 * \param fx função que trata o obj.
 */
void Printables::read(void* obj,Func_Obj fx){ fx(obj); }

//--------------------------------------------------------
//Get ,Sets
//--------------------------------------------------------
/*!\param tema novo tema.*/
void Printables::set_tema(Tm tema){ th=tema; }

/*!\return tema atual do printable.*/
Tm Printables::get_tema(){ return th; }

/*! Set → spacing
 * =============
 * \note Considera um valor inteiro que reprenta o espaçamento.
 * __________________________________________________________________________________
 *  \param limit número de caracteres que representaõ o espaçamento
 *  \sa space() 
 */
void Printables::space(int limit){ 
	spacing=cor_space;
	while(limit-->0) spacing+=" ";
	spacing+=cor_space;
}

/*! Get → spacing
 * =============
 * \note Leva apenas em concideração o espaço lógico sugerido pela variável spacing.
 * __________________________________________________________________________________
 *  \return número de caracteres que representão o espaçamento.
 *  \sa space(int)
 */
int Printables::space(){ return  spacing.size()-(cor_space.size()*2); } 
