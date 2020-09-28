#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "qpalette.h"
#include "qpainter.h"
#include <QDebug>

QString Str_Enter = "\r\n";
QString Speed = "1000.0";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/Lunyeelogo.ico"));       //设置窗口左上角图标
    this->setWindowTitle(QString("仑业写字机控制台"));
    ui->Xup->setIcon(QIcon(":/image/1.jpg"));
    //setFixedSize(this->width(), this->height());        //设置固定窗口大小
//    /* 设置背景色 */
//    QPalette palette = this->palette();
//    palette.setBrush(QPalette::Background, QBrush(Qt::red));
//    this->setPalette(palette);
//    this->setAutoFillBackground(true);

    //连接信号和槽
    QObject::connect(&serial, &QSerialPort::readyRead, this, &MainWindow::serialPort_readyRead);

    //发送按键失能
    ui->sendButton->setEnabled(false);
    //波特率默认选择下拉第四项：115200
    ui->baudrateBox->setCurrentIndex(4);
    ui->portNameBox->clear();
    /***初始化刷新串口 *******/
    //通过QSerialPortInfo查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->portNameBox->addItem(info.portName());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    (void)event;    /* 去除警告 */
//    QPainter painter(this);
//    painter.drawPixmap(0,0,width(),height(),QPixmap(":/image/Lunyee.jpg"));
    //设置窗口背景色
        setPalette(QPalette(Qt::gray));
//        setPalette(QPalette(qRgba(43,115,175,1)));
        setAutoFillBackground(true);
}

void MainWindow::serialPort_readyRead()
{
    //从接收缓冲区中读取数据
    QByteArray buffer = serial.readAll();
    //从界面中读取以前收到的数据
    QString recv = ui->recvTextEdit->toPlainText();
    recv += QString(buffer);
    //清空以前的显示
    ui->recvTextEdit->clear();
    //重新显示
    ui->recvTextEdit->append(recv);
}


void MainWindow::on_searchButton_clicked()
{
    ui->portNameBox->clear();
    //通过QSerialPortInfo查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->portNameBox->addItem(info.portName());
    }
}

void MainWindow::on_openButton_clicked()
{
    if(ui->openButton->text()==QString("打开串口"))
    {
        //设置串口名
        serial.setPortName(ui->portNameBox->currentText());
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
    QByteArray data = ui->sendTextEdit->toPlainText().toUtf8();
    serial.write(data);
}

void MainWindow::on_clearButton_clicked()
{
    ui->recvTextEdit->clear();
}

void MainWindow::on_clearSend_clicked()
{
    ui->sendTextEdit->clear();
}

void MainWindow::on_Xup_clicked()
{
    //X+ 移动
    QByteArray data = "$J=G21G91X";
    data += ui->Contrl_Step->toPlainText().toUtf8();
    data +="Y0.0Z0.0F";
    Speed = ui->Run_Speed->toPlainText().toUtf8();
    data+=Speed;
    data+=Str_Enter;
    serial.write(data);
    ui->sendTextEdit->append(data);
    //qDebug() << data ;
}

void MainWindow::on_Xdown_clicked()
{
    //X- 移动
    QByteArray data = "$J=G21G91X-";
    data += ui->Contrl_Step->toPlainText().toUtf8();
    data +="Y0.0Z0.0F";
    Speed = ui->Run_Speed->toPlainText().toUtf8();
    data+=Speed;
    data+=Str_Enter;
    serial.write(data);
    ui->sendTextEdit->append(data);
}

//void MainWindow::on_sendTextEdit_textChanged()
//{
//    QByteArray buffer = serial.writeData(NULL);
//    //从界面中读取以前收到的数据
//    QString recv = ui->sendTextEdit->toPlainText();
//    recv += QString(buffer);
//    //清空以前的显示
//    ui->sendTextEdit->clear();
//    //重新显示
//    ui->sendTextEdit->append(recv);
//}

void MainWindow::on_sendTextEdit_textChanged()
{

}

void MainWindow::on_Yup_2_clicked()
{
    //>>> G10 P0 L20 X0.0Y0.0Z0

}

void MainWindow::on_Yup_clicked()
{
    //Y+ 移动
    QByteArray data = "$J=G21G91X0.0Y";
    data += ui->Contrl_Step->toPlainText().toUtf8();
    data +="Z0.0F";
    Speed = ui->Run_Speed->toPlainText().toUtf8();
    data+=Speed;
    data+=Str_Enter;
    serial.write(data);
    ui->sendTextEdit->append(data);
}

void MainWindow::on_Ydown_clicked()
{
    //Y- 移动
    QByteArray data = "$J=G21G91X0.0Y-";
    data += ui->Contrl_Step->toPlainText().toUtf8();
    data +="Z0.0F";
    Speed = ui->Run_Speed->toPlainText().toUtf8();
    data+=Speed;
    data+=Str_Enter;
    serial.write(data);
    ui->sendTextEdit->append(data);
}

void MainWindow::on_Set_Origin_Button_clicked()
{
    //设置原点  G10 P0 L20 X0.0Y0.0Z0
    QByteArray data = "G10 P0 L20 X0.0Y0.0Z0";
    data+=Str_Enter;
    serial.write(data);
    ui->sendTextEdit->append(data);
}

void MainWindow::on_To_Origin_Button_clicked()
{
    //回归原点  G90G0 X0Y0
    QByteArray data = "G90G0 X0Y0";
    data+=Str_Enter;
    serial.write(data);
    ui->sendTextEdit->append(data);
}
