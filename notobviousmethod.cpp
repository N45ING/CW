#include "notobviousmethod.h"
#include "ui_notobviousmethod.h"
#include "SLAE.h"

NotObviousMethod::NotObviousMethod(QWidget *parent,int _numberOfX, int _numberOfT) :
    QWidget(parent),
    ui(new Ui::NotObviousMethod)
{
    ui->setupUi(this);
    ui->accurateA->setVisible(false);
    ui->accurateB->setVisible(false);
    ui->equationA->setVisible(false);
    ui->equationB->setVisible(false);
    ui->tabWidget->setTabText(0,"Main");
    ui->tabWidget->setTabText(1,"Graph Thau");
    ui->tabWidget->setTabText(2,"Graph H");
    stream.setString(&outputString);
    leftBoundary=0.0;
    rightBoundary=1.0;
    numberOfX=_numberOfX;
    numberOfT=_numberOfT;
    _h=(rightBoundary-leftBoundary)/(numberOfX-1);
    _thau=(rightBoundary-leftBoundary)/(numberOfT-1);
    coeffMax=4.0;
    coeffMin=0.5;
    hMax=(rightBoundary-leftBoundary)/5.0;
    hMin=(rightBoundary-leftBoundary)/50.0;
    tMax=(rightBoundary-leftBoundary)/4.0;
    tMin=(rightBoundary-leftBoundary)/100.0;
    setEquationA(0.00001);
    setEquationB(0.00001);
    setAccurateA(0.006);
    setAccurateB(0.009);
    edop=0.001;
    fout.open("test.out");
}

