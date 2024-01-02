/*!*****************************************************
 *	\file display.cpp
 * \brief Arquivo de aplicação da classe display,shadow,space
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/
#include "display_rag.hpp"
#include <algorithm>
#include <sstream>
using std::string;
using std::vector;

using list_gd=std::initializer_list<Ground*>;
using list_str=vector<string>::iterator;


int Dp::ID=0;

const char 
	Dp::Line::G[3]{"%G"},									///< Background
	Dp::Line::X[3]{"%X"};									///< Neutro	
//------------------------------------------------------------------------------------------------
// Build class
//------------------------------------------------------------------------------------------------
Dp::Display():id(ID++){dps.push_back(this);}

Dp::Display(Tm theme):id(ID++),tm(theme),dft(theme.fg().clr(),Efc::Bold()){ dps.push_back(this); } 

Dp::Line::Line(string st,int n,vector<Gd*> lt):str(st),tt(n),gd(lt){ diff=count_(G)+count_(X); }
//------------------------------------------------------------------------------------------------
// Headings and subheadings
//------------------------------------------------------------------------------------------------
void Dp::title(string str,int head){  split_rows(Line::G+str+Line::X,head,{&dft}); }

void Dp::title(string str,list_gd lt,int head){ split_rows(str,head,lt); }

void Dp::subtitle(string str,int head){ title(str,head); }

void Dp::subtitle(string str,list_gd lt,int head ){ split_rows(str,head,lt); }
//------------------------------------------------------------------------------------------------
// Write
//------------------------------------------------------------------------------------------------
void Dp::write(string str){ split_rows(str,NORMAL,{}); }

void Dp::write(string str,list_gd lt){ split_rows(str,NORMAL,lt); }

void Dp::split_rows(string str,int head,list_gd lt,string tmp){
	std::stringstream sstr(str+" ");
	while(getline(sstr,tmp,'\n')){
		Line line(tmp,head,lt);
		update_width(tmp.size()-line.diff);
		lines.push_back(line);
	} 
}
//------------------------------------------------------------------------------------------------
// Draw Display
//------------------------------------------------------------------------------------------------
vector<string>::iterator Display::draw_display(int size,int i){ 
	line_img.resize(size);
	for(Dp* dp:dps){ i=0;
		for(Line& ln : dp->lines) line_img[i++]+=draw_line(&ln,&dp->tm,dp->b,complete(&ln.str,dp->w,dp->b,ln.diff))+side(&dp->rigth);}	
	return line_img.begin();
}

string Dp::build(){int size=n_lines(); return  (size)?side(&down)+straighten(draw_display(size),size):"";}

string Display::draw_line(Line* line,Tm* tm,int b,int add){ return fill(b,tm->bg(line->tt))+line->form(tm)+fill(add,tm->bg(line->tt)); }

string Dp::straighten( list_str line,int cnt){  return (cnt)?rigth.str()+*line+end(cnt)+straighten(line+1,cnt-1):""; }

int Dp::accentuation(string str,int soma){ for(char c:str) soma+=(c<0)? 1:0; return soma/2; }

string Dp::end(int cnt){return (cnt>1)?br()+'\n':br();}

string Dp::side(Directions* dr){ return (dr->size())?dr->str():"";}

int Dp::complete(string* str,int w,int b,int diff){ return (w+b+accentuation(*str))-str->size()+diff ;}

string Dp::fill(int count,Bg bg){ return bg.str()+empty(count); }

string Dp::empty(int count){return (count>0)?" "+empty(count-1):"";}

int Dp::top_line(){ std::sort(dps.begin(),dps.end(),compare);  return dps[0]->lines.size(); }

int Dp::n_lines(){  return (dps.size())?top_line():0;} 
//------------------------------------------------------------------------------------------------
// Memory
//------------------------------------------------------------------------------------------------
void Dp::disassemble(){ dps.clear();  dps.push_back(this); }

void Dp::clear(){ dps.clear();}
//------------------------------------------------------------------------------------------------
// Proportions
//------------------------------------------------------------------------------------------------
//------------------------------------
// Getting
//------------------------------------
int Dp::width(){ return w+b;}

int Dp::horizontal(){return rigth.size(); }

int Dp::vertical(){ return down.size(); }

int Dp::edge(){ return b;}
//------------------------------------
// Setting
//------------------------------------
void  Dp::update_width(int size){  if(w<size) w=size; }

void Dp::width(int n){if(n>=0) w=n; } 

void Dp::horizontal(int n){ rigth.size(n);}

void Dp::vertical(int n){ down.size(n); }

void Dp::edge(int n){ b=n; }
//------------------------------------------------------------------------------------------------
// Operator
//------------------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out,Display dp){ return out<<dp.build(); }
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
int Dp::Line::count_(const char* dft,int i,int sm){ return ((i=str.find(dft,i))>=0)? count_(dft,i+1,sm+2) : sm;  }

string* Dp::Line::replace_G(string* str,int i,int ef){ return  ((i=str->find(G,i))>=0)? replace_G(&str->replace(i,2,gd[ef]->str()),i+1,ef+1) : str;  }

string Dp::Line::replace_X(string* str,Tm* tm,int i){ return  ((i=str->find(X,i))>=0)? replace_X(&str->replace(i,2,br()+(*tm)(tt)),tm,i+1):*str;  }

string Dp::Line::replace(string str,Tm* tm){  return replace_X( replace_G(&str),tm);}

string Dp::Line::treat(Tm* tm){ return (gd.size())?replace(str,tm):str; }

string Dp::Line::form(Tm* tm, int i){  return (*tm)(tt)+treat(tm)+br(); }
