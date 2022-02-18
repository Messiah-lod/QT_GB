#include "startwindow.h"

startWindow::startWindow(QWidget *parent)
    : QWidget(parent)
{
    mainGrid = new QGridLayout(this);

    buttonOne = new QPushButton(this);
    gEdit = new graphicsEditor(this);
    gEdit->setWindowFlags(Qt::Window);

    buttonOne->setText("Задание 1");


    mainGrid->addWidget(buttonOne, 1, 1, 1, 1);
 //   mainGrid->addWidget(buttonTwo, 3,1,1,1);
  //  mainGrid->addWidget(buttonThree, 5, 1, 1, 1);

    connect(buttonOne, SIGNAL(clicked()), this, SLOT(buttonOne_clicked()));


    this->setLayout(mainGrid);
}

void startWindow::buttonOne_clicked()
{
//    QMessageBox msgBox;
//    msgBox.setText("Задание 1");
//    msgBox.exec();
        gEdit->show();
}


