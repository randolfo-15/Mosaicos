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
        Dp a;
        a.width(3);
        a.edge(1);
        
        a.title(" A");
        a.write("aaa");
        a.write("aaa");
        a.write("aaa");
        
        Tm tm({Magenta(),Yellow()},{Fg(Black()),Fg(Black())});
        
        Dp b(tm);
        b.width(3);
        b.edge(1);
        Bg g=Green();
        b.title(" B");
        b.write("b%Gb%Xb",{&g});
        b.write("%Gb%Xb%Gb%X",{&g,&g});
        b.write("b%Gb%Xb",{&g});
        
        cout<<a+b+a<<'\n';
        cout<<b+a+b<<'\n';
        cout<<a+b+a<<'\n';
        return 0;
}
