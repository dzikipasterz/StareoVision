#include "depthdisplay.h"

DepthDisplay::DepthDisplay(QWidget *parent) :
    QLabel(parent)
{
    this->setScaledContents(true);
    xPixelSelect = int (this->width()/2);
    yPixelSelect = int (this->height()/2);
    penline.setColor(Qt::green);
    penline.setWidth(5);
    timer.start();
}


QSize DepthDisplay::minimumSizeHint() const
{
    return QSize(200,150);
}

void DepthDisplay::mousePressEvent(QMouseEvent *event)
{
    if((event->button() == Qt::LeftButton) && (pixmapTemp.size() != QSize(0,0)))
    {
        double x = event->x();
        double y = event->y();

        double labelWidth = this->width();
        double labelHeight = this->height();

        double pixmapWidth = this->pixmap()->width();
        double pixmapHeight = this->pixmap()->height();

        xPixelSelect = int (pixmapWidth*(x/labelWidth));
        yPixelSelect = int (pixmapHeight*(y/labelHeight));

        emit sendCoords(xPixelSelect, yPixelSelect);
        this->setImage(imageRaw);
    }

    else
    {
        QLabel::mousePressEvent(event);
    }
}

void DepthDisplay::setImage(QImage disparity)
{
    fps = 1000000000/(double(timer.nsecsElapsed()));
    timer.restart();

    imageRaw = disparity;
    pixmapTemp = QPixmap::fromImage(imageRaw);
    painter = new QPainter(&pixmapTemp);
    painter->setPen(penline);
    painter->drawPoint(xPixelSelect, yPixelSelect);

    dispToDepth();
    emit sendFPS(fps);
    emit sendDistance(distance);
    QLabel::setPixmap(pixmapTemp);
    delete painter;

    emit sendJobDone();
}

void DepthDisplay::setDispToDistMat(cv::Mat dispMap)
{
    dispDistMap = dispMap;
}

void DepthDisplay::dispToDepth()
{
    cv::Mat temp(1,1, CV_8UC1, cv::Scalar(imageRaw.pixelColor(xPixelSelect, yPixelSelect).red()));
    cv::Mat output;
    cv::reprojectImageTo3D(temp, output, dispDistMap);
    cv::Point3f coords = output.at<cv::Point3f>(0,0);
    distance = sqrt(double((coords.x)*(coords.x)+(coords.y)*(coords.y)+(coords.z)*(coords.z)));
}

void DepthDisplay::receiveCoords(int x, int y)
{
    xPixelSelect = x;
    yPixelSelect = y;
    this->setImage(imageRaw);
}
