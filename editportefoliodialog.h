#ifndef EDITPORTEFOLIODIALOG_H
#define EDITPORTEFOLIODIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QLineEdit>
#include "portefolio.h"

class EditPortefolioDialog : public QDialog
{
        Q_OBJECT

    public:
        EditPortefolioDialog(QWidget *parent = nullptr);
        void editPortefolio(Portefolio portefolio);

        QVariant name() const;
        QVariant description() const;

    private:
        QLineEdit *nameText;
        QTextEdit *descriptionText;
    };

#endif // EDITPORTEFOLIODIALOG_H
