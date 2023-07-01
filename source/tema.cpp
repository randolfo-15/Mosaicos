#include "tema.hpp"

string  Tema::key(string str){
	if(str!="") this->key_tm=str;
	return this->key_tm;
}

string  Tema::bkg(string str){
	if(str!="") this->bkg_tm=str;
	return this->bkg_tm;
}

string  Tema::bld(string str){
	if(str!="") this->bld_tm=str;
	return this->bld_tm;
}

string  Tema::bkg2(string str){
	if(str!="") this->bkg2_tm=str;
	return this->bkg2_tm;
}	

Tema::Tema(){
	this->key_tm="\033[1;97m";
	this->bkg_tm="\033[44m";
	this->bld_tm="\033[3m";
	this->bkg2_tm="\033[101m";
}

Tema::Tema(cor key,cor bkg,cor bkg2,cor bold):
	key_tm(key),bkg_tm(bkg),bld_tm(bold),bkg2_tm(bkg2)
{}

