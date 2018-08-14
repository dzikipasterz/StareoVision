#include "timerregulator.h"

timerRegulator::timerRegulator(QObject *parent, int timerInterval) :
    QObject(parent),
    upperThreshold(20),
    lowerThreshold(5),
    triggerCounter(0)
{
    msecInterval = timerInterval;
}

timerRegulator::~timerRegulator()
{

}

void timerRegulator::receiveTimeout()
{
    triggerCounter++;
    flag = false;

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
}
