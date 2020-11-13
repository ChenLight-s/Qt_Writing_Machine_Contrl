#include "paintyuan.h"
#include "ui_paintyuan.h"

PaintYuan::PaintYuan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaintYuan)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/image/music.png"));
    this->setWindowTitle("画矩形");
}

PaintYuan::~PaintYuan()
{
    delete ui;
}
