#include "xycontrol.h"
#include "ui_xycontrol.h"
#include <QPushButton>
#include <QtMath>
#include <QDebug>
#include <QLine>
#include <QTextEdit>
#include <QLineEdit>
#include <QString>
#include <string.h>
#include<QFile>
#include<QFileDialog>
#include<QDir>
#include<QTextStream>
#include<QMessageBox>
#include <QThread>
#include <QDateTime>
#include <QTime>
#include <windows.h>
#include "midi.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>
#include "MidiFile.h"
#include "Options.h"
#include <iostream>
#include <iomanip>
//#include "mainwindow.h"
/***
 * 使用12平均律
 * 以A4 440Hz 频率为标准
 *一个半音为（2开12次方） 12√2 ≈ 1.05946
 *八度为12个半音分别为：C4 C#4/Db4 D4 D#4/Eb4 E4 F4 F#4/Gb4 G4 G#4/Ab4 A4 A#4/Bb4 B4
 *
 *
 *
*******/
#define PitchBasics 1.05946
#define A4  440.00              // 6,4,1
#define Bb4 A4*PitchBasics      // 6.5,4,1
#define B4  Bb4*PitchBasics     // 7,4,1
#define Ab4 A4/PitchBasics      // 5.5,4,1

#define G4  Ab4/PitchBasics     // 5,4,1
#define Gb4 G4/PitchBasics      // 4.5,4,1
#define F4  Gb4/PitchBasics     // 4,4,1
#define E4  F4/PitchBasics      // 3,4,1
#define Eb4 E4/PitchBasics      // 2.5,4,1
#define D4  Eb4/PitchBasics     // 2,4,1
#define Db4 D4/PitchBasics      // 1.5,4,1
#define C4  Db4/PitchBasics     // 1,4,1
#define Xiu 40.0
//extern QSerialPort serial;
//#define Octave
QByteArray ControlData;
float beatsPerMin =120.0;
musicStruct musicStruct1[128]={};
int mus0[200] ;
float mus1[200] ;
float mus2[200] ;
int musicnum;
bool StopFlag = false;
XYControl::XYControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::XYControl)
{
    ui->setupUi(this);
    QPushButton *btn = new QPushButton("播放音乐",this);
    this->adjustSize();
    this->setWindowIcon(QIcon(":/image/music.png"));
    this->setWindowTitle("音乐");
    btn->adjustSize();
    ui->pushButton->adjustSize();
    ui->label->adjustSize();
    ui->pushButton_2->adjustSize();
    ui->label_2->adjustSize();
    ui->pushButton_3->adjustSize();
    ui->lineEdit->adjustSize();
    ui->lineEdit_2->adjustSize();
    ui->lineEdit_3->adjustSize();
    ui->lineEdit_4->adjustSize();
    connect(btn,&QPushButton::clicked,this,[=](){playmusic();/*Note2Frequency();*/});
}

XYControl::~XYControl()
{
    delete ui;
}

//全局变量不能用
//XYControl beatsPerMin;
void XYControl::gCodeCMD(float speed,float distance)
{
    QString Str_Enter = "\n";
    QByteArray data;
    if(speed == 0)
    {
        data = "G21G91X0.0Y0.0Z";
        data += QString::number(3.0*distance);
        data +="F";
        data += "300.0";
    }
    else{
    data = "G21G91X0.0Y";
    data += QString::number(distance);
    data +="Z0.0F";
    data += QString::number(speed);
    }
    data+=Str_Enter;
    ControlData =data;
    qDebug()<<"ControlData"<<ControlData;
    serial.write(data);
}

