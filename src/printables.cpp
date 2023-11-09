/*!*****************************************************
 *	\file printables.cpp
 * \brief Define o conceito da classe printables
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#include "printables.hpp"

//--------------------------------------------------------
//Fabricação:
//--------------------------------------------------------

Printables::Printables(){ this->th=&modelo; }

Printables::Printables(THEME *tema){ this->th=tema;	}

Printables::~Printables(){th=nullptr;} ///< Liberar referncia do ponteiro de tema

//--------------------------------------------------------
//Show:
//--------------------------------------------------------

void Printables::show(){ show(spacing); }

void Printables::show(string x,vector<string>* buf){
	(buf!=nullptr)?
		loop(buf,buf->size())
		:
		loop(&buffer,buffer.size());	
}

void Printables::loop(vector<string>*buf,int last_line,int line){
	if(line>=last_line) return;
	cout<<spacing<<buf->at(line)<<'\n';	
	loop(buf,last_line,line+1);
}

//--------------------------------------------------------
//Geral:
//--------------------------------------------------------

//Cópia o contéudo do buffer
void Printables::copy(vector<string>* copy){
	*copy=buffer;
}

//Apaga todo contéudo do buffer
void Printables::clear(){
	if(buffer.size())buffer.clear();
}

//Retorna n° de linhas 
int Printables::n_lines(){return buffer.size();}

//--------------------------------------------------------
//Write:
//--------------------------------------------------------

//Formatação Customizada:
void Printables::write(void* obj,Func_Obj fx){
	fx(obj);
}

//Formatação Padrão:
void Printables::write(string line,MODO modo,Func_Obj fx){
	
	switch (modo){
		case CUSTOM: fx(&line);                      break;
		case BOLD:   line=th->bkg() +th->bld()+line; break;
		case SELECT: line=th->bkg2()+th->key()+line; break;
		default:     line=th->bkg() +th->key()+line;
	}
	
	buffer.push_back(line);
}

//--------------------------------------------------------
//Read:
//--------------------------------------------------------

//Leitura de dados:
void Printables::read(void* obj,Func_Obj fx){
	fx(obj);
}
//--------------------------------------------------------
//Get,Set(Tema): 
//--------------------------------------------------------
void Printables::set_tema(THEME* tema){
	this->th=tema;
}

THEME Printables::get_tema(){
	return *th;
}

void Printables::space(int limit){ 
	spacing=cor_space;
	while(limit-->0) spacing+=" ";
	spacing+=cor_space;
}

int Printables::space(){ return  spacing.size(); } 
