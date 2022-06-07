#include "portefolio.h"

Portefolio::Portefolio() : name_(QString("Portefolio")), tradeModel_(new TradeModel)
{
}

Portefolio::Portefolio(QString name, QString description) : name_(name), tradeModel_(new TradeModel), description_(description)
{
}

TradeModel* Portefolio::tradeModel()
{
    return tradeModel_;
}

void Portefolio::tradeModel(TradeModel *tradeModel)
{
    tradeModel_ = tradeModel;
}

QString Portefolio::name() const
{
    return name_;
}

void Portefolio::name(QString name)
{
    name_ = name;
}

QString Portefolio::description() const
{
    return description_;
}
void Portefolio::description(QString description)
{
    description_ = description;
}
