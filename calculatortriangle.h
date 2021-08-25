#ifndef CALCULATORTRIANGLE_H
#define CALCULATORTRIANGLE_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include <QtCore/qmath.h>

class calculatorTriangle : public QWidget
{
    Q_OBJECT
public:
    explicit calculatorTriangle(QWidget *parent = nullptr);

    QGridLayout *mainGrid; //создаем грид, который кладем на вкладку
    QPushButton *buttonCalculate;

    QRadioButton *grad;
    QRadioButton *rad;

    QLineEdit *sideAEdit;
    QLineEdit *sideBEdit;
    QLineEdit *angEdit;

    QLabel *description;
    QLabel *answer;
    QLabel *textSideA;
    QLabel *textSideB;
    QLabel *textAng;

    double sideA, sideB, ang, result;
    QString strSideA, strSideB, strAng;

signals:

public slots:
    void on_buttonCalculate_clicked();
};

#endif // CALCULATORTRIANGLE_H