NotObviousMethod::~NotObviousMethod()
{
    delete ui;
}
double NotObviousMethod::getInitialConditions(double x)
{
    double value;
    double returnableValue=0.0;
    value = (1/_accurateB)*x*x+_accurateA*pow(_accurateB,(-1.0/4.0))-(_equationB/(15.0*_equationA))*_accurateB;
    returnableValue= value*sqrt(fabs(value));
    return returnableValue;
}
double NotObviousMethod::getAccurateValue(double x, double t)
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
double NotObviousMethod::getLeftBoundaryCondition(double t)
{
    return getAccurateValue(0.0,t);
}
double NotObviousMethod::getRightBoundaryCondition(double t)
{
    return getAccurateValue(1.0,t);
}
void NotObviousMethod::printf(QString string)
{
    ui->plainTextEdit->setPlainText(string);
}
void NotObviousMethod::setEquationA(double a)
{
    _equationA=a;
}
void NotObviousMethod::setEquationB(double b)
{
    _equationB=b;
}
void NotObviousMethod::setAccurateA(double a)
{
    _accurateA=a;
}
void NotObviousMethod::setAccurateB(double b)
{
    _accurateB=b;
}
double NotObviousMethod::powr(double x, double y)
{
    if (x>=0) return exp(y*log(x));
    else return -1*exp(y*log(fabs(x)));
}
double NotObviousMethod::getMax(QVector<double> array)
{
    double max=fabs(array[0]);
    foreach(double value, array)
    {
        if (fabs(max)<fabs(value)) max=value;
    }
    return max;
}
double NotObviousMethod::getMin(QVector<double> array)
{
    double min=array[0];
    foreach(double value, array)
    {
      if (min>value) min=value;
    }
    return min;
}
double NotObviousMethod::dfdwiminus1(double wiminus1, double wi, double wiplus1, double h, double thau)
{
    double x1,x2,x3;
    x1=powr(wi,2.0/3.0)/(h*h);
    x2=9.0*h*powr(wi,1.0/3.0);
    x3=powr((wiplus1-wiminus1)/h,4.0/3.0);
    return _equationA*thau*(x1 + (2.0*pow(2.0,1.0/3.0))/(x2*x3));
}
double NotObviousMethod::dfdwi(double wiminus1, double wi, double wiplus1, double h, double thau)
{
    double x1,x2,x3,x4,x5,x6;
    x1=2.0*(wiminus1-2.0*wi+wiplus1);
    x2=3*h*h*powr(wi,1.0/3.0);
    x3=(2*powr(wi,2.0/3.0))/(h*h);
    x4=9*powr(wi,4.0/3.0);
    x5=powr((wiplus1-wiminus1)/h,1.0/3.0);
    x6=_equationB*thau/(3*powr(wi,2.0/3.0));
    return _equationA*thau*(x1/x2-x3- (2.0*pow(2.0,1.0/3.0))/(x4*x5))+x6-1.0;
}
double NotObviousMethod::dfdwiplus1(double wiminus1, double wi, double wiplus1, double h, double thau)
{
    double x1,x2,x3;
    x1=powr(wi,2.0/3.0)/(h*h);
    x2=9.0*h*powr(wi,1.0/3.0);
    x3=powr((wiplus1-wiminus1)/h,4.0/3.0);
    return _equationA*thau*(x1 - (2.0*pow(2.0,1.0/3.0))/(x2*x3));
}
QVector<double> NotObviousMethod::solveGauss(QVector<double> A, QVector<double> B)
{
    QVector<double> result;
    double *matrixA = new double[A.size()];
    double *rowB = new double[B.size()];
    double *rowR = new double [B.size()];
    for (int i=0;i<A.size();i++)
    {
        matrixA[i]=A[i];
    }
    for(int i=0;i<B.size();i++)
    {
        rowB[i]=B[i];
    }
    rowR = methodGauss02(matrixA,rowB,B.size());
    for(int i=0;i<B.size();i++)
    {
        result.push_back(rowR[i]);
    }
    delete [] matrixA;
    delete [] rowB;
    delete [] rowR;
    return result;
}
QVector<double> NotObviousMethod::calculateNewton(QVector<double> oldW, double time, double h, double thau)
{
    QVector<double> result(oldW.size());
    QVector<double> testResult(oldW.size());
    testResult=oldW;
    result=oldW;

    result[0]=getAccurateValue(leftBoundary,time);
    result.back()=getAccurateValue(rightBoundary,time);

    QVector<double> du(result.size());
    QVector<double> ddu(result.size());
    QVector<double> olddu(result.size());
    QVector<double> A(du.size()*du.size());
    QVector<double> B(result.size());

    double maxDu;
    double maxDdu;
    int count=0;
    for (int i=0;i<du.size();i++)
    {
        du[i]=5.0;
        olddu[i]=5.0;
        ddu[i]=5.0;
    }
    B[0]=0;
    B[B.size()-1]=0;
    A=fillYacoby(result,h,thau);
    for (int i=1;i<B.size()-1;i++)
        B[i]=-fi(oldW,result[i],result[i+1],result[i-1],i,h,thau);
    maxDu=fabs(getMax(du));
    maxDdu=fabs(getMax(ddu));
    while ((maxDu>0.005 || maxDdu > 0.001) && count<1000)
        {
            olddu=solveGauss(A,B);
            B[0]=0;
            B[B.size()-1]=0;
            A=fillYacoby(result,h,thau);
            for (int i=1;i<B.size()-1;i++)
                B[i]=-fi(oldW,result[i],result[i+1],result[i-1],i,h,thau);
            du=solveGauss(A,B);
            for(int i=0;i<du.size();i++)
            {
                ddu[i]=fabs(olddu[i]-du[i]);
            }
            for (int i=0;i<du.size();i++)
            {
                result[i]=result[i]+du[i];
                testResult[i]=result[i];
            }
            maxDu=fabs(getMax(du));
            maxDdu=fabs(getMax(ddu));
            count++;
        }
    return result;
}
QVector<double> NotObviousMethod::fillYacoby(QVector<double> ws, double h, double thau)
{
    QVector<double> A(ws.size()*ws.size());
    A[0]=1;
    for (int i=1;i<ws.size()-1;i++)
    {
        A[i*ws.size()+i]=dfdwi(ws[i],ws[i+1],ws[i-1],h,thau);
        A[i*ws.size()+i+1]=dfdwiplus1(ws[i],ws[i+1],ws[i-1],h,thau);
        A[i*ws.size()+i-1]=dfdwiminus1(ws[i],ws[i+1],ws[i-1],h,thau);
     }
     A[A.size()-1]=1;
     return A;
}
QVector<double> NotObviousMethod::solveInterpolation(QVector<double> xOld, QVector<double> yOld, QVector<double> xNew)
{
    const int sizeXNew = xNew.size();
    const int sizeXOld = xOld.size();
    QVector<double> yNew(sizeXNew);
    QVector<double> yCopy(sizeXNew);
    double Fi = 0;
    double p1 = 1;
    double p2 = 1;
    for (int k = 0; k < sizeXNew; k++)
        {
            Fi = 0;
            for (int i = 0; i < sizeXOld; i++)
                {
                    p1 = 1;
                    p2 = 1;
                    for (int j = 0; j < sizeXOld; j++)
                        {
                            if (i != j)
                            {
                                p1 = p1 * (xNew[k] - xOld[j]);
                                p2 = p2 * (xOld[i] - xOld[j]);
                            }
                        }
                    Fi = Fi + yOld[i] * p1 / p2;
                }
        yNew[k] = Fi;
        yCopy[k] =Fi;
    }
    return yNew;
}
QVector<double> NotObviousMethod::getDoubleX(QVector<double> oldX)
{
    QVector<double> newX(oldX.size()*2-1);
    double h = (rightBoundary-leftBoundary)/(newX.size()-1);
    newX[0]=leftBoundary;
    for (int i=1;i<newX.size();i++)
    {
        newX[i]=newX[i-1]+h;
    }
    return newX;
}
QVector<double> NotObviousMethod::getCoeffs(QVector<double> WHT, QVector<double> WHTdiv2, QVector<double> WHdiv2T, double h, double t, double &alphaOut)
{
    QVector<double> C1(WHT.size()),C2(WHT.size());
    for (int i=0;i< WHT.size();i++)
    {
        C1[i]=2.0/pow(t,2)*(WHTdiv2[i]-WHT[i]);
        C2[i]=4.0/(3.0*h*h*t)*(WHdiv2T[i*2]-WHT[i]);
    }
    QVector<double> alphai(WHT.size()),bettai(WHT.size());
    for (int i=0;i< WHT.size();i++)
    {
        alphai[i]=sqrt(edop/(2*fabs(C1[i])*pow(t,2)));
    }
    double alpha=getMin(alphai);
    if (alpha<coeffMin) alpha=coeffMin;
    if(alpha>coeffMax) alpha=coeffMax;
    QVector<double> e1(WHT.size());
    for (int i=0;i<e1.size();i++)
    {
        e1[i]=edop-fabs(C1[i])*pow(alpha*t,2.0);
        bettai[i]=1.0/h*sqrt(e1[i]/(alpha*t*fabs(C2[i])));
    }
    alphaOut=alpha;
    return bettai;
}
QVector<double> NotObviousMethod::clarifyW(QVector<double> WHT, QVector<double> WHTdiv2, QVector<double> WHdiv2T)
{
    QVector<double> clU(WHT.size());
    for (int i=0;i<clU.size();i++)
    {
        clU[i]=2 * WHTdiv2[i]+4.0/3 * WHdiv2T[i*2]-7.0/3 * WHT[i];
    }
    return clU;
}
QVector<double> NotObviousMethod::createNewWeb(QVector<double> oldX, QVector<double> bettas,double& h)
{
    double betta=getMin(bettas);
    if(betta<coeffMin) betta=coeffMin;
    if(betta>coeffMax) betta=coeffMax;
    h*=betta;
    if (h>hMax) h=hMax;
    if (h<hMin) h=hMin;
    int number=(rightBoundary-leftBoundary)/h+1;
    h=(rightBoundary-leftBoundary)/(number-1);//floor;
    QVector<double> x(number);
    x[0]=leftBoundary;
    for (int i=1;i<number;i++)
    {
        x[i]=x[i-1]+h;
    }
    if (x.back()!=rightBoundary)
    {
        qDebug() << "working...";
        //exit(4);
    }
    return x;
}

