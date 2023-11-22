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
        dp.write("text ......");
        dp.write("text ......");
        dp.subtitle("subtitle");
        dp.write("Outro objeto");
        dp.write("text ......");
        dp.write("text ......");
        dp.write("end ......");
        dp.show();
        
        return 0;
}
