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
        
        Dp dp;
        dp.write("");
        dp.write(Underline(),"Olá mundo");
        dp.write(Bold(),"Olá Adoração fora\ndo normal");
        dp.write("sseção de pirokadaaão");
        dp.write(Tachado(),"fim");
        dp.write("");
        dp.show();
        
        return 0;
}
