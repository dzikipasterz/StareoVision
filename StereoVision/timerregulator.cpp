#include "timerregulator.h"

timerRegulator::timerRegulator(QObject *parent) :
    QObject(parent),
    alertThreshold(20),
    upperThreshold(10),
    lowerThreshold(5),
    triggerCounter(0),
    paused(false)
{
}

timerRegulator::~timerRegulator()
{

}

void timerRegulator::setInterval(const int interval)
{
    msecInterval = interval;
}

void timerRegulator::receiveTimeout()
{
    triggerCounter++;
    flag = false;

    if(triggerCounter == alertThreshold)
        emit sendStop();

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

    if(flag) emit sendInterval(msecInterval);

}

void timerRegulator::receiveJobDone()
{
    triggerCounter--;
    if((triggerCounter == upperThreshold) && !paused)
        emit sendStart(msecInterval);

}

void timerRegulator::receivePause()
{
    paused = true;
    emit sendStop();
}

void timerRegulator::receiveResume()
{
    paused = false;
    emit sendStart(msecInterval);
}
