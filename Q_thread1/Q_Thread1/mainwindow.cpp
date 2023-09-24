#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
//MainWindow就是主线程
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建子线程对象
    Generate *gen = new Generate;

    //子线程接收信号
    //由当前窗口类MainWindow发送信号starting，接收对象是gen,接收信号后执行函数recvNum
    //函数recvNum的参数即信号starting传递的数据10000
    connect(this,&MainWindow::starting,gen,&Generate::recvNum);

    //启动子线程,当ui界面的start按钮被按下，在当前窗口类里面启动子线程
    connect(ui->start,&QPushButton::clicked,this,[=]()
    {
        //给子线程发送信号，生成随机数数量为10000个
        emit starting(10000);
        //子线程启动，执行run（）函数
        gen->start();
    });

    //主线程接收子线程发送的信号,这里的list就是由子线程传递过来的
    //使用传递QVector<int>数据时需要先在main函数中使用qRegisterMetaType注册
    connect(gen,&Generate::sendArray,this,[=](QVector<int> list)
    {
        for(int i = 0;i < list.size();++i)
        {
            ui->randlist->addItem(QString::number(list.at(i)));
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

