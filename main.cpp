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
        
        a.title("A");
        a.write("aaa");
        a.write("aaa");
        a.write("aaa");
        
        b.title("B");
        b.write("bbb");
        b.write("bbb");
        b.write("bbb");
        b.write("bbb");
        
        c.title("C");
        c.write("ccc");
        
        
        d.title("D");
        d.write("ddd");
        d.write("ddd");
        b=a+b+c+d;
        
         cout<<b<<'\n';
        return 0;
}
