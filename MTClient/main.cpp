#include "mainwindow.h"
#include "capture_thread.h"
#include "recv_thread.h"
#include "send_thread.h"
#include <QApplication>
#include <QTcpSocket>
#include <QMutex>



int main(int argc, char *argv[])
{
    QTcpSocket socket;
    QApplication a(argc, argv);
    MainWindow w(&socket);
    QMutex mMutex;
    QByteArray m_SendArray;
    QBuffer m_buffer(&m_SendArray);
    CaptureThread *capture_thread = new CaptureThread(&w, &mMutex, &m_buffer,&socket);
    ReceiveThread *recv_thread = new ReceiveThread(&w,&socket);
    SendThread *send_thread = new SendThread(&socket,&mMutex,&m_SendArray);
    w.setSendThread(send_thread);
    w.setCaptureThread(capture_thread);
    w.setReceiveThread(recv_thread);
    w.show();
    capture_thread->start();
    send_thread->start();
    recv_thread->start();
    return a.exec();
}
