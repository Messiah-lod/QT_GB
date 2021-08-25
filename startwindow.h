#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>

#include "calculatorquadratic.h"
#include "calculatortriangle.h"
#include "planetext.h"

class startWindow : public QWidget
{
    Q_OBJECT
public:
    startWindow(QWidget *parent = nullptr);

    QGridLayout *mainGrid; //создаем грид, который кладем на вкладку
    QPushButton *buttonOne;
    QPushButton *buttonTwo;
    QPushButton *buttonThree;

    calculatorQuadratic *calc;
    calculatorTriangle *calcTriangle;
    planeText *planeTxt;

 public slots:

    void buttonOne_clicked();
    void buttonTwo_clicked();
    void buttonThree_clicked();



};

#endif // STARTWINDOW_H
