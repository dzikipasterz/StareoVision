#include "depthdisplay.h"

DepthDisplay::DepthDisplay(QWidget *parent) : QLabel(parent)
{

}


QSize DepthDisplay::minimumSizeHint() const
{
    return QSize(200,150);
}
