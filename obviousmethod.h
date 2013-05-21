#ifndef OBVIOUSMETHOD_H
#define OBVIOUSMETHOD_H

#include <QWidget>
#include <math.h>
#include <stdio.h>
#include <QTextStream>
#include <QString>
#include <QVector>
#include <fstream>
#include <time.h>


using namespace std;

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
    void calculateMethod(double a=0.001,double b=0.001,double A=0.01,double B=0.0425*1.55);
    void testConstant();
    ofstream fout;
    ofstream graph;
    ofstream logObvious;

private slots:
    void on_calculateButton_clicked();
    void setEquationA(double a);
    void setEquationB(double b);
    void setAccurateA(double a);
    void setAccurateB(double b);

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
    void displayGraph3D();
};

#endif // OBVIOUSMETHOD_H
