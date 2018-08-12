#ifndef SELFREGULATINGTIMER_H
#define SELFREGULATINGTIMER_H

#include <QObject>
#include <QTimer>


class Timer : public QTimer
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = nullptr);

signals:

public slots:
    void receiveSlowDown();
    void receiveSpeedUp();


private:
    int msecInterval;
};

#endif // SELFREGULATINGTIMER_H
