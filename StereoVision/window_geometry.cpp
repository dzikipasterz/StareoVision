#include "window_geometry.h"

void centerChild(QWidget *parent, QWidget *child)
{
    QRect rectParent = parent->geometry();
    QPoint centerParent = rectParent.center();
    QRect rectChild = child -> geometry();
    rectChild.moveCenter(centerParent);
    child -> setGeometry(rectChild);
}
