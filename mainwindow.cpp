#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "qpalette.h"
#include "qpainter.h"
#include "xycontrol.h"
#include "form.h"
#include <QDebug>
#include "writepaint.h"
#include "writepaints.h"
#include "ui_writepaints.h"
#include <QStatusBar>
#include <QDateTime>
#include <QTime>
#include <QTextCursor>
//#include "ui_writepaint.h"
int ksljdflk;
QSerialPort serial;

extern QByteArray ControlData;
QString Str_Enter = "\n";
QString Speed = "1000.0";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置为只读
    ui->recvTextEdit->setReadOnly(true);
//    ui->recvTextEdit->textCursor();
//    setWindowFlags(windowFlags()|Qt::WindowStaysOnTopHint);
    ui->recvTextEdit->setTextColor("#000000");
//    ui->recvTextEdit->moveCursor(
//    //状态栏 最多有一个
//    QStatusBar *statusBar = new QStatusBar;
//    //把状态栏放入窗口
//    setStatusBar(statusBar);


    setFocusPolicy(Qt::StrongFocus);
    //放入标签控件
    QLabel *label = new QLabel("版本信息 V1.0.0.2",this);

    QTime time =QTime::currentTime();

    qDebug()<<time.toString()<<time.minute()<<time.second();

    QLabel *label1 = new QLabel("时间:",this);
    //从左到右
    ui->statusBar->addWidget(label);

//    QLabel lab(time.toString(),this);
//    lab.setText(time.toString());
//    ui->statusBar->addPermanentWidget(&lab);
    //从右到左
    ui->statusBar->addPermanentWidget(label1);
    //手动调用timer的事件函数
    //  启动定时器
//    qDebug()<<startTimer(1000);
//    qDebug()<<startTimer(10000);
    QTimerEvent timerEvet(startTimer(1000));
    QApplication::sendEvent(this,&timerEvet);
    //连接信号和槽
    QObject::connect(&serial, &QSerialPort::readyRead, this, &MainWindow::serialPort_readyRead);
    //QObject::connect(&serial, &QSerialPort:, this, &MainWindow::serialPort_readyRead);
    //先刷新串口
    on_searchButton_clicked();
    //发送按键失能
    ui->sendButton->setEnabled(false);
    //波特率默认选择下拉第三项：9600
    ui->baudrateBox->setCurrentIndex(4);
//    ui->portNameBox->setCurrentIndex(1);
    //显示窗口字体大小设置
//    ui->recvPlainTextEdit
    ui->recvTextEdit->zoomIn(3);

    //新增音乐界面
    XYControl *xYControl = new XYControl;
    connect(ui->actionmusic,&QAction::triggered,xYControl,[=](){xYControl->show();});

//    //新增写字机绘图界面
//    WritePaint *writePaint = new WritePaint;
//    connect(ui->actionxieZiJi_2,&QAction::triggered,xYControl,[=](){writePaint->show();});

    //新增写字机绘图界面
    WritePaints *writePaints = new WritePaints;

//    writePaints->show();
    connect(ui->actiondiaoKeJi_2,&QAction::triggered,xYControl,[=](){writePaints->show();});

//    connect(ui->actionxieZiJi_2,&QAction::triggered,xYControl,[=](){writePaints->show();});
    //----------手动触发按键按下-------------------------
//    ui->sendButton->clicked(true);
//    ui->actionxieZiJi_2->triggered(true);
    //-------------------------------------------------

    //使用别的ui显示方法，
    //1.包含相应ui的两个头文件，
    //#include "writepaints.h"
    //#include "ui_writepaints.h"
    //把writepaints.h文件中的  Ui::WritePaints *ui; 从private: 提到 public
