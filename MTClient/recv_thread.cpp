#include "recv_thread.h"
#include <QThread>
#include <QMutex>
#include <QBuffer>
ReceiveThread::ReceiveThread(QMainWindow *window,QTcpSocket *socket):
    disconnected(true)
{
    this->window = window;
    this->socket= socket;
}

void ReceiveThread::run()
{
    while(socket->isReadable()){
        QByteArray readArray = socket->read(123123);
        qDebug()<<readArray;
    }
}
