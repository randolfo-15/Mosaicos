/*!*****************************************************
 *	\file display.cpp
 * \author Randolfo Augusto
 * \date 21/09/22
 ******************************************************/
#include "display.hpp"

//--------------------------------------------------------
//(Fabricação)
//--------------------------------------------------------

//Construtor Padrão:
Dp::Display():Printables(){init_default();}

//Construtor com tema definido:
Dp::Display(THEME *t):Printables(t){init_default();}

//Construtor Custumizado:
Dp::Display(void (*fx)(Dp*)):Printables(){init_compnents(),fx(this);}

//***************** Construtor externos ******************

//Contrutor de texto;
Texto::Texto(string str,MODO m,Func_Obj fy):
	line(str),modo(m),fx(fy){}

//Construtor de sombras:
Shadow::Shadow(){}
Shadow::Shadow(string color):cor(color){}

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

int Dp::size_display(){
	return (w_dp.value()+x_dp.value()+(2*b_dp.value())+sb_side+((int)sb.start));
}

void Dp::erro_exec(string str){cout<<str<<'\n';}

//--------------------------------------------------------
//(Inicialização)
//--------------------------------------------------------

//Inicialização customizada:
void Dp::init_mode(void (*fx)(Dp*)){init_compnents(),fx(this);}

//Inicicialzar componetes comuns:
void Dp::init_compnents(){
	w_dp.init(21,' ');
	x_dp.init(2,' ');
	y_dp.init(2,'\n');
	b_dp.init(2, ' ');
	no_sb.cor=DEFAULT_BKG;
}
//Inicialização Padrão:
void Dp::init_default(){
	init_compnents();	
}

//--------------------------------------------------------
//(Métodos estrangeiros)
//--------------------------------------------------------

//Coletar char:
void collect_char(string* str,char c,int i,int end){
	if(i<end) {
		str->push_back(c);
		collect_char(str,c,i+1,end);
	}
}
//Iniciar e configurar space:
int Space::value(int n){
	if(n>=0){
		spc_int=n;
		spc_str.clear();
		collect_char(&spc_str,spc_chr,0,n);
	}		
	return spc_int;
}

//Fazer sombra:
string Shadow::shade(int n){
	if(!start) return "";
	
	string tmp=cor;
	collect_char(&tmp,' ',0,n);
	return tmp;
}


//Modo de inicicializar espaço:
void Space::init(int a,char b){
	this->spc_chr=b;value(a);
}

//--------------------------------------------------------
//(Escrita)
//--------------------------------------------------------

//Contar letras:
int Dp::n_letter(const char* l){
	if(!l[0]) return 0;
	return ((l[0]!='\n')?1:0)+n_letter(l+1);
}

//Gravar dados linha a linha:
void Dp::write(string text,MODO m,Func_Obj fx){
	format(text,n_letter(text.c_str()),m,fx);
}

//Configurar Texto:
void Dp::format(string text,size_t size,MODO m,Func_Obj fx){ 
	write_aux_buffer(slice_text(text,size),m,fx);
}

//Definir pontos de salto de linha:
string Dp::slice_text(string t,size_t size){
	int n=size/w_dp.spc_int;	
	while(n>0){
		size_t pos=n*w_dp.spc_int;
		
		//Busca inicio da Palavra:
		if((t.find(' ')!=-1)&&!corte)
			while(t[pos-1]!=' ')pos--;
		
		//Inserir '\n':	
		if((pos>0)&&(pos<size-1))
			t.insert(t.begin()+pos,'\n');
		n--;	
	}
	return t;
}

//Gravar dados no buffer auxiliar:
void Dp::write_aux_buffer(string text,MODO m,Func_Obj fx){
	text.push_back('\n');
	stringstream sstr(text);
	string line;
	while(getline(sstr,line,'\n')){
		update_width(line.size());
		buffer_aux.push_back(Texto(line,m,fx));
	}
}

//Atualizar Largura:
void  Dp::update_width(int size){
	if(w_dp.spc_int<size) w_dp.value(size);      
}

//--------------------------------------------------------
//(Exposição)
//--------------------------------------------------------

int Dp::loop(const char *c){
	if(!c[0]) return 0;
	else if(c[0]<0) return 1+loop(c+1);
	else return 0+loop(c+1);
}

int Dp::size_line(const char *vet){
	
	int size=loop(vet);	

	return size/2;
}