//        writePaints->ui->statusbar->addWidget(label);
}
//时间事件函数
void MainWindow::timerEvent(QTimerEvent *event)
{
//    qDebug()<<event;
    (void)event;
//    qDebug()<<event;
    QTime time =QTime::currentTime();
    static QLabel *lab =new QLabel(time.toString(),this);
    lab->setText(time.toString());
    ui->statusBar->addPermanentWidget(lab);
//    ui->actionxieZiJi_2->triggered(true);
//    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//设置主窗口属性，背景，填充等
void MainWindow::paintEvent(QPaintEvent *event)
{
    (void)event;    /* 去除警告 */
    //置顶于所有应用

    this->setWindowIcon(QIcon(":/image/Lunyeelogo.ico"));       //设置窗口左上角图标
    this->setWindowTitle(QString("仑业控制台"));
//    this->adjustSize();
//    setFixedSize(this->width(), this->height());        //设置固定窗口大小
//    /* 设置背景色 */
//    QPalette palette = this->palette();
//    palette.setBrush(QPalette::Background, QBrush(Qt::red));
//    this->setPalette(palette);
//    this->setAutoFillBackground(true);
    QPainter painter(this);
    //#808080
//    setPalette(QPalette("#ff0000"));
    setPalette(QPalette(Qt::gray));
    //painter.drawPixmap(0,0,width(),height(),QPixmap(":/image/4.jpg"));



}

void MainWindow::serialPort_readyRead()
{
    //从接收缓冲区中读取数据
    QByteArray buffer = serial.readAll();
    //从界面中读取以前收到的数据
//    QString recv = ui->recvTextEdit->toPlainText();
//    recv += QString(buffer);
    //清空以前的显示
//    ui->recvTextEdit->clear();
    //重新显示
//    ui->recvTextEdit->append(recv);
    //serial.
//    ui->recvTextEdit->setTextColor("#000000");

//    display(">>"+buffer);
//    ui->recvTextEdit->insertPlainText(">> "+buffer);

//    ui->recvTextEdit->appendPlainText("");
//    ui->recvTextEdit->append("");
//    ui->recvTextEdit->redo();
    ui->recvTextEdit->insertPlainText(">> "+buffer);
    ui->recvTextEdit->redo();
//    ui->recvTextEdit->append("");
}
void MainWindow::display(QByteArray data)
{
//    QTextCursor textCursor;
//    textCursor.endEditBlock();
//    ui->recvTextEdit->setTextCursor(textCursor);
//    QTextCursor cursor(ui->recvTextEdit->document());
//    cursor.beginEditBlock();
//    cursor.insertText(data);
//    qDebug()<<"1";
//    qDebug()<<(ui->recvTextEdit->textCursor());
//    ui->recvTextEdit->textCursor().End;
//    cursor.endEditBlock();
//    ui->recvTextEdit->undo();
//    ui->recvTextEdit->setTextCursor(ui->recvTextEdit->textCursor());
//    ui->recvTextEdit->setTextColor(color);
    ui->recvTextEdit->append(data);
}

void MainWindow::display(QByteArray data,QColor color)
{
    ui->recvTextEdit->setTextColor(color);
    ui->recvTextEdit->append(data);
}

void MainWindow::on_searchButton_clicked()
{
    ui->portNameBox->clear();
    //通过QSerialPortInfo查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->portNameBox->addItem(info.description()+"--->"+info.portName());
        if(info.description().indexOf("USB-SERIAL CH340")!=-1)
        {


            ui->portNameBox->setCurrentIndex(ui->portNameBox->count()-1);
//            qDebug()<<"USB-SERIAL CH340"<<ui->portNameBox->count();
        }
    }


}

void MainWindow::on_openButton_clicked()
{
//    const QSerialPortInfo *info = new QSerialPortInfo;

    if(ui->openButton->text()==QString("打开串口"))
    {

        //设置串口名
//        qDebug()<< info->portName();
        serial.setPortName(ui->portNameBox->currentText().right(4));
        //设置波特率
        serial.setBaudRate(ui->baudrateBox->currentText().toInt());
        //设置数据位数
        switch(ui->dataBitsBox->currentIndex())
        {
        case 8: serial.setDataBits(QSerialPort::Data8); break;
        default: break;
        }
        //设置奇偶校验
        switch(ui->ParityBox->currentIndex())
        {
        case 0: serial.setParity(QSerialPort::NoParity); break;
        default: break;
        }
        //设置停止位
        switch(ui->stopBitsBox->currentIndex())
        {
        case 1: serial.setStopBits(QSerialPort::OneStop); break;
        case 2: serial.setStopBits(QSerialPort::TwoStop); break;
        default: break;
        }
        //设置流控制
        serial.setFlowControl(QSerialPort::NoFlowControl);

        //打开串口
        if(!serial.open(QIODevice::ReadWrite))
        {
            QMessageBox::about(NULL, "提示", "无法打开串口！");
            return;
        }

        //下拉菜单控件失能
        ui->portNameBox->setEnabled(false);
        ui->baudrateBox->setEnabled(false);
        ui->dataBitsBox->setEnabled(false);
        ui->ParityBox->setEnabled(false);
        ui->stopBitsBox->setEnabled(false);

        ui->openButton->setText(QString("关闭串口"));
        //发送按键使能
        ui->sendButton->setEnabled(true);
    }
    else
    {
        //关闭串口
        serial.close();

        //下拉菜单控件使能
        ui->portNameBox->setEnabled(true);
        ui->baudrateBox->setEnabled(true);
        ui->dataBitsBox->setEnabled(true);
        ui->ParityBox->setEnabled(true);
        ui->stopBitsBox->setEnabled(true);

        ui->openButton->setText(QString("打开串口"));
        //发送按键失能
        ui->sendButton->setEnabled(false);
    }
}
void MainWindow::on_sendButton_clicked()
{
    //获取界面上的数据并转换成utf8格式的字节流
    QByteArray data = ui->sendTextEdit->text().toUtf8();
    if(ui->checkBox->checkState() == Qt::Checked)
    {
        data +=Str_Enter;
    }
    serial.write(data);

    display(data,"#21373d");
//    ui->recvTextEdit->insertPlainText(data);
}

