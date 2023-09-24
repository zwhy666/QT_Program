#ifndef RICH_H
#define RICH_H

#include <QWidget>

namespace Ui {
class Rich;
}

class Rich : public QWidget
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

#endif // RICH_H
