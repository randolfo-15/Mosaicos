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
        Tm tm={Bg(Blue()+150),Fg(Underline())};
        
        Dp dp;
        dp.title("Title...");
        dp.write("Google Tradutor - Um intérprete\n no seu smartphone ou computador. Tradutor. Traduzir agora.\n Entenda seu mundo e se comunique em\n outros idiomas com o Google Tradutor. Traduza textos, falas, imagens,\n documentos, sites e muito mais nos seus dispositivos.");
        dp.subtitle("subtitle...");
        dp.write(Green(),"....");
        dp.write("....");
        dp.write("pppp");
        cout<<dp<<Rigth(10)<<"end\n";
        dp.write("pppp");
        cout<<dp<<"end\n";
        
        return 0;
}