void MainWindow::on_clearButton_clicked()
{
    ui->recvTextEdit->clear();

}

void MainWindow::on_clearSend_clicked()
{
    ui->sendTextEdit->clear();
}
//void MainWindow::gCodeCMD(float speed,float distance)
//{
//    QString Str_Enter = "\r\n";
//    QByteArray data = "$J=G21G91X0.0Y";
//    data += QString::number(speed);
//    data +="Z0.0F";
//    data += QString::number(distance);
//    data+=Str_Enter;
//    QByteArray data1 = "dfaser";
//    serial.write(data);
//    //serial.write(data);
//    //QSerialPort
//    //ui->sendTextEdit->append(data);
//}
//void sjikdjfi(void)
//{
//    QSerialPort new
//}
void MainWindow::sendmusic(void)
{
}



/***-----------------------------------------------------------------------*******/
/*以下为主界面的控制按键和步进距离、速度的控制槽函数
 *
 *
 *
 *
 * */
/***-----------------------------------------------------------------------*******/
//设置原点  G10 P0 L20 X0.0Y0.0Z0
void MainWindow::on_searchButton_9_clicked()
{
    //设置原点  G10 P0 L20 X0.0Y0.0Z0
//    QByteArray data = "G10 P0 L20 X0.0Y0.0Z0";
   //  字符串："G10 P0 L20 X0.0Y0.0Z0" 是 char * 类型
    QString data = "G10 P0 L20 X0.0Y0.0Z0";
    data+=Str_Enter;
    // QString型 转 QByteArray型 使用 toUtf8() 转 char * data()
    serial.write(data.toUtf8());
//    ui->recvTextEdit->setTextColor("green");
    display("<< "+data.toUtf8(),"green");
//    ui->recvTextEdit->insertPlainText("<< "+data);
//    ui->sendTextEdit->append(data.toUtf8());
            //insertPlainText：直接在文本最后追加
            //append：先换行，再追加
}
//回归原点  G90G0 X0Y0
void MainWindow::on_searchButton_8_clicked()
{
    //回归原点  G90G0 X0Y0
    QByteArray data = "G90G0 X0Y0";
    data+=Str_Enter;
    serial.write(data);
//    ui->sendTextEdit->setTextColor(Qt::red);
    //颜色表示法，
//    ui->recvTextEdit->setTextColor("#808080");
//    /<font
//            color=\"#808080\">
    display("<< "+data,"#808080");
//    ui->recvTextEdit->insertPlainText("<< "+data);
}

//Z- 移动
void MainWindow::on_searchButton_7_clicked()
{
    //Z- 移动
    QByteArray data = "$J=G21G91X0.0Y0.0Z-";
//    ui->Contrl_Step->text().toUtf8()
    data += ui->ZContrl_Step->text().toUtf8();
    data +="F";
//    Speed = ui->Run_Speed->toPlainText().toUtf8();
    Speed = "200";
    data+=Speed;
    data+=Str_Enter;
    serial.write(data);
//    ui->recvTextEdit->setTextColor("#E16B8C");
    display("<< "+data,"#E16B8C");
//    ui->recvTextEdit->insertPlainText("<< "+data);
}
//Z+ 移动
void MainWindow::on_searchButton_6_clicked()
{
    //Z+ 移动
    QByteArray data = "$J=G21G91X0.0Y0.0Z";
//    ui->Contrl_Step->text().toUtf8()
    data += ui->ZContrl_Step->text().toUtf8();
    data +="F";
//    Speed = ui->Run_Speed->toPlainText().toUtf8();
    Speed = "200";
    data+=Speed;
    data+=Str_Enter;
    serial.write(data);
//    ui->recvTextEdit->setTextColor("#F75C2F");
    display("<< "+data,"#F75C2F");
//    ui->recvTextEdit->insertPlainText("<< "+data);
}

