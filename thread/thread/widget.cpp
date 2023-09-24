#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


class WorkerThread;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

   // workerthread = new WorkerThread(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //启动线程
    //workerthread->start();

    //开启多个线程(每点击一次开启一个线程)
    workerthread = new WorkerThread(this);
    workerthread->start();
}


WorkerThread::~WorkerThread()
{
    //线程销毁的时候会执行析构函数
    qDebug()<<"线程销毁"<<endl;
}

void WorkerThread::run()
{
    qDebug()<<"打开线程"<<endl;
    sleep(5);
    qDebug()<<"关闭线程"<<endl;

    //线程结束的时候一定要销毁线程
    deleteLater();
}

void Widget::on_pushButton_2_clicked()
{
   //判断线程是否已经结束，未结束，关闭线程
    if(!workerthread->isFinished())
    {
        workerthread->terminate();
    }
}

