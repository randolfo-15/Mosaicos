#include "src/colour.hpp"
#include "src/display_rag.hpp"
#include <iostream>
using namespace Colors;
using namespace Effect;

using std::cout;
int main(){
    
    Gd gd=Bg(Yellow());
    Fg fg=gd.colour();
    cout<<fg<<"Ola mundo"<<!gd<<'\n';
    
    return 0;
}
