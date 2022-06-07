#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "portefolioview.h"
#include "trademodel.h"
#include "tradeview.h"
#include "portefoliomodel.h"
#include "portefoliolistview.h"
#include <QStackedWidget>

class Controller : public QStackedWidget
{
    Q_OBJECT
public:
    Controller(QStackedWidget *parent = 0);

public slots:
    void goToPortefolioListView();
    void goToPortefolioView();
    void goToTradeView();

    void addTrade();
    void editSelectedTrade();
    void deleteSelectedTrade();
    void displaySelectedTrade();

    void addPortefolio();
    void editSelectedPortefolio();
    void deleteSelectedPortefolio();
    void displaySelectedPortefolio();

private:
    void editTrade(TradeModel *tradeModel, const int tradeRow,const Trade &trade);
    void editPortefolio(PortefolioModel *portefolioModel, const int portefolioRow,const Portefolio &portefolio);

    PortefolioListView *portefolioListView;
    PortefolioView *portefolioView;
    TradeView *tradeView;

    PortefolioModel *portefolioModel;
};

#endif // CONTROLLER_H
