#ifndef INSERTVALUTE_H
#define INSERTVALUTE_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>

#include "parservalute.h"

class insertValute : public QWidget
{
    Q_OBJECT
public:
    explicit insertValute(QWidget *parent = nullptr);

private:
    QGridLayout *mainGrid; //создаем грид, который кладем на вкладку

    QPlainTextEdit *planeOne;
    QLabel *desc;
    ParserValute *parserValute;//парсер для замены знаков валюты
signals:

public slots:
    void on_plainTextEdit_textChanged(); //слот при изменении текста
};

#endif // INSERTVALUTE_H
