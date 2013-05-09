#include "obviousmethod.h"
#include "ui_obviousmethod.h"

ObviousMethod::ObviousMethod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ObviousMethod)
{
    ui->setupUi(this);
    stream.setString(&outputString);
    _thau=1.0/100.0;
    _h=1.0/4;
    numberOfT=101;
    numberOfX=5;
    X= new double[numberOfX];
    T= new double[numberOfT];
    W= new double[numberOfT*numberOfX];
}
ObviousMethod::~ObviousMethod()
{
    delete ui;
    delete [] X;
    delete [] T;
    delete [] W;
}
double ObviousMethod::getInitialConditions(double x)
{
    double value;
    double returnableValue;
    value = (1/_accurateB)*x*x+_accurateA*pow(_accurateB,(-1.0/4.0))-(_equationB/(15.0*_equationA))*_accurateB;
    returnableValue= value*sqrt(fabs(value));
    return returnableValue;
}

double ObviousMethod::getAccurateValue(double x, double t)
{
    double value;
    double returnableValue;
    double x1,x2,x3;
    double expression = _accurateB-(8.0*_equationA*t);
    x1=1.0/expression;
    x2=pow(expression,-1.0/4.0);
    x3=expression*(_equationB/(15.0*_equationA));
    value = x1*x*x+_accurateA*x2-x3;
    returnableValue = value*sqrt(fabs(value));
    return returnableValue;
}

double ObviousMethod::getLeftBoundaryCondition(double t)
{
    return getAccurateValue(0.0,t);
}

double ObviousMethod::getRightBoundaryCondition(double t)
{
    return getAccurateValue(1.0,t);
}
void ObviousMethod::calculateMethod()
{
    double XR;
    double TR;
    int i,j,k;
    int n=numberOfX;
    double left;
    double right;
    double *Accurate = new double [numberOfT*numberOfX];
    double maxAbs,maxVidn;
    double x1,x2,x3,x4,x5,x6;


    for(XR=0,i=0;i<numberOfX;i++,XR+=_h)
    {
        X[i]=XR;
    }
    for(TR=0,j=0;j<numberOfT;j++,TR+=_thau)
    {
        T[j]=TR;
    }
    for(i=0;i<numberOfX;i++)
    {
        W[i]=getInitialConditions(X[i]);
    }

    for(k=0;k<numberOfT;k++)
    {
        for(i=0;i<numberOfX;i++)
        {
            Accurate[k*n+i]=getAccurateValue(X[i],T[k]);
        }
    }
    for(k=1;k<numberOfT;k++)
    {
        //stream << endl;
        left = getLeftBoundaryCondition(T[k]);
        right = getRightBoundaryCondition(T[k]);
        W[k*n]=left; //stream << W[k*n] << " ";
        W[k*n+4]=right;
        for(i=1;i<numberOfX-1;i++)
        {
            x1=powr(W[(k-1)*n+i],-1.0/3.0);
            x2=powr(((W[(k-1)*n+i+1]-W[(k-1)*n+i-1])/(2*_h)),-1.0/3.0);
            x3=powr(W[(k-1)*n+i],2.0/3.0);
            x4=(W[(k-1)*n+i-1] - 2*W[(k-1)*n+i] + W[(k-1)*n+i+1])/(_h*_h);
            x5=powr(W[(k-1)*n+i],1.0/3.0);
            x6=W[(k-1)*n+i];
            W[k*n+i]=_thau*_equationA*(2.0/3.0*x1+x2+x3*x4)+_thau*_equationB*x5+x6;
           // stream << W[k*n+i] << " ";
        }
       // stream << W[k*n+4]<<" ";
    }
    maxAbs=fabs(W[0]-Accurate[0]);
    maxVidn=fabs((W[0]-Accurate[0])/Accurate[0]*100);
    for(k=0;k<numberOfT;k++)
    {
        //stream<<endl;
        for(i=0;i<numberOfX;i++)
        {
            if(fabs(W[k*n+i]-Accurate[k*n+i]) > maxAbs) maxAbs =fabs(W[k*n+i]-Accurate[k*n+i]);
            if(fabs((W[k*n+i]-Accurate[k*n+i])/Accurate[k*n+i]*100)>maxVidn) maxVidn =fabs((W[k*n+i]-Accurate[k*n+i])/Accurate[k*n+i]*100);
            //stream << fabs(W[k*n+i] - Accurate[k*n+i]) << "       " ;
        }
    }
    stream << maxAbs<< "  " << maxVidn;
    stream.flush();
}

void ObviousMethod::printf(QString string)
{
    ui->plainTextEdit->setPlainText(string);
}
void ObviousMethod::setEquationA(double a)
{
    _equationA=a;
}
void ObviousMethod::setEquationB(double b)
{
    _equationB=b;
}
void ObviousMethod::setAccurateA(double a)
{
    _accurateA=a;
}
void ObviousMethod::setAccurateB(double b)
{
    _accurateB=b;
}
void ObviousMethod::on_calculateButton_clicked()
{
    calculateMethod();
    ui->plainTextEdit->clear();
    printf(outputString);
    outputString.clear();
}
double ObviousMethod::powr(double x, double y)
{
    if (x>=0) return exp(y*log(x));
    else return -1*exp(y*log(fabs(x)));
}

void ObviousMethod::on_equationA_valueChanged(double arg1)
{
    setEquationA(arg1);
}
void ObviousMethod::on_equationB_valueChanged(double arg1)
{
    setEquationB(arg1);
}
void ObviousMethod::on_accurateA_valueChanged(double arg1)
{
    setAccurateA(arg1);
}
void ObviousMethod::on_accurateB_valueChanged(double arg1)
{
    setAccurateB(arg1);
}
