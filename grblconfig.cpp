#include "grblconfig.h"
#include "ui_grblconfig.h"

GrblConfig::GrblConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GrblConfig)
{
    ui->setupUi(this);
}

GrblConfig::~GrblConfig()
{
    delete ui;
}
