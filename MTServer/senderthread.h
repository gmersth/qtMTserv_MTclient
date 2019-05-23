#ifndef SENDERTHREAD_H
#define SENDERTHREAD_H

#include <QThread>
#include <QTcpSocket>

class SenderThread : public QThread
{
public:
    SenderThread(int socketDescriptor, const QString &fortune, QObject *parent);

    void run() override;

signals:
    void error(QTcpSocket::SocketError socketError);

private:
    int socketDescriptor;
    QString text;
};

#endif // SENDERTHREAD_H
