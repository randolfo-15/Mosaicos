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
        
        Dp a,b,c;
        a.title("...");
        b.title("...");
        a.write(Yellow(),"a");
        a.write(Yellow(),"a");
        a.write(Yellow(),"a");
        b.write("b");
        b.write("b");
        a.subtitle("ese");
        a.write(Yellow(),"a");
        b.write("b");
        b.write("b");
        b.subtitle("ese");
        b.write("b");
        b.write("b");
        b.write("b");
        
        cout<<a+b<<'\n';
        
        return 0;
}
