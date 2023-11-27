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

//------------------------------------------------------------------------------------------------
// Build class
//------------------------------------------------------------------------------------------------
Dp::Display(){}
Dp::Display(Tm theme):tm(theme){} 

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
	draw_display();
	return  down.str()+straighten(lines.begin(),lines.size());
}

void Display::draw_display(){ for(Line& ln : lines) ln.img = draw_line(ln,complement(ln.str)); }

string Display::draw_line(Line& line,int attach){ return fill(b,tm.bg(line.type))+line()+Clr::br()+fill(attach,tm.bg(line.type)); }

int Dp::complement(string str){ return (width()+accentuation(str))-str.size(); }

string Dp::straighten( vector<Line>::iterator line,int cnt){ return (cnt)?rigth.str()+line->img+end()+straighten(line+1,cnt-1):""; }

string Dp::fill(int count,Bg bg){ return bg+empty(count); }

string Dp::empty(int count){return (count)?" "+empty(count-1):"";}

string Dp::end(){return Clr::br()+'\n';}

int Dp::accentuation(string str,int soma){ for(char c:str) soma+=(c<0)? 1:0; return soma/2;}

string Dp::show(){ return (changer)?(img=build()):img; }
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

void Dp::horizontal(int n){ x=n;}

int Dp::horizontal(){return x; }

void Dp::vertical(int n){ y=n;}

int Dp::vertical(){return y;}

void Dp::edge(int n){ b=n; }

int Dp::edge(){ return b;}

//------------------------------------------------------------------------------------------------
// Operator
//------------------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out,Display& dp){ return out<<dp.show(); }

string Dp::operator+(Dp dp){ return (lines.size()>=dp.lines.size())? add(*this,dp,down.str()):add(dp,*this,dp.down.str()); }

string Dp::add(Dp& a,Dp& b,string image,int i){
	a.build();
	b.build();
	for(;i<b.lines.size();i++) image+=a.rigth+a.lines[i].img+b.rigth+b.lines[i].img+end();
	for(;i<a.lines.size();i++) image+=a.rigth+a.lines[i].img+end();
	return image;
}

//------------------------------------
// Line
//------------------------------------
string Dp::Line::operator()(){return bg.str()+fg.str()+str; }

 
