/*!*****************************************************
 *	\file display.cpp
 * \brief Arquivo de aplicação da classe display,shadow,space
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#include "display_rag.hpp"
#include <vector>
using std::string;
using std::vector;

int Dp::ID=0;

//------------------------------------------------------------------------------------------------
// Build class
//------------------------------------------------------------------------------------------------
Dp::Display(){init();}

Dp::Display(Tm theme):tm(theme){init();} 

void Dp::init(){  
	dps.push_back(this);
	id=ID++;
}
//------------------------------------------------------------------------------------------------
// Headings and subheadings
//------------------------------------------------------------------------------------------------
void Dp::title(string str,int head){ if(check_bg(head)) split_rows({str,tm.bg(head),tm.fg(head),head});}

void Dp::title(Fg fg,string str,int head){ if(check_bg(head)) split_rows({str,tm.bg(head),fg,head});}

void Dp::title(Hlg efc,string str,int head){ if(check_bg(head)) split_rows({str,tm.bg(head),Fg(efc),head}); }

void Dp::subtitle(string str,int head){ if(check_bg(head)) title(str,head); }

void Dp::subtitle(Fg fg,string str,int head){ if(check_bg(head)) title(fg,str,head); }

void Dp::subtitle(Hlg efc,string str,int head){ if(check_bg(head)) title(efc,str,head); }

bool Dp:: check_bg(int bg){return (bg<tm.bgs.size())?true:throw ;}
//------------------------------------------------------------------------------------------------
// Write
//------------------------------------------------------------------------------------------------
void Dp::write(string str){ split_rows({str,tm.bg(),tm.fg()}); }

void Dp::write(Fg  fg,string str){ split_rows({str,tm.bg(),fg}); }

void Dp::write(Bg bg,string str){ split_rows({str,bg,tm.fg()}); }

void Dp::write(Bg bg,Fg fg,string str){ split_rows({str,bg,fg}); }

void Dp::write(Clr clr,string str){ split_rows({str,tm.bg(),Fg(clr)}); }

void Dp:: write(Hlg efc,string str){ split_rows({str,tm.bg(),Fg(efc)}); }

void Dp::write(Clr  clr,Hlg efc,string str){ split_rows({str,Bg(clr),Fg(efc)}); }

void Dp::split_rows(Line ln,string tmp){
	changer=true;
	std::stringstream sstr(ln.str);
	while(getline(sstr,tmp,'\n')){
		update_width(tmp.size());
		lines.push_back({tmp,ln.bg,ln.fg,ln.type});
	} 
}
//------------------------------------------------------------------------------------------------
// Draw Display
//------------------------------------------------------------------------------------------------
string Dp::build(){   
	changer=false;
	sort();
	draw_display();
	return  down.str()+straighten(dps[0]->lines.begin(),dps[0]->lines.size());
}

void Display::draw_display(){ 
	for(Dp* dp:dps){ int i=0;
		for(Line& ln : dp->lines) dps[0]->lines[i++].img += draw_line(ln,complement(ln.str))+dp->rigth; 
	}
}

string Display::draw_line(Line& line,int attach){ return fill(b,tm.bg(line.type))+line()+Clr::br()+fill(attach,tm.bg(line.type)); }

string Dp::straighten( vector<Line>::iterator line,int cnt){ return (cnt)?rigth.str()+line->img+end()+straighten(line+1,cnt-1):""; }

int Dp::accentuation(string str,int soma){ for(char c:str) soma+=(c<0)? 1:0; return soma/2;}

string Dp::show(){ return (changer)?(img=build()):img; }

string Dp::end(){return Clr::br()+'\n';}

int Dp::complement(string str){ return (width()+accentuation(str))-str.size(); }

string Dp::fill(int count,Bg bg){ return bg+empty(count); }

string Dp::empty(int count){return (count)?" "+empty(count-1):"";}

void Dp::sort(){
	auto fx=[](Dp*a,Dp*b){ return (a->lines.size()>b->lines.size()); };
	std::sort(dps.begin(),dps.end(),fx);
}
//------------------------------------------------------------------------------------------------
// Memory
//------------------------------------------------------------------------------------------------
void Dp::clear(){ lines.resize(0); }

//------------------------------------------------------------------------------------------------
// Proportions
//------------------------------------------------------------------------------------------------
void  Dp::update_width(int size){  if(w<size) w=size; }

void Dp::width(int n){if(n>=0) w=n; } 
int Dp::width(){ return w+b;}

void Dp::horizontal(int n){ rigth.size(n);}
int Dp::horizontal(){return rigth.size(); }

void Dp::vertical(int n){ down.size(n); }
int Dp::vertical(){ return down.size(); }

void Dp::edge(int n){ b=n; }
int Dp::edge(){ return b;}

//------------------------------------------------------------------------------------------------
// Operator
//------------------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out,Display& dp){ return out<<dp.show(); }
//------------------------------------
// Addition
//------------------------------------
void Dp::operator+=(Dp& dp){ dps.push_back(&dp); }
void Dp::operator+=(Dp dp){ *this=*this+dp;  }
Dp Dp::operator+(Dp dp){ return copy(dp,*this); }
//------------------------------------
// Assist
//------------------------------------
Dp Dp::copy(Dp src,Dp tmp){  for(Dp* dp:src.dps) tmp.dps.push_back(dp); return tmp; }
//------------------------------------
// Line
//------------------------------------
string Dp::Line::operator()(){return bg.str()+fg.str()+str; }

 
