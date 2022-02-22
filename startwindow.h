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

    QGridLayout *mainGrid {nullptr}; //создаем грид, который кладем на вкладку
    QPushButton *buttonOne {nullptr};

    Explorer *exp {nullptr};


 public slots:

    void buttonOne_clicked();

};

#endif // STARTWINDOW_H
