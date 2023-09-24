#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class WorkerThread;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);


    ~Widget();
    WorkerThread *workerthread;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
};

//创建自己的线程类,继承于QThread类
class WorkerThread : public QThread
{
    Q_OBJECT//使用信号槽需要使用该宏

public:
    WorkerThread(QWidget *parent = nullptr)
    {Q_UNUSED(parent);}
    ~WorkerThread();
    //只有这个run函数在新的线程里面
    void run() override;//重写虚函数run()

};


#endif // WIDGET_H
