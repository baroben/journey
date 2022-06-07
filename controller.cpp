#include "controller.h"
#include <QStackedWidget>
#include <QPixmap>
#include "editportefoliodialog.h"
#include "edittradedialog.h"
#include "trade.h"
#include "portefolio.h"

#define TRADE_VIEW_INDEX 2
#define PORTEFOLIO_VIEW_INDEX 1
#define PORTEFOLIO_LIST_VIEW_INDEX 0


Controller::Controller(QStackedWidget *parent) : QStackedWidget(parent)
{
    portefolioListView = new PortefolioListView;
    portefolioView = new PortefolioView;
    tradeView = new TradeView;

    addWidget(portefolioListView);
    addWidget(portefolioView);
    addWidget(tradeView);

    portefolioModel = new PortefolioModel;
    portefolioListView->portefolioList()->setModel(portefolioModel);
    portefolioListView->portefolioList()->setMinimumWidth(605);
    portefolioListView->portefolioList()->setMaximumWidth(605);

    connect(portefolioListView->portefolioList(), SIGNAL(clicked(QModelIndex)),this, SLOT(displaySelectedPortefolio()));
    connect(portefolioListView, SIGNAL(addPortefolio()),this, SLOT(addPortefolio()));
    connect(portefolioView->tradeTableView(), SIGNAL(clicked(QModelIndex)),this, SLOT(displaySelectedTrade()));
    connect(portefolioView, SIGNAL(goBack()),this, SLOT(goToPortefolioListView()));
    connect(portefolioView,SIGNAL(portefolioDeleted()), this, SLOT(deleteSelectedPortefolio()));
    connect(portefolioView,SIGNAL(portefolioEdited()), this, SLOT(editSelectedPortefolio()));
    connect(portefolioView,SIGNAL(addTrade()), this, SLOT(addTrade()));

    connect(tradeView, SIGNAL(goBack()),this, SLOT(goToPortefolioView()));
    connect(tradeView,SIGNAL(deleted()),this,SLOT(deleteSelectedTrade()));
    connect(tradeView,SIGNAL(editRequested()),this,SLOT(editSelectedTrade()));

    setCurrentIndex(PORTEFOLIO_LIST_VIEW_INDEX);
}

void Controller::addPortefolio()
{
    int newPortefolioRow = 0;
    portefolioModel->insertRows(newPortefolioRow,1,QModelIndex());
    Portefolio newPortefolio;
    editPortefolio(portefolioModel,newPortefolioRow, newPortefolio);
}

void Controller::addTrade()
{
    QModelIndex index = portefolioListView->portefolioList()->selectionModel()->selectedIndexes().first();
        if(index.isValid())
        {
            int row = index.row();
            int col = 1;

            index = portefolioModel->index(row, col);
            TradeModel *tradeModel = portefolioModel->data(index).value<TradeModel*>();
            int newTradeRow = 0;
            Trade newTrade;
            tradeModel->insertRows(0,1,QModelIndex());

            editTrade(tradeModel, newTradeRow, newTrade);
       }
}

