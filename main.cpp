#include "httagen.h"
#include "selectdialog.h"

#include <QApplication>
#include <algorithm>

char* getCmdOption(char ** begin, char ** end, const std::string & option)
{
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(char** begin, char** end, const std::string& option)
{
    return std::find(begin, end, option) != end;
}

int main(int argc, char *argv[])
{
    if(cmdOptionExists(argv, argv+argc, "--wip-gui-refresh")) {
        QApplication a_gr(argc,argv);
        httagen w_gr;
        w_gr.show();
        return a_gr.exec();
    }
    else {
    QApplication a(argc, argv);
    selectdialog w;
    w.show();
    return a.exec();
    }
}
