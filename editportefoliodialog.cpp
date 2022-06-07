#include "editportefoliodialog.h"
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

EditPortefolioDialog::EditPortefolioDialog(QWidget *parent) : QDialog(parent)
{
    descriptionText = new QTextEdit;
    nameText = new QLineEdit;

    QPushButton *cancelBtn = new QPushButton("Cancel");
    QPushButton *saveBtn = new QPushButton("Save");
    connect(saveBtn, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelBtn, &QPushButton::clicked, this, &QDialog::reject);

    QLabel *nameLabel = new QLabel(tr("Name"));
    QLabel *descriptionLabel = new QLabel(tr("Description"));

    QGridLayout *gLayout = new QGridLayout;
    gLayout->setColumnStretch(1, 2);

    gLayout->addWidget(nameLabel, 0, 0);
    gLayout->addWidget(nameText, 0, 1);

    gLayout->addWidget(descriptionLabel, 1, 0);
    gLayout->addWidget(descriptionText, 1, 1);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addWidget(saveBtn);
    btnLayout->addWidget(cancelBtn);

    gLayout->addLayout(btnLayout, 2,1, Qt::AlignRight);

    setLayout(gLayout);
}

void EditPortefolioDialog::editPortefolio(Portefolio portefolio)
{
    nameText->setText(portefolio.name());
    descriptionText->setText(portefolio.description());
}

QVariant EditPortefolioDialog::description() const
{
    return descriptionText->toPlainText();
}

QVariant EditPortefolioDialog::name() const
{
    return nameText->text();
}
