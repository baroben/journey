#include "tabbarportefolio.h"

TabBarPortefolio::TabBarPortefolio()
{
    if(!portefolios.empty()){
        for(PortefolioTab *p : portefolios)
            this->addTab(p,"oui");
    }
}
