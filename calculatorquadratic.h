#ifndef CALCULATORQUADRATIC_H
#define CALCULATORQUADRATIC_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include <QtCore/qmath.h>

class calculatorQuadratic : public QWidget
{
    Q_OBJECT
public:
    explicit calculatorQuadratic(QWidget *parent = nullptr);

    QGridLayout *mainGrid; //создаем грид, который кладем на вкладку
    QPushButton *buttonCalculate;
    QPushButton *buttonClear;

    QLineEdit *numberA;
    QLineEdit *numberB;
    QLineEdit *numberC;

    QLabel *description;
    QLabel *answer;
    QLabel *textX2;
    QLabel *textX;
    QLabel *textEqually;

private:
    double numA, numB, numC, numD, resultX1, resultX2;
    QString numAtxt, numBtxt, numCtxt;

signals:

public slots:
    void on_buttonCalculate_clicked();
    void on_buttonClear_clicked();
};

#endif // CALCULATORQUADRATIC_H