void Controller::editTrade(TradeModel *tradeModel, const int tradeRow,const Trade &trade)
{
    QModelIndex index;
    EditDialog dialog;
    dialog.editTrade(trade);
    if(dialog.exec())
    {
        if(dialog.date().canConvert<QDateTime>() && dialog.date().toDateTime() != trade.date())
        {
            index = tradeModel->index(tradeRow,0);
            tradeModel->setData(index, dialog.date(),Qt::EditRole);
        }
        if(dialog.entry().canConvert<float>() && dialog.entry() != trade.entry())
        {
            index = tradeModel->index(tradeRow,1);
            tradeModel->setData(index, dialog.entry(),Qt::EditRole);
        }
        if(dialog.exit().canConvert<float>() && dialog.exit() != trade.exit())
        {
            index = tradeModel->index(tradeRow,2);
            tradeModel->setData(index, dialog.exit(),Qt::EditRole);
        }
        if(dialog.stoploss().canConvert<float>() && dialog.stoploss() != trade.stoploss())
        {
            index = tradeModel->index(tradeRow,3);
            tradeModel->setData(index, dialog.stoploss(),Qt::EditRole);
        }
        if(dialog.gain().canConvert<float>() && dialog.gain() != trade.gain())
        {
            index = tradeModel->index(tradeRow,4);
            tradeModel->setData(index, dialog.gain(),Qt::EditRole);
        }
        if(dialog.comment().canConvert<QString>() && dialog.comment() != trade.comment())
        {
            index = tradeModel->index(tradeRow,5);
            tradeModel->setData(index, dialog.comment(),Qt::EditRole);
        }
        if(dialog.image().canConvert<QPixmap>() && dialog.image() != trade.image())
        {
            index = tradeModel->index(tradeRow,6);
            tradeModel->setData(index, dialog.image(),Qt::EditRole);
        }
    }
}

void Controller::editSelectedTrade()
{
    QModelIndex index = portefolioListView->portefolioList()->selectionModel()->selectedIndexes().first();
        if(index.isValid())
        {
            int row = index.row();
            int col = 1;

            index = portefolioModel->index(row, col);
            TradeModel *tradeModel = portefolioModel->data(index).value<TradeModel*>();

            EditDialog dialog;

            int newTradeRow = portefolioView->tradeTableView()->selectionModel()->selectedIndexes().first().row();

            Trade newTrade;
            index = tradeModel->index(newTradeRow,0);
            newTrade.date(tradeModel->data(index).toDateTime());
            index = tradeModel->index(newTradeRow,1);
            newTrade.entry(tradeModel->data(index).toFloat());
            index = tradeModel->index(newTradeRow,2);
            newTrade.exit(tradeModel->data(index).toFloat());
            index = tradeModel->index(newTradeRow,3);
            newTrade.stoploss(tradeModel->data(index).toFloat());
            index = tradeModel->index(newTradeRow,4);
            newTrade.gain(tradeModel->data(index).toFloat());
            index = tradeModel->index(newTradeRow,5);
            newTrade.comment(tradeModel->data(index).toString());
            index = tradeModel->index(newTradeRow,6);
            newTrade.image(tradeModel->data(index).value<QPixmap>());


            editTrade(tradeModel, newTradeRow, newTrade);

            displaySelectedTrade();

       }
}

void Controller::deleteSelectedTrade()
{
    QModelIndex index = portefolioListView->portefolioList()->selectionModel()->selectedIndexes().first();
    if(index.isValid())
    {
        int row = index.row();
        int col = 1;
        index = portefolioModel->index(row, col);
        TradeModel *tradeModel = portefolioModel->data(index).value<TradeModel*>();

        int tradeRow = portefolioView->tradeTableView()->selectionModel()->selectedIndexes().first().row();
        tradeModel->removeRows(tradeRow, 1, QModelIndex());

        goToPortefolioView();
    }
}

void Controller::displaySelectedTrade()
{
    QModelIndex index = portefolioListView->portefolioList()->selectionModel()->selectedIndexes().first();
        if(index.isValid())
        {
            int row = index.row();
            int col = 1;

            index = portefolioModel->index(row, col);
            TradeModel *tradeModel = portefolioModel->data(index).value<TradeModel*>();

            int tradeRow = portefolioView->tradeTableView()->selectionModel()->selectedIndexes().first().row();

            index = tradeModel->index(tradeRow,0);
            tradeView->setDate(tradeModel->data(index).toDateTime());
            index = tradeModel->index(tradeRow,1);
            tradeView->setEntry(tradeModel->data(index).toFloat());
            index = tradeModel->index(tradeRow,2);
            tradeView->setExit(tradeModel->data(index).toFloat());
            index = tradeModel->index(tradeRow,3);
            tradeView->setStoploss(tradeModel->data(index).toFloat());
            index = tradeModel->index(tradeRow,4);
            tradeView->setGain(tradeModel->data(index).toFloat());
            index = tradeModel->index(tradeRow,5);
            tradeView->setComment(tradeModel->data(index).toString());
            index = tradeModel->index(tradeRow,6);
            tradeView->setImage(tradeModel->data(index).value<QPixmap>());

            goToTradeView();
        }
}

