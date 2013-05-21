/********************************************************************************
** Form generated from reading UI file 'notobviousmethod.ui'
**
** Created: Tue 21. May 10:05:04 2013
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
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotObviousMethod
{
public:
    QTabWidget *tabWidget;
    QWidget *tabOne;
    QPlainTextEdit *plainTextEdit;
    QDoubleSpinBox *equationA;
    QDoubleSpinBox *equationB;
    QDoubleSpinBox *accurateA;
    QDoubleSpinBox *accurateB;
    QPushButton *calculateButton;
    QWidget *tabTwo;
    QFrame *graphThauFrame;
    QWidget *tabThree;
    QFrame *graphHFrame;
    QWidget *tabFour;
    QFrame *graphEpsFrame;
    QWidget *tabFive;
    QFrame *graphMistakesFrame;
    QWidget *tabSix;
    QFrame *frame3D;
    QWidget *tabEight;
    QFrame *graphProjectionFrame;
    QSpinBox *projectionNumber;
    QLabel *projectionLabel;

    void setupUi(QWidget *NotObviousMethod)
    {
        if (NotObviousMethod->objectName().isEmpty())
            NotObviousMethod->setObjectName(QString::fromUtf8("NotObviousMethod"));
        NotObviousMethod->resize(854, 585);
        tabWidget = new QTabWidget(NotObviousMethod);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 841, 571));
        tabOne = new QWidget();
        tabOne->setObjectName(QString::fromUtf8("tabOne"));
        plainTextEdit = new QPlainTextEdit(tabOne);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 40, 801, 481));
        equationA = new QDoubleSpinBox(tabOne);
        equationA->setObjectName(QString::fromUtf8("equationA"));
        equationA->setEnabled(true);
        equationA->setGeometry(QRect(750, 10, 62, 22));
        equationB = new QDoubleSpinBox(tabOne);
        equationB->setObjectName(QString::fromUtf8("equationB"));
        equationB->setGeometry(QRect(750, 40, 62, 22));
        accurateA = new QDoubleSpinBox(tabOne);
        accurateA->setObjectName(QString::fromUtf8("accurateA"));
        accurateA->setGeometry(QRect(750, 70, 62, 22));
        accurateB = new QDoubleSpinBox(tabOne);
        accurateB->setObjectName(QString::fromUtf8("accurateB"));
        accurateB->setGeometry(QRect(750, 100, 62, 22));
        calculateButton = new QPushButton(tabOne);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setGeometry(QRect(10, 10, 75, 23));
        tabWidget->addTab(tabOne, QString());
        equationA->raise();
        equationB->raise();
        accurateA->raise();
        accurateB->raise();
        calculateButton->raise();
        plainTextEdit->raise();
        tabTwo = new QWidget();
        tabTwo->setObjectName(QString::fromUtf8("tabTwo"));
        graphThauFrame = new QFrame(tabTwo);
        graphThauFrame->setObjectName(QString::fromUtf8("graphThauFrame"));
        graphThauFrame->setGeometry(QRect(140, 10, 681, 501));
        graphThauFrame->setFrameShape(QFrame::StyledPanel);
        graphThauFrame->setFrameShadow(QFrame::Raised);
        tabWidget->addTab(tabTwo, QString());
        tabThree = new QWidget();
        tabThree->setObjectName(QString::fromUtf8("tabThree"));
        graphHFrame = new QFrame(tabThree);
        graphHFrame->setObjectName(QString::fromUtf8("graphHFrame"));
        graphHFrame->setGeometry(QRect(140, 10, 681, 521));
        graphHFrame->setFrameShape(QFrame::StyledPanel);
        graphHFrame->setFrameShadow(QFrame::Raised);
        tabWidget->addTab(tabThree, QString());
        tabFour = new QWidget();
        tabFour->setObjectName(QString::fromUtf8("tabFour"));
        graphEpsFrame = new QFrame(tabFour);
        graphEpsFrame->setObjectName(QString::fromUtf8("graphEpsFrame"));
        graphEpsFrame->setGeometry(QRect(190, 30, 581, 271));
        graphEpsFrame->setFrameShape(QFrame::StyledPanel);
        graphEpsFrame->setFrameShadow(QFrame::Raised);
        tabWidget->addTab(tabFour, QString());
        tabFive = new QWidget();
        tabFive->setObjectName(QString::fromUtf8("tabFive"));
        graphMistakesFrame = new QFrame(tabFive);
        graphMistakesFrame->setObjectName(QString::fromUtf8("graphMistakesFrame"));
        graphMistakesFrame->setGeometry(QRect(140, 30, 681, 501));
        graphMistakesFrame->setFrameShape(QFrame::StyledPanel);
        graphMistakesFrame->setFrameShadow(QFrame::Raised);
        tabWidget->addTab(tabFive, QString());
        tabSix = new QWidget();
        tabSix->setObjectName(QString::fromUtf8("tabSix"));
        frame3D = new QFrame(tabSix);
        frame3D->setObjectName(QString::fromUtf8("frame3D"));
        frame3D->setGeometry(QRect(20, 10, 791, 521));
        frame3D->setFrameShape(QFrame::StyledPanel);
        frame3D->setFrameShadow(QFrame::Raised);
        tabWidget->addTab(tabSix, QString());
        tabEight = new QWidget();
        tabEight->setObjectName(QString::fromUtf8("tabEight"));
        graphProjectionFrame = new QFrame(tabEight);
        graphProjectionFrame->setObjectName(QString::fromUtf8("graphProjectionFrame"));
        graphProjectionFrame->setGeometry(QRect(130, 60, 601, 411));
        graphProjectionFrame->setFrameShape(QFrame::StyledPanel);
        graphProjectionFrame->setFrameShadow(QFrame::Raised);
        projectionNumber = new QSpinBox(tabEight);
        projectionNumber->setObjectName(QString::fromUtf8("projectionNumber"));
        projectionNumber->setGeometry(QRect(220, 480, 42, 22));
        projectionLabel = new QLabel(tabEight);
        projectionLabel->setObjectName(QString::fromUtf8("projectionLabel"));
        projectionLabel->setGeometry(QRect(130, 480, 91, 20));
        tabWidget->addTab(tabEight, QString());

        retranslateUi(NotObviousMethod);

        tabWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(NotObviousMethod);
    } // setupUi

    void retranslateUi(QWidget *NotObviousMethod)
    {
        NotObviousMethod->setWindowTitle(QApplication::translate("NotObviousMethod", "NotObviousMethod", 0, QApplication::UnicodeUTF8));
        calculateButton->setText(QApplication::translate("NotObviousMethod", "Calculate", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabOne), QApplication::translate("NotObviousMethod", "Tab 1", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabTwo), QApplication::translate("NotObviousMethod", "Tab 2", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabThree), QApplication::translate("NotObviousMethod", "Page", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabFour), QApplication::translate("NotObviousMethod", "Page", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabFive), QApplication::translate("NotObviousMethod", "Page", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabSix), QApplication::translate("NotObviousMethod", "Page", 0, QApplication::UnicodeUTF8));
        projectionLabel->setText(QApplication::translate("NotObviousMethod", "Layer number :", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabEight), QApplication::translate("NotObviousMethod", "Page", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NotObviousMethod: public Ui_NotObviousMethod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTOBVIOUSMETHOD_H
