#include "mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //, ui(new Ui::MainWindow)
    ,offset(200)
{
    //ui->setupUi(this);
    //设置显示位置与大小
    this->setGeometry(0,0,800,480);
    //最大存储maxSize-1个数据
    maxSize = 61;

    maxX = 5000;
    maxY = 50;

    lineSeries = new QLineSeries();
    chart = new QChart();
    chartView = new QChartView();

    valueAxisX = new QValueAxis();
    valueAxisY = new QValueAxis();
    timer = new QTimer(this);

    chart->setTitle("实时动态曲线示例");

    //注意添加曲线要放在最前面
    chart->addSeries(lineSeries);
    // chart->legend()->hide();

    //设置横纵坐标范围
    valueAxisX->setRange(0,maxX);
    valueAxisY->setRange(0,maxY);
    //设置横纵坐标的数值显示格式
    valueAxisX->setLabelFormat("%i");
    valueAxisY->setLabelFormat("%i");
    //设置横纵坐标标题
    valueAxisX->setTitleText("time/ms");
    valueAxisY->setTitleText("temperatture/℃");
    //注意：必须先添加坐标轴然后才能与坐标轴建立联系！！，否则画图失败
    chart->addAxis(valueAxisX,Qt::AlignBottom);
    chart->addAxis(valueAxisY,Qt::AlignLeft);

    lineSeries->setColor("red");

    //让折线与x轴联系
    lineSeries->attachAxis(valueAxisY);
    lineSeries->attachAxis(valueAxisX);



    lineSeries->append(20,1000);
    lineSeries->append(30,2000);
    lineSeries->append(15,3000);
    lineSeries->append(50,4000);

    chart->addSeries(lineSeries);
    //将图表添加到图表视图
    chartView->setChart(chart);
    //设置抗锯齿
    chartView->setRenderHint(QPainter::Antialiasing);

    setCentralWidget(chartView);

    //启动定时器，定时时间为offset
    timer->start(offset);

    connect(timer,SIGNAL(timeout()),this,SLOT(timerTimeOut()));
    //设置随机种子，随机数初始化
    qsrand(time(NULL));
}

MainWindow::~MainWindow()
{

}

void MainWindow::receivedData(int val)
{
    data.append(val);

    //当保存的数据量大于maxSize时，删除列表的第一个数据
    while(data.size() > maxSize)
    {
        data.removeFirst();
    }

    lineSeries->clear();

    int interval = maxX/(maxSize-1);
    for(int i = 0;i<data.size();++i)
    {
        lineSeries->append(interval*i,data.at(i));
    }

}

void MainWindow::timerTimeOut()
{
    //产生0-maxY之间的随机数
    receivedData(qrand() % maxY );
}

