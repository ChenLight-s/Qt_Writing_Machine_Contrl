#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QPaintEvent>
#include <QEvent>
#include <QTimerEvent>
#include <QTimer>
#include <QKeyEvent>
extern QSerialPort serial;
extern int ksljdflk;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    QSerialPort serial;
    void sendmusic(void);
    Ui::MainWindow *ui;
    void timerEvent(QTimerEvent *);
    void timeOutEvent(QTimerEvent *);
    void display(QByteArray data);
    void display(QByteArray data,QColor color);
    QKeyEvent *key;
    void keyReleaseEvent(QKeyEvent *);
    void on_Laser(QString gongLv);
    void off_Laser(void);

private slots:
    void serialPort_readyRead();

    void on_searchButton_clicked();

    void on_openButton_clicked();

    void on_sendButton_clicked();

    void on_clearButton_clicked();

    void on_clearSend_clicked();

    void on_searchButton_9_clicked();

    void on_searchButton_8_clicked();

    void on_searchButton_6_clicked();

    void on_searchButton_4_clicked();

    void on_searchButton_5_clicked();

    void on_searchButton_3_clicked();

    void on_searchButton_2_clicked();

    void on_searchButton_7_clicked();

    void on_checkBox_stateChanged(int arg1);
    void on_sendButton_2_clicked();

    void on_onLaser_clicked();

    void on_openGCodefile_clicked();

private:

//    QSerialPort serial;
protected:
    void paintEvent(QPaintEvent *event);    /* 绘图事件，需要重写 */
};

#endif // MAINWINDOW_H
