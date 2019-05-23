#ifndef RECV_THREAD_H
#define RECV_THREAD_H
#include <QThread>
#include <QTcpSocket>
#include <QMutex>
#include <QBuffer>
#include <QMainWindow>

class ReceiveThread : public QThread
{
protected:
    virtual void run();
public:
    ReceiveThread(QMainWindow *window,QTcpSocket *socket);

private:
    bool disconnected;
    QMainWindow *window;
    QTcpSocket *socket;
};

#endif // RECV_THREAD_H
