#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QVector>
//生成随机数
class Generate : public QThread
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);

    //槽函数，接收从主线程传递过来的num
    void recvNum(int num);

protected:
    void run() override;

signals:
    //定义信号用于把子线程的随机数传递给主线程
    void sendArray(QVector<int> list);

private:
    int m_num;

};

#endif // MYTHREAD_H
