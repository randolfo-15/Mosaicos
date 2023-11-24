/*!*****************************************************
 *	\file display.cpp
 * \brief Arquivo de aplicação da classe display,shadow,space
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#include "display_rag.hpp"
using std::string;
using std::vector;

const Hlg Dp::bold=Efc::Bold();

//------------------------------------------------------------------------------------------------
// Build class
//------------------------------------------------------------------------------------------------
Dp::Display(){}
Dp::Display(Tm theme):tm(theme){} 

//------------------------------------------------------------------------------------------------
// Headings and subheadings
//------------------------------------------------------------------------------------------------
void Dp::title(string str,int head){ if(check_bg(head)) split_rows({str,tm.bg(head),bold,head});}

void Dp::title(Fg fg,string str,int head){ if(check_bg(head)) split_rows({str,tm.bg(head),fg,head});}

void Dp::title(Hlg efc,string str,int head){ if(check_bg(head)) split_rows({str,tm.bg(head),Fg(efc),head}); }

void Dp::subtitle(string str,int head){ if(check_bg(head)) title(str,head); }

void Dp::subtitle(Fg fg,string str,int head){ if(check_bg(head)) title(fg,str,head); }

void Dp::subtitle(Hlg efc,string str,int head){ if(check_bg(head)) title(efc,str,head); }

bool Dp:: check_bg(int bg){return (bg<tm.bgs.size())?true:throw;}
//------------------------------------------------------------------------------------------------
// Write
//------------------------------------------------------------------------------------------------
void Dp::write(string str){ split_rows({str,tm.bg(),tm.fg()}); }

void Dp::write(Fg  fg,string str){ split_rows({str,tm.bg(),fg}); }

void Dp::write(Bg bg,string str){ split_rows({str,bg,tm.fg()}); }

void Dp::write(Bg bg,Fg fg,string str){ split_rows({str,bg,fg}); }

void Dp::write(Clr clr,string str){ split_rows({str,Bg(clr),tm.fg()}); }

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

string Display::draw_line(Line& line,int attach){ return fill(b,tm.bg(line.type))+line()+fill(attach,tm.bg(line.type)); }

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

///\warning Precisamos descobrir o tamanho do terminal e redesenhar janela.
void Dp::width(int n){if(n>=0) w=n; } 

int Dp::width(){ return w+b;}

void Dp::horizontal(int n){ x=n;}

int Dp::horizontal(){return x; }

void Dp::vertical(int n){ y=n;}

int Dp::vertical(){return y;}

void Dp::edge(int n){ b=n; }

int Dp::edge(){ return b;}
///\warning

//------------------------------------------------------------------------------------------------
// Operator
//------------------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out,Display& dp){ return out<<dp.show(); }

string Dp::Line::operator()(){return bg.str()+fg.str()+str; }

/*
void Dp::show(int grupo,int x,int y)
{
	int size_draw=0;
	for(Dp *dp: dps){
		size_draw+=(dp->size_display()+x);
	}
	size_draw-=x;	
	
	if(dps.size()&&size_terminal(size_draw)){
		//Quadro de todos diplays:
		std::vector<string> mult_buf;	
		
		//Definir espaçamento:
		string str_x=!Bg()+"",
			   str_y;
		//Definir espaçamento:
		collect_char(&str_x,' ',0,x);	
		
		//Ordenar:
		std::sort(dps.begin(),dps.end(),[](Display *x,Display *y){return (x->n_lines()>y->n_lines());});
		

		int g=grupo--;
		
		int cont_line=0,   //Linha atual
			i=0;           //Display aual

		//Tratar cada display por vez:
		for(Display*dp:dps){
			
			//O primeiro define o space_x de todos:
			dp->x_dp.value(this->x_dp.spc_int);
				
			//O texto é create_lineado:
			dp->draw();

			//Coipiar os dados create_lineados do display:
			std::vector<string> buf;
			//dp->copy(&buf);		

		    // Conta linha atual levando em concideração o salto
			int j=0+cont_line,    
				k=buf.size()-1;    // Indice do ultimo display
			
			//Gera o espaçamento y no programa,inserindo novas linhas:
			if(g<=0){

				size_t pos=i-(grupo+1);
				cont_line+=dps[pos]->n_lines();
				for(int i=0;i<y;i++){ 
					mult_buf.push_back("");
					cont_line++;	
				}
			}
			
			//Inicia o tratamento das linhas:
			for(string line:buf){ 
				//Anote na mesma linha
				if(g>0){
					if(i==0)mult_buf.push_back("");
					mult_buf[j]+=line+str_x;
					
				}else mult_buf.push_back(line+str_x);	
				
				j++;                  //Contador de linha.
			}
				g=(g>0)?(g-1):grupo;  //Contador de grupos.
				i++;                  //Indice de objeto.
		}
		//Expõe saida:
		engine();
		//Printables::show(&mult_buf);
	}else erro_exec();
}
*/

