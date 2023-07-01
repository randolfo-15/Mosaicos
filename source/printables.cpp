#include "printables.hpp"

//--------------------------------------------------------
//Fabricação:
//--------------------------------------------------------

//Cria ptb.:
Printables::Printables(){
	this->th=&modelo;
}

Printables::Printables(THEME *tema){
	this->th=tema;	
}

Printables::~Printables(){th=nullptr;}

//--------------------------------------------------------
//Show:
//--------------------------------------------------------

//Mostrar contéudo:
void Printables::show(string x,vector<string>* buf){
	
	(buf!=nullptr)?
		loop(0,buf->size(),buf,x)
		:
		loop(0,buffer.size(),&buffer,x);	
}

void Printables::loop(int i,int end,vector<string>*buf,string x){
	if(i<end) {
		cout<<x<<buf->at(i)<<'\n';	
		loop(i+1,end,buf,x);
	}
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
