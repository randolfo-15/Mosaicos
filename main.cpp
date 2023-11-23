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
        dp.title("Title...");
        dp.write("....");
        dp.write("....");
        dp.write("....");
        
        cout<<dp<<"Randolfo\n";
        dp.write("pppp");
        cout<<dp<<"end\n";
        return 0;
}
