#include "startwindow.h"

startWindow::startWindow(QWidget *parent)
    : QWidget(parent)
{
    mainGrid = new QGridLayout;

    buttonOne = new QPushButton;
    buttonTwo = new QPushButton;
    buttonThree = new QPushButton;

    buttonOne->setText("Задание 1");
    buttonTwo->setText("Задание 2");
    buttonThree->setText("Задание 3");

    mainGrid->addWidget(buttonOne, 1, 1, 1, 1);
    mainGrid->addWidget(buttonTwo, 3,1,1,1);
    mainGrid->addWidget(buttonThree, 5, 1, 1, 1);

    QObject::connect(buttonOne, SIGNAL(clicked()), this, SLOT(buttonOne_clicked()));
    QObject::connect(buttonTwo, SIGNAL(clicked()), this, SLOT(buttonTwo_clicked()));
    QObject::connect(buttonThree, SIGNAL(clicked()), this, SLOT(buttonThree_clicked()));

    this->setLayout(mainGrid);

    calc = new calculatorQuadratic(this);
    calc->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);//запустить отдельным окном

    calcTriangle = new calculatorTriangle(this);
    calcTriangle->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    planeTxt = new planeText(this);
    planeTxt->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
}

void startWindow::buttonOne_clicked()
{
    calc->show();
}

void startWindow::buttonTwo_clicked()
{
    calcTriangle->show();
}

void startWindow::buttonThree_clicked()
{
    planeTxt->show();
}

