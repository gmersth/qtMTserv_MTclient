#ifndef CAPTURE_THREAD_H
#define CAPTURE_THREAD_H
#include <QThread>
#include <QMutex>
#include <QBuffer>
#include <QMainWindow>
#include <QPixmap>
#include <QTcpSocket>

class CaptureThread : public QThread
{

public:
    CaptureThread(QMainWindow *window, QMutex *mutex,QBuffer *buffer,QTcpSocket *socket);
    QBuffer* getBuffer();
    QPixmap screencapture();
protected:
    virtual void run();
    void initPixmap();


private:
    QTcpSocket *socket;
    QMainWindow *window;
    QByteArray imagedata;
    QMutex *mutex;
    QBuffer *buffer;
    QPixmap defaultImage;
    QPixmap pixmap;
};

#endif // CAPTURE_THREAD_H
