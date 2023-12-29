#include "src/colour.hpp"
#include "src/display_rag.hpp"
#include "src/effect.hpp"
#include <iostream>
using namespace Colors;
using namespace Effect;

using std::cout;
int main(){
    Fg fg=Yellow()+Red();
    fg+=Blink()+Underline();
    
    cout<<fg<<"   sssssss ssssss"<<'\n';
    return 0;
}
