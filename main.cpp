#include <QtGui/QApplication>
#include <stdio.h>
#include "mainwindow.h"
#include "obviousmethod.h"
#include "notobviousmethod.h"


int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
    // ObviousMethod obviousMethod;
     // obviousMethod.testConstant();
     //obviousMethod.show();
    NotObviousMethod notObviousMethod;
     notObviousMethod.show();
    return a.exec();
}
