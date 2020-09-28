#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QPaintEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void serialPort_readyRead();

    void on_searchButton_clicked();

    void on_openButton_clicked();

    void on_sendButton_clicked();

    void on_clearButton_clicked();

    void on_clearSend_clicked();

    void on_Xup_clicked();

    void on_Xdown_clicked();

    void on_sendTextEdit_textChanged();

    void on_Yup_2_clicked();

    void on_Yup_clicked();

    void on_Ydown_clicked();

    void on_Set_Origin_Button_clicked();

    void on_To_Origin_Button_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort serial;

protected:
    void paintEvent(QPaintEvent *event);    /* 绘图事件，需要重写 */
};

#endif // MAINWINDOW_H
