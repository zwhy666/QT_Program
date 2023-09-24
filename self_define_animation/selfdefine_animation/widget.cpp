#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    rich = new Rich(this);
    //方法1，直接调用成员函数
    //rich->setmoney(100);

    //方法2：采用函数名匹配的方法
    //setProperty会自动 调用Q_PROPERTY下面的WRITE方法，即函数setmoney
    //money对应于Q_PROPERTY的第一个参数属性
    //rich->setProperty("money",100);

    propertyanimation = new QPropertyAnimation(ui->rich_Label,"money");
    propertyanimation->setStartValue(0);
    propertyanimation->setEndValue(100);
    propertyanimation->setDuration(2000);

    //richMoney是qreal类型，setText需要string类型，需要类型转换
    //ui->rich_Label->setText(QString::number())
}



Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    propertyanimation->start();
}

