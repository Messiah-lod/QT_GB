#include "planetext.h"

planeText::planeText(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout(this);

    buttonTextToSecond = new QPushButton(this);
    buttonTextToSecond->setText("Добавить из 1 во 2");
    buttonReplaceTextOne = new QPushButton(this);
    buttonReplaceTextOne->setText("Заменить в 1 на 2");
    buttonAppendHtmlTextSecond = new QPushButton(this);
    buttonAppendHtmlTextSecond->setText("Добавить во 2 HTML");

    description = new QLabel(this);
    description->setWordWrap(true);
    description->setText("Первая кнопка будет добавлять текст из"
                         " одного текстового виджета в другой, вторая"
                         " кнопка - заменять текст в одном виджете на "
                         "текст в другом виджете. Добавить третью кнопку,"
                         " которая вставляет в один из текстовый виджет "
                         "текст произвольного html-кода");
    oneText = new QLabel(this);
    oneText->setText("Поле ввода №1");
    twoText = new QLabel(this);
    twoText->setText("Поле ввода №2");

    planeOne = new QPlainTextEdit(this);
    planeTwo = new QPlainTextEdit(this);

    mainGrid->addWidget(description, 0, 0, 1, 6);
    mainGrid->addWidget(oneText, 2, 0, 1, 3);
    mainGrid->addWidget(twoText, 2, 3, 1, 3);
    mainGrid->addWidget(planeOne, 3, 0, 1, 3);
    mainGrid->addWidget(planeTwo, 3, 3, 1, 3);
    mainGrid->addWidget(buttonTextToSecond, 4, 0, 1, 2);
    mainGrid->addWidget(buttonReplaceTextOne, 4, 2, 1, 2);
    mainGrid->addWidget(buttonAppendHtmlTextSecond, 4, 4, 1, 2);

    connect(buttonTextToSecond, SIGNAL(clicked()), this, SLOT(on_buttonTextToSecond_clicked()));
    connect(buttonReplaceTextOne, SIGNAL(clicked()), this, SLOT(on_buttonReplaceTextOne_clicked()));
    connect(buttonAppendHtmlTextSecond, SIGNAL(clicked()), this, SLOT(on_buttonAppendHtmlTextSecond_clicked()));

    this->setLayout(mainGrid);
    this->setWindowTitle("QPlainTextEdit");
}


void planeText::on_buttonTextToSecond_clicked(){
    planeTwo->appendPlainText(planeOne->toPlainText());
}

void planeText::on_buttonReplaceTextOne_clicked(){
    planeOne->clear();
    planeOne->appendPlainText(planeTwo->toPlainText());
}

void planeText::on_buttonAppendHtmlTextSecond_clicked(){
    planeTwo->appendHtml("<font color='red'>Hello</font>");
}