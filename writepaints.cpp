#include "writepaints.h"
#include "ui_writepaints.h"
#include <QToolBar>
#include <QToolBox>
#include <QToolButton>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QDebug>
#include <QDockWidget>
#include <QMetaObject>


WritePaints::WritePaints(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WritePaints)
{
    ui->setupUi(this);
//    MainWindow *mainWindow = new MainWindow;
//    mainWindow->close();
//    setWindowFlags(/*windowFlags()|*/Qt::WindowStaysOnTopHint);
//    setWindowFlags(windowFlags()|Qt::WindowCloseButtonHint);
    toolBarSet();


//    coYuan = connect(paintYuan->ui->pushButton,&QPushButton::clicked,this,[=](){on_yuan_clicked();});
//    coRectangle = connect(paintYuan->ui->pushButton,&QPushButton::clicked,this,[=](){on_Rectangle_clicked();});

    paintYuan =new PaintYuan(this);

    paintYuan->show();

    //    先显示画圆
    on_paintCircularButton_clicked();
    paintYuan->move(79,23);
//    paintYuan->move(ui->toolBar->width(),ui->toolBar->y());

}
/***-------------------------------------
 * 工具栏设置
 * 2020年11月3日08:45:27
 * ------------------------------------*/
void WritePaints::toolBarSet(void)
{
    //    QToolBox *toolBox = new QToolBox(this);
    //    QToolBox toolBox(ui->toolBar);

    //    //工具栏
    //    QToolBar *toolBar =new QToolBar(this);

        //把工具栏放入窗口
        addToolBar(Qt::LeftToolBarArea,ui->toolBar);

        //设置只能左右停靠，不能上下停靠
        ui->toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
        //设置不能悬停，浮动，只能停靠
        ui->toolBar->setFloatable(false);
        //设置移动使能（总开关）
        ui->toolBar->setMovable(true);

        //设置工具栏内容
        //方式1
        ui->toolBar->addAction("命令窗口");
        ui->toolBar->addSeparator();
    //    //方式2
    //    toolBar->addAction(controlAction);
    //    toolBar->addSeparator();
//        paintCircularButton =new QPushButton(ui->toolBar);
        paintCircularButton->setText("画圆");
        ui->toolBar->addWidget(paintCircularButton);
        connect(paintCircularButton,&QPushButton::clicked,ui->toolBar,[=](){on_paintCircularButton_clicked();});
//        paintCircularButton->setText("123");
        ui->toolBar->addSeparator();
        //工具栏添加控件
        QPushButton *btn0 = new QPushButton("画矩形",this);
        btn0->adjustSize();
        ui->toolBar->addWidget(btn0);
        ui->toolBar->addSeparator();
        connect(btn0,&QPushButton::clicked,ui->toolBar,[=](){on_paintRectangleButton_clicked();});
}
WritePaints::~WritePaints()
{
    delete ui;
}

void WritePaints::on_paintCircularButton_clicked()
{
    paintYuan->close();
    paintYuan =new PaintYuan(this);
    coYuan = connect(paintYuan->ui->pushButton,&QPushButton::clicked,this,[=](){on_yuan_clicked();});
    coRectangle = connect(paintYuan->ui->pushButton,&QPushButton::clicked,this,[=](){on_Rectangle_clicked();});
    disconnect(coRectangle);

    paintYuan->move(ui->toolBar->width(),ui->toolBar->y());
    qDebug()<<ui->toolBar->width()<<ui->toolBar->y();
    paintYuan->ui->label_Title->setText("画圆");
    paintYuan->ui->label_banJingX->setText("半径");
    paintYuan->ui->label_banJingY->close();
    paintYuan->ui->banJingY->close();

    paintYuan->show();

}

void WritePaints:: on_yuan_clicked()
{
    QString data;
    mainwindow = new MainWindow;
    data = "G01G91X" + paintYuan->ui->yuanXinX->text().toUtf8();
    data +="Y" + paintYuan->ui->yuanXinY->text().toUtf8();
    data +="F"+paintYuan->ui->runSpeed->text() + "\n";
//    serial.write(data.toUtf8());
    qDebug()<<data.toUtf8();
//  设置运行激光功率
    mainwindow->on_Laser(paintYuan->ui->maxLaser_Control->text());
    data += "G02G91X0Y0I0";
    data +="J" +paintYuan->ui->banJingX->text().toUtf8();
    data +="F"+paintYuan->ui->runSpeed->text() + "\n";
    serial.write(data.toUtf8());
    qDebug()<<data.toUtf8();
//      设置停止激光功率
    mainwindow->on_Laser(paintYuan->ui->minLaser_Control->text());
    qDebug()<<"圆";
}
void WritePaints::on_paintRectangleButton_clicked()
{
    paintYuan->close();
//    delete paintYuan;
    paintYuan =new PaintYuan(this);
    coYuan = connect(paintYuan->ui->pushButton,&QPushButton::clicked,this,[=](){on_yuan_clicked();});
    coRectangle = connect(paintYuan->ui->pushButton,&QPushButton::clicked,this,[=](){on_Rectangle_clicked();});
    disconnect(coYuan);

    paintYuan->move(ui->toolBar->width(),ui->toolBar->y());
    paintYuan->ui->label_Title->setText("画矩形");
    paintYuan->ui->label_banJingX->setText("长");
    paintYuan->ui->label_banJingY->show();
    paintYuan->ui->banJingY->show();
    paintYuan->show();
}
void WritePaints:: on_Rectangle_clicked()
{
    QString data;

//    mainwindow
    mainwindow = new MainWindow;
    data = "G01G91X" + paintYuan->ui->yuanXinX->text().toUtf8();
    data +="Y" + paintYuan->ui->yuanXinY->text().toUtf8();
    data +="F"+paintYuan->ui->runSpeed->text() + "\n";
//    serial.write(data.toUtf8());
    qDebug()<<data.toUtf8();
//  设置运行激光功率
    mainwindow->on_Laser(paintYuan->ui->maxLaser_Control->text());
//    左边
    data += "G01G91X0Y";
    data +=paintYuan->ui->banJingY->text().toUtf8();
    data +="F"+paintYuan->ui->runSpeed->text() + "\n";
//    上边
    data += "G01G91X";
    data +=paintYuan->ui->banJingX->text().toUtf8();
    data +="F"+paintYuan->ui->runSpeed->text() + "\n";
//    右边
    data += "G01G91X0Y-";
    data +=paintYuan->ui->banJingY->text().toUtf8();
    data +="F"+paintYuan->ui->runSpeed->text() + "\n";
    //    下边
    data += "G01G91X-";
    data +=paintYuan->ui->banJingX->text().toUtf8();
    data +="F"+paintYuan->ui->runSpeed->text() + "\n";

    serial.write(data.toUtf8());
    qDebug()<<data.toUtf8();
//      设置停止激光功率
    mainwindow->on_Laser(paintYuan->ui->minLaser_Control->text());
    qDebug()<<"矩形";
//    qDebug()<<paintYuan->ui->yuanXinY->text().toInt();
}
