#ifndef SEND_THREAD_H
#define SEND_THREAD_H
#include <QThread>
#include <QTcpSocket>
#include <QMutex>
#include <QBuffer>

class SendThread : public QThread
{

public:
    SendThread(QTcpSocket *sock, QMutex *mutex,
               QByteArray *array);
protected:
    virtual void run();


private:
    QMutex *mutex;
    QByteArray *array;
    QTcpSocket *socket;

};

#endif // SEND_THREAD_H
