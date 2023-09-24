#ifndef RICH_H
#define RICH_H

#include <QWidget>

class Rich : public QWidget
{
    Q_OBJECT
    //定义该宏用于识别属性的名字money，这个money是个函数，从而执行该函数
    Q_PROPERTY(qreal money READ money)
public:
    explicit Rich(QWidget *parent = nullptr);
    //函数类型要与Q_PROPERTY中的类型一致
    qreal money(qreal m) const;

private:
    qreal richMoney;
signals:

};

#endif // RICH_H
