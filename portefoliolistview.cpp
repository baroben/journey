#include "portefoliolistview.h"
#include <QVBoxLayout>

PortefolioListView::PortefolioListView(QWidget *parent)
    : QWidget{parent}
{
    portefolioList_ = new QListView;
    portefolioList_->setStyleSheet("* {border:0;background-color:#242526;border-radius:5px}");

    addPortefolioButton = new QPushButton("Add a portefolio");
    addPortefolioButton->setGeometry(0,0,600,30);
    connect(addPortefolioButton, SIGNAL(clicked()), this, SIGNAL(addPortefolio()));

    QGridLayout *mainLayout = new QGridLayout;
    QGridLayout *upperLayout = new QGridLayout;
    QGridLayout *buttonLayout = new QGridLayout;

    upperLayout->setColumnStretch(2, 2);
    buttonLayout->setRowStretch(3, 2);
    mainLayout->setRowStretch(2, 10);
    mainLayout->setRowStretch(1, 2);
    mainLayout->setRowStretch(0, 1);
    mainLayout->setColumnStretch(0, 2);
    mainLayout->setColumnStretch(1, 6);
    mainLayout->setColumnStretch(2, 2);

    buttonLayout->addWidget(addPortefolioButton,0,0,Qt::AlignRight | Qt::AlignTop);
    upperLayout->addLayout(buttonLayout,0,3);

    mainLayout->addLayout(upperLayout,1,1);
    mainLayout->addWidget(portefolioList_,2,1,Qt::AlignCenter);
    setLayout(mainLayout);
}

QListView *PortefolioListView::portefolioList() const
{
    return portefolioList_;
}
