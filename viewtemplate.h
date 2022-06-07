#ifndef VIEWTEMPLATE_H
#define VIEWTEMPLATE_H

#include <QLayout>

class ViewTemplate
{
public:
    ViewTemplate();
    static void setTemplate(QLayout *mainLayout,QLayout *lowerLayout, QLayout *upperLayout, QLayout *buttonLayout, QLayout *descriptionLayout);
};

void setTemplate(QGridLayout *mainLayout, QGridLayout *lowerLayout,QGridLayout *upperLayout, QGridLayout *buttonLayout, QGridLayout *descriptionLayout){
   descriptionLayout->setColumnStretch(1, 2);
   upperLayout->setColumnStretch(2, 2);
   buttonLayout->setRowStretch(3, 2);
   mainLayout->setRowStretch(2, 10);
   mainLayout->setRowStretch(1, 2);
   mainLayout->setRowStretch(0, 1);
   mainLayout->setColumnStretch(0, 2);
   mainLayout->setColumnStretch(2, 2);

   QWidget *statPane = new QWidget;
   statPane->setStyleSheet("* {background-color:#242526;border-radius: 5px}");
   statPane->setLayout(descriptionLayout);

   upperLayout->addWidget(statPane,0,1);
   upperLayout->addLayout(buttonLayout,0,3);

   mainLayout->addLayout(upperLayout,1,1);
   mainLayout->addLayout(lowerLayout,2,1,Qt::AlignCenter);
}
#endif // VIEWTEMPLATE_H
