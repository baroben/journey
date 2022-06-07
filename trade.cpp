#include <QFile>
#include <QDir>
#include "trade.h"

Trade::Trade() : gain_(0), exit_(0),entry_(0), stoploss_(0),
    date_(QDate(2022,05,1), QTime(12,00,00,00), Qt::UTC),
    comment_(QString("comment")), image_("C:/Users/benit/Documents/TRADE/DS/ALGO.PNG")
{
    image_ = image_.scaled(QSize(1000,1000), Qt::KeepAspectRatio);
}

Trade::Trade(float entry, float exit, float stoploss, float gain, QDateTime dateTime, QString comment, QPixmap image)
 : gain_(gain), exit_(exit),entry_(entry), stoploss_(stoploss),
   date_(dateTime), comment_(comment), image_(image)
{
    image_ = image_.scaled(QSize(1000,1000), Qt::KeepAspectRatio);
}

void Trade::entry(float e){entry_ = e;}
void Trade::exit(float e){exit_ = e;}
void Trade::stoploss(float sl){stoploss_ = sl;}
void Trade::gain(float g){gain_ = g;}
void Trade::date(QDateTime d){date_ = d;}
void Trade::comment(QString comment){comment_ = comment;}
void Trade::image(QPixmap image){image_ = image;}

float Trade::entry() const{return entry_;}
float Trade::exit() const{return exit_;}
float Trade::stoploss() const{return stoploss_;}
float Trade::gain() const{return gain_;}
QDateTime Trade::date() const{return date_;}
QString Trade::comment() const{return comment_;}
QPixmap Trade::image() const {return image_;}

