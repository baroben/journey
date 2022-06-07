#ifndef PORTEFOLIOVIEW_H
#define PORTEFOLIOVIEW_H

#include <QListView>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "trademodel.h"

class PortefolioView : public QWidget
{
    Q_OBJECT

public:
    PortefolioView();
    QTableView *tradeTableView() const;

    void name(QString name);
    void description(QString description);

signals:
    void tradeSelected();
    void goBack();
    void portefolioDeleted();
    void portefolioEdited();
    void addTrade();

private:
    QPushButton *deleteButton;
    QPushButton *addTradeButton;
    QPushButton *editButton;
    QPushButton *backButton;

    QTableView *tradeTableView_;

    QLabel *name_;
    QLabel *description_;
};

#endif // PORTEFOLIOVIEW_H