double NotObviousMethod::getEps(QVector<double> WHT, QVector<double> WHTdiv2, QVector<double> WHdiv2T)
{
    QVector<double> eps(WHT.size());
    for (int i=0;i<eps.size();i++)
    {
        eps[i]=2 * WHTdiv2[i]+4.0/3.0 * WHdiv2T[i*2]-10.0/3.0 * WHT[i];
    }
    double maxEps=getMax(eps);
    return maxEps;
}
double NotObviousMethod::fi(QVector<double> oldW, double wi, double wiplus1, double wiminus1, int i, double h, double thau)
{
    double x1,x2,x3,x4,x5;
    x1=powr(wi,-1.0/3.0);
    x2=powr((wiplus1-wiminus1)/(2.0*h),-1.0/3.0);
    x3=powr(wi,2.0/3.0);
    x4=(wiminus1-2*wi+wiplus1)/(h*h);
    x5=thau*_equationB*powr(wi,1.0/3.0);
    return oldW[i]-wi+thau*_equationA*(2.0/3.0*x1*x2+x3*x4)+x5;
}
void NotObviousMethod::calculateMethod()
{
    int i;
    //double t=tMin;
    //double h=hMin;

    double h = (rightBoundary-leftBoundary)/(numberOfX-1);
    double t = (rightBoundary-leftBoundary)/(numberOfT-1);

    QVector< QVector<double> > Z;
    Z.push_back((QVector<double>)0);
    W.push_back((QVector<double>)0);

    int number=(rightBoundary-leftBoundary)/h+1;
    double XR;
    QVector<double> VXR;
    for(XR=0,i=0;i<number;i++,XR+=h)
    {
        VXR.push_back(XR);
    }
    X.push_back(VXR);

    foreach(double value, X[0])
    {
        W[0].push_back(getAccurateValue(value,0));
        Z[0].push_back(getAccurateValue(value,0));
    }
    int k=0;
    double time = leftBoundary;
    T.push_back(time);
    while(time<rightBoundary-0.01)
    {
        time+=t;
        T.push_back(time);
        H.push_back(h);
        THAU.push_back(t);
        steps.push_back(k);
        Z.push_back((QVector<double>)0);
        for (i=0;i<X[0].size();i++)
        {
            Z.back().push_back(getAccurateValue(X[0][i],time));
        }
        QVector<double> WHT;
        QVector<double> WHTdiv2;
        QVector<double> WHdiv2T;
        QVector<double> WSupport;
        QVector<double> doubleX;
        QVector<double> oldX=X.back();
        QVector<double> supportX;
        QVector<double> WClarify;

        WHT=calculateNewton(W.back(),time,h,t);

        WHTdiv2=calculateNewton(W.back(),time-t/2.0,h,t/2.0);
        WHTdiv2=calculateNewton(WHTdiv2,time,h,t/2.0);

        doubleX=getDoubleX(oldX);
        WSupport=solveInterpolation(oldX,W.back(),doubleX);
        WHdiv2T=calculateNewton(WSupport,time,h/2.0,t);

        double eps = getEps(WHT,WHTdiv2,WHdiv2T);
        if(fabs(eps)>edop && (h>hMin || t>tMin))
        {
            h=h/2.0;
            time-=t;
            t=t/2;
            if(t<tMin) t=tMin;
            if(t>tMax) t=tMax;
            if(h<hMin)
            {
                h=hMin;
                X.back()=oldX;
                W.back()=W.back();
            }
            else
            {
                supportX=getDoubleX(oldX);
                X.back()=supportX;
                W.back()=solveInterpolation(oldX,W.back(),supportX);
            }
            qDebug() << "OTKAZ " << "h= " << h << "t= "<<t << "time is" << time << "eps is" << fabs(eps);
        }
        else
        {
            WClarify=clarifyW(WHT,WHTdiv2,WHdiv2T);
            double alpha;
            QVector<double> bettas=getCoeffs(WHT,WHTdiv2,WHdiv2T,h,t,alpha);
            t*=alpha;
            X.push_back(createNewWeb(oldX,bettas,h));
            W.push_back(solveInterpolation(oldX,WClarify,X.back()));

            double argument=leftBoundary;
            foreach (double value, W.back())
            {
                 stream <<"time is " << time <<" yApp=  " << value <<" yAcc=  " <<getAccurateValue(argument,time) <<" absPoh=  "<< value-getAccurateValue(argument,time)  << " otnPoh=  "<<(value-getAccurateValue(argument,time))/value*100. <<"\n";
                 argument+=h;
                 fout << argument << " " << time << " " << value << endl;
            }
            stream <<endl;
        }
        k++;
    }
    displayGraphThau();
    displayGraphH();
    stream<<"test";
}
void NotObviousMethod::displayGraphThau()
{
    QGridLayout *grLay = new QGridLayout(ui->graphThauFrame);
    grLay->setContentsMargins(1,1,1,1);
    QwtText *testText = new QwtText("Graphic of thau(time step) dependence");
    QwtPlot *testPlot = new QwtPlot(*testText,ui->graphThauFrame);
    grLay->addWidget(testPlot,0,0);
    QwtPlotCurve *testCurve = new QwtPlotCurve();
    testCurve->setRenderHint(QwtPlotItem::RenderAntialiased);
    QPen pen = QPen(Qt::blue);
    testCurve->setPen(pen);
    testCurve->attach(testPlot);
    testCurve->setData(steps,THAU);
    testPlot->replot();
}
void NotObviousMethod::displayGraphH()
{
    QGridLayout *grLay = new QGridLayout(ui->graphHFrame);
    grLay->setContentsMargins(1,1,1,1);
    QwtText *testText = new QwtText("Graphic of h(space step) dependence");
    QwtPlot *testPlot = new QwtPlot(*testText,ui->graphHFrame);
    grLay->addWidget(testPlot,0,0);
    QwtPlotCurve *testCurve = new QwtPlotCurve();
    testCurve->setRenderHint(QwtPlotItem::RenderAntialiased);
    QPen pen = QPen(Qt::blue);
    testCurve->setPen(pen);
    testCurve->attach(testPlot);
    testCurve->setData(steps,H);
    testPlot->replot();
}
void NotObviousMethod::on_calculateButton_clicked()
{
    calculateMethod();
    ui->plainTextEdit->clear();
    printf(outputString);
    outputString.clear();
}
void NotObviousMethod::on_equationA_valueChanged(double arg1)
{
    setEquationA(arg1);
}
void NotObviousMethod::on_equationB_valueChanged(double arg1)
{
    setEquationB(arg1);
}
void NotObviousMethod::on_accurateA_valueChanged(double arg1)
{
    setAccurateA(arg1);
}
void NotObviousMethod::on_accurateB_valueChanged(double arg1)
{
    setAccurateB(arg1);
}

