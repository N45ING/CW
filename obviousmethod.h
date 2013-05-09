#ifndef OBVIOUSMETHOD_H
#define OBVIOUSMETHOD_H

#include <QWidget>
#include <math.h>
#include <stdio.h>
#include <QTextStream>
#include <QString>

namespace Ui {
class ObviousMethod;
}

class ObviousMethod : public QWidget
{
    Q_OBJECT
    
public:
    explicit ObviousMethod(QWidget *parent = 0);
    ~ObviousMethod();
    double getInitialConditions(double x);
    double getAccurateValue(double x, double t);
    double getLeftBoundaryCondition(double t);
    double getRightBoundaryCondition(double t);
    void calculateMethod();

private slots:
    void on_calculateButton_clicked();
    void setEquationA(double a);
    void setEquationB(double b);
    void setAccurateA(double a);
    void setAccurateB(double b);
    void on_equationA_valueChanged(double arg1);
    void on_equationB_valueChanged(double arg1);
    void on_accurateA_valueChanged(double arg1);
    void on_accurateB_valueChanged(double arg1);

private:
    Ui::ObviousMethod *ui;
    double _equationA;
    double _equationB;
    double _accurateA;
    double _accurateB;
    double _thau;
    double _h;
    int numberOfT;
    int numberOfX;
    double *X;
    double *T;
    double *W;
    void printf(QString string);
    QString outputString;
    QTextStream stream;
    double powr(double x, double y);
};

#endif // OBVIOUSMETHOD_H
