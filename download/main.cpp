#include "mainwindow.h"

#include <QApplication>
#include "downloadmanager.h"
#include "getjson.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QFile file(":/qss/psblack.css");
//    if (file.open(QFile::ReadOnly)) {
//        QString qss = QLatin1String(file.readAll());
//        QString paletteColor = qss.mid(20, 7);
//        qApp->setPalette(QPalette(QColor(paletteColor)));
//        qApp->setStyleSheet(qss);
//        file.close();
//    }
    GetJson json;

//    MainWindow w;
//    w.show();

    return a.exec();
}

