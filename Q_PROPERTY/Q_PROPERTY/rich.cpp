#include "rich.h"
#include "widget.h"
#include "ui_widget.h"

Rich::Rich(QWidget *parent) : QWidget(parent)
   //,ui(new UI::Rich),
        ,ui(new Ui::Widget),
        ,richMoney(500),
{
    ui->setupUi(this);
}
