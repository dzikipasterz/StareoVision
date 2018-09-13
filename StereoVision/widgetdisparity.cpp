#include "widgetdisparity.h"
#include "ui_widgetdisparity.h"

WidgetDisparity::WidgetDisparity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetDisparity),
    sourcesDir("/home"),
    resultsDir("/home"),
    lastDir("/home")
{
    ui->setupUi(this);
    ui->labelSourcesDir->setText("/home");
    ui->labelResultsDir->setText("/home");
}

WidgetDisparity::~WidgetDisparity()
{
    delete ui;
}

void WidgetDisparity::on_pushButtonSource_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"Wybierz folder ze źródłami", lastDir,QFileDialog::ShowDirsOnly);

    if(!dir.isNull())
    {
        dir.append("/");
        lastDir = dir;
        sourcesDir = dir;
        ui->labelSourcesDir->setText(dir);
    }

}

void WidgetDisparity::on_pushButtonResults_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"Wybierz folder dla wyników", lastDir,QFileDialog::ShowDirsOnly);
    lastDir = dir;
    resultsDir = dir;
    ui->labelResultsDir->setText(dir);
}
