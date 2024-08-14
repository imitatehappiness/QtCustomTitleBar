#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSizeGrip>
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){

    ui->setupUi(this);

    this->statusBar()->setSizeGripEnabled(false);

    initTimer();
    initMenuBar();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::initMenuBar(){
    mMenuBar = new QMenuBar();
    setMenuBar(mMenuBar);
    QMenu *settingsMenu = mMenuBar->addMenu(tr("&Settings"));

    QAction *exitAction = settingsMenu->addAction(tr("&Exit"));
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);
}

void MainWindow::initTimer(){
    const uint interval = 1000;

    QTimer *t = new QTimer(this);
    t->setInterval(interval);
    connect(t, &QTimer::timeout, [&]() {
       QString time1 = QTime::currentTime().toString();
       ui->clock->setText(time1);
    } );
    t->start();
}

