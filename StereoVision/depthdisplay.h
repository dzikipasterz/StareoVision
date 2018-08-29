#ifndef DEPTHDISPLAY_H
#define DEPTHDISPLAY_H

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

signals:
    void sendPixelArrCoord(int x, int y);

protected:
    void mousePressEvent(QMouseEvent *event) override;

public slots:
    void setPixmap(const QPixmap &);

private:
    int xPixelSelect, yPixelSelect;
    QPainter *painter;
    QPen penline;
};

#endif // DEPTHDISPLAY_H
