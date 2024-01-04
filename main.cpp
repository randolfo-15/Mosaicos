#include "src/clear_rag.hpp"
#include "src/colour.hpp"
#include "src/display_rag.hpp"
#include "src/effect.hpp"
#include <iostream>

using namespace Colors;
using namespace Effect;

using std::cout;
int main(){
    Dp dp;
    
    dp.write("\n%GOla mundo%X\n",{Fg(Magenta(),Blink())});
    cout<<dp<<'\n';
    return 0;
}
