#include "Widget.h"
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QWidget>
#include <QDateTime>
#include <QTimer>
#include <QDebug>
#include <QLCDNumber>
#include <QPalette>
#include <QBrush>
#include <QColor>
#include <QSettings>
int FinalSeconds;
int finalSeconds = QDateTime::currentSecsSinceEpoch()+int(50000/0.0031);
float Income = (QDateTime::currentSecsSinceEpoch()-1628154370)*0.0031;
Widget::Widget(QWidget *parent):
        QWidget(parent)
{
//定义一个窗口，所有实现基于此窗口
    this->setFixedSize(300,280);
//时间标签
    QLabel* labelTime = new QLabel(QString("时间："),this);
    labelTime->setGeometry(50,10,50,30);
//当前时间线性编辑框
    QLineEdit* LineEditTime = new QLineEdit(this);
//当前时间定时器，间隔为一秒
    QTimer *currentTimer = new QTimer(this);
    currentTimer->setInterval(1000);
    currentTimer->start();
//使用定时器更新显示
    connect(currentTimer,&QTimer::timeout,[=](){
        QDateTime * datetime = new QDateTime();
        LineEditTime->setText(datetime->currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));});
    LineEditTime->setFont(QFont("Timers",12,QFont::Bold));
    LineEditTime->setAlignment(Qt::AlignHCenter);
    LineEditTime->setEnabled(false);
    LineEditTime->setGeometry(90,10,140,30);
    QLabel* labelIncome = new QLabel(QString("收入："),this);
    labelIncome->setGeometry(50,50,50,30);
    QLineEdit* LineEditIncome = new QLineEdit(this);
//定义qlcdnumber显示倒计时。
//定义收入，使用定时器更新倒计时以及收入还有时间戳。
    QLCDNumber* qlcdNumber = new QLCDNumber(this);
    qlcdNumber->setAutoFillBackground(true);
    QPalette pal = qlcdNumber->palette();
    pal.setBrush(qlcdNumber->backgroundRole(),QBrush(QColor(127,0,0)));
    qlcdNumber->setPalette(pal);
    qlcdNumber->resize(140,30);
    qlcdNumber->setGeometry(10,210,280,30);
    qlcdNumber->setSegmentStyle(QLCDNumber::Outline);
    qlcdNumber->setDecMode();
    qlcdNumber->setDigitCount(15);
    qlcdNumber->setSmallDecimalPoint(true);
    connect(currentTimer,&QTimer::timeout,[=](){
        int  intcurrenttime = QDateTime::currentSecsSinceEpoch();
        //qDebug()<<intcurrenttime<<endl;
        Income = Income+0.0031;
        //qDebug("收入是：%f",Income);
        LineEditIncome->setText(QString("%1").arg(Income));
        QSettings *configIniRead = new QSettings("config.ini",QSettings::IniFormat);
        QString FinalTime_FinalSeconds = configIniRead->value("FinalTime/FinalSeconds").toString();
        delete configIniRead;
        FinalSeconds=int((50000-Income)/0.0031);
        FinalSeconds--;
        QDateTime ftime = QDateTime::fromTime_t(FinalSeconds);
        qlcdNumber->display(ftime.toString("MM-dd HH:mm:ss"));
        //qDebug()<<ftime.toString("MM-dd hh:mm:ss")<<endl;
        QSettings *configInitWrite = new QSettings("config.ini",QSettings::IniFormat);
        configInitWrite->setValue("FinalTime/FinalSeconds",FinalSeconds);
        delete configInitWrite;
    });
    LineEditIncome->setEnabled(false);
    LineEditIncome->setAlignment(Qt::AlignHCenter);
    LineEditIncome->setFont(QFont("Timers",12,QFont::Bold));
    LineEditIncome->setGeometry(90,50,140,30);
    QLabel* secondsTimeLabel = new QLabel(QString("时间戳："),this);
    secondsTimeLabel->setGeometry(50,90,50,30);
    QLineEdit* secondsTimeLineEditTime = new QLineEdit(this);
    secondsTimeLineEditTime->setGeometry(100,90,130,30);
    connect(currentTimer,&QTimer::timeout,[=](){
        int intcurrenttime = QDateTime::currentSecsSinceEpoch();
        secondsTimeLineEditTime->setText(QString::number(intcurrenttime,10));
        secondsTimeLineEditTime->setFont(QFont("Timers",12,QFont::Bold));
        secondsTimeLineEditTime->setAlignment(Qt::AlignCenter);
        secondsTimeLineEditTime->setEnabled(false);

    });
    QLabel* startTimeLabel = new QLabel(QString("开始时间:"),this);
    startTimeLabel->setGeometry(30,130,50,30);
    QLineEdit* startTimeLineEditTime = new QLineEdit(this);
    startTimeLineEditTime->setGeometry(90,130,140,30);
    QDateTime time = QDateTime::fromTime_t(1628154370);
    startTimeLineEditTime->setText(time.toString("yyyy-MM-dd hh:mm:ss"));
    startTimeLineEditTime->setFont(QFont("Timers",12,QFont::Bold));
    startTimeLineEditTime->setAlignment(Qt::AlignHCenter);
    startTimeLineEditTime->setEnabled(false);

    QLabel* finalTimeLabel = new QLabel(QString("存50000倒计时:"),this);
    finalTimeLabel->setGeometry(100,170,80,30);


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
