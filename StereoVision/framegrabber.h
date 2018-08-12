#ifndef FRAMEGRABBER_H
#define FRAMEGRABBER_H

#include <QObject>

class frameGrabber : public QObject
{
    Q_OBJECT
public:
    explicit frameGrabber(QObject *parent = nullptr);

private:
    bool status;

signals:
    void sendStatus();

public slots:
    void receiveGrabFrame();
    void receiveSetup();
};

#endif // FRAMEGRABBER_H
