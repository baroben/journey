#ifndef PORTEFOLIO_H
#define PORTEFOLIO_H

#include <QString>
#include "trademodel.h"

class Portefolio
{
public:
    Portefolio();
    Portefolio(QString name, QString description);

    QString name() const;
    void name(QString name);

    QString description() const;
    void description(QString description);


    TradeModel *tradeModel();
    void tradeModel(TradeModel *tradeModel);

private:
    QString name_;
    TradeModel *tradeModel_;
    QString description_;
};

#endif // PORTEFOLIO_H
