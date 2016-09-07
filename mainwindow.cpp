#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_nn = new NeuralNetwork();

    m_nn->loadNetwork("neuralnetwork.xml", 784);

    connect(ui->scribbler,SIGNAL(guessDigit(QVector<double>)),this,SLOT(guessDigit(QVector<double>)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::guessDigit(QVector<double> image)
{
    QVector<double> output = m_nn->getResults(image);
    double max = 0;
    unsigned number = 0;

    for ( unsigned i=0; i<10; ++i )
    {
        if ( output[i] > max )
        {
            max = output[i];
            number = i;
        }
    }

    ui->digit->setText(QString::number(number));
    ui->percent->setText(QString::number(max*100.0)+'%');
}
