#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *event) override;
    QTimer *timer;//定时器

private:
    Ui::Widget *ui;
    QFont font;
    int offset;
    QString textContent;
    int contentWidth;
private slots:
     void timeOut();
};
#endif // WIDGET_H
