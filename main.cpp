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
                        Fg(Black(),Underline())
                }
        );
        
        Dp a,b(tm);
        
        a.horizontal(2);
        b.horizontal(2);
        a.vertical(2);
        b.vertical(2);
        
        a.edge(1);
        a.width(1);
        a.title(Underline()," A ");
        a.write("aaa");
        
        b.edge(1);
        b.width(1);
        b.title(" B ");
        b.write("bbb");
        a.write({Green()},"aa#Fa");
        b.write({Green()},"bbb");
        
         cout<<a+b+a+b<<'\n';
         cout<<b+a+b+a<<'\n';
         cout<<a+b+a+b<<'\n';
         cout<<b+a+b+a<<'\n';
        
        return 0;
}
