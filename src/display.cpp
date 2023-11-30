/*!*****************************************************
 *	\file display.cpp
 * \brief Arquivo de aplicação da classe display,shadow,space
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#include "colour.hpp"
#include "display_rag.hpp"
#include <sstream>
#include <vector>
using std::string;
using std::vector;
using list_gd=std::initializer_list<Ground*>;


int Dp::ID=0;

const string Dp::sig[3]{			///< Signos
	"%F",										///< Foreground
	"%G",										///< Background
	"%X"										///< Neutro
};

//------------------------------------------------------------------------------------------------
// Build class
//------------------------------------------------------------------------------------------------
Dp::Display():id(ID++){dps.push_back(this);}

Dp::Display(Tm theme):id(ID++),tm(theme){ dps.push_back(this); } 
//------------------------------------------------------------------------------------------------
// Headings and subheadings
//------------------------------------------------------------------------------------------------
void Dp::title(string str,int head){ if(check_bg(head)) split_rows({str,head,{}});}

void Dp::subtitle(string str,int head){ if(check_bg(head)) title(str,head); }

bool Dp:: check_bg(int bg){return (bg<tm.bgs.size())?true:throw ;}
//------------------------------------------------------------------------------------------------
// Write
//------------------------------------------------------------------------------------------------
void Dp::write(string str){ split_rows({str,NORMAL,{}}); }

void Dp::write(string str,list_gd lt){ split_rows({str,NORMAL,lt}); }

void Dp::split_rows(Line ln,string tmp){(changer=true);
	std::stringstream sstr(ln.str);
	while(getline(sstr,tmp,'\n')){
		update_width(tmp.size()-diff(" "+tmp));
		lines.push_back(Line(tmp,ln.tt,ln.gd));
	} 
}
//------------------------------------------------------------------------------------------------
// Draw Display
//------------------------------------------------------------------------------------------------
string Dp::build(){(changer=false);
	line_img.resize(sort());
	draw_display();
	return  side(&down)+straighten(line_img.begin(),line_img.size());
}

void Display::draw_display(int i){ 
	for(Dp* dp:dps){ i=0;
		for(Line& ln : dp->lines) line_img[i++]+=draw_line(&ln,&dp->tm,dp->b,complete(&ln.str,dp->w,dp->b))+side(&dp->rigth);
	}
}

int Dp::diff(string str, int sm){ for(string sb:sig) for(int i=0;(i=str.find(sb,i))>=0;sm+=2,i++)  if(!i)break; return sm; }

string Display::draw_line(Line* line,Tm* tm,int b,int add){ return fill(b,tm->bg(line->tt))+line->form(tm)+fill(add,tm->bg(line->tt)); }

string Dp::straighten( vector<string>::iterator line,int cnt){  return (cnt)?rigth.str()+*line+end(cnt)+straighten(line+1,cnt-1):""; }

int Dp::accentuation(string str,int soma){  for(char c:str) soma+=(c<0)? 1:0; return soma/2; }

string Dp::show(){ return (!dps.size())?"EMPTY":(changer)?(img=build()):img; }

string Dp::end(int cnt){return (cnt>1)?Clr::br()+'\n':Clr::br();}

string Dp::side(Directions* dr){ return (dr->size())?dr->str():"";}

int Dp::complete(string* str,int w,int b){ return (w+b+accentuation(*str))-str->size()+diff(" "+*str); }

string Dp::fill(int count,Bg bg){ return bg+empty(count); }

string Dp::empty(int count){return (count>0)?" "+empty(count-1):"";}

int Dp::sort(){ std::sort(dps.begin(),dps.end(),compare);  return dps[0]->lines.size();}
//------------------------------------------------------------------------------------------------
// Memory
//------------------------------------------------------------------------------------------------
void Dp::disassemble(){ dps.clear();  dps.push_back(this); }

void Dp::clear(){ dps.clear();}
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
std::ostream& operator<<(std::ostream& out,Display dp){ return out<<dp.show(); }
//------------------------------------
// Addition
//------------------------------------
void Dp::operator+=(Dp dp){ this->dps=(*this+dp).dps;  }
Dp Dp::operator+(Dp dp){ return copy(&dp,*this); }
//------------------------------------
// Subtration
//------------------------------------
void Dp::operator-=(Dp dp){ remove(dp.id); }
Dp Dp::operator-(Dp dp){  return remove(*this,dp.id); }
//------------------------------------
// Assign
//------------------------------------
void Dp::operator=(Dp src){ dps.clear(); for(Dp* dp:src.dps) dps.push_back(dp); }
//------------------------------------
// Assist
//------------------------------------
Dp Dp::copy(Dp* src,Dp tmp){  for(Dp* dp:src->dps) tmp.dps.push_back(dp); return tmp; }

Dp Dp::remove(Dp dp,int id){   dp.remove(id);  return dp;}

void Dp::remove(int id){ ((id=find(id,dps.size()))>=0)?dps.erase(dps.begin()+id):throw;  }

int 	Dp::find(int id,int size,int i){  return  (i>=size)?-1:(id==dps[i]->id)?i:find(id,size,i+1); }

bool Dp::compare(Dp*a,Dp*b){ return (a->lines.size()>b->lines.size()); }
//------------------------------------
// Line
//------------------------------------
#include <iostream>

Dp::Line::Line(string st,int n,vector<Gd*> lt):str(st),tt(n),gd(lt){}

string Dp::Line::replace(string str,Tm* tm,int efc){ 
	if(gd.size()) 
		for(const string sb: Dp::sig) 
			for(int i=0;(i=str.find(sb,i))>=0;i++,efc++) str.replace(i,2,(sb!="%X")?gd[efc]->str():tm->bg(tt).str()+tm->fg(tt)); 
	return str;
}

string Dp::Line::form(Tm* tm, int i){  return tm->bg(tt).str()+tm->fg(tt)+replace(str,tm)+Clr::br(); }
