#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    //创建给子线程传递要生成的随机数个数的信号
    void starting(int num);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
