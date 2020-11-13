#ifndef WRITEPAINT_H
#define WRITEPAINT_H

#include <QWidget>

namespace Ui {
class WritePaint;
}

class WritePaint : public QWidget
{
    Q_OBJECT

public:
    explicit WritePaint(QWidget *parent = nullptr);
    ~WritePaint();
    void paintrCircular(float center,float radius);
    void paintEvent(QPaintEvent *);
//    void timerEent(WritePaint *);
private:
    Ui::WritePaint *ui;
};

#endif // WRITEPAINT_H
