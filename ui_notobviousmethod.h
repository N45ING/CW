/********************************************************************************
** Form generated from reading UI file 'notobviousmethod.ui'
**
** Created: Wed 8. May 14:51:56 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTOBVIOUSMETHOD_H
#define UI_NOTOBVIOUSMETHOD_H

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

class Ui_NotObviousMethod
{
public:
    QPlainTextEdit *plainTextEdit;
    QPushButton *calculateButton;
    QDoubleSpinBox *equationA;
    QDoubleSpinBox *equationB;
    QDoubleSpinBox *accurateA;
    QDoubleSpinBox *accurateB;

    void setupUi(QWidget *NotObviousMethod)
    {
        if (NotObviousMethod->objectName().isEmpty())
            NotObviousMethod->setObjectName(QString::fromUtf8("NotObviousMethod"));
        NotObviousMethod->resize(1059, 703);
        plainTextEdit = new QPlainTextEdit(NotObviousMethod);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 40, 961, 621));
        calculateButton = new QPushButton(NotObviousMethod);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setGeometry(QRect(10, 0, 75, 23));
        equationA = new QDoubleSpinBox(NotObviousMethod);
        equationA->setObjectName(QString::fromUtf8("equationA"));
        equationA->setGeometry(QRect(100, 10, 62, 22));
        equationB = new QDoubleSpinBox(NotObviousMethod);
        equationB->setObjectName(QString::fromUtf8("equationB"));
        equationB->setGeometry(QRect(170, 10, 62, 22));
        accurateA = new QDoubleSpinBox(NotObviousMethod);
        accurateA->setObjectName(QString::fromUtf8("accurateA"));
        accurateA->setGeometry(QRect(240, 10, 62, 22));
        accurateB = new QDoubleSpinBox(NotObviousMethod);
        accurateB->setObjectName(QString::fromUtf8("accurateB"));
        accurateB->setGeometry(QRect(310, 10, 62, 22));

        retranslateUi(NotObviousMethod);

        QMetaObject::connectSlotsByName(NotObviousMethod);
    } // setupUi

    void retranslateUi(QWidget *NotObviousMethod)
    {
        NotObviousMethod->setWindowTitle(QApplication::translate("NotObviousMethod", "Form", 0, QApplication::UnicodeUTF8));
        calculateButton->setText(QApplication::translate("NotObviousMethod", "Calculate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NotObviousMethod: public Ui_NotObviousMethod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTOBVIOUSMETHOD_H
