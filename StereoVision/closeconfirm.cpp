#include "closeconfirm.h"
#include "ui_closeconfirm.h"

closeConfirm::closeConfirm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::closeConfirm)
{
    ui->setupUi(this);
}

closeConfirm::~closeConfirm()
{
    delete ui;
}

void closeConfirm::on_buttonBox_accepted()
{
    emit closeApplication();
}

void closeConfirm::on_buttonBox_rejected()
{
    this->close();
}
