#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    if (translator.load(QLocale::system(), ""))
        a.installTranslator(&translator);

    MainWindow w;
    w.show();

    return a.exec();
}
