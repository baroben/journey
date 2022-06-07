#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "portefolio.h"
#include "controller.h"
#include "portefolioview.h"
#include "tradeview.h"
#include <QPushButton>
#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Controller *controller;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
