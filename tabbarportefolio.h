#ifndef TABBARPORTEFOLIO_H
#define TABBARPORTEFOLIO_H

#include "portefoliotab.h"
#include <QTabWidget>

class TabBarPortefolio : public QTabWidget
{
    Q_OBJECT

public slots:

public:
    TabBarPortefolio();
private:
    QList<PortefolioTab*> portefolios;
};

#endif // TABBARPORTEFOLIO_H
