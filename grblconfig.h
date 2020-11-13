#ifndef GRBLCONFIG_H
#define GRBLCONFIG_H

#include <QWidget>

namespace Ui {
class GrblConfig;
}

class GrblConfig : public QWidget
{
    Q_OBJECT

public:
    explicit GrblConfig(QWidget *parent = nullptr);
    ~GrblConfig();

private:
    Ui::GrblConfig *ui;
};

#endif // GRBLCONFIG_H
