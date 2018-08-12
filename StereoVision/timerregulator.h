#ifndef TIMERREGULATOR_H
#define TIMERREGULATOR_H

#include <QObject>

class timerRegulator : public QObject
{
    Q_OBJECT
public:
    explicit timerRegulator(QObject *parent = nullptr);

signals:


public slots:
    void pet();
};

#endif // TIMERREGULATOR_H
