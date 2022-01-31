#include "startwindow.h"

startWindow::startWindow(QWidget *parent)
    : QWidget(parent)
{
    mainGrid = new QGridLayout(this);

    buttonOne = new QPushButton(this);
    buttonTwo = new QPushButton(this);
    buttonThree = new QPushButton(this);

    buttonOne->setText("Задание 1");
    buttonTwo->setText("Задание 2");
    buttonThree->setText("Задание 3");

    mainGrid->addWidget(buttonOne, 1, 1, 1, 1);
    mainGrid->addWidget(buttonTwo, 3,1,1,1);
    mainGrid->addWidget(buttonThree, 5, 1, 1, 1);

    connect(buttonOne, SIGNAL(clicked()), this, SLOT(buttonOne_clicked()));
    connect(buttonTwo, SIGNAL(clicked()), this, SLOT(buttonTwo_clicked()));
    connect(buttonThree, SIGNAL(clicked()), this, SLOT(buttonThree_clicked()));

    this->setLayout(mainGrid);

    valute = new insertValute(this);
    valute->setWindowFlags(Qt::Window);
    viewlanguage = new ViewLanguage(this);
    viewlanguage->setWindowFlags(Qt::Window);
    computerview = new ComputerView(this);
    computerview->setWindowFlags(Qt::Window);
}

void startWindow::buttonOne_clicked()
{
    valute->show();
}

void startWindow::buttonTwo_clicked()
{
    viewlanguage->show();
}

void startWindow::buttonThree_clicked()
{
    computerview->show();
}

