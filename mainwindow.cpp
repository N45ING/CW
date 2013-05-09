#include "mainwindow.h"
#include <QGridLayout>
#include "ui_mainwindow.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
};
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_actionExit_triggered()
{
    MainWindow::close();
}

void MainWindow::on_pushButton_clicked()
{
}
