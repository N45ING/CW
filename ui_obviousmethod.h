/********************************************************************************
** Form generated from reading UI file 'obviousmethod.ui'
**
** Created: Mon 20. May 23:22:01 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBVIOUSMETHOD_H
#define UI_OBVIOUSMETHOD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ObviousMethod
{
public:
    QPushButton *calculateButton;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *ObviousMethod)
    {
        if (ObviousMethod->objectName().isEmpty())
            ObviousMethod->setObjectName(QString::fromUtf8("ObviousMethod"));
        ObviousMethod->resize(1052, 633);
        calculateButton = new QPushButton(ObviousMethod);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setGeometry(QRect(40, 10, 75, 23));
        plainTextEdit = new QPlainTextEdit(ObviousMethod);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(40, 60, 981, 551));

        retranslateUi(ObviousMethod);

        QMetaObject::connectSlotsByName(ObviousMethod);
    } // setupUi

    void retranslateUi(QWidget *ObviousMethod)
    {
        ObviousMethod->setWindowTitle(QApplication::translate("ObviousMethod", "ObviousMethod", 0, QApplication::UnicodeUTF8));
        calculateButton->setText(QApplication::translate("ObviousMethod", "Calculate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ObviousMethod: public Ui_ObviousMethod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBVIOUSMETHOD_H