void XYControl::gCodeCMD(float speed,float distance,axis axis)
{
    QString Str_Enter = "\n";
    QByteArray data;
    if(speed == 0)
    {
        data = "G21G91X0.0Y0.0Z";
        data += QString::number(3.0*distance);
        data +="F";
        data += "300.0";
    }
    else if(axis == Y){
    data = "G21G91X0.0Y";
    data += QString::number(distance);
    data +="Z0.0F";
    data += QString::number(speed);
    }
    else if(axis == X){
    data = "G21G91X";
    data += QString::number(distance);
    data +="Y0.0Z0.0F";
    data += QString::number(speed);
    }
    data+=Str_Enter;
    ControlData =data;
    qDebug()<<"ControlData"<<ControlData;
    serial.write(data);
}
int XYControl::frequency2GCode(float frequency,float time)
{

    float speed = frequency*0.85;
    float distance = frequency/100 *time;
    if(frequency == 0)
    {
        distance = time;
    }
    QTime time1;
    QTime delayTime = QTime::currentTime().addMSecs(time * 800);	//在当前时间上增加3S
    gCodeCMD(speed,distance);

    time1=QTime::currentTime();
    qDebug()<<"time="<<time;
    qDebug()<<time1.second()<<time1.msec();
    /* lyh delete -> 避免有拉拽小票冲突 */
    while( QTime::currentTime() < delayTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
    time1=QTime::currentTime();
    qDebug()<<time1.second()<<time1.msec();
    return 1;
}

void XYControl::Note2Frequency(musicStruct ms)
{
    float frequency = 0;
    float time = 0;
    beatsPerMin = ui->lineEdit_4->text().toFloat();
    ms.octave  = ms.octave + ui->lineEdit_8->text().toFloat();
    qDebug()<<"note="<<ms.note;
    if(ms.note == 1)
    {
        frequency = C4;
    }
    else if (ms.note ==2) {
        frequency = D4;
    }
    else if (ms.note ==3) {
        frequency = E4;
    }
    else if (ms.note ==4) {
        frequency = F4;
    }
    else if (ms.note ==5) {
        frequency = G4;
    }
    else if (ms.note ==6) {
        frequency = A4;
    }
    else if (ms.note ==7) {
        frequency = B4;
    }
    else if (ms.note ==1.5) {
        frequency = Db4;
    }
    else if (ms.note ==2.5) {
        frequency = Eb4;
    }
    else if (ms.note ==4.5) {
        frequency = Gb4;
    }
    else if (ms.note ==5.5) {
        frequency = Ab4;
    }
    else if (ms.note ==6.5) {
        frequency = Bb4;
    }
    else if(ms.note == 0)
    {
        frequency = 0;
    }

    if(ms.octave>=4)
    {
        ms.octave -=4;
        ms.octave=pow(2,ms.octave);
        frequency = frequency *ms.octave;
    }
    else
    {
        ms.octave = 4 - ms.octave;
         ms.octave=pow(2,ms.octave);
        frequency = frequency /ms.octave;
    }
    qDebug()<<"frequency="<<frequency;
    time =ms.soundLength*(60.0/beatsPerMin);
    frequency2GCode(frequency,time);
}

void XYControl::Note2Frequency(musicStruct ms, float times)
{
    float frequency = 0;
    float time = 0;
    beatsPerMin = ui->lineEdit_4->text().toFloat();
    ms.octave  = ms.octave + ui->lineEdit_8->text().toFloat();
    qDebug()<<"note="<<ms.note;
    if(ms.note == 1)
    {
        frequency = C4;
    }
    else if (ms.note ==2) {
        frequency = D4;
    }
    else if (ms.note ==3) {
        frequency = E4;
    }
    else if (ms.note ==4) {
        frequency = F4;
    }
    else if (ms.note ==5) {
        frequency = G4;
    }
    else if (ms.note ==6) {
        frequency = A4;
    }
    else if (ms.note ==7) {
        frequency = B4;
    }
    else if (ms.note ==1.5) {
        frequency = Db4;
    }
    else if (ms.note ==2.5) {
        frequency = Eb4;
    }
    else if (ms.note ==4.5) {
        frequency = Gb4;
    }
    else if (ms.note ==5.5) {
        frequency = Ab4;
    }
    else if (ms.note ==6.5) {
        frequency = Bb4;
    }
    else if(ms.note == 0)
    {
        frequency = 0;
    }
    if(ms.octave>=4)
    {
        ms.octave -=4;
        ms.octave=pow(2,ms.octave);
        frequency = frequency *ms.octave;
    }
    else
    {
        ms.octave = 4 - ms.octave;
         ms.octave=pow(2,ms.octave);
        frequency = frequency /ms.octave;
    }
    qDebug()<<"frequency="<<frequency;
//    time =ms.soundLength*(60.0/beatsPerMin);
    //qDebug()<<"time="<<time;
    time =times;
    frequency2GCode(frequency,time);
}
void XYControl::Note2Frequency(void)
{
    float frequency = 0;
    float time = 0;
    int note =0;
    float octave =0;
    float soundLength =0;
    musicnum =0;
    //note +1 方便倍数计算
    beatsPerMin = ui->lineEdit_4->text().toFloat();
    note = ui->lineEdit->text().toInt();
    octave = ui->lineEdit_2->text().toFloat();
    soundLength = ui->lineEdit_3->text().toFloat();
//    qDebug()<<note<<octave<<soundLength;
//    qDebug()<<"A4="<<A4<<B4<<D4<<E4<<F4<<C4<<G4;
    if(note == 1)
    {
        frequency = C4;
    }
    else if (note ==2) {
        frequency = D4;
    }
    else if (note ==3) {
        frequency = E4;
    }
    else if (note ==4) {
        frequency = F4;
    }
    else if (note ==5) {
        frequency = G4;
    }
    else if (note ==6) {
        frequency = A4;
    }
    else if (note ==7) {
        frequency = B4;
    }
    else if (note ==1.5) {
        frequency = Db4;
    }
    else if (note ==2.5) {
        frequency = Eb4;
    }
    else if (note ==4.5) {
        frequency = Gb4;
    }
    else if (note ==5.5) {
        frequency = Ab4;
    }
    else if (note ==6.5) {
        frequency = Bb4;
    }
    octave +=1;
    if(octave>4)
    {
        octave -=4;
    }
    else
    {
        octave -=2;
        octave = 4 - octave;
        octave = (float)( 1/(float)octave);
    }
//    qDebug()<<note<<octave<<soundLength;
    frequency = frequency *octave;
//    qDebug()<<"frequency="<<frequency;
    time = frequency/100 *(soundLength*(60/beatsPerMin));

//    qDebug()<<"time="<<time;
    frequency2GCode(frequency,time);

}
void XYControl::liangzhilaohu(void)
{
    StopFlag = false;
    musicStruct ms[]={
1,4,0.5,0,0,0,
2,4,0.5,0,0,0,
3,4,0.5,0,0,0,
1,4,0.5,0,0,0,
1,4,0.5,0,0,0,
2,4,0.5,0,0,0,
3,4,0.5,0,0,0,
1,4,0.5,0,0,0,
3,4,0.5,0,0,0,
4,4,0.5,0,0,0,
5,4,1,0,0,0,
3,4,0.5,0,0,0,
4,4,0.5,0,0,0,
5,4,1,0,0,0,
//一只没有耳朵
5,4,0.5,0,0,0,
6,4,0.5,0,0,0,
5,4,0.5,0,0,0,
4,4,0.5,0,0,0,
3,4,1,0,0,0,
1,4,1,0,0,0,
//一只没有眼睛
5,4,0.5,0,0,0,
6,4,0.5,0,0,0,
5,4,0.5,0,0,0,
4,4,0.5,0,0,0,
3,4,1,0,0,0,
1,4,1,0,0,0,
2,4,1,0,0,0,
5,3,1,0,0,0,
1,4,1,0,0,0,
0,4,1,0,0,0,
2,4,1,0,0,0,
5,3,1,0,0,0,
1,4,1,0,0,0,
0,4,1,0,0,0,
};
    for (int n=0;n<34;n++) {


        Note2Frequency(ms[n]);
        if(StopFlag)
            break;

    }
}
void  XYControl::readtext(void)
{
//    QString string = ui->textBrowser->toPlainText();
    QString string = ui->textEdit->toPlainText();
    musicnum = 0;
    QString strTemp ;
    int num =0, flag =0;
    //char str1[1024]={0};
//    musicStruct ms[2000] ;
//    qDebug()<<string.indexOf(',');
    if(string.size() !=0)
    {
        string += '\n';
//        qDebug()<<"元素不为零";
//        qDebug()<<"string="<<string;
        for (int i =0;string.size()>1;i++) {
//            qDebug()<<(num     = string .indexOf(','));
//            qDebug()<<(flag    += string.indexOf('\n'));
            if((flag==-1) || (flag >num))
            {
                for (int n =0;n<6;n++) {
                    strTemp = string .left(num);
                    switch (n) {
                    case 0:
                        musicStruct1[i].note =strTemp.toInt();
                        break;
                    case 1:
                        musicStruct1[i].octave =strTemp.toFloat();
                        break;
                    case 2:
                        musicStruct1[i].soundLength =strTemp.toFloat();
                        break;
                    case 3:
                        musicStruct1[i].notex =strTemp.toInt();
                        break;
                    case 4:
                        musicStruct1[i].octavex =strTemp.toFloat();
                        break;
                    case 5:
                        musicStruct1[i].soundLengthx =strTemp.toFloat();
                        break;
                    }
                    qDebug()<<"strTemp="<<strTemp;
                    string = string.right(string.size()-num-1);
                    qDebug()<<"string="<<string;
                    num     = string.indexOf(',');
                    qDebug()<<"num="<<num;
                }
                string = string.right(string.size()-1);
            }
//            qDebug()<<"string.size()="<<string.size();
//            qDebug()<<musicStruct1[musicnum].note<<musicStruct1[musicnum].octave<<musicStruct1[musicnum].soundLength;
//            qDebug()<<musicStruct1[musicnum].notex<<musicStruct1[musicnum].octavex<<musicStruct1[musicnum].soundLengthx;
            musicnum++;

        }
    }
//    qDebug()<<string[0]<<string[2];

//    qDebug()<<string;
    delete (&strTemp);
    delete (&num);
    delete (&string);
//    delete(ms);
    //return ms;

}
//播放音乐
void XYControl::playmusic(void)
{

    StopFlag =false;
    readtext();
    qDebug()<<musicnum;
    for (int i=0;i<musicnum;i++)
    {
        Note2Frequency(musicStruct1[i]);
        qDebug()<<musicStruct1[i].note<<musicStruct1[i].octave<<musicStruct1[i].soundLength;
        if(StopFlag)
            break;
    }
    //musicnum =0;
}

//手动添加音谱
void XYControl::on_pushButton_clicked()
{
    QString string;
    string = ui->lineEdit->text();
    string +=',';
    string += ui->lineEdit_2->text();
    string +=',';
    string += ui->lineEdit_3->text();
    string +=',';
    string += ui->lineEdit_5->text();
    string +=',';
    string += ui->lineEdit_6->text();
    string +=',';
    string += ui->lineEdit_7->text();
    string +=',';
//    string += '\n';
//    ui->textBrowser->append(string);
    ui->textEdit->append(string);
}
//清除文本
void XYControl::on_pushButton_4_clicked()
{
    musicnum =0;
    ui->textEdit->clear();
}
//保存文件
void XYControl::on_pushButton_2_clicked()
{
//    QString filename = QFileDialog::getSaveFileName(this,"","D:\\");//获取需要保存成的文件名
    QString filename = tr("%1.txt").arg(QFileDialog::getSaveFileName(this,"","D:/"));
    qDebug()<<filename;
    QFile *file = new QFile;
    file->setFileName(filename);
    bool ok = file->open(QIODevice::WriteOnly);
    if(ok)
    {
//        QTextStream out(file);
//        out<<ui->textEdit->toPlainText(); //转化成纯文本
        file->write(ui->textEdit->toPlainText().toUtf8());
        file->close();
        delete(file);
    }
    else
    {
        QMessageBox::information(this,"错误","保存失败");
    }
//    QString string = ui->textBrowser->toPlainText();
//    qDebug()<<string[0]<<string[2];
//    qDebug()<<string;
}
//打开文件函数
void XYControl:: openFile(void)
{
    QString filename =QFileDialog::getOpenFileName(this,"","D:/",tr("Exe files(*.txt);;All files(*.*)"));
    qDebug()<<tr("Exe files(*.txt);;All files(*.*)");
    qDebug()<<filename;
    QFile *file = new QFile;
    file->setFileName(filename);
    bool ok = file->open(QIODevice::ReadOnly);
    if(ok)
    {
//        QTextStream out(file);
//        out<<ui->textEdit->toPlainText(); //转化成纯文本
        ui->textEdit->append(file->readAll());
        //file->read();
        //file->write(ui->textEdit->toPlainText().toUtf8());
        file->close();
        delete(file);
    }
    else
    {
        QMessageBox::information(this,"错误","打开失败");
    }

}
void XYControl:: openFile(QByteArray fileLaod,QByteArray fileTpye)
{
    QString filename =QFileDialog::getOpenFileName(this,"",fileLaod,tr("Exe files(*." + fileTpye +");;All files(*.*)"));
//    qDebug()<<tr("Exe files(*.txt);;All files(*.*)");
    qDebug()<<filename;
    QFile *file = new QFile;
    file->setFileName(filename);
    bool ok = file->open(QIODevice::ReadOnly);
    if(ok)
    {
        file->close();
        delete(file);
    }
    else
    {
        QMessageBox::information(this,"错误","打开失败");
    }

}
//打开文件按钮
void XYControl::on_pushButton_3_clicked()
{
    ui->textEdit->clear();
    openFile();
    readtext();
    playmusic();
}

void XYControl::on_pushButton_5_clicked()
{
    liangzhilaohu();
}

//停止播放音乐
void XYControl::on_pushButton_6_clicked()
{
    StopFlag = true;
    serial.close();
    serial.open(QIODevice::ReadWrite);

}

//打开MIDI文件
using namespace std;
using namespace smf;
void XYControl::on_pushButton_7_clicked()
{
//    testls();
    musicStruct ms;
    float times =0.0;
    MidiFile midifile;
    QString filename =QFileDialog::getOpenFileName(this,"","D:/",tr("Exe files(*.mid);;All files(*.*)"));
    qDebug()<<filename;
    StopFlag = false;
//    midifile.read("D:/lemon.mid");
     midifile.read(filename.toStdString());
    midifile.doTimeAnalysis();
    midifile.linkNotePairs();
    int tracks = midifile.getTrackCount();
    cout  << "TPQ: " << midifile.getTicksPerQuarterNote() << endl;
    /*if (tracks > 1)*/ cout  << "TRACKS: " << tracks << endl;
//    int track =tracks-1;
    for (int track=0; track<tracks; track++) {
       if (tracks > 1) cout  << "\nTrack " << track << endl;
       cout  << "Tick\tSeconds\tDur\tMessage" << endl;
       for (int event=0; event<midifile[track].size(); event++) {
//             cout  << dec << midifile[track][event].tick;
          cout  << '\t' << dec << midifile[track][event].seconds;
          cout  << '\t';
          if (midifile[track][event].isNoteOn())
             cout  <<(times =(midifile[track][event].getDurationInSeconds())); //每个音符播放的时间
          times = times /( ui->lineEdit_4->text().toFloat())*((float)midifile.getTicksPerQuarterNote());
          cout  <<' '<<times<<' ';
          cout  << '\t' << dec;
//          for (int i=0; i<midifile[track][event].size(); i++)
             cout  << (int)midifile[track][event][1] << ' ';
             ms.octave =((int)midifile[track][event][1] ) / 12;
//             ms.octave =((int)midifile[track][event][1] +1) / 12;
             switch (((int)midifile[track][event][1]) %12) {
             case 0:
                 ms.note= 1;
                 break;
             case 1:
                 ms.note= 1.5;
                 break;
             case 2:
                 ms.note= 2;
                 break;
             case 3:
                 ms.note=2.5;
                 break;
             case 4:
                 ms.note=3;
                 break;
             case 5:
                 ms.note=4;
                 break;
             case 6:
                 ms.note=4.5;
                 break;
             case 7:
                 ms.note=5;
                 break;
             case 8:
                 ms.note=5.5;
                 break;
             case 9:
                 ms.note=6;
                 break;
             case 10:
                 ms.note=6.5;
                 break;
             case 11:
                 ms.note=7;
                 break;
             }
          cout  << endl;
//          times = times *( ui->label->text().toFloat())/((float)midifile.getTicksPerQuarterNote());
          Note2Frequency(ms,times);
          if(StopFlag)
              break;
       }
    }
}
