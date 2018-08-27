#ifndef DEPTHDISPLAY_H
#define DEPTHDISPLAY_H

#include <QLabel>
#include <QSize>

class DepthDisplay : public QLabel
{
    Q_OBJECT
public:
    explicit DepthDisplay(QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;

signals:

public slots:
};

#endif // DEPTHDISPLAY_H
