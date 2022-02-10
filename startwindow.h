#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>

#include "explorer.h"

class startWindow : public QWidget
{
    Q_OBJECT
public:
    startWindow(QWidget *parent = nullptr);

    QGridLayout *mainGrid; //создаем грид, который кладем на вкладку
    QPushButton *buttonOne;
//    QPushButton *buttonTwo;
//    QPushButton *buttonThree;

    Explorer *exp;


 public slots:

    void buttonOne_clicked();
    void buttonTwo_clicked();
    void buttonThree_clicked();



};

#endif // STARTWINDOW_H
