#ifndef WRITEPAINTS_H
#define WRITEPAINTS_H

#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QLabel>
#include "paintyuan.h"
#include "ui_paintyuan.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
namespace Ui {
class WritePaints;
}

class WritePaints : public QMainWindow
{
    Q_OBJECT

public:
    explicit WritePaints(QWidget *parent = nullptr);
    ~WritePaints();
    Ui::WritePaints *ui;
    void toolBarSet(void);
    QWidget *paint = new QWidget;
    QPushButton *paintButton = new QPushButton("开始绘图");
    QPushButton *paintCircularButton = new QPushButton("画圆");
    QLabel *yuanXin = new QLabel("圆心");
    QLineEdit *yuanXinX =new QLineEdit("0");
    QLineEdit *yuanXinY =new QLineEdit("0");

    QLabel *banJing = new QLabel("半径");

    QLineEdit *banJingX =new QLineEdit("1");
    QLineEdit *banJingY =new QLineEdit("1");
    QDockWidget *dockWidget =new QDockWidget("圆");
    void on_paintCircularButton_clicked();
    void on_yuan_clicked();
    void on_paintRectangleButton_clicked();
    void on_Rectangle_clicked();
private slots:
//    void on_pushButton_clicked();


private:
    PaintYuan *paintYuan;
    MainWindow *mainwindow;
    QMetaObject::Connection coYuan;
    QMetaObject::Connection coRectangle;


};

#endif // WRITEPAINTS_H
