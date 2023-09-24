#include "mythread.h"
#include <QElapsedTimer>//计算程序运行时间
#include <QDebug>


Generate::Generate(QObject *parent) : QThread(parent)
{

}

void Generate::recvNum(int num)
{
    m_num = num;
}

void Generate::run()
{
    //生成随机数的线程的线程地址
    qDebug()<<"生成随机数的线程的线程地址为:"<<QThread::currentThread()<<endl;

    //使用容器保存生成的随机数
    QVector<int> list;

    QElapsedTimer time ;

    //开始计时
    time.start();
    //循环m_num次，生成m_num个随机数，这个m_num从主线程传递过来
    for(int i = 0; i < m_num ;i++)
    {
        //生成0-100000之间的随机数并保存至容器
        list.push_back(qrand()%100000);
    }

    //结束计时并返回时间，单位为ms
    int msc = time.elapsed();
    qDebug()<<"生成"<<m_num<<"个随机数所用时间为："<<msc<<"ms"<<endl;

    //将生成的参数利用发送信号的方式发送给主线程
    emit sendArray(list);
}
