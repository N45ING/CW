#ifndef NOTOBVIOUSMETHOD_H
#define NOTOBVIOUSMETHOD_H

#include <QWidget>
#include <QTextStream>
#include <QLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QString>
#include <QVector>
#include <QDebug>
#include <QDialog>
#include <math.h>
#include <iostream>
#include <fstream>
#include <qwt.h>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include "qfunc3d.h"
#include <qwt3d_surfaceplot.h>
#include "widget.h"

using namespace std;
namespace Ui {
class NotObviousMethod;
}

class NotObviousMethod : public QWidget
{
    Q_OBJECT
    
public:
    explicit NotObviousMethod(QWidget *parent = 0, int _numberOfX=20, int _numberOfT=100);
    ~NotObviousMethod();
    double getInitialConditions(double x);
    double getAccurateValue(double x, double t);
    double getLeftBoundaryCondition(double t);
    double getRightBoundaryCondition(double t);
    ofstream fout;
private slots:
    void on_calculateButton_clicked();
    void on_equationA_valueChanged(double arg1);
    void on_equationB_valueChanged(double arg1);
    void on_accurateA_valueChanged(double arg1);
    void on_accurateB_valueChanged(double arg1);

    void on_projectionNumber_valueChanged(int arg1);

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
    QDialog dialogForNet;
    QVector< QVector<double> > X;
    QVector<double> T;
    QVector<double> acceptedT;
    QVector<double> THAU;
    QVector<double> H;
    QVector<double> steps;
    QVector<double> MISTAKE;
    QVector<double> EPS;
    QVector< QVector<double> > W;
    QVector< QVector<double> > Z;
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

    /* змінні для графіки */
    QPen globalPen;
    QwtText *thauGraphText;
    QwtPlot *thauGraphPlot;
    QGridLayout *thauGraphLayout;
    QwtPlotCurve *thauGraphCurve;

    QwtText *hGraphText;
    QwtPlot *hGraphPlot;
    QGridLayout *hGraphLayout;
    QwtPlotCurve *hGraphCurve;

    QwtText *epsGraphText;
    QwtPlot *epsGraphPlot;
    QGridLayout *epsGraphLayout;
    QwtPlotCurve *epsGraphCurve;

    QwtText *mistakesGraphText;
    QwtPlot *mistakesGraphPlot;
    QGridLayout *mistakesGraphLayout;
    QwtPlotCurve *mistakesGraphCurve;

    QwtText *gridGraphText;
    QwtPlot *gridGraphPlot;
    QGridLayout *gridGraphLayout;
    QwtPlotCurve *gridGraphCurve;

    QwtText *projectionGraphText;
    QwtPlot *projectionGraphPlot;
    QGridLayout *projectionGraphLayout;
    QwtPlotCurve *projectionGraphCurve;
    QwtPlotCurve *projectionGraphCurveAdd;


    void displayGraphThau();
    void displayGraphH();
    void displayGraphEps();
    void displayGraphMistakes();
    void displayGraph3D();
    void displayGrid();
    void displayProjections(int number);
};

#endif // NOTOBVIOUSMETHOD_H
