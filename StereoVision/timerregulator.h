#ifndef TIMERREGULATOR_H
#define TIMERREGULATOR_H

#include <QObject>
#include <QTimer>

class timerRegulator : public QObject
{
    Q_OBJECT
public:
    explicit timerRegulator(QObject *parent = nullptr);
    ~timerRegulator();

    void setInterval(const int interval);


signals:
    void sendTimeout();

public slots:

    void receiveStart();
    void receiveJobDone();
    void receiveTimeout();
    void receivePause();
    void receiveResume();

private:
    QTimer *timer;
    int alertThreshold;
    int upperThreshold;
    int lowerThreshold;
    int msecInterval;
    int triggerCounter;
    bool paused;
};

#endif // TIMERREGULATOR_H
