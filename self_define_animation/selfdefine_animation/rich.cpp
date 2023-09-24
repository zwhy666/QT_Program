#include "rich.h"
//#include "ui_rich.h"
#include "widget.cpp"

Rich::Rich(QWidget *parent) :
    QWidget(parent){}
   // ui(new Ui::Rich)
    //,richMoney(500)

Rich::~Rich()
{
   // delete ui;
}

qreal Rich::money() const
{
    //richMoney是私有变量，需要通过成员函数访问
    return richMoney;
}

void Rich::setmoney(qreal m)
{
    richMoney = m;
}


