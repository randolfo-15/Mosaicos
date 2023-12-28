#include "src/colour.hpp"
#include "src/display_rag.hpp"
#include <iostream>
using namespace Colors;
using namespace Effect;

using std::cout;
int main(){
    Bg bg,bg1=Red(),bg2=Green();
    bg1+=bg2;
    cout<<bg1<<"                  "<<'\n';
    bg1-=bg2;
    cout<<bg<<"                  "<<'\n';
    
    return 0;
}
