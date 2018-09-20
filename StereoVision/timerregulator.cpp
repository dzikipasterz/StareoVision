#include "timerregulator.h"

timerRegulator::timerRegulator(QObject *parent) :
    QObject(parent),
    timer(nullptr),
    alertThreshold(5),
    upperThreshold(3),
    lowerThreshold(1),
    msecInterval(42),
    triggerCounter(0),
    paused(false)
{
}

timerRegulator::~timerRegulator()
{
    if(timer != nullptr) timer->deleteLater();
}

void timerRegulator::setInterval(const int interval)
{
    msecInterval = interval;
}

void timerRegulator::receiveStart()
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(receiveTimeout()));
    timer->setInterval(msecInterval);
    timer->start();
}

void timerRegulator::receiveTimeout()
{
    triggerCounter++;
    bool flag = false;
    emit sendTimeout();

    if(triggerCounter == alertThreshold)
        timer->stop();

    if(triggerCounter > upperThreshold)
    {
        msecInterval++;
        flag=true;
    }
    if(triggerCounter < lowerThreshold)
    {
        msecInterval--;
        if(msecInterval<=0) msecInterval=1;
        flag=true;
    }

    if(flag) timer->setInterval(msecInterval);

}

void timerRegulator::receiveJobDone()
{
    triggerCounter--;
    if((triggerCounter == upperThreshold) && !paused)
        timer->start(msecInterval);

}

void timerRegulator::receivePause()
{
    paused = true;
    timer->stop();
}

void timerRegulator::receiveResume()
{
    paused = false;
    timer->start(msecInterval);
}
