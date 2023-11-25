#include "src/colour.hpp"
#include "src/effect.hpp"
#include "src/theme.hpp"
#include "src/directions_rag.hpp"
#include <iostream>
#include "src/clear_rag.hpp"
#include "src/display_rag.hpp"


using namespace std;
using namespace Cls;
using namespace Efc;

int main(){
        Tm tm({Magenta(),White(),Blue()},{Black()});
        Dp dp(tm);
        dp.title(Underline(),"Dados do João");
        dp.write(" ");
        dp.write(Yellow(),"Nome: Anão guerreiro");
        dp.write(Black(),"Signo: vida louca");
        dp.write("Niver:18/02");
        cout<<dp<<'\n';
        return 0;
}
