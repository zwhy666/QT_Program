/********************************************************************************
** Form generated from reading UI file 'rich.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RICH_H
#define UI_RICH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rich
{
public:
    QLabel *richLabel;

    void setupUi(QWidget *Rich)
    {
        if (Rich->objectName().isEmpty())
            Rich->setObjectName(QString::fromUtf8("Rich"));
        Rich->resize(400, 80);
        richLabel = new QLabel(Rich);
        richLabel->setObjectName(QString::fromUtf8("richLabel"));
        richLabel->setGeometry(QRect(110, 30, 201, 41));
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        richLabel->setFont(font);
        richLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(Rich);

        QMetaObject::connectSlotsByName(Rich);
    } // setupUi

    void retranslateUi(QWidget *Rich)
    {
        Rich->setWindowTitle(QApplication::translate("Rich", "Form", nullptr));
        richLabel->setText(QApplication::translate("Rich", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rich: public Ui_Rich {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RICH_H
