#include "src/colour.hpp"
#include "src/theme.hpp"
#include <iostream>

using namespace std;
using namespace Cls;
using namespace Efc;

int main(){
    Bg bg=Cyan();
    Bg b=Red();
    Bg d=Yellow()+Red();
    for(int i=0;i<255;i++) {
        bg=Cyan()-i;
        d=(Yellow()+Red())-i;
        cout<<bg+"                     "+!bg<<b+"                                 "+!b<<d+"                                 "+!d<<'\n';
        if(i==244) i=0;
        for(int i=0;i<15555555;i++);
    }
    return 0;
    
}
