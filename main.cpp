#include "hrd/display.hpp"


int main(){
    
    Dp dp;
    dp.write(" ",SELECT);
    dp.write("\n\nOla mundo\n\n");
    dp.show();
    
    return EXIT_SUCCESS;
}
