#include "depthdisplay.h"

DepthDisplay::DepthDisplay(QWidget *parent) :
    QLabel(parent)
{
    this->setScaledContents(true);
    this->setPixmap(QPixmap(this->width(), this->height()));
    xPixelSelect = int (this->width()/2);
    yPixelSelect = int (this->height()/2);
    penline.setColor(Qt::green);
    penline.setWidth(5);
}


QSize DepthDisplay::minimumSizeHint() const
{
    return QSize(200,150);
}

void DepthDisplay::mousePressEvent(QMouseEvent *event)
{
    if((event->button() == Qt::LeftButton))
    {
        double x = event->x();
        double y = event->y();

        double labelWidth = this->width();
        double labelHeight = this->height();

        double pixmapWidth = this->pixmap()->width();
        double pixmapHeight = this->pixmap()->height();

        xPixelSelect = int (pixmapWidth*(x/labelWidth));
        yPixelSelect = int (pixmapHeight*(y/labelHeight));

        emit sendPixelArrCoord(xPixelSelect, yPixelSelect);

        //test
        //QPixmap temp = this->pixmap()->copy();
        //this->setPixmap(temp);

    }

    else
    {
        QLabel::mousePressEvent(event);
    }
}

void DepthDisplay::setPixmap(const QPixmap &pix)
{
    QPixmap pixmap = pix;
    painter = new QPainter(&pixmap);
    painter->setPen(penline);
    painter->drawPoint(xPixelSelect, yPixelSelect);


    QLabel::setPixmap(pixmap);
    delete painter;
}
