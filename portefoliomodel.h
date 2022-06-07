#ifndef PORTEFOLIOMODEL_H
#define PORTEFOLIOMODEL_H

#include "portefolio.h"
#include <QAbstractTableModel>

class PortefolioModel : public QAbstractTableModel
{
public:
    PortefolioModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool removeRows(int position, int rows, const QModelIndex &parent) override;
    bool insertRows(int position, int rows, const QModelIndex &parent) override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;


private:
    QList<Portefolio*> portefolioList;
};

#endif // PORTEFOLIOMODEL_H
