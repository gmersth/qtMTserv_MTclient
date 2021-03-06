#include "mainwindow.h"

#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>
#include <QGuiApplication>
#include <QLabel>
#include <QtWidgets>
MainWindow::MainWindow(QTcpSocket * socket,QWidget *parent) //메인윈도우가 곧 메인쓰레드?
    : QMainWindow(parent)
{
    QLabel label;
    QPixmap mainImage(100,100);
    label.setPixmap(mainImage);

    //createActions();
    //createMenus();


}

void MainWindow::connToServ(){
    socket->connectToHost(QHostAddress("127.0.0.1"), 4242);
}
void MainWindow::disconnFromServ(){
    socket->disconnectFromHost();
}

void MainWindow::createActions(){
    connectAct = new QAction(tr("&Connect to server"), this);
    connect(connectAct,SIGNAL(triggered()),this,SLOT(ConntoServ()));
    disconnectAct = new QAction(tr("&Disconnect from server"), this);
    connect(disconnectAct,SIGNAL(triggered()),this,SLOT(disconnFromServ()));
}


void MainWindow::createMenus(){
    optionMenu = new QMenu(tr("&Options"), this);
    optionMenu->addAction(connectAct);
    optionMenu->addAction(disconnectAct);
}

void MainWindow::closeEvent(QCloseEvent *event){
    captureThread->terminate();
    qDebug()<<"close Window";
}

void MainWindow::setReceiveThread(ReceiveThread *receiveThread){
    this->receiveThread = receiveThread;
}


void MainWindow::setCaptureThread(CaptureThread *captureThread){
    this->captureThread = captureThread;
}

void MainWindow::setSendThread(SendThread *sendThread){
    this->sendThread = sendThread;
}

ReceiveThread* MainWindow::getReceiveThread(){
    return this->receiveThread;
}

CaptureThread* MainWindow::getCaptureThread(){
    return this->captureThread;
}

SendThread* MainWindow::getSendThread(){
    return this->sendThread;
}











MainWindow::~MainWindow()
{

}
