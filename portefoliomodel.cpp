#include "portefoliomodel.h"

PortefolioModel::PortefolioModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    portefolioList.push_back(new Portefolio("Portefolio 1", "This is the 1st portefolio"));
    portefolioList.push_back(new Portefolio("Portefolio 2", "This is the 2nd portefolio"));
    portefolioList.push_back(new Portefolio("Portefolio 3", "This is the 3rd portefolio"));
}

int PortefolioModel::rowCount(const QModelIndex &parent) const
{
    return portefolioList.size();
}

int PortefolioModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant PortefolioModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();


    if(role == Qt::DisplayRole)
    {
        switch(col){
        case 0:
            return portefolioList.value(row)->name();
            break;
        case 1:
            return QVariant::fromValue(portefolioList.value(row)->tradeModel());
            break;
        case 2:
            return portefolioList.value(row)->description();
            break;
        }
    }
    return QVariant();
}

bool PortefolioModel::removeRows(int row, int count, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), row, row+count-1);
    for (int i = row; i < row+count; i++) {
      if(portefolioList.size() == 1)
      {
          insertRows(0,1,QModelIndex());
      }
      portefolioList.removeAt(row);
    }
    endRemoveRows();
    return true;
}

bool PortefolioModel::insertRows(int row, int count, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), row, row+count-1);
    for (int i = row; i < row+count; i++)
    {
      Portefolio *p = new Portefolio;
      portefolioList.insert(row, p);
    }
    endInsertRows();
    return true;
}

bool PortefolioModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        int row = index.row();
        int col = index.column();
        Portefolio *p = portefolioList.value(row);
        switch(col)
        {
        case 0:
            p->name(value.toString());
            break;
        }
    }
    else
        return false;
    return true;
}
