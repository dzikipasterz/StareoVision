#ifndef TIMERREGULATOR_H
#define TIMERREGULATOR_H

#include <QObject>

class timerRegulator : public QObject
{
    Q_OBJECT
public:
    explicit timerRegulator(QObject *parent = nullptr);
    ~timerRegulator();

    void setInterval(const int interval);


signals:
    void sendInterval(int msecInterval);
    void sendStop();
    void sendStart(int msecInterval);

public slots:

    void receiveJobDone();
    void receiveTimeout();
    void receivePause();
    void receiveResume();

private:
    int alertThreshold;
    int upperThreshold;
    int lowerThreshold;
    int msecInterval;
    int triggerCounter;
    bool flag;
    bool paused;
};

#endif // TIMERREGULATOR_H
