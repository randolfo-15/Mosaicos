#include "src/colour_rag.hpp"
#include "src/display_rag.hpp"
#include <iostream>

using namespace Colors;
using namespace Effect;

using std::cout;
int main(){
    Dp dp;
    
    dp.write("\n%GOla mundo%X\n",{Fg(Cls::Green(),Blink())});
    cout<<dp<<'\n';
    return 0;
}
