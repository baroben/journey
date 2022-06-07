#ifndef TRADE_H
#define TRADE_H

#include <QDateTime>
#include <QPixmap>

class Trade
{
public:
    Trade();
    Trade(float entry, float exit, float stoploss, float gain, QDateTime dateTime, QString comment, QPixmap image);
    void entry(float entry);
    void exit(float exit);
    void stoploss(float stoploss);
    void gain(float gain);
    void date(QDateTime dateTime);
    void comment(QString comment);
    void image(QPixmap image);

    float entry() const;
    float exit() const;
    float stoploss() const;
    float gain() const;
    QDateTime date() const;
    QString comment() const;
    QPixmap image() const;

private:
    float gain_;
    float exit_;
    float entry_;
    float stoploss_;
    QDateTime date_;
    QString comment_;
    QPixmap image_;
};

#endif // TRADE_H
