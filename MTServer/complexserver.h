#ifndef COMPLEXSERVER_H
#define COMPLEXSERVER_H
#include <QTcpServer>

class ComplexServer : public QTcpServer
{
public:
    ComplexServer(QObject* parent=0);

    void incomingConnection(qintptr socketDescriptor) override;
    int userAmount;
    QSet<QTcpSocket*> clients;
    QMap<QTcpSocket*,QString> users;
};

#endif // COMPLEXSERVER_H
