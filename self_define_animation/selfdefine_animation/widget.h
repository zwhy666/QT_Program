#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
//#include "rich.h"
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Rich
{
    Q_OBJECT
    //使用宏Q_PROPERTY，定义money函数
    Q_PROPERTY(qreal money READ money WRITE setmoney);

public:
    explicit Rich(QWidget *parent = nullptr);
    ~Rich();

    qreal money() const;
    void setmoney(qreal m);



private:
    //Ui::Rich *ui;
    qreal richMoney;
};

class Widget : public QWidget
{
    Q_OBJECT
    //Q_PROPERTY(qreal money READ money WRITE setmoney);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    Rich *rich;
    QPropertyAnimation *propertyanimation;


private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    qreal richMoney;
};
#endif // WIDGET_H
