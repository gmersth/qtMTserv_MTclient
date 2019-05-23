#include "send_thread.h"
#include "mainwindow.h"

SendThread::SendThread(QTcpSocket *socket, QMutex *mutex,
                       QByteArray *array)
{
    this->mutex = mutex;
    this->socket = socket;
    this->array = array;
}

void SendThread::run(){
    while(socket->isWritable()){
        mutex->lock();//lock and send, then release
        socket->write(*array);
        mutex->unlock();
    }
}
