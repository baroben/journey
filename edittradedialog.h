#ifndef EDITTRADEDIALOG_H
#define EDITTRADEDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QTextEdit>

#include "trade.h"

class EditDialog: public QDialog
{
    Q_OBJECT

public:
    EditDialog(QWidget *parent = nullptr);
    void editTrade(Trade trade);

    QVariant entry() const;
    QVariant exit() const;
    QVariant stoploss() const;
    QVariant gain() const;
    QVariant date() const;
    QVariant comment() const;
    QVariant image() const;


private:
    QLineEdit *entryText;
    QLineEdit *exitText;
    QLineEdit *stoplossText;
    QLineEdit *gainText;
    QDateTimeEdit *dateText;
    QTextEdit *commentText;
};

#endif // EDITTRADEDIALOG_H
