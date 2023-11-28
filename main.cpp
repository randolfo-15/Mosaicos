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
        Dp a,b,c,d;
        
        
        
        a.edge(5);
        a.width(3);
        a.title(" A");
        a.write("aaa");
        a.write("aaa");
        a.write("aaa");
        
        b.title(" B");
        b.write("bbb");
        b.write("bbb");
        b.write("bbb");
        
         cout<<a+b+a<<'\n';
        return 0;
}