//Y- 移动
void MainWindow::on_searchButton_4_clicked()
{
    //Y- 移动
    QByteArray data = "$J=G21G91X0.0Y-";
//    ui->Contrl_Step->text().toUtf8()
    data += ui->Contrl_Step->text().toUtf8();
    data +="Z0.0F";
//    Speed = ui->Run_Speed->toPlainText().toUtf8();
    Speed = ui->Run_Speed->text().toUtf8();
    data+=Speed;
    data+=Str_Enter;
    serial.write(data);
//    ui->recvTextEdit->setTextColor(Qt::blue);
    display("<< "+data,Qt::blue);
//    ui->recvTextEdit->insertPlainText("<< "+data);
}

//Y+ 移动
void MainWindow::on_searchButton_5_clicked()
{
    //Y+ 移动
    QByteArray data = "$J=G21G91X0.0Y";
//    ui->Contrl_Step->text().toUtf8()
    data += ui->Contrl_Step->text().toUtf8();
    data +="Z0.0F";
//    Speed = ui->Run_Speed->toPlainText().toUtf8();
    Speed = ui->Run_Speed->text().toUtf8();
    data+=Speed;
    data+=Str_Enter;
    serial.write(data);
    display("<< "+data,"#ee3f4d");
//    ui->recvTextEdit->setTextColor("#ee3f4d");
//    ui->recvTextEdit->insertPlainText("<< "+data);
}
//X- 移动
void MainWindow::on_searchButton_3_clicked()
{
    //X- 移动
    QByteArray data = "$J=G21G91X-";
    data += ui->Contrl_Step->text().toUtf8();
    data +="Y0.0Z0.0F";
    Speed = ui->Run_Speed->text().toUtf8();
    data+=Speed;
    data+=Str_Enter;
    serial.write(data);
//    ui->recvTextEdit->setTextColor("#4f383e");
    display("<< "+data,"#4f383e");
//    ui->recvTextEdit->insertPlainText("<< "+data);
//    ui->sendTextEdit->append(data);
}

//X+ 移动
void MainWindow::on_searchButton_2_clicked()
{
    //X+ 移动
    QString data = "$J=G21G91X";
    data += ui->Contrl_Step->text();
    data +="Y0.0Z0.0F";
    Speed = ui->Run_Speed->text();
    data+=Speed;
    data+=Str_Enter;
    serial.write(data.toUtf8());
//    ui->recvTextEdit->colorCount();
//    ui->recvTextEdit->setTextColor("#132c33");
    display("<< "+data.toUtf8(),"#132c33");
//    ui->recvTextEdit->insertPlainText("<< "+data);
}


//发送新行的选项槽函数
void MainWindow::on_checkBox_stateChanged(int arg1)
{
    qDebug()<< arg1;
}

void MainWindow::on_sendButton_2_clicked()
{
    QString data={0x18};
    data +=Str_Enter;
    serial.write(data.toUtf8());
    display(data.toUtf8(),"#2bae85");
}


void MainWindow::on_Laser(QString gongLv="30")
{
    QString data;
    ui->onLaser->setText("关闭激光");
    data ="M3S"+gongLv +Str_Enter;
//    data ="M3S"+ui->Contrl_Laser->text() +Str_Enter;
    data +="G1F1000" +Str_Enter;
    serial.write(data.toUtf8());
    display(data.toUtf8(),"#0000FF");
}
void MainWindow::off_Laser(void)
{
    ui->onLaser->setText("打开激光");
    serial.write("M5"+Str_Enter.toUtf8());
    display("M5"+Str_Enter.toUtf8(),"#0000FF");
}

void MainWindow::on_onLaser_clicked()
{
    QString data;
    static bool flag =0;
    if(!flag)
    {
        on_Laser(ui->Contrl_Laser->text());
        flag = true;
    }
    else {
        off_Laser();
        flag = false;
    }

}

//void MainWindow::keyPressEvent(QKeyEvent *)
//{
//    static int a=0;
//    qDebug()<<a++;
//}

void MainWindow::keyReleaseEvent(QKeyEvent *key)
{
//    key->key();

    switch (key->key()) {
    case Qt::Key_Left :
        on_searchButton_3_clicked();
        break;
    case Qt::Key_Right :
        on_searchButton_2_clicked();
        break;
    case Qt::Key_Up :
        on_searchButton_5_clicked();
        break;
    case Qt::Key_Down :
        on_searchButton_4_clicked();
        break;

    }
//    static int a=0;
//    qDebug()<<a++<<Qt::Key_Down;
//    qDebug()<<a++<<Qt::Key_Down;

}

void MainWindow::on_openGCodefile_clicked()
{

}
