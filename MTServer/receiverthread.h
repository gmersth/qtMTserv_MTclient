#ifndef RECEIVERTHREAD_H
#define RECEIVERTHREAD_H
#include <QThread>
#include <QTcpSocket>

class ReceiverThread : public QThread
{
protected:
    virtual void run();


public:
    ReceiverThread();

private:
    bool isConnected;
    QTcpSocket *socket;
};

#endif // RECEIVERTHREAD_H
