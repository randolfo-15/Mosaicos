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
        dp.dist_x(10);
        dp.dist_y(11);
        dp.write(Bold()+Blink()," a");
        dp.write(Blink()," a");
        dp.write(Underline()," Olaaaaaaaaaaaá \n");
        dp.write(Hlg()," a");
        dp.write(Tachado()," a");
        dp.show();
        
        return 0;
}
