/********************************************************************************
** Form generated from reading UI file 'obviousmethod.ui'
**
** Created: Fri 10. May 10:10:01 2013
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
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ObviousMethod
{
public:
    QPushButton *calculateButton;
    QDoubleSpinBox *equationA;
    QDoubleSpinBox *equationB;
    QDoubleSpinBox *accurateA;
    QDoubleSpinBox *accurateB;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *ObviousMethod)
    {
        if (ObviousMethod->objectName().isEmpty())
            ObviousMethod->setObjectName(QString::fromUtf8("ObviousMethod"));
        ObviousMethod->resize(1052, 633);
        calculateButton = new QPushButton(ObviousMethod);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setGeometry(QRect(350, 10, 75, 23));
        equationA = new QDoubleSpinBox(ObviousMethod);
        equationA->setObjectName(QString::fromUtf8("equationA"));
        equationA->setGeometry(QRect(30, 10, 62, 22));
        equationB = new QDoubleSpinBox(ObviousMethod);
        equationB->setObjectName(QString::fromUtf8("equationB"));
        equationB->setGeometry(QRect(110, 10, 62, 22));
        accurateA = new QDoubleSpinBox(ObviousMethod);
        accurateA->setObjectName(QString::fromUtf8("accurateA"));
        accurateA->setGeometry(QRect(200, 10, 62, 22));
        accurateB = new QDoubleSpinBox(ObviousMethod);
        accurateB->setObjectName(QString::fromUtf8("accurateB"));
        accurateB->setGeometry(QRect(280, 10, 62, 22));
        plainTextEdit = new QPlainTextEdit(ObviousMethod);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(40, 60, 981, 551));

        retranslateUi(ObviousMethod);

        QMetaObject::connectSlotsByName(ObviousMethod);
    } // setupUi

    void retranslateUi(QWidget *ObviousMethod)
    {
        ObviousMethod->setWindowTitle(QApplication::translate("ObviousMethod", "Form", 0, QApplication::UnicodeUTF8));
        calculateButton->setText(QApplication::translate("ObviousMethod", "Calculate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ObviousMethod: public Ui_ObviousMethod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBVIOUSMETHOD_H
