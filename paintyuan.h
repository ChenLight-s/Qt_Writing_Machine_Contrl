#ifndef PAINTYUAN_H
#define PAINTYUAN_H

#include <QWidget>

namespace Ui {
class PaintYuan;
}

class PaintYuan : public QWidget
{
    Q_OBJECT

public:
    explicit PaintYuan(QWidget *parent = nullptr);
    ~PaintYuan();
    Ui::PaintYuan *ui;
private:

};

#endif // PAINTYUAN_H
