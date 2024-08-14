#include "mainwindow.h"
#include "windowframe.h"

#include <QApplication>
#include <QProxyStyle>
#include <QStyleFactory>
#include <QFile>

const QString style = "Fusion";
const QString appstylePath = ":/recources/style/appstyles.qss";

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    a.setStyle(new QProxyStyle(QStyleFactory::create(style)));

    QFile styleFile(appstylePath);
    styleFile.open(QFile::ReadOnly);
    QString styleQSS = styleFile.readAll();

    a.setStyleSheet(styleQSS);

    WindowFrame w(nullptr, new MainWindow());
    w.show();
    return a.exec();
}
