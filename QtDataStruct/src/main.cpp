#include "Widget.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>
//#include <QApplication>
//#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QWidget>
#include <QDateTime>
#include <QTimer>
#include <QDebug>
float Income =0;
Widget::Widget(QWidget *parent):
    QWidget(parent)
    {
    this->setFixedSize(280,200);
    QLabel* labelTime = new QLabel(QString("时间："),this);
    labelTime->setGeometry(20,50,50,30);
    QLineEdit* LineEditTime = new QLineEdit(this);
    QTimer *currentTimer = new QTimer(this);
    currentTimer->setInterval(1000);
    currentTimer->start();
    connect(currentTimer,&QTimer::timeout,[=](){
    QDateTime * datetime = new QDateTime();
    LineEditTime->setText(datetime->currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));});
    LineEditTime->setFont(QFont("Timers",12,QFont::Bold));
    LineEditTime->setAlignment(Qt::AlignHCenter);
    LineEditTime->setEnabled(false);
    LineEditTime->setGeometry(80,50,140,30);
    QLabel* labelIncome = new QLabel(QString("收入："),this);
    labelIncome->setGeometry(20,90,50,30);
    QLineEdit* LineEditIncome = new QLineEdit(this);
    QDateTime * currenttime = new QDateTime();
    long int intcurrenttime =currenttime->toTime_t();
    connect(currentTimer,&QTimer::timeout,[=](){
    //QString seconds = Qstring::number(intcurrenttime,10);
    qDebug("时间戳是：%ld\n",intcurrenttime);
    //QString timestamp = QString::number(QDateTime::currentMSecsSinceEpoch() / 1000);
    currentTimer->setInterval(1000);
    Income = Income+0.003;
    qDebug("收入是：%f",Income);
    LineEditIncome->setText(QString("%1").arg(Income));
    LineEditIncome->setEnabled(false);
    LineEditIncome->setAlignment(Qt::AlignHCenter);
    LineEditIncome->setFont(QFont("Timers",12,QFont::Bold));
    LineEditIncome->setGeometry(80,90,140,30);});
    /*QLabel* secondsTimeLabel = new QLabel(QString("时间："),this);
    labelTime->setGeometry(20,50,50,30);
    QLineEdit* secondsTimeLineEditTime = new QLineEdit(this);*/

}




Widget::~Widget() {

}

/*
void Widget::TimerStart() {

    QTimer *Timer = new QTimer(this);
    Timer->setInterval(1000);
    Timer->start();

}
*/

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Widget *window = new Widget;
    //connect(window->Timer, SIGNAL(timer()),window,SLOT(window->TimerStart()));
    window->show();

    /*QLabel label("this is a control window.");
    label.setWindowTitle("DataStruct");
    label.setGeometry(100,50,360,160);
    label.setAlignment(Qt::AlignCenter);*/
    return a.exec();

}
