#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //初始化属性动画，对象为ui界面的geometryWidget，动画名为geometry
    propertyanimation = new QPropertyAnimation(ui->geometryWidget,"geometry");

    //设置动画的起始位置，大小以及结束位置和大小
    //geometry的属性可以在QWidget中看到，其类型是QRect
    propertyanimation->setStartValue(QRect(0,0,100,100));
    propertyanimation->setEndValue(QRect(600,400,200,200));

    //设置某个时间段的值
    propertyanimation->setKeyValueAt(0.5,QRect(0,500,150,150));

    //设置动画时长以及次数
    propertyanimation->setDuration(2000);
    propertyanimation->setLoopCount(3);

    //设置动画缓和曲线
    propertyanimation->setEasingCurve(QEasingCurve::InQuad);

    //设置颜色动画
    QGraphicsColorizeEffect *graphicsColorizeEffect = new QGraphicsColorizeEffect(this);
    ui->colorWidget->setGraphicsEffect(graphicsColorizeEffect);
    propertyanimation1 = new QPropertyAnimation(graphicsColorizeEffect,"color");
    propertyanimation1->setStartValue(QColor(Qt::yellow));
    propertyanimation1->setEndValue(QColor(Qt::darkGreen));
    propertyanimation1->setDuration(3000);

    //不透明度动画
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(this);
    ui->opacityWidget->setGraphicsEffect(opacityEffect);
    propertyanimation2 = new QPropertyAnimation(opacityEffect,"opacity");
    //不透明度的取值范围是0.0-1.0,1.0为完全不透明，0.0为透明
    propertyanimation2->setStartValue(0.0);
    propertyanimation2->setEndValue(1.0);
    propertyanimation2->setDuration(2000);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //点击按钮时启动动画
    propertyanimation->start();
}


void Widget::on_pushButton_2_clicked()
{
    propertyanimation1->start();
}


void Widget::on_pushButton_3_clicked()
{
    propertyanimation2->start();
}

