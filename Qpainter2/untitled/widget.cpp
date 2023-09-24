#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QFontMetrics>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , offset(0)//设置offset默认值为0
    ,textContent("正点原子阿尔法开发板")
{
    ui->setupUi(this);
    font.setPixelSize(50);
    //初始化定时器,在父对象中创建，不用自己释放
    timer = new QTimer(this);
    //设置定时时间为100ms
    timer->start(100);

    connect(timer,SIGNAL(timeout()),this,SLOT(timeOut()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QPen pen;
    pen.setColor(QColor("red"));
    pen.setStyle(Qt::PenStyle::DashLine);
    painter.setFont(font);
    painter.setPen(pen);

    QRectF rectf = this->rect();


    //获取文字的宽度
    QFontMetrics fontMetrics(font);
    contentWidth = fontMetrics.width(textContent);


    //设置文字距离矩形边框左边的位置为100
    rectf.setLeft(this->rect().width()-offset);
    //paintEvent为垂直居中对齐
    painter.drawText(rectf,Qt::AlignVCenter,textContent);

}

void Widget::timeOut()
{
    if(offset < this->width()+contentWidth)
    {
        offset+=3;
    }
    else
        offset = 0;
    //paintEvent只会在程序初次运行时调用，想要更新界面，即调用paintEvent，则需使用update
    this->update();
}

