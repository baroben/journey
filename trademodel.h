#ifndef TRADEMODEL_H
#define TRADEMODEL_H

#include <QTableView>
#include <QAbstractTableModel>
#include <QList>
#include "trade.h"

extern const numbercolumn;

class TradeModel : public QAbstractTableModel
{
    Q_OBJECT

    public :
        TradeModel(QObject *parent = nullptr);
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        int columnCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
        bool removeRows(int position, int rows, const QModelIndex &parent) override;
        bool insertRows(int position, int rows, const QModelIndex &parent) override;
        bool setData(const QModelIndex &index, const QVariant &value, int role) override;

        float getAverageGain();
        float getNumberTrades();

    private :
        QList<Trade*> dataStorage;

};

Q_DECLARE_METATYPE(TradeModel)

#endif // TRADEMODEL_H
