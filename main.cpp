#include "src/display_rag.hpp"
#include <iostream>

using namespace Colors;
using namespace Effect;

using std::cout;
int main(){
    Dp dp;
    Fg bg=Yellow();
    dp.write("\n%GOlá mundo!!!%X\n",{&bg});
    cout<<dp<<'\n';
    return 0;
}
