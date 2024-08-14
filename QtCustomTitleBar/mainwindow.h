#pragma once

#include <QMainWindow>
#include <QMenuBar>

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
    void initMenuBar();
    void initTimer();
private:
    Ui::MainWindow *ui;
    QMenuBar *mMenuBar;
};
