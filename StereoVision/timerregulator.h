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

public slots:

    void receiveJobDone();
    void receiveTimeout();

private:
    int upperThreshold;
    int lowerThreshold;
    int msecInterval;
    int triggerCounter;
    bool flag;
};

#endif // TIMERREGULATOR_H
