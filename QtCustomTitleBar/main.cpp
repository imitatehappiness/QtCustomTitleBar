#include "mainwindow.h"
#include "windowframe.h"

#include <QApplication>
#include <QProxyStyle>
#include <QStyleFactory>
#include <QFile>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    a.setStyle(new QProxyStyle(QStyleFactory::create("Fusion")));

    QFile styleFile("resources/style/appstyles.qss");
    styleFile.open(QFile::ReadOnly);
    QString styleQSS = styleFile.readAll();

    a.setStyleSheet(styleQSS);

    WindowFrame w(nullptr, new MainWindow());
    w.show();
    return a.exec();
}
