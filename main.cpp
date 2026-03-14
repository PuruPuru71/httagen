//#include "httagen.h"
#include "selectdialog.h"

#include <QApplication>

//int main(int argc, char *argv[])
//{
    //QApplication a(argc, argv);
    //httagen w;
    //w.show();
    //return a.exec();
//}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    selectdialog w;
    w.show();
    return a.exec();
}
