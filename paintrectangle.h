#ifndef PAINTRECTANGLE_H
#define PAINTRECTANGLE_H

#include <QWidget>

namespace Ui {
class PaintRectangle;
}

class PaintRectangle : public QWidget
{
    Q_OBJECT

public:
    explicit PaintRectangle(QWidget *parent = nullptr);
    ~PaintRectangle();

private:
    Ui::PaintRectangle *ui;
};

#endif // PAINTRECTANGLE_H