//Desenhar figura:
void Dp::draw(){
	Printables::clear();
	move_buffer(0,buffer_aux.size());              
	base_shading();
}

//Mostrar conteudo do buffer:(Show)
void Display::show(){
	
	if(size_terminal(size_display())){
		draw();   
		Printables::show(DEFAULT_BKG+DEFAULT_KEY+x_dp.spc_str);  
	}else erro_exec();
}

//Listar linhas
void Display::move_buffer(int i,int end){
	if(i<end){ 
		format_line(i,
				    buffer_aux[i].line,
					buffer_aux[i].modo,
					buffer_aux[i].fx 
	    ); 
		move_buffer(i+1,end);	
	}
}

//Ajusta contéudo em relação a display:
void Display::format_line(size_t i,string line,MODO modo,Func_Obj fx){
	 
	//Desenhar lado direito a line:	
	string aux=b_dp.spc_str+line;
	
	//Definir N° caracter que completa janela:
	int limit=w_dp.value()-line.size()+b_dp.value()+size_line(line.c_str());
	
	//Desenhar lado esquerdo a line
	for(int i=0;i<=limit;i++) aux.push_back(' ');
	
	if(sb.start)
		aux+=(i)?sb.shade(sb_side):no_sb.shade(sb_side);
	
		
	Printables::write(aux,modo,fx);	
}


void Dp::show(int grupo,int x,int y)
{
	int size_draw=0;
	for(Dp *dp: dps){
		size_draw+=(dp->size_display()+x);
	}
	size_draw-=x;	
	
	if(dps.size()&&size_terminal(size_draw)){
		//Quadro de todos diplays:
		vector<string> mult_buf;	
		
		//Definir espaçamento:
		string str_x=DEFAULT_BKG+"",
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
			vector<string> buf;
			dp->copy(&buf);		

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
		Printables::show(DEFAULT_BKG+DEFAULT_KEY+x_dp.spc_str,&mult_buf);
	}else erro_exec();
}

//Insere sombreamento inferior:
void Display::base_shading(){	
	if(sb.start){
		string tmp=no_sb.shade(sb_side)+
				   sb.shade(w_dp.spc_int+2*b_dp.spc_int+1);
		tmp+=DEFAULT_BKG+DEFAULT_KEY;
		Printables::write(tmp,NORMAL,nullptr);
	}else{
		string tmp=DEFAULT_BKG+DEFAULT_KEY;
		Printables::write(tmp,NORMAL,nullptr);
	}
}

//Limpar janela, e posicioanr display:
void Display::update(){
	
	(sys)?system("cls"):(system("clear"));
	cout<<y_dp.spc_str;	
}

//--------------------------------------------------------
//(Configurações)
//--------------------------------------------------------

//*********************** Display ************************
void Dp::shadow(bool x){sb.start=x;}
int  Dp::side_shadow(int x){
	return sb_side=(x>0&&x<w_dp.spc_int)?(x):sb_side;
}

void Dp::set_color_shadow(string cor){
	this->sb.cor=cor;
}

//********************* Espaciasis ***********************

//Criar linhas vazais no display
void Dp::skip_line(int n){while(n-->0) write(" ");}

//Largura do display:
int Dp::width(int n){return w_dp.value((n>0)?n:-1);}

//Distanciamneto horizontal:
int Dp::dist_x(int n){return x_dp.value(n);}

//Distanciamento vertical:
int Dp::dist_y(int n){return y_dp.value(n);}

//Espacamento do texto:
int Dp::spacing(int n){return b_dp.value(n);}

//*********************** Texto *************************

//Modo de corte:
void Display::distribution(slice_mode x){corte=x;}

int Display::n_lines(){
	return buffer_aux.size()+((sb.start)?1:0);
}

void Display::clear(){buffer_aux.clear();}

void Display::insert(int pos,string t,MODO m,Func_Obj fx){
	
	string aux=slice_text(t,t.size());
	aux.push_back('\n');
	stringstream sstr(aux);
	string line;
	while(getline(sstr,line,'\n')){
		update_width(line.size());
		buffer_aux.insert(buffer_aux.begin()+pos,Texto(line,m,fx));
		pos++;
	}
}

void Display::remove(int pos){
	buffer_aux.erase(buffer_aux.begin()+pos);
}
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
