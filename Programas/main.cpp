#include "display.hpp"

int main(int argc, char *argv[])
{
	Dp dp;
	dp.shadow(false);
	dp.write("\nCadastro\n",SELECT);
	dp.write(" ");
	vector<string> qt{"Nome: ","Idade: ","Signo: ","Tel: "},
		           aw;
    Dp::read(dp,&qt,&aw,1);

	return 0;
}



