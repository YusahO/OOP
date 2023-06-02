#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;
    w.show();

    // qDebug() << QStyleFactory::keys();
    QApplication::setStyle("Windows");

    return app.exec();
}
