#include "writepaint.h"
#include "ui_writepaint.h"
#include <QIcon>
#include <QPainter>
#include <qdrawutil.h>
#include <QPoint>
#include <QPalette>
#include <QPainter>
#include <QPen>
#include <QPaintEvent>
#include <QToolBar>
#include <QToolBox>
#include <QToolButton>

#include <QTextEdit>
#include <QDockWidget>
#include <QStatusBar>
#include <QPushButton>
#include "mainwindow.h"
#include <QMenuBar>
#include <QDebug>
#include <QToolBar>
#include <QLabel>
WritePaint::WritePaint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WritePaint)
{
    ui->setupUi(this);
    this->adjustSize();
//    this->setWindowIcon(QIcon(":/image/music.png"));
    this->setWindowTitle("写字机绘图");

//    QToolBar *toolBar = new QToolBar(this);
//    //把工具栏放入窗口

//    addToolBar(Qt::LeftToolBarArea,toolBar);

//    //设置只能左右停靠，不能上下停靠
//    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
//    //设置不能悬停，浮动，只能停靠
//    toolBar->setFloatable(false);
//    //设置移动使能（总开关）
//    toolBar->setMovable(true);

}

void WritePaint::paintEvent(QPaintEvent *)
{
//    QPen pen;
       //1、画字

       QPainter painter(this);
       //painter.setPen(Qt::blue);
//       painter.setPen(Qt::blue);
//       painter.setFont(QFont("Arial", 10));
//       painter.drawText(rect(), Qt::AlignCenter, "Qt");
       //2、画多边形
       QRectF rectangle(100.0, 20.0, 80.0, 60.0);
       int startAngle = 30 * 16;
       int spanAngle = 120 * 16;

       painter.drawArc(rectangle, startAngle, spanAngle);

       static const QPointF points[4] = {
           QPointF(10.0, 80.0),
           QPointF(20.0, 10.0),
           QPointF(80.0, 30.0),
           QPointF(90.0, 70.0)
       };
       painter.drawConvexPolygon(points, 4);


}



void WritePaint::paintrCircular(float center,float radius)
{
//    QPalette palette;
//    QPen pen;
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 50));
    painter.drawText(rect(), Qt::AlignCenter, "Qt");

    painter.drawLine(1,1,5,5);
//    drawLine(1,1,2,2);
//    qDrawWinPanel(1,1,5,5,palette,true);



}

WritePaint::~WritePaint()
{
    delete ui;
}
