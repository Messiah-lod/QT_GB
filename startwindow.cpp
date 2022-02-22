#include "startwindow.h"

startWindow::startWindow(QWidget *parent)
    : QWidget(parent)
{
    mainGrid = new QGridLayout(this);
    exp = new Explorer(this);

    buttonOne = new QPushButton(this);
    buttonOne->setText("Файловая система");
    mainGrid->addWidget(buttonOne, 1, 1, 1, 1);
    connect(buttonOne, &QPushButton::clicked, this, &startWindow::buttonOne_clicked);

    exp->setWindowFlags(Qt::Window);
    this->setLayout(mainGrid);
}

void startWindow::buttonOne_clicked()
{
    exp->show();
}
