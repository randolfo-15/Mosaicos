#include "src/color.hpp"
#include "src/display.hpp"

int main(){    
    Tm tm;
    std::cout<<tm.bkg()+"........................................................... = "<<tm.bkg().size()<<'\n'; 
    std::cout<<tm.bkg2()+"........................................................... = "<<tm.bkg2().size()<<'\n';
    std::cout<<COR::BKG::GREEN_BKG+"........................................................... = "<<COR::BKG::GREEN_BKG.size()<<'\n'; 
}