void Controller::editSelectedPortefolio()
{
    QModelIndex index = portefolioListView->portefolioList()->selectionModel()->selectedIndexes().first();
        if(index.isValid())
        {
            int editedRow = index.row();
            int col = 0;
            index = portefolioModel->index(editedRow, col);

            EditPortefolioDialog dialog;

            Portefolio portefolio;
            index = portefolioModel->index(editedRow,0);
            portefolio.name(portefolioModel->data(index).toString());
            index = portefolioModel->index(editedRow,2);
            portefolio.description(portefolioModel->data(index).toString());

            editPortefolio(portefolioModel, editedRow, portefolio);

            displaySelectedPortefolio();

       }
}

void Controller::editPortefolio(PortefolioModel *portefolioModel, const int portefolioRow,const Portefolio &portefolio)
{
    QModelIndex index;
    EditPortefolioDialog dialog;
    dialog.editPortefolio(portefolio);
    if(dialog.exec())
    {
        if(dialog.name().canConvert<QString>() && dialog.name() != portefolio.name())
        {
            index = portefolioModel->index(portefolioRow,0);
            portefolioModel->setData(index, dialog.name(),Qt::EditRole);
        }
        if(dialog.description().canConvert<QString>() && dialog.description() != portefolio.description())
        {
            index = portefolioModel->index(portefolioRow,2);
            portefolioModel->setData(index, dialog.description(),Qt::EditRole);
        }
    }
}

void Controller::deleteSelectedPortefolio()
{
    QModelIndex index = portefolioListView->portefolioList()->selectionModel()->selectedIndexes().first();
    if(index.isValid())
    {
        portefolioModel->removeRows(index.row(),1,QModelIndex());
        goToPortefolioListView();
    }
}

void Controller::displaySelectedPortefolio()
{
    QModelIndex index = portefolioListView->portefolioList()->selectionModel()->selectedIndexes().first();
    if(index.isValid())
    {
        int row = index.row();
        int col = 1;
        index=portefolioModel->index(row,col);
        TradeModel *tradeModel = portefolioModel->data(index).value<TradeModel*>();
        portefolioView->tradeTableView()->setModel(tradeModel);
        portefolioView->tradeTableView()->setShowGrid(false);
        portefolioView->tradeTableView()->setMinimumWidth(605);
        portefolioView->tradeTableView()->setMaximumWidth(605);
        portefolioView->tradeTableView()->setColumnWidth(0,200);
        portefolioView->tradeTableView()->setColumnWidth(1,100);
        portefolioView->tradeTableView()->setColumnWidth(2,100);
        portefolioView->tradeTableView()->setColumnWidth(3,100);
        portefolioView->tradeTableView()->setColumnWidth(4,100);
        portefolioView->tradeTableView()->setColumnHidden(5,true);
        portefolioView->tradeTableView()->setColumnHidden(6,true);

        index=portefolioModel->index(row,0);
        portefolioView->name(portefolioModel->data(index).toString());

        index=portefolioModel->index(row,2);
        portefolioView->description(portefolioModel->data(index).toString());

        goToPortefolioView();
    }
}

void Controller::goToTradeView()
{
    setCurrentIndex(TRADE_VIEW_INDEX);
}

void Controller::goToPortefolioView()
{
    setCurrentIndex(PORTEFOLIO_VIEW_INDEX);
}

void Controller::goToPortefolioListView()
{
    setCurrentIndex(PORTEFOLIO_LIST_VIEW_INDEX);
}


