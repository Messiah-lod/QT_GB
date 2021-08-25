#include "calculatorquadratic.h"

calculatorQuadratic::calculatorQuadratic(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout;

    buttonCalculate = new QPushButton;
    buttonCalculate->setText("Вычислить");
    buttonClear = new QPushButton;
    buttonClear->setText("Очистить");

    numberA = new QLineEdit;
    numberB = new QLineEdit;
    numberC = new QLineEdit;

    description = new QLabel;
    description->setText("Укажите коэффициенты A, B и C квадратного уравнения Ax^2 + Bx + C = 0");
    answer = new QLabel;
    textX2 = new QLabel;
    textX2->setText("x^2 + ");
    textX = new QLabel;
    textX->setText(" x + ");
    textEqually = new QLabel;
    textEqually->setText(" = 0");

    mainGrid->addWidget(description, 0, 0, 1, 6);
    mainGrid->addWidget(numberA, 2, 0, 1, 1);
    mainGrid->addWidget(textX2, 2, 1, 1, 1);
    mainGrid->addWidget(numberB, 2, 2, 1, 1);
    mainGrid->addWidget(textX, 2, 3, 1, 1);
    mainGrid->addWidget(numberC, 2, 4, 1, 1);
    mainGrid->addWidget(textEqually, 2, 5, 1, 1);
    mainGrid->addWidget(buttonClear, 4, 0, 1, 2);
    mainGrid->addWidget(buttonCalculate, 4, 3, 1, 2);
    mainGrid->addWidget(answer, 5, 3, 2, 3);

    QObject::connect(buttonCalculate, SIGNAL(clicked()), this, SLOT(on_buttonCalculate_clicked()));
    QObject::connect(buttonClear, SIGNAL(clicked()), this, SLOT(on_buttonClear_clicked()));

    this->setLayout(mainGrid);

    this->setWindowTitle("Рассчет квадратного уравнения");
}


void calculatorQuadratic::on_buttonCalculate_clicked(){
    numAtxt = numberA->text();
    numBtxt = numberB->text();
    numCtxt = numberC->text();
    //проверим на пустой ввод
    if( numAtxt == "" && numBtxt == "" && numCtxt == ""){
        QMessageBox msgBox;
        msgBox.setText("Данные для расчета не введены!");
        msgBox.exec();
    };
    //выполним преобразование и приведение строк к числам
    numAtxt.replace(",",".");
    numBtxt.replace(",",".");
    numCtxt.replace(",",".");
    numA = numAtxt.toDouble();
    numB = numBtxt.toDouble();
    numC = numCtxt.toDouble();
    //заполним edit значениями после преобразования
    numberA->setText(QString::number(numA));
    numberB->setText(QString::number(numB));
    numberC->setText(QString::number(numC));

    //Проведем рачет корней уравнения
    numD = qPow(numB, 2) - 4 * numA * numC;
    if(numA != 0.0 && numD >= 0){
        resultX1 = ((-1 * numB) + qSqrt(numD))/(2*numA);
        resultX2 = ((-1 * numB) - qSqrt(numD))/(2*numA);
    } else if(numA == 0.0) {
        resultX1 = resultX2 = (-1 * numC)/numB;
        numD = 0;
    }

    if(numD > 0){
        answer->setText("Результат: D = " + QString::number(numD) +
                        "\n X1 = " + QString::number(resultX1) +
                        "\n X2 = " +QString::number(resultX2));
    } else if (numD < 0){
        numD *= -1;
        answer->setText("Результат: D = " + QString::number(numD * (-1)) +
                        "\n X1 = " + QString::number((-1 * numB)/(2*numA)) + "+" + QString::number(qSqrt(numD)/(2*numA)) + "j" +
                        "\n X2 = " +QString::number((-1 * numB)/(2*numA)) + "-" + QString::number(qSqrt(numD)/(2*numA)) + "j" );
    } else {
        answer->setText("Результат: D = " + QString::number(numD) +
                        "\n X = " + QString::number(resultX1));
    }

}

void calculatorQuadratic::on_buttonClear_clicked(){
    numberA->setText("");
    numberB->setText("");
    numberC->setText("");
}
