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
        dp.show("Olá mundo!!!");
        dp.show("Randolfo!!!");
        dp.show("pedro papel tesoura!!!");
        
        return 0;
}
