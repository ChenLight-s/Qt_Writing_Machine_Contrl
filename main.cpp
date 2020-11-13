#include "mainwindow.h"
#include <QApplication>
#include "MidiFile.h"
#include "Options.h"
#include <iostream>
#include <iomanip>
#include <QDebug>
using namespace std;
using namespace smf;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