//*********************** Texto *************************
//Modo de corte:
//void Display::distribution(slice_mode x){corte=x;}

//Autosomar:
void Display::operator+=(Display& dp){dps.push_back(&dp);}

//Autosubtrair:
void Display::operator-=(Display& dp){
	auto it=std::find(dps.begin(),dps.end(),&dp);
	if(it!=this->dps.end()) dps.erase(it);
}

Dp* Display::operator<<(Dp& dp){
	this->dps.push_back(&dp);
	return this;
}

Dp* Display::operator>>(Dp& dp){
	*this-=dp;
	return this;
}

void Display::operator*=(int n){
	while(n-->0) dps.push_back(this);	
}

//Fluso de entrada:
Dp* operator<<(Dp* a,Dp& b){
	a->dps.push_back(&b);
	return a;
}

//Fluxo de saida:
Dp* operator>>(Dp* a,Dp& b){
	*a-=b;
	return a;
}

//Obter display por indice:
Dp* Display::operator[](int i){
	return this->dps[i];
}

/*
//------------------------------------------------------------
//(Ler dados)
//------------------------------------------------------------
void Dp::read(Dp dp,vector<string> *pg,vector<string> *rp,int sl){
	int i=0,
		limit=pg->size(),
		no_shade=0;
	if(!dp.sb.start) no_shade=1;
		for(;i<limit;i++){
			dp.write(pg->at(i),BOLD);
			string cmd="tput cup "
				       +std::to_string(dp.n_lines()+no_shade)
					   +" "+std::to_string(pg->at(i).size()
					   +dp.dist_x()
					   +dp.spacing()
					   );

			dp.update();
			dp.show();
			system(cmd.c_str());
			cout<<dp.get_tema().bkg()
				<<dp.get_tema().key();
			
			rp->push_back(" ");
			getline(cin,rp->at(i));
			dp.write(rp->at(i));
			if(sl) for(int i=0;i<sl;i++) dp.write(" ");

			cout<<COR::EFFECT::DEFAULT_BKG
				<<COR::EFFECT::DEFAULT_KEY;
				
			dp.update();
	}			
		if(limit>1){
			dp.update();
			dp.show();
			cin.get();
			cout<<COR::EFFECT::DEFAULT_BKG
				<<COR::EFFECT::DEFAULT_KEY;
			
			dp.update();
		
		}else dp.update();
}
*/
/*
//--------------------------------------------------------
//(Size Terminal)
//--------------------------------------------------------
bool Dp::size_terminal(int size_dp){
	
	string term="term.txt",cmd;	
	cmd="tput cols >"+term;
	//system(cmd.c_str());
	ifstream f;
	f.open(term);
	//if(!f) return false;
	int size_term=0;
	f>>size_term;
	std::remove(term.c_str());
//	return (size_dp<=size_term)?true:false;
	return true;	
}
*/ 
