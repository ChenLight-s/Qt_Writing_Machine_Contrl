#ifndef XYCONTROL_H
#define XYCONTROL_H

#include <QWidget>
#include "mainwindow.h"
struct musicStruct
{
    float note;
    float octave;
    float soundLength;
    float notex;
    float octavex;
    float soundLengthx;
};
enum axis{X = 0,Y =1,Z =2};

//extern musicStruct musicStruct1[128];

namespace Ui {
class XYControl;
}

class XYControl : public QWidget
{
    Q_OBJECT

public:
    explicit XYControl(QWidget *parent = nullptr);
    ~XYControl();
    void playmusic(void);
    void Note2Frequency(void);
    void Note2Frequency(musicStruct ms);
    void Note2Frequencyx(musicStruct ms);
    /*QString*/ void gCodeCMD(float speed,float distance);
    void gCodeCMD(float speed,float distance,axis axis);
    void gCodeCMD(float speed,float distance,float speedx,float distancex);
    void liangzhilaohu(void);
    void readtext(void);
    void openFile(void);
    void openFile(QByteArray fileLaod,QByteArray fileTpye);
    int frequency2GCode(float frequency,float time);
    int frequency2GCode(float frequency,float time,axis axis);
    int testls();
    void Note2Frequency(musicStruct ms, float time);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::XYControl *ui;
    QSerialPort serial1;
};
#endif // XYCONTROL_H
