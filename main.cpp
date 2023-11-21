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
        Tm tm={Bg(Blue()+150),Fg(Underline())};
        
        Dp dp;
        Colour clr(85,116,102);
        dp.shadow(false);
        dp.write(Yellow()," ");
        dp.write(clr,"Mariana");
        dp.write(Reverse(),"Olá mundo");
        dp.write(Bold(),"Olá Adoração fora\ndo normal");
        dp.write(Bg(Yellow()+Red()),"11111111111111111111111 111111111111111111111111111");
        dp.write("sseção de pirokadaaão");
        dp.write(Tachado(),"fim");
        dp.write("");
        dp.show();
        
        return 0;
}
