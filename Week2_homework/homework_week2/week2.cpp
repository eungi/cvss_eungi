#include "week2.h"
#include "ui_week2.h"

week2::week2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::week2)
{
    ui->setupUi(this);
}

week2::~week2()
{
    delete ui;
}
