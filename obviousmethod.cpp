#include "obviousmethod.h"
#include "ui_obviousmethod.h"

ObviousMethod::ObviousMethod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ObviousMethod)
{
    ui->setupUi(this);
    stream.setString(&outputString);
    _thau=1.0/100;
    _h=1.0/9;
    numberOfT=101;
    numberOfX=10;
    X= new double[numberOfX];
    T= new double[numberOfT];
    W= new double[numberOfT*numberOfX];
    fout.open("test.out");
    graph.open("graph_obvious.txt");
    logObvious.open("logObvious.txt");
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
    x2=powr(expression,-1.0/4.0);
    x3=expression*(_equationB/(15.0*_equationA));
    value = x1*x*x+_accurateA*x2-x3;
    //returnableValue = value*sqrt(fabs(value));
    returnableValue = powr(value,3.0/2.0);
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
void ObviousMethod::calculateMethod(double a, double b, double A, double B)
{
    setEquationA(a);
    setEquationB(b);
    setAccurateA(A);
    setAccurateB(B);
    double XR;
    double TR;
    int i,j,k;
    int n=numberOfX;
    QVector< QVector<double> > testValue;
    QVector<double> helpVector(numberOfX);
    testValue.push_back(helpVector);
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
        W[i]=getAccurateValue(X[i],0);
    }

    for(k=0;k<numberOfT;k++)
    {

        for(i=0;i<numberOfX;i++)
        {
            Accurate[k*n+i]=getAccurateValue(X[i],T[k]);
            testValue[0][i]=Accurate[i];
        }
    }
    for(k=1;k<numberOfT;k++)
    {
        testValue.push_back(helpVector);
        //stream << endl;
        left = getLeftBoundaryCondition(T[k]);
        right = getRightBoundaryCondition(T[k]);
        W[k*n]=left;//stream << W[k*n] << " ";
        W[k*n+n-1]=right;
        testValue[k][0]=W[k*n];
        testValue[k][n-1]=W[k*n+n-1];
        for(i=1;i<numberOfX-1;i++)
        {
            x1=powr(W[(k-1)*n+i],-1.0/3.0);
            x2=powr(((W[(k-1)*n+i+1]-W[(k-1)*n+i-1])/(2*_h)),-1.0/3.0);
            x3=powr(W[(k-1)*n+i],2.0/3.0);
            double test1,test2,test3,test4,test5,test6;
            test1=W[(k-1)*n+i-1];
            test2=W[(k-1)*n+i];
            test3=W[(k-1)*n+i+1];
            test6=2*test2;
            test4=(test1-test6+test3)/(_h*_h);
            x4=(W[(k-1)*n+i-1] - 2*W[(k-1)*n+i] + W[(k-1)*n+i+1])/(_h*_h); // change formula
            x5=powr(W[(k-1)*n+i],1.0/3.0);
            x6=W[(k-1)*n+i];
            test5=_thau*_equationA*((2.0/3.0*x1*x2)+(x3*x4))+_thau*_equationB*x5+x6;
            W[k*n+i]=_thau*_equationA*((2.0/3.0*x1*x2)+(x3*x4))+_thau*_equationB*x5+x6;
            testValue[k][i]=W[k*n+i];
           //stream << W[k*n+i] << " ";
        }
        //stream << W[k*n+4]<<" ";
        for(i=0;i<numberOfX;i++)
        {
            stream << qSetFieldWidth(15)<< "time is " << T[k] << " yApp " << W[k*n+i] << " yAcc " << Accurate[k*n+i] << "      absPoh" << fabs(W[k*n+i]-Accurate[k*n+i])<< "      otnPoh=  "<< fabs((W[k*n+i]-Accurate[k*n+i])/W[k*n+i]*100.)<<endl;
            graph << X[i] << " " << T[k] << " " << W[k*n+i] << endl;
            logObvious << W[k*n+i] << "     " << Accurate[k*n+i]<< "     " << fabs(W[k*n+i]-Accurate[k*n+i])*0.01<< "     "<< fabs((W[k*n+i]-Accurate[k*n+i])/W[k*n+i]*100.)*0.01<< endl;
        }
        stream<<endl;
        logObvious<<endl;
    }
    maxAbs=fabs(W[0]-Accurate[0]);
    maxVidn=fabs((W[0]-Accurate[0])/Accurate[0]*100.0);
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
    fout << a << " "<< b<< " "<<A<< " "<< B<< "            "<< maxAbs << "          " << maxVidn << endl;
    stream.flush();
}
void ObviousMethod::testConstant()
{
    const long max_rand = 1000000L;
    double x1 = 0, x2 = 0.1;
    double a,b,A,B;
    srand(time(NULL));
    for(int i=0;i<10000;i++)
    {
        a = x1 + ( x2 - x1) * (rand() % max_rand) / max_rand;
        b = x1 + ( x2 - x1) * (rand() % max_rand) / max_rand;
        A = x1 + ( x2 - x1) * (rand() % max_rand) / max_rand +b;
        B = x1 + ( x2 - x1) * (rand() % max_rand) / max_rand +a*1000;
        calculateMethod(a,b,A,B);
    }
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
