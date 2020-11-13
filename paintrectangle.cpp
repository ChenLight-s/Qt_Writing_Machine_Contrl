#include "paintrectangle.h"
#include "ui_paintrectangle.h"

PaintRectangle::PaintRectangle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaintRectangle)
{
    ui->setupUi(this);
}

PaintRectangle::~PaintRectangle()
{
    delete ui;
}
