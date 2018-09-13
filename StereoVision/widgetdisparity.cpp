#include "widgetdisparity.h"
#include "ui_widgetdisparity.h"

WidgetDisparity::WidgetDisparity(AppSettings *sett) :
    ui(new Ui::WidgetDisparity),
    sourcesDir("/home/"),
    resultsDir("/home/"),
    lastDir("/home/"),
    threadSourceReader(nullptr),
    threadRectifier(nullptr),
    threadStereoMatcher(nullptr)
{
    ui->setupUi(this);
    ui->labelSourcesDir->setText("/home");
    ui->labelResultsDir->setText("/home");
    ui->textBrowserStatus->setAlignment(Qt::AlignTop);
    settings = sett;
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

void WidgetDisparity::on_pushButton_clicked()
{
    status = "";
    dir = ui->labelSourcesDir->text();

    QDir directory(ui->labelSourcesDir->text());
    QStringList filter;
    filter.append("*.jpg");
    filter.append("*.avi");
    directory.setNameFilters(filter);
    directory.setSorting(QDir::Name);
    QStringList files = directory.entryList();

    for(int i = 0; i < files.size(); i++)
    {
        filesVector.push_back(files.at(i));
    }

    filesVector.clear();
    iter = filesVector.begin();

    for(int i = 0; i < files.size(); i+=2)
    {
        leftSource = files.at(i);
        rightSource = files.at(i+1);

        QDateTime currentTime = QDateTime::currentDateTime();
        status.append(currentTime.toString("[hh:mm:ss] ")).append("Analizowany plik ").append(leftSource).append("\n");
        status.append(currentTime.toString("[hh:mm:ss] ")).append("Analizowany plik ").append(rightSource).append("\n");
        ui->textBrowserStatus->setText(status);
        ui->textBrowserStatus->moveCursor(QTextCursor::End);

        leftSource = ui->labelSourcesDir->text().append(leftSource);
        rightSource = ui->labelSourcesDir->text().append(rightSource);

    }

}

void WidgetDisparity::stopThreads()
{
    if(threadSourceReader != nullptr)
    {
        threadSourceReader->quit();
        while(!threadSourceReader->isFinished());
        threadSourceReader = nullptr;
    }

    if(threadRectifier != nullptr)
    {
        threadRectifier->quit();
        while(!threadRectifier->isFinished());
        threadRectifier = nullptr;
    }

    if(threadStereoMatcher != nullptr)
    {
        threadStereoMatcher->quit();
        while(!threadStereoMatcher->isFinished());
        threadStereoMatcher = nullptr;
    }
}


void WidgetDisparity::grabNextFiles()
{
    iter++;
    leftSource = dir.append(*iter);
    iter++;
    rightSource = dir.append(*iter);

    stopThreads();

}
