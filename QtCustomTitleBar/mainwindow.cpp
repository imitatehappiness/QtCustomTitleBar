#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSizeGrip>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){

    ui->setupUi(this);
    this->statusBar()->setSizeGripEnabled(false);
}

MainWindow::~MainWindow(){
    delete ui;
}

