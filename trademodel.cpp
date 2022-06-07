#include "trademodel.h"
#include <QTableView>
#include <QAbstractTableModel>
#include "mainwindow.h"
#include <ctime>
#include "trade.h"
#include <QDebug>


TradeModel::TradeModel(QObject *parent) : QAbstractTableModel(parent)
{
    dataStorage.push_back(new Trade(100,110,95,2000,QDateTime(QDate(2022,5,1), QTime(12,00,00,00), Qt::UTC),"This is a comment", QPixmap("C:/Users/benit/Documents/TRADE/DS/ALGO.PNG")));
    dataStorage.push_back(new Trade(2000,1850,1850,-1200,QDateTime(QDate(2022,6,1), QTime(12,20,00,00), Qt::UTC),"This is another comment", QPixmap("C:/Users/benit/Documents/TRADE/DS/ALGO.PNG")));
    dataStorage.push_back(new Trade(50,80,40,3000,QDateTime(QDate(2022,8,1), QTime(13,40,00,00), Qt::UTC),QString("This is a comment too"), QPixmap("C:/Users/benit/Documents/TRADE/DS/ALGO.PNG")));
}

int TradeModel::rowCount(const QModelIndex &) const {
    return dataStorage.size();
}

int TradeModel::columnCount(const QModelIndex &) const {
    return 7;
}

QVariant TradeModel::data(const QModelIndex &index, int role) const{
    int row = index.row();
    int col = index.column();

    if(role == Qt::DisplayRole)
    {
            switch(col){
            case 0:
                return dataStorage.value(row)->date();
                break;
            case 1:
                return dataStorage.value(row)->entry();
                break;
            case 2:
                return dataStorage.value(row)->exit();
                break;
            case 3:
                return dataStorage.value(row)->stoploss();
                break;
            case 4:
                return dataStorage.value(row)->gain();
                break;
            case 5:
                return dataStorage.value(row)->comment();
                break;
            case 6:
                return dataStorage.value(row)->image();
                break;
            }
    }
    return QVariant();
}

QVariant TradeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch(section){
        case 0:
            return QString("Date");
            break;
        case 1:
            return QString("Entry");
            break;
        case 2:
            return QString("Exit");
            break;
        case 3:
            return QString("Stoploss");
            break;
        case 4:
            return QString("Gain");
            break;
        }
    }
    return QVariant();
}

bool TradeModel::removeRows(int row, int count, const QModelIndex &index)
  {
      Q_UNUSED(index);
      beginRemoveRows(QModelIndex(), row, row+count-1);
      for (int i = row; i < row+count; i++) {
        if(dataStorage.size() == 1)
        {
            insertRows(0,1,QModelIndex());
        }
        dataStorage.removeAt(row);
      }
      endRemoveRows();
      return true;
}

bool TradeModel::insertRows(int row, int count, const QModelIndex &index)
{
      Q_UNUSED(index);
      beginInsertRows(QModelIndex(), row, row+count-1);
      for (int i = row; i < row+count; i++)
      {
        Trade *t = new Trade;
        dataStorage.insert(row, t);
      }
      endInsertRows();
      return true;
}

bool TradeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        int row = index.row();
        int col = index.column();
        Trade *t = dataStorage.value(row);
        switch(col)
        {
        case 0:
            t->date(value.toDateTime());
            break;
        case 1:
            t->entry(value.toFloat());
            break;
        case 2:
            t->exit(value.toFloat());
            break;
        case 3:
            t->stoploss(value.toFloat());
            break;
        case 4:
            t->gain(value.toFloat());
            break;
        case 5:
            t->comment(value.toString());
            break;
        case 6:
            t->image(value.value<QPixmap>());
            break;
        }
    }
    else
        return false;
    return true;
}


