#include <QPushButton>
#include <QGridLayout>
#include "portefolioview.h"

PortefolioView::PortefolioView()
{
    tradeTableView_ = new QTableView;
    tradeTableView_->setStyleSheet("* {border:0;background-color:#242526;border-radius:5px}");
    connect(tradeTableView_,SIGNAL(clicked(QModelIndex)), this, SIGNAL(tradeSelected()));

    deleteButton = new QPushButton(tr("Delete the Portefolio"));
    addTradeButton = new QPushButton(tr("Add a Trade"));
    editButton = new QPushButton(tr("Edit the Portefolio"));
    backButton = new QPushButton(tr("All Portefolios"));

    connect(deleteButton,SIGNAL(clicked()), this, SIGNAL(portefolioDeleted()));
    connect(addTradeButton,SIGNAL(clicked()), this, SIGNAL(addTrade()));
    connect(editButton,SIGNAL(clicked()), this, SIGNAL(portefolioEdited()));
    connect(backButton,SIGNAL(clicked()), this, SIGNAL(goBack()));

    name_ = new QLabel;
    description_ = new QLabel;

    name_->setStyleSheet("font:bold 25px");

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

    statLayout->addWidget(name_,0,0,Qt::AlignTop);
    statLayout->addWidget(description_,1,0,Qt::AlignTop);

    statPane->setLayout(statLayout);

    buttonLayout->addWidget(backButton,0,0,Qt::AlignRight | Qt::AlignTop);
    buttonLayout->addWidget(editButton,1,0,Qt::AlignRight | Qt::AlignTop);
    buttonLayout->addWidget(deleteButton,2,0,Qt::AlignRight | Qt::AlignTop);
    buttonLayout->addWidget(addTradeButton,3,0,Qt::AlignRight | Qt::AlignTop);

    upperLayout->addWidget(statPane,0,1);
    upperLayout->addLayout(buttonLayout,0,3);

    mainLayout->addLayout(upperLayout,1,1);
    mainLayout->addWidget(tradeTableView_,2,1,Qt::AlignCenter);
    setLayout(mainLayout);
}

QTableView *PortefolioView::tradeTableView() const
{
    return tradeTableView_;
}

void PortefolioView::name(QString name)
{
    name_->setText(name);
}

void PortefolioView::description(QString description)
{
    description_->setText(description);
}


