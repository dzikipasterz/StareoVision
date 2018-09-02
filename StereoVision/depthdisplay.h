#ifndef DEPTHDISPLAY_H
#define DEPTHDISPLAY_H

#include <opencv2/core/core.hpp>
#include <QLabel>
#include <QSize>
#include <QEvent>
#include <QMouseEvent>
#include <QPainter>

class DepthDisplay : public QLabel
{
    Q_OBJECT
public:
    explicit DepthDisplay(QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    void setImage(QImage imageRaw, QImage imageEqualized);


signals:
    void sendPixelArrCoord(int x, int y);
    void sendPixelValue(int val);

protected:
    void mousePressEvent(QMouseEvent *event) override;


private:
    bool showPixel;
    int xPixelSelect, yPixelSelect;
    QPainter *painter;
    QPen penline;
    QPixmap pixmapTemp;
    QImage imageRaw, imageEqualized;
};

#endif // DEPTHDISPLAY_H
