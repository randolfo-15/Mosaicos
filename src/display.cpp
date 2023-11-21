/*!*****************************************************
 *	\file display.cpp
 * \brief Arquivo de aplicação da classe display,shadow,space
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/

#include "directions_rag.hpp"
#include "display_rag.hpp"
#include "effect.hpp"

using std::string;
using std::cout;


//------------------------------------------------------------------------------------------------
// Build
//------------------------------------------------------------------------------------------------
Dp::Display(){}

Dp::Display(Tm theme):tm(theme){} 

//------------------------------------------------------------------------------------------------
// Line
//------------------------------------------------------------------------------------------------
Line::Line(Hlg efc, string st):str(st),fg(efc){}

//------------------------------------------------------------------------------------------------
// Write
//------------------------------------------------------------------------------------------------

void Dp::write(Hlg efc,string line){ format(line,line.size(),efc); }

void Dp::write(string line){ format(line,line.size() ,Hlg() ); }

void Dp::format(string text,size_t size,Hlg efc){ write_aux_buffer(slice_text(text,size),efc); }

string Dp::slice_text(string line,size_t size){
	for(int n=size/w, pos=size; n>0 ; n--){
		if((line.find(' ')!=-1)&&!corte) while(line[pos-1]!=' ') pos--;               ///< 1 	Busca inicio da Palavra:
		if((pos>0)&&(pos<size-1)) line.insert(line.begin()+pos,'\n');            ///< 2 Inserir '\n'
	}
	return line;
}

void Dp::write_aux_buffer(string text,Hlg efc,string line){
	std::stringstream sstr(text);                                                                   ///< 1 Recebe o coteudo da linha.
	while(getline(sstr,line,'\n')){                                                                     ///< 2 Busca por interrupções.
		update_width(line.size());                                                                      ///< 3 Atualiza o tamanho do display.
		asst_buf.push_back(Line(efc,line));                                                      ///< 4 Adiciona nova linha ao buffer aux.
	}
}

void  Dp::update_width(int size){ if(w<size) w=size; }

//------------------------------------------------------------------------------------------------
// Show
//------------------------------------------------------------------------------------------------
void Display::show(){
	
	//if(size_terminal(size_display())){
		draw();   
		engine(); 
	//}else erro_exec();
}

//------------------------------------------------------------------------------------------------
// Draw
//------------------------------------------------------------------------------------------------
void Dp::draw(){
	draw_display();                                                                 
	if(shading) draw_shadow(main_buf.size());
}

//--------------------------------------------------------
// Draw Display
//--------------------------------------------------------
void Display::draw_display(){ for(Line ln:asst_buf) format_line(ln.str,ln.fg); }

//--------------------------------------------------------
// Format line
//--------------------------------------------------------
void Display::format_line(string line,Fg fg){
	 
	//Desenhar lado esquerdo a line:	
	string aux=fill(b,tm.bg())+fg+line;
	
	//Definir N° caracter que completa janela:
	int limit=w-line.size()+b+size_line(line.c_str());
	
	//Desenhar lado direito a line
	aux+=Clr::br()+tm.bg()+tm.fg();
	while(limit--) aux.push_back(' ');
	
	main_buf.push_back(aux);
}

//--------------------------------------------------------
// Size line
//--------------------------------------------------------
int Dp::size_line(const char *vet){ return loop(vet)/2; }

int Dp::loop(const char *c){
	if(!c[0]) return 0;
	else if(c[0]<0) return 1+loop(c+1);
	else return 0+loop(c+1);
}

//--------------------------------------------------------
// Draw Shadow
//--------------------------------------------------------
void Dp::draw_shadow(int limit,int i){
	for(;i<limit;i++) main_buf[i]+=fill(sb_side,shade);
	main_buf.push_back(Rigth(sb_side)+fill(size(),shade));
}

//------------------------------------------------------------------------------------------------
// Engine
//------------------------------------------------------------------------------------------------

void Dp::engine(){
	cout<<down;
	for(string line:main_buf) 
		cout<<rigth
				<<tm
			    <<line
			    <<tm
				<<Clr::br()<<'\n';
}

string Dp::fill(int count,Bg bg){
	string str=bg.str();
	while(count--) str+=" ";
	return str;
}

int Dp::size(){ return w+b+sb_side;  }

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
				
			//O texto é formatado:
			dp->draw();

			//Coipiar os dados formatados do display:
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

//Insere sombreamento inferior:



//Limpar janela, e posicioanr display:
void Display::update(){ cout<<Clear_screen::total()<<down;}

//--------------------------------------------------------
//(Configurações)
//--------------------------------------------------------

//*********************** Display ************************
/*
void Dp::shadow(bool x){sb.start=x;}
int  Dp::side_shadow(int x){
	return sb_side=(x>0&&x<w_dp.spc_int)?(x):sb_side;
}

void Dp::set_color_shadow(string cor){
	this->sb.cor=cor;
}
*/
//********************* Espaciasis ***********************

//Criar linhas vazais no display
void Dp::skip_line(int n){while(n-->0) write(Efc::Bold()," ");}

//Largura do display:
int Dp::width(int n){
	if(n>=0) w=n;
	return w;
}

//Distanciamneto horizontal:
int Dp::dist_x(int n){
	if(n>=0) rigth=n;
	return rigth.size();
}

//Distanciamento vertical:
int Dp::dist_y(int n){
	if(n>=0) down=n;
	return down.size();
}

//Espacamento do texto:
int Dp::spacing(int n){
	if(n>=0) b=n;
	return b;
}

//*********************** Texto *************************

//Modo de corte:
void Display::distribution(slice_mode x){corte=x;}

int Display::n_lines(){ return asst_buf.size()+shading; }

void Display::clear(){asst_buf.clear();}

void Display::insert(int pos,Hlg efc,string t){
	
	string aux=slice_text(t,t.size());
	aux.push_back('\n');
	std::stringstream sstr(aux);
	string line;
	while(getline(sstr,line,'\n')){
		update_width(line.size());
		asst_buf.insert(asst_buf.begin()+pos,Line(efc,line));
		pos++;
	}
}

void Display::remove(int pos){ asst_buf.erase(asst_buf.begin()+pos); }

//-------------------------------------------------------------
//(Aritimética de displays)
//-------------------------------------------------------------

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

//Número de displays:
int Display::n_dps(){return dps.size();}



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
