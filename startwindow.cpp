#include "startwindow.h"

startWindow::startWindow(QWidget *parent)
    : QWidget(parent)
{
    mainGrid = new QGridLayout(this);

    buttonOne = new QPushButton(this);
//    buttonTwo = new QPushButton(this);
//    buttonThree = new QPushButton(this);

    exp = new Explorer(this);

    buttonOne->setText("Файловая система");
//    buttonTwo->setText("Задание 2");
//    buttonThree->setText("Задание 3");

    mainGrid->addWidget(buttonOne, 1, 1, 1, 1);
//    mainGrid->addWidget(buttonTwo, 3,1,1,1);
//    mainGrid->addWidget(buttonThree, 5, 1, 1, 1);

    connect(buttonOne, &QPushButton::clicked, this, &startWindow::buttonOne_clicked);

//    connect(buttonTwo, SIGNAL(clicked()), this, SLOT(buttonTwo_clicked()));
//    connect(buttonThree, SIGNAL(clicked()), this, SLOT(buttonThree_clicked()));

    exp->setWindowFlags(Qt::Window);
    this->setLayout(mainGrid);
}

void startWindow::buttonOne_clicked()
{
    exp->show();
}

void startWindow::buttonTwo_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Задание 2");
    msgBox.exec();
}

void startWindow::buttonThree_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Задание 3");
    msgBox.exec();
}

