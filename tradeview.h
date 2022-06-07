#ifndef TRADEVIEW_H
#define TRADEVIEW_H

#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QItemSelectionModel>

class TradeView: public QWidget
{
    Q_OBJECT

public:
    TradeView();

    void setEntry(float entry);
    void setExit(float exit);
    void setStoploss(float sl);
    void setGain(float gain);
    void setDate(QDateTime dateTime);
    void setComment(QString comment);
    void setImage(QPixmap image);

signals:
    void goBack();
    void editRequested();
    void deleted();

private:
    QPushButton *backButton;
    QPushButton *editButton;
    QPushButton *deleteButton;

    QLabel *entry_;
    QLabel *exit_;
    QLabel *stoploss_;
    QLabel *gain_;
    QLabel *image_;
    QLabel *comment_;
    QLabel *date_;
};

#endif // TRADEVIEW_H
