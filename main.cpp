#include "src/colour.hpp"
#include "src/theme.hpp"
#include <iostream>

using namespace std;
using namespace Cls;
using namespace Efc;

int main(){
    //Tm tm;
    string b;
    Bg bg;
    for(int i=0;i<255;i+=3){
        bg=(Yellow()+Red());
        b+=bg+" ";
        
    }
    cout<<b<<'\n';
    return 0;
}
