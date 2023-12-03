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
        
        //a.width(3);
        a.edge(1);
        
        
        
        Tm tm({Magenta(),Yellow(),Yellow()},{Fg(Black()),Fg(Black())});
        
        Dp b(tm);
        //b.width(3);
        b.edge(1);
        Bg g=Green();
        Bg y=Yellow();
        Fg bl=Blink();
        b.title(" B");
        
        b.write("b%Gb%Xb",{&g});
        b.subtitle("sub B");
        b.write("%Gb%X%Gb%X%X%Gb%X",{&g,&bl,&g});
        b.write("b%Gb%Xb",{&g});
        
        a.title(" %GA%X",{&y});
        Fg u=Underline();
        Fg t=Tachado();
        
        a.write("%Ga%X%Gaa%X",{&u,&t});
        a.write("a%Ga%X\na",{&bl});
        a.subtitle("sub %GA%X",{&bl});
        a.write("                aaa");
        
        b.clear();
        string x=(a+b+a).build();
        string w=(b+a+b).build();
        cout<<x<<'\n';
        cout<<w<<'\n';
        cout<<w<<'\n';
        return 0;
}
