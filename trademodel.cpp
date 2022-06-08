#include "trademodel.h"
#include <QTableView>
#include <QAbstractTableModel>
#include "mainwindow.h"
#include <ctime>
#include "trade.h"
#include <QDebug>

const int NUMBER_COLUMN_TRADE_MODEL = 8;

TradeModel::TradeModel(QObject *parent) : QAbstractTableModel(parent)
{
    dataStorage.push_back(new Trade(100,110,95,2000,QDateTime(QDate(2022,5,1), QTime(12,00,00,00), Qt::UTC),"This is a comment", QPixmap(":/images/trade.PNG")));
    dataStorage.push_back(new Trade(2000,1850,1850,-1200,QDateTime(QDate(2022,6,1), QTime(12,20,00,00), Qt::UTC),"This is another comment", QPixmap(":/images/trade.PNG")));
    dataStorage.push_back(new Trade(50,80,40,3000,QDateTime(QDate(2022,8,1), QTime(13,40,00,00), Qt::UTC),QString("This is a comment too"), QPixmap(":/images/trade.PNG")));
}

int TradeModel::rowCount(const QModelIndex &) const {
    return dataStorage.size();
}

int TradeModel::columnCount(const QModelIndex &) const {
    return NUMBER_COLUMN_TRADE_MODEL;
}

QVariant TradeModel::data(const QModelIndex &index, int role) const{
    int row = index.row();
    int col = index.column();

    if(role == Qt::DisplayRole)
    {
            switch(col){
            case DATE_INDEX:
                return dataStorage.value(row)->date();
                break;
            case ENTRY_INDEX:
                return dataStorage.value(row)->entry();
                break;
            case EXIT_INDEX:
                return dataStorage.value(row)->exit();
                break;
            case STOPLOSS_INDEX:
                return dataStorage.value(row)->stoploss();
                break;
            case GAIN_INDEX:
                return dataStorage.value(row)->gain();
                break;
            case COMMENT_INDEX:
                return dataStorage.value(row)->comment();
                break;
            case IMAGE_INDEX:
                return dataStorage.value(row)->image();
                break;
            case ASSET_INDEX:
                return dataStorage.value(row)->asset();
                break;
            }
    }
    return QVariant();
}

QVariant TradeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch(section){
        case DATE_INDEX:
            return QString("Date");
            break;
        case ENTRY_INDEX:
            return QString("Entry");
            break;
        case EXIT_INDEX:
            return QString("Exit");
            break;
        case STOPLOSS_INDEX:
            return QString("Stoploss");
            break;
        case GAIN_INDEX:
            return QString("Gain");
            break;
        case ASSET_INDEX:
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
        case DATE_INDEX:
            t->date(value.toDateTime());
            break;
        case ENTRY_INDEX:
            t->entry(value.toFloat());
            break;
        case EXIT_INDEX:
            t->exit(value.toFloat());
            break;
        case STOPLOSS_INDEX:
            t->stoploss(value.toFloat());
            break;
        case GAIN_INDEX:
            t->gain(value.toFloat());
            break;
        case COMMENT_INDEX:
            t->comment(value.toString());
            break;
        case IMAGE_INDEX:
            t->image(value.value<QPixmap>());
            break;
        case ASSET_INDEX:
            t->asset(value.toString());
            break;
        }
    }
    else
        return false;
    return true;
}


