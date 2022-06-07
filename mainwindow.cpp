#include "mainwindow.h"
#include <QPushButton>
#include "controller.h"
#include "ui_mainwindow.h"
#include <QTabWidget>
#include "portefolioview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    controller = new Controller;
    setCentralWidget(controller);

    setStyleSheet("QPushButton { background-color: #3A3B3C;border-radius: 5px;min-width: 170;min-height: 30;font-weight: 600}"
                  "QPushButton:hover {background-color : #303132} "
                  "* {font : roboto;background-color : #141d26; color : #E4E6EB;font-weight: 550; font-size: 16px}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

