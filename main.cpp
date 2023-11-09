#include <mosaicos/display.hpp>


int main(){
    Dp dp;
    dp.write("...",SELECT);
    dp.skip_line();
    dp.write("Ola mundo");
    dp.skip_line();
    dp.show();
    
}
