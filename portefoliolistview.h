#ifndef PORTEFOLIOLISTVIEW_H
#define PORTEFOLIOLISTVIEW_H

#include <QListView>
#include <QPushButton>
#include <QWidget>

class PortefolioListView : public QWidget
{
    Q_OBJECT
public:
    PortefolioListView(QWidget *parent = nullptr);
    QListView *portefolioList() const;

private:
    QListView *portefolioList_;
    QPushButton *addPortefolioButton;

signals:
    void addPortefolio();
};

#endif // PORTEFOLIOLISTVIEW_H
