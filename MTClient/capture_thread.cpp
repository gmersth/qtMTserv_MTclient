#include "capture_thread.h"
#include <QtCore>
#include <QDebug>
#include <QMutexLocker>
#include <QGuiApplication>
#include <QWindow>
#include <QScreen>

CaptureThread::CaptureThread(QMainWindow *window, QMutex *mutex,QBuffer *buffer,QTcpSocket *socket){
    initPixmap();
    this->mutex = mutex;
    this->buffer = buffer;
    this->window = window;
    this->socket = socket;
}
void CaptureThread::initPixmap(){
    QPixmap* newpixmap = new QPixmap(window->width(),window->height());

    newpixmap->fill(Qt::white);
    defaultImage = *newpixmap;
}
QPixmap CaptureThread::screencapture(){
    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QWindow *mwindow = window->windowHandle())
        screen = mwindow->screen();
    if (!screen)
        return defaultImage;

    return screen->grabWindow(0);
}


QBuffer* CaptureThread::getBuffer(){
   return this->buffer;
}

void CaptureThread::run(){


    while(socket->isWritable()){//lock, capture(linked to buffer,buffer is bytestring), send, then unlock
        mutex->lock();
        screencapture().save(buffer,"PNG");
        mutex->unlock();
    }



}
