#ifndef PORTEFOLIOTAB_H
#define PORTEFOLIOTAB_H

#include <QStackedWidget>
#include "portefolio.h"
#include "trademodel.h"
#include "portefolioview.h"
#include "portefolio.h"
#include "tradeview.h"

class PortefolioTab : public QStackedWidget
{
    Q_OBJECT
public:
    PortefolioTab(QWidget *parent = nullptr);

public slots:
    void goToPortefolioView();
    void goToTradeView();
    void editSelectedTrade();
    //void addEntry();
    void deleteSelectedTrade();
    void displaySelectedTrade();

private:
    PortefolioView *portefolioView;
    TradeView *tradeView;

    Portefolio *portefolio;


};

#endif // PORTEFOLIOTAB_H
