#include <QGridLayout>
#include <QModelIndex>
#include <QAbstractItemModel>
#include "tradeview.h"
#include <QDateTime>

TradeView::TradeView()
{
    backButton = new QPushButton("Portefolio");
    backButton->setGeometry(0,0,200,100);
    editButton = new QPushButton("Edit the Trade");
    deleteButton = new QPushButton("Delete the Trade");

    connect(backButton, SIGNAL(clicked()),this,SIGNAL(goBack()));
    connect(editButton, SIGNAL(clicked()),this,SIGNAL(editRequested()));
    connect(deleteButton, SIGNAL(clicked()),this,SIGNAL(deleted()));

    auto entryLabel = new QLabel("Entry : ");
    auto exitLabel = new QLabel("Exit : ");
    auto stoplossLabel = new QLabel("Stoploss : ");
    auto gainLabel = new QLabel("Gain : ");
    auto commentLabel = new QLabel("Comment : ");
    auto dateLabel = new QLabel("Date : ");

    entry_ = new QLabel;
    exit_ = new QLabel;
    stoploss_ = new QLabel;
    gain_ = new QLabel;
    image_ = new QLabel;
    comment_ = new QLabel;
    comment_->setWordWrap(true);
    date_ = new QLabel;

    QGridLayout *mainLayout = new QGridLayout;
    QGridLayout *statLayout = new QGridLayout;
    QGridLayout *upperLayout = new QGridLayout;
    QGridLayout *buttonLayout = new QGridLayout;
    statLayout->setColumnStretch(1, 2);
    upperLayout->setColumnStretch(2, 2);
    buttonLayout->setRowStretch(3, 2);
    mainLayout->setRowStretch(2, 10);
    mainLayout->setRowStretch(1, 2);
    mainLayout->setRowStretch(0, 1);
    mainLayout->setColumnStretch(0, 2);
    mainLayout->setColumnStretch(1, 6);
    mainLayout->setColumnStretch(2, 2);

    QWidget *statPane = new QWidget;
    statPane->setStyleSheet("* {background-color:#242526;border-radius: 5px}");
    statPane->setLayout(statLayout);

    statLayout->addWidget(dateLabel,0,0,Qt::AlignRight);
    statLayout->addWidget(date_,0,1);
    statLayout->addWidget(entryLabel,1,0,Qt::AlignRight);
    statLayout->addWidget(entry_,1,1);
    statLayout->addWidget(exitLabel,2,0,Qt::AlignRight);
    statLayout->addWidget(exit_,2,1);
    statLayout->addWidget(stoplossLabel,3,0,Qt::AlignRight);
    statLayout->addWidget(stoploss_,3,1);
    statLayout->addWidget(gainLabel,4,0,Qt::AlignRight);
    statLayout->addWidget(gain_,4,1);
    statLayout->addWidget(commentLabel,5,0,Qt::AlignRight|Qt::AlignTop);
    statLayout->addWidget(comment_,5,1);

    buttonLayout->addWidget(backButton,0,0,Qt::AlignRight | Qt::AlignTop);
    buttonLayout->addWidget(editButton,1,0,Qt::AlignRight | Qt::AlignTop);
    buttonLayout->addWidget(deleteButton,2,0,Qt::AlignRight | Qt::AlignTop);

    upperLayout->addWidget(statPane,0,1);
    upperLayout->addLayout(buttonLayout,0,3);

    mainLayout->addLayout(upperLayout,1,1);
    mainLayout->addWidget(image_,2,1,Qt::AlignCenter);
    setLayout(mainLayout);
}

void TradeView::setEntry(float entry)
{
    entry_->setText(QString::number(entry));
}

void TradeView::setExit(float exit)
{
    exit_->setText(QString::number(exit));
}

void TradeView::setStoploss(float sl)
{
    stoploss_->setText(QString::number(sl));
}

void TradeView::setGain(float gain)
{
    gain_->setText(QString::number(gain));
}

void TradeView::setDate(QDateTime dateTime)
{
    date_->setText(dateTime.toString());
}

void TradeView::setComment(QString comment)
{
    comment_->setText(comment);
}

void TradeView::setImage(QPixmap image)
{
    image_->setPixmap(image);
}
