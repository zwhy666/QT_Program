#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    //this指定绘图对象
    QPainter painter(this);

    //设置抗锯齿
    painter.setRenderHint(QPainter::Antialiasing);

    //设置颜色，线条粗细
    QPen pen;
    pen.setColor("green");
    pen.setWidth(5);
    painter.setPen(pen);

    QBrush brush;
    brush.setColor("green");
    painter.setBrush(brush);

    //画矩形
    painter.drawRect(60,60,100,100);

    //多边形类
    QPolygon polygon;
    //设置3个点的坐标
    polygon.setPoints(3,60,60,160,80,80,160);
    //画三角形
    painter.drawPolygon(polygon);

    //画直线
    painter.drawLine(300,300,600,300);

    //画椭圆
    painter.drawEllipse(200,200,90,180);

    //画文字
    //创建一个矩形区域用于画文字
    QRectF rectf(300,300,100,200);
    painter.drawText(rectf,Qt::AlignCenter,"QT开发");
}

