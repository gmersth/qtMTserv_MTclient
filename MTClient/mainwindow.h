#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTcpSocket>

#include <QList>
#include "capture_thread.h"
#include "recv_thread.h"
#include "send_thread.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QTcpSocket *socket, QWidget *parent = 0);
    void setCaptureThread(CaptureThread *captureThread);
    void setReceiveThread(ReceiveThread *receiveThread);
    void setSendThread(SendThread *sendThread);
    CaptureThread* getCaptureThread();
    ReceiveThread* getReceiveThread();
    SendThread* getSendThread();
    void shootScreen();
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event) override;
    void createActions();
    void createMenus();

protected slots:
    void connToServ();
    void disconnFromServ();


private:
    QTcpSocket *socket;
    ReceiveThread *receiveThread;
    CaptureThread *captureThread;
    SendThread *sendThread;
    QPixmap mainImage;
    QMenu *optionMenu;
    QMenu *helpMenu;
    QAction *connectAct;
    QAction *disconnectAct;

};

#endif // MAINWINDOW_H
