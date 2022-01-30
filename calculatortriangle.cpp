#include "calculatortriangle.h"

calculatorTriangle::calculatorTriangle(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout(this);

    buttonCalculate = new QPushButton(this);
    buttonCalculate->setText("Вычислить");

    sideAEdit = new QLineEdit(this);
    sideBEdit = new QLineEdit(this);
    angEdit = new QLineEdit(this);

    grad = new QRadioButton(this);
    grad->setText("Угол в градусах");
    grad->setChecked(true);
    rad = new QRadioButton(this);
    rad->setText("Угол в радианах");

    description = new QLabel(this);
    description->setText("Укажите стороны треугольника A, B и угол между ними для расчета третьей стороны треугольника.");
    answer = new QLabel(this);
    textSideA = new QLabel(this);
    textSideA->setText("Сторона А ");
    textSideB = new QLabel(this);
    textSideB->setText("Сторона В ");
    textAng = new QLabel(this);
    textAng->setText("Угол ");

    mainGrid->addWidget(description, 0, 0, 1, 6);
    mainGrid->addWidget(textSideA, 2, 0, 1, 1);
    mainGrid->addWidget(sideAEdit, 2, 1, 1, 1);
    mainGrid->addWidget(textSideB, 2, 2, 1, 1);
    mainGrid->addWidget(sideBEdit, 2, 3, 1, 1);
    mainGrid->addWidget(textAng, 2, 4, 1, 1);
    mainGrid->addWidget(angEdit, 2, 5, 1, 1);
    mainGrid->addWidget(grad, 3, 4, 1, 2);
    mainGrid->addWidget(rad, 4, 4, 1, 2);
    mainGrid->addWidget(buttonCalculate, 5, 3, 1, 2);
    mainGrid->addWidget(answer, 6, 3, 1, 3);

    connect(buttonCalculate, SIGNAL(clicked()), this, SLOT(on_buttonCalculate_clicked()));

    this->setLayout(mainGrid);
    this->setWindowTitle("Рассчет стороны реугольника");
}

void calculatorTriangle::on_buttonCalculate_clicked(){
    strSideA = sideAEdit->text();
    strSideB = sideBEdit->text();
    strAng = angEdit->text();
    strSideA.replace(",",".");
    strSideB.replace(",",".");
    strAng.replace(",",".");
    if(strSideA == "" || strSideB == "" || strAng == "") {
        QMessageBox msgBox;
        msgBox.setText("Данные для расчета введены не корректно");
        msgBox.exec();
    }
    sideA = strSideA.toDouble();
    sideB = strSideB.toDouble();
    ang = strAng.toDouble();
    //заполним edit значениями после преобразования
    sideAEdit->setText(QString::number(sideA));
    sideBEdit->setText(QString::number(sideB));
    angEdit->setText(QString::number(ang));

    if(grad->isChecked()) ang /= ( 180 / M_PI );

    result = qSqrt(qPow(sideA,2) + qPow(sideB,2) - 2*sideA*sideB*qCos(ang));
    answer->setText("Длина третьей стороны равна: " + QString::number(result));

}
