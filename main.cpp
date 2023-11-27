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
        
        Dp dp,a;
        
        dp.title("...");
        dp.write(" o");
        dp.write("Olá mundo!!!");
        
        
        a.title("...");
        a.write("a b c");
a.write("a b c");
        dp+=a;
        a.write("--->");
        dp+=a;
        cout<<dp<<'\n';
        
        
        return 0;
}
