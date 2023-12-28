#include "src/colour.hpp"
#include "src/display_rag.hpp"
#include <iostream>
using namespace Colors;
using namespace Effect;

using std::cout;
int main(){
    Clr clr;
    
    Gd gd;
    Bg bg,bg1=Yellow(),bg2=Blue();
    Fg fg;
    bg1-=bg-50;
    cout<<bg1<<"         "<<'\n';
    return 0;
}
