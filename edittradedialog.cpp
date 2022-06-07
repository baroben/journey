#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QPushButton>

#include "edittradedialog.h"

EditDialog::EditDialog(QWidget *parent): QDialog(parent)
{
    entryText = new QLineEdit;
    exitText = new QLineEdit;
    stoplossText = new QLineEdit;
    gainText = new QLineEdit;
    dateText = new QDateTimeEdit;
    commentText = new QTextEdit;

    QPushButton *cancelBtn = new QPushButton("Cancel");
    QPushButton *saveBtn = new QPushButton("Save");
    connect(saveBtn, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelBtn, &QPushButton::clicked, this, &QDialog::reject);

    QLabel *entryLabel = new QLabel(tr("Entry"));
    QLabel *exitLabel = new QLabel(tr("Exit"));
    QLabel *stoplossLabel = new QLabel(tr("Stoploss"));
    QLabel *gainLabel = new QLabel(tr("Gain"));
    QLabel *dateLabel = new QLabel(tr("Date"));
    QLabel *commentLabel = new QLabel(tr("Comment"));

    QGridLayout *gLayout = new QGridLayout;
    gLayout->setColumnStretch(1, 2);

    gLayout->addWidget(entryLabel, 0, 0);
    gLayout->addWidget(entryText, 0, 1);

    gLayout->addWidget(exitLabel, 1, 0);
    gLayout->addWidget(exitText, 1, 1);

    gLayout->addWidget(stoplossLabel, 2, 0);
    gLayout->addWidget(stoplossText, 2, 1);

    gLayout->addWidget(gainLabel, 3, 0);
    gLayout->addWidget(gainText, 3, 1);

    gLayout->addWidget(dateLabel, 4, 0);
    gLayout->addWidget(dateText, 4, 1);

    gLayout->addWidget(commentLabel, 5, 0, Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(commentText, 5, 1, Qt::AlignLeft);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addWidget(saveBtn);
    btnLayout->addWidget(cancelBtn);

    gLayout->addLayout(btnLayout, 6,1, Qt::AlignRight);

    setLayout(gLayout);
}

void EditDialog::editTrade(Trade trade)
{
    entryText->setText(QString::number(trade.entry()));
    exitText->setText(QString::number(trade.exit()));
    stoplossText->setText(QString::number(trade.stoploss()));
    gainText->setText(QString::number(trade.gain()));
    dateText->setDateTime(trade.date());
    commentText->setText(trade.comment());
}

QVariant EditDialog::entry() const
{
    return entryText->text();
}

QVariant EditDialog::exit() const
{
    return exitText->text();
}

QVariant EditDialog::stoploss() const
{
    return stoplossText->text();
}

QVariant EditDialog::gain() const
{
    return gainText->text();
}

QVariant EditDialog::date() const
{
    return dateText->dateTime();
}

QVariant EditDialog::comment() const
{
    return commentText->toPlainText();
}

QVariant EditDialog::image() const
{
    return commentText->toPlainText();
}


