#ifndef NOTOBVIOUSMETHOD_H
#define NOTOBVIOUSMETHOD_H

#include <QWidget>
#include <QTextStream>
#include <QString>
#include <QVector>
#include <QDebug>
#include <math.h>
#include <iostream>

namespace Ui {
class NotObviousMethod;
}

class NotObviousMethod : public QWidget
{
    Q_OBJECT
    
public:
    explicit NotObviousMethod(QWidget *parent = 0, int _numberOfX=10, int _numberOfT=100);
    ~NotObviousMethod();
    double getInitialConditions(double x);
    double getAccurateValue(double x, double t);
    double getLeftBoundaryCondition(double t);
    double getRightBoundaryCondition(double t);
private slots:
    void on_calculateButton_clicked();
    void on_equationA_valueChanged(double arg1);
    void on_equationB_valueChanged(double arg1);
    void on_accurateA_valueChanged(double arg1);
    void on_accurateB_valueChanged(double arg1);
private:
    Ui::NotObviousMethod *ui;
    double _equationA;
    double _equationB;
    double _accurateA;
    double _accurateB;

    void setEquationA(double a);
    void setEquationB(double b);
    void setAccurateA(double a);
    void setAccurateB(double b);
    double _thau;
    double _h;
    int numberOfT;
    int numberOfX;
    double leftBoundary;
    double rightBoundary;
    double edop;
    double coeffMax;
    double coeffMin;
    double hMax,hMin;
    double tMax,tMin;
    QVector< QVector<double> > X;
    QVector<double> T;
    QVector< QVector<double> > W;
    void printf(QString string);
    QString outputString;
    QTextStream stream;
    double powr(double x, double y);
    double getMax(QVector<double> array);
    double getMin(QVector<double> array);
    double dfdwiminus1(double wiminus1, double wi, double wiplus1, double h, double thau);
    double dfdwi(double wiminus1, double wi, double wiplus1, double h, double thau);
    double dfdwiplus1(double wiminus1, double wi, double wiplus1, double h, double thau);
    QVector<double> solveGauss(QVector<double> A, QVector<double> B);
    QVector<double> calculateNewton(QVector<double> oldW,double time, double h, double thau);
    QVector<double> fillYacoby(QVector<double> ws, double h, double thau);
    QVector<double> solveInterpolation(QVector<double> xOld, QVector<double> yOld, QVector<double> xNew);
    QVector<double> getDoubleX(QVector<double> oldX);
    QVector<double> getCoeffs(QVector<double> WHT, QVector<double> WHTdiv2, QVector<double> WHdiv2T,double h, double t,double& alphaOut);
    QVector<double> clarifyW(QVector<double> WHT, QVector<double> WHTdiv2, QVector<double> WHdiv2T);
    QVector<double> createNewWeb(QVector<double> oldX, QVector<double> bettas, double& h);
    double getEps(QVector<double> WHT, QVector<double> WHTdiv2, QVector<double> WHdiv2T);
    double fi(QVector<double> oldW,double wi, double wiplus1, double wiminus1,int i,double h, double thau);
    void calculateMethod();
};

#endif // NOTOBVIOUSMETHOD_H
