#include "mainwindow.h"

#include <QApplication>

#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("C:/Users/ODYSSEY/Desktop/img/HBrain_Logo.png"));

    MainWindow w;

    QFile f("C:/Users/ODYSSEY/Desktop/qdarkstyle/style.qss");
    f.open(QFile::ReadOnly | QFile::Text);
    QTextStream ts(&f);
    QString s = ts.readAll();
    f.close();
    w.setStyleSheet(s);

    w.show();
    //w.showFullScreen();

    //QApplication::setQuitOnLastWindowClosed(false);


    return a.exec();
}
