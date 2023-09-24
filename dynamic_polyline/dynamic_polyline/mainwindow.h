#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QChartView>
#include <QTimer>
#include <QLineSeries>
#include <QValueAxis>
#include <QSplineSeries>

//使用QChart必须添加命名空间
QT_CHARTS_USE_NAMESPACE


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void receivedData(int);

    //X轴最大值
    int maxX;
    //Y轴最大值
    int maxY;
    //数据最大个数
    int maxSize;
    //点和点之间的间隔
    //int interval;
    //存放数据的列表容器
    QList<int>data;

    QChartView *chartView;
    QLineSeries *lineSeries;
    QValueAxis *valueAxisX;
    QValueAxis *valueAxisY;

    QTimer *timer;
    //定时时间
    int offset;
    QChart *chart;

private slots:

    void timerTimeOut();
};
#endif // MAINWINDOW_H
