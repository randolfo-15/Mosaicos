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
        Tm tm(
                {
                        // Background:
                        Magenta(),
                        Yellow()},
              
                        // Foreground:
                        {Fg(Black(),Bold()),
                        Fg(Black(),Underline()+Blink())
                }
        );
        
        Dp a,b(tm);
        a.horizontal(0);
        b.horizontal(0);
        a.vertical(2);
        b.vertical(0);
        a.edge(1);
        a.width(1);
        a.title(Underline()," A ");
        a.write("aaa");
        a.write("aaa");
        a.write("aaa");
        
        
        b.edge(1);
        b.width(1);
        b.title(" B ");
        b.write("bbb");
        b.write("bbb");
        b.write("bbb");
        
         cout<<a+b+a<<'\n';
         cout<<a+b+a<<'\n';
        
        return 0;
}
